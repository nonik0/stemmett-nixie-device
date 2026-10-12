#pragma once

#include "tubes.h"

// T6 | T5 | T4 | T3 | T2 | T1

#if defined(STELLA)
#define LIGHT_SENSOR_PIN 8
#define EN_PIN 7      // OE pin
#define LATCH_PIN 34  // RCLK pin
#define PWM_PIN_1 1   // PWM pin for tube 1 anode
#define PWM_PIN_2 2   // PWM pin for tube 2 anode
#define PWM_PIN_3 3   // PWM pin for tube 3 anode
#define PWM_PIN_4 4   // PWM pin for tube 4 anode
#define PWM_PIN_5 5   // PWM pin for tube 5 anode
#define PWM_PIN_6 6   // PWM pin for tube 6 anode
#define NUM_TUBES 6
inline Tube Tubes[NUM_TUBES] = {
            {IN7_PARTIAL,  IN7_A    /*A*/, PWM_PIN_1, 0, 0, 0},
          {IN4,  IN4_7    /*L*/, PWM_PIN_2, 0, 0, 0},
        {IN4,  IN4_7    /*L*/, PWM_PIN_3, 0, 0, 0},
      {IN7A, IN7_m    /*E*/, PWM_PIN_4, 0, 0, 0},
    {IN7A, IN7_Plus /*T*/, PWM_PIN_5, 0, 0, 0},
  {IN7B, IN7B_S   /*S*/, PWM_PIN_6, 0, 0, 0},
};
#elif defined(EMMETT)
#define LIGHT_SENSOR_PIN 8
#define EN_PIN 7      // OE pin
#define LATCH_PIN 34  // RCLK pin
#define PWM_PIN_1 1   // PWM pin for tube 1 anode
#define PWM_PIN_2 2   // PWM pin for tube 2 anode
#define PWM_PIN_3 3   // PWM pin for tube 3 anode
#define PWM_PIN_4 4   // PWM pin for tube 4 anode
#define PWM_PIN_5 5   // PWM pin for tube 5 anode
#define PWM_PIN_6 6   // PWM pin for tube 6 anode
#define NUM_TUBES 6
inline Tube Tubes[NUM_TUBES] = {
            {IN7,  IN7_Plus /*T*/, PWM_PIN_1, 0, 0, 0},
          {IN7A, IN7A_Plus /*T*/, PWM_PIN_2, 0, 0, 0},
        {IN7,  IN7_m     /*E*/, PWM_PIN_3, 0, 0, 0},
      {IN7A, IN7A_m    /*M*/, PWM_PIN_4, 0, 0, 0},
    {IN7,  IN7_m     /*M*/, PWM_PIN_5, 0, 0, 0},
  {IN7A, IN7A_m    /*E*/, PWM_PIN_6, 0, 0, 0},
};
#elif defined(BEAU)
#define EN_PIN 21 //D6      // OE pin
#define LATCH_PIN 20 //D7  // RCLK pin
#define PWM_PIN_1 5 //D3   // PWM pin for tube 1 anode
#define PWM_PIN_2 4 //D2   // PWM pin for tube 2 anode
#define PWM_PIN_3 3 //D1   // PWM pin for tube 3 anode
#define PWM_PIN_4 2 //D0   // PWM pin for tube 4 anode
// SDA: D4, SCL: D5, SIN: D10/MOSI, SCLK: D8/SCK, EXP: D9/MISO
#define NUM_TUBES 4
inline Tube Tubes[NUM_TUBES] = {
        {IN7, IN7_Pi /*U*/, PWM_PIN_1, 0, 0, 0},
      {IN7, IN7_A  /*A*/, PWM_PIN_2, 0, 0, 0},
    {IN7, IN7_m  /*E*/, PWM_PIN_3, 0, 0, 0},  // or IN7A_m
  {IN7, IN7_m  /*B*/, PWM_PIN_4, 0, 0, 0}, // or IN7A_m
};
#elif defined(OWEN)
#define EN_PIN 21 //D6      // OE pin
#define LATCH_PIN 20 //D7  // RCLK pin
#define PWM_PIN_1 5 //D3   // PWM pin for tube 1 anode
#define PWM_PIN_2 4 //D2   // PWM pin for tube 2 anode
#define PWM_PIN_3 3 //D1   // PWM pin for tube 3 anode
#define PWM_PIN_4 2 //D0   // PWM pin for tube 4 anode
// SDA: D4, SCL: D5, SIN: D10/MOSI, SCLK: D8/SCK, EXP: D9/MISO
#define NUM_TUBES 4
inline Tube Tubes[NUM_TUBES] = {
        {IN7, IN7_Pi /*N*/, PWM_PIN_1, 0, 0, 0},
      {IN7, IN7_m  /*E*/, PWM_PIN_2, 0, 0, 0}, // or IN7A_m
    {IN7, IN7_m  /*W*/, PWM_PIN_3, 0, 0, 0}, // or IN7A_m
  {IN4, IN4_0  /*O*/, PWM_PIN_4, 0, 0, 0}, // or IN7B_Omega
};
#endif