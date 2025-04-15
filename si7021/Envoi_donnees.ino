// données envoyées au format JSON (pour MQTT) sur le port série

void EnvoiDonnees() {// fonction qui envoie les valeurs de l'éclairement et du temps  {"E_Lux":E_Lux,"temps":leTemps})
  
  // mesure du temps en secondes
  unsigned long CurrentTime = millis(); //(long > 32 bits, int > 16 bits, byte > 8bits ,float > 32 bits)
  float leTemps = CurrentTime/1000;

  float humidite = sensor.readHumidity();
  float temperature = sensor.readTemperature();  
// Serial.print("Humidity:    ");
//  Serial.print(sensor.readHumidity(), 2);
//  Serial.print("\tTemperature: ");
//  Serial.println(sensor.readTemperature(), 2);
 // delay(1000);

  // Toggle heater enabled state every 30 seconds
  // An ~1.8 degC temperature increase can be noted when heater is enabled
/*  if (++loopCnt == 30) {
    enableHeater = !enableHeater;
    sensor.heater(enableHeater);
    Serial.print("Heater Enabled State: ");
    if (sensor.isHeaterEnabled())
      Serial.println("ENABLED");
    else
      Serial.println("DISABLED");
       
    loopCnt = 0;
  } */

  // envoi des données au format JSON
  String chaine = "{\"Humidite\":";   // il faut toujours initialiser la chaine avant de concaténer à la ligne suivante
  Serial.println(chaine + humidite +",\"Temperature\":"+temperature+ ",\"temps\":"+leTemps+"}");
  
}
