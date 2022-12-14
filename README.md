# LoRa_Comms
Project Lab 3 Code (Digital Communications)

This code allows utilization of communication between modules using the Ebyte E32-900T20D (https://www.cdebyte.com/products/E32-900T20D)
The library used, "EBYTE.h" is developed from Kris Kasprzak (https://github.com/KrisKasprzak/EBYTE). 
This library is utilized in order to program and change parameters of these devices.  

To recreate these modules the following is needed:
1. Arduino Uno
2. Ebyte E32900T20D (Works with other Ebyte E32 Modules. Have not tested with the E220 but will in the future)
3. Logic Level Shifters: Ebyte Logic pins require 3.3V so a 5V to 3V Logic Level Shifter is necessary 

The software developed utilizes a while loop which will always be searching for data until an input is found within the Serial Monitor. Serial.Avaliable() is the trigger in order to change the module into transmit mode. If something is avaliable the function Serial.Read will input each character where SendStruct will send the data and type.  

In terms of Range testing two Antennas were used

1. TX915-JK-11 (2.5dBi antenna that came with the Modules): This paired with the set parameters and 5V Vcc measured a distance of ~3100ft (.9Km)
2. TX915-XPL-100 (3.5dBi Sucker Antenna): With same parameters as previous testing this antenna measured a distance of ~1.27mi (2.04Km)

These range tests had many obstructions in play such as buildings, trees, and busy roads. The 5Km advertised range from Ebyte was within an open field with line of sight. 

Links:
1. Kris Kasprzak Library: https://github.com/KrisKasprzak/EBYTE
2. Ebyte E32 900T20D Module: https://www.cdebyte.com/products/E32-900T20D
3. TX915-JK-11 Rubber Antenna: https://www.cdebyte.com/products/TX915-JK-11
4. TX915-XPL-100 Sucker Antenna: https://www.cdebyte.com/products/TX915-XPL-100
5. Logic Level Converter Bi Directional Module 3.3V to 5V: https://a.co/d/9XxwXr4
