# LoRa_Comms
Project Lab 3 Code (Digital Communications)

This code allows utilization of communication between modules using the Ebyte E32-900T20D (https://www.cdebyte.com/products/E32-900T20D)
The library used, "EBYTE.h" is developed from Kris Kasprzak (https://github.com/KrisKasprzak/EBYTE). 
This library is utilized in order to program and change parameters of these devices.  

To recreate these modules the following is needed:
1. Arduino Uno
2. Ebyte E32900T20D (Works with other Ebyte E32 Modules. Have not tested with the E220 but will in the future)
3. Logic Level Shifters: Ebyte Logic pins require 3.3V so a 5V to 3V Logic Level Shifter is necessary 

The software developed utilizes a while loop which will always be searching for data until an input is found within the Serial Monitor. Serial.Avaliable() is the trigger in order to change the module into transmit mode. 
