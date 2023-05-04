#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino_FreeRTOS.h>

#define RST_PIN 2
#define SS_PIN 53

MFRC522 mfrc(SS_PIN, RST_PIN);

bool READ_ID = false;

void setup() 
{
    Serial.begin(115200);
    while(!Serial);
    SPI.begin();
    mfrc.PCD_Init();
}

void loop() 
{
    if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial())
    {
    }
    else
    {
        READ_ID = true;
    }

    if (READ_ID == true) 
    {
        for (byte i = 0; i < 10; i++) {
        Serial.println(mfrc.uid.uidByte[i]);
      }
    }
}
