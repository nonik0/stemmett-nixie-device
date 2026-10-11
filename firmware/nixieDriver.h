#include <Arduino.h>
#include <SPI.h>
#include "board.h"

#if defined(BEAU) || defined(OWEN)
constexpr int NUM_CATHODE_REGISTERS = 5;
#else
constexpr int NUM_CATHODE_REGISTERS = 3;
#endif

void nixieSetup() {
  log_d("Setting up nixie tubes");
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);
  pinMode(LATCH_PIN, OUTPUT);
  digitalWrite(LATCH_PIN, LOW);
  for (int i = 0; i < NUM_TUBES; i++) {
    pinMode(Tubes[i].AnodePin, OUTPUT);
    digitalWrite(Tubes[i].AnodePin, LOW);
  }

  SPI.begin();

  // zero out cathode buffer
  for (int i = 0; i < NUM_CATHODE_REGISTERS; i++) {
    SPI.transfer(0x00);
  }
  digitalWrite(LATCH_PIN, HIGH);

  // Setup PWM for each tube.
  for (int i = 0; i < NUM_TUBES; i++) {
    ledcSetup(i, PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(Tubes[i].AnodePin, i);

    // Calculate PWM phase offset to smooth out power consumption.
    int phaseDeg = (360 / NUM_TUBES) * i;
    Tubes[i].PwmPhase = (phaseDeg / 360.0) * pow(2, PWM_RESOLUTION);

    ledcWrite(i, 128);
  }

  log_d("Nixie tubes setup complete");
}

void nixieDisplay(Tube tubes[NUM_TUBES]) {
  digitalWrite(LATCH_PIN, LOW);

#if defined(BEAU) || defined(OWEN)
  // Bowen: All 40 cathodes are controlled by 5x shift registers
  uint64_t cathodes = 0;

  for (int i = 0; i < NUM_TUBES; i++) {
    uint8_t cathode = tubes[i].ActiveCathode;

    if (cathode < 10) {
      cathodes |= (uint64_t)1 << (i * 10 + cathode);
    }
  }

  // Shift out all 40 bits, most significant byte first.
  for (int i = NUM_CATHODE_REGISTERS - 1; i >= 0; i--) {
    SPI.transfer((cathodes >> (i * 8)) & 0xFF);
  }
#else
  // Stemmett: cathode index is decoded by the KDL
  for (int i = NUM_TUBES - 1; i >= 1; i -= 2) {
    uint8_t high = tubes[i].ActiveCathode;
    uint8_t low = tubes[i - 1].ActiveCathode;

    SPI.transfer(((high & 0x0F) << 4) | (low & 0x0F));
  }
#endif

  digitalWrite(LATCH_PIN, HIGH);
}

void nixieBrightness(Tube tubes[NUM_TUBES]) {
  for (int i = 0; i < NUM_TUBES; i++) {
    ledcWrite(i, tubes[i].Brightness);
  }
}

void nixieOff(Tube tubes[NUM_TUBES]) {
  for (int i = 0; i < NUM_TUBES; i++) {
    ledcWrite(i, 0);
  }
}
