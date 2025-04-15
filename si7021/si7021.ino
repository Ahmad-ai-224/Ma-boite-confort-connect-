#include "Adafruit_Si7021.h"
#include <SimpleTimer.h>// Bibliothèque utilisée pour exécuter une fonction à intervalle de temps régulier ( lien pour télécharger la bibliothèque : https://github.com/jfturcot/SimpleTimer )
#include <ArduinoJson.h>// Bibliothèque nécessaire pour lire les données au format Json.

bool enableHeater = false;
uint8_t loopCnt = 0;

Adafruit_Si7021 sensor = Adafruit_Si7021();

SimpleTimer timer;// objet timer permet d'exécuter une fonction à intervalle de temps régulier > on l'utilisera pour la fonction EnvoiDonnees
int periode = 1000; // periode des mesures en ms


void setup() {
  Serial.begin(115200);

  // wait for serial port to open
  while (!Serial) {
    delay(10);
  }

  Serial.println("Si7021 test!");
  
  if (!sensor.begin()) {
    Serial.println("Did not find Si7021 sensor!");
    while (true)
      ;
  }

  Serial.print("Found model ");
  switch(sensor.getModel()) {
    case SI_Engineering_Samples:
      Serial.print("SI engineering samples"); break;
    case SI_7013:
      Serial.print("Si7013"); break;
    case SI_7020:
      Serial.print("Si7020"); break;
    case SI_7021:
      Serial.print("Si7021"); break;
    case SI_UNKNOWN:
    default:
      Serial.print("Unknown");
  }
  Serial.print(" Rev(");
  Serial.print(sensor.getRevision());
  Serial.print(")");
  Serial.print(" Serial #"); Serial.print(sensor.sernum_a, HEX); Serial.println(sensor.sernum_b, HEX);

  timer.setInterval(periode, EnvoiDonnees); // définit un timer qui va exécuter la fonction EnvoiDonnees toutes les periodes

}

void loop() {
  timer.run();// exécute en permanence le timer  > lecture des données toutes les périodes
  /*Serial.print("Humidity:    ");
  Serial.print(sensor.readHumidity(), 2);
  Serial.print("\tTemperature: ");
  Serial.println(sensor.readTemperature(), 2);
  delay(1000);

  // Toggle heater enabled state every 30 seconds
  // An ~1.8 degC temperature increase can be noted when heater is enabled
  if (++loopCnt == 30) {
    enableHeater = !enableHeater;
    sensor.heater(enableHeater);
    Serial.print("Heater Enabled State: ");
    if (sensor.isHeaterEnabled())
      Serial.println("ENABLED");
    else
      Serial.println("DISABLED");
       
    loopCnt = 0;
  }*/
}
