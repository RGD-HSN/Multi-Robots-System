#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(10, 9);  // CE, CSN (Adjust pins as per your setup)
const byte address[6] = "00001";  // Must match receiver
int8_t received_data[24];  // Buffer for incoming serial data

void setup() {
    Serial.begin(57600);
    Serial.println("Arduino Nano Ready");
pinMode(5,OUTPUT);

    // NRF24 Setup
    radio.begin();
    radio.openWritingPipe(address);
    radio.setRetries(15, 0);  // 3 retries, 0ms delay (instead of default 15 retries, 4ms delay)
    radio.setPALevel(RF24_PA_HIGH);
    radio.setDataRate(RF24_1MBPS); 
    radio.stopListening();  // Set as transmitter
}

// Function to read a valid 24-byte packet from Serial
bool read_serial_data() {
    while (Serial.available() >= 26) {  // Ensure a full packet (1 start + 24 data + 1 end)
        if (Serial.read() == 0xAA) {  // Look for Start Byte
            Serial.readBytes((char*)received_data, 24);  // Read 24 data bytes
            if (Serial.read() == 0x55) {  // Look for End Byte
                  return true;  // Successfully read a valid packet
            }
        }
    }
    
     return false;  // No valid packet found

}

void loop() {
     if( read_serial_data())
       {  // Only send if valid data was read
        bool success = radio.write(&received_data, sizeof(received_data));

    }

}