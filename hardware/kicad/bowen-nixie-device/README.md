# Bowen Nixie Device

## Description
A Nixie device that is a successor/companion to the original Stemmett Nixie Device. Like its predecessor, it uses front-viewed [PL31 socket](https://tubes-store.com/product_info.php?products_id=101) Nixie tubes ([IN-4](https://www.tube-tester.com/sites/nixie/data/in-4/in-4-sh2.htm), [IN-7](https://www.tube-tester.com/sites/nixie/data/IN-7/in-7.htm), [IN-7A](https://www.swissnixie.com/tubes/IN7A/), IN-7B) to spell words with makeshift letters. These Nixie tubes plug into custom PL31 breakout boards which orient the tubes in different rotations. Then these tube breakout boards plug into the main board that supports control of 4 tubes in total. More breakout board variations were added from the original project to enable more letter possible.

Bowen Nixie Device differs from the prior project primarily through some different component choices. In this version, I am primarily using SMD components and have included discrete cathode control for each tube, i.e. every cathode gets its own transistor for control. Cathode control remains the same as before, using a series of shift registers to control the gate for each transistor that controls the cathode on each tube. Each tube still has an anode control circuit for switching the high voltage on the tube's anode, allowing manual control of each tube's brightness with PWM. 

Hardware prototype is pending, firmware

## Work Left
- get new main board and tube breakout boards made
- create initial prototype, vet hardware design
- update existing firmware to work with new board and tube configuration

## Images

#### PCB Layout
<img width="1409" alt="schematic" src="https://github.com/user-attachments/assets/ea55e35f-2240-458f-b62f-b04599d72aab">
<img width="1062" alt="layout" src="https://github.com/user-attachments/assets/d3f8a463-915f-4086-bd1c-70b7b26c18d1"">
