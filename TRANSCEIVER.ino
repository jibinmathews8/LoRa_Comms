// Transceiver
/*
  connections
  Module      Arduino
  M0          4
  M1          5
  Rx          2 (This is the MCU Tx lined)
  Tx          3 (This is the MCU Rx line)
  Aux         6
  Vcc         3V3
  Gnd         Gnd
*/

#include <SoftwareSerial.h> // Take Inputs and Outputs from Serial Monitor
#include "EBYTE.h" // Ebyte Library for communications

#define PIN_RX 2 // Recieve Pin
#define PIN_TX 3 // Transmit Pin
#define PIN_M0 4 // Mode 0 Pin
#define PIN_M1 5 // Mode 1 Pin
#define PIN_AX 6 // Auxillary Pin


struct Codeword{ // Struct for Codeword
  char letter; // Can change to String but RX module will recieve garbage
};

int Chan; // Channel Value Initialization
Codeword test; // Calling Structure

unsigned long Last; // Used for Repition in search

SoftwareSerial ESerial(PIN_RX, PIN_TX); 
EBYTE Transceiver(&ESerial, PIN_M0, PIN_M1, PIN_AX); // Initialize pins with Transceiver


void setup() {

  Serial.begin(9600);

  // start the transceiver serial port--i have yet to get a different
  // baud rate to work--data sheet says to keep on 9600
  ESerial.begin(9600);

  Serial.println("Starting Homebase...");

  Transceiver.init(); // Initialize
  
  Serial.println(Transceiver.GetAirDataRate());
  Serial.println(Transceiver.GetChannel());
  Serial.println(Transceiver.GetTransmissionMode());
  Serial.println(Transceiver.GetTransmitPower());

  
  Transceiver.SetAirDataRate(1); // Set Air Data Rate
  Transceiver.SetAddressH(69); // Set Address High
  Transceiver.SetAddressL(0); // Set Address Low
  Transceiver.SetSpeed(25); // Set Speed
  Chan = 45;
  Transceiver.SetChannel(Chan); // Set Channel ( 862 MHz + ( 1MHz * Channel #))
  Transceiver.SetTransmitPower(0); // Transmit Power 0 for 20 dBm

  Transceiver.SaveParameters(PERMANENT); // Permanately save parameters
  Transceiver.PrintParameters(); // Print all parameters for debugging

}

void loop() {

  if (Serial.available()>0){ // If something available in Serial (Take as input)
   test.letter = Serial.read();
   Transceiver.SendStruct(&test, sizeof(test));
   //ESerial.write((uint8_t*) &test, (uint8_t) sizeof(test) );
   Serial.print(test.letter);
   
   }
  else {
    if (ESerial.available()) {
    Transceiver.GetStruct(&test, sizeof(test));
    //ESerial.readBytes((uint8_t*)&test, (uint8_t) sizeof(test));
    // Serial.print("Recieved from Rover: "); 
    Serial.print(test.letter);
    //Serial.print("Recieved from Rover: "); Serial.println(test.letter);
    
    // if you got data, update the checker
    Last = millis();
    }
      else {
        // if the time checker is over some prescribed amount
        // let the user know there is no incoming data
        if ((millis() - Last) > 1000) {
          Serial.println("Searching/ No Data... ");
          Last = millis();
        }
      }
    }
}
