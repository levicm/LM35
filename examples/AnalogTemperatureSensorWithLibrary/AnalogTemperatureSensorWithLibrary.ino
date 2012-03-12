#include <LM35Thermometer.h>

#define SAMPLES 500 //Número de amostras de temperaturas
#define sensortemp 0 //Pino analógico em que estará conectado o sensor LM35
#define TEMPO_LEITURA 1000 //Intervalo entre cada leitura do sensor LM35 em milisegundos! OBS: 1000ms = 1s

Thermometer therm(SAMPLES);

void setup() { 
  Serial.begin(9600); //Iniciando Serial
  therm.setHighRes(true);
}

void loop() {
  Serial.println(therm.read(sensortemp));
  delay(TEMPO_LEITURA);// Espera um tempo determinado em TEMPO_LEITURA (milisegundos)
}