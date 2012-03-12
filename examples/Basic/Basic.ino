#include <LM35Thermometer.h>

#define pinoSensor 0 //Pino analógico em que estará conectado o sensor LM35
#define TEMPO_ESPERA 1000 //Intervalo entre cada leitura do sensor LM35 em milisegundos! OBS: 1000ms = 1s

Thermometer therm;

void setup() { 
  Serial.begin(9600); //Iniciando Serial
}

void loop() {
  Serial.println(therm.read(pinoSensor));
  delay(TEMPO_ESPERA);// Espera um tempo determinado em TEMPO_LEITURA (milisegundos)
}
