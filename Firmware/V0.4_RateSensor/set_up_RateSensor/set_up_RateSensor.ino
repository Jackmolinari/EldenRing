#include <Wire.h>
#include "MAX30105.h"

MAX30105 particleSensor;

// Pin I²C utilizzati sul nostro ESP32-C3
#define SDA_PIN 0
#define SCL_PIN 21

void setup()
{
  // Avvio della comunicazione seriale
  Serial.begin(115200);
  delay(1000);

  Serial.println("Avvio test MAX30102...");

  // Inizializzazione del bus I²C
  Wire.begin(SDA_PIN, SCL_PIN);

  // Inizializzazione del sensore
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST))
  {
    Serial.println("MAX30102 non trovato!");
    Serial.println("Controlla alimentazione e collegamenti.");

    while (true)
    {
      delay(1000);
    }
  }

  // Configurazione del sensore con i parametri di default
  particleSensor.setup();

  Serial.println("Sensore inizializzato.");
  Serial.println("Apri il Serial Plotter e appoggia il dito.");
}

void loop()
{
  // Legge il valore grezzo del canale infrarosso
  long irValue = particleSensor.getIR();

  // Invia SOLO il numero al Serial Plotter
  Serial.println(irValue);

  delay(10);
}