#include <Wire.h>

constexpr uint8_t SDA_PIN = 0;
constexpr uint8_t SCL_PIN = 21;

void setup()
{
  Serial.begin(115200);
  delay(1000);

  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println();
  Serial.println("Elden Ring - I2C Scanner");
  Serial.println("Scansione in corso...");

  uint8_t dispositiviTrovati = 0;

  for (uint8_t indirizzo = 1; indirizzo < 127; indirizzo++)
  {
    Wire.beginTransmission(indirizzo);
    const uint8_t errore = Wire.endTransmission();

    if (errore == 0)
    {
      Serial.print("Dispositivo trovato: 0x");

      if (indirizzo < 16)
      {
        Serial.print("0");
      }

      Serial.println(indirizzo, HEX);
      dispositiviTrovati++;
    }
  }

  if (dispositiviTrovati == 0)
  {
    Serial.println("Nessun dispositivo I2C trovato.");
  }
  else
  {
    Serial.println("Scansione completata.");
  }
}

void loop()
{
}
