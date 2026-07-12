/*
--------------------------------------------------
 Project : Elden Ring
 Version : 0.1 - The First Grace
 Authors : Antonio & ChatGPT
 Date    : 27/06/2026
--------------------------------------------------
 Description:
 Primo firmware del progetto.
 Verifica della comunicazione seriale.
--------------------------------------------------
*/

const char* PROJECT_NAME = "Elden Ring";
const char* VERSION = "0.1 - The First Grace";

void setup()
{
  Serial.begin(115200);

  // Aspetta che la seriale sia pronta
  delay(1000);

  Serial.println();
  Serial.println("=================================");
  Serial.println(PROJECT_NAME);
  Serial.println(VERSION);
  Serial.println("System Boot OK");
  Serial.println("=================================");
}

void loop()
{
  Serial.println("Firmware running...");
  delay(1000);
}