
#include "WiFi.h"

//Configuração para o Wifi
const char* ssid = "REDE 3 2.4G"; //SSID da rede
const char* password =  "ponto1244"; // Senha da Rede

// Define o numero dos pinos do ultrassonico
const int trigPin = 2;
const int echoPin = 5;

// Define as variáveis
long duration;
int distance;

void setup() {
  
  pinMode(trigPin, OUTPUT); // Difine o trigPin como Output
  pinMode(echoPin, INPUT); // Define o echoPin como Input
  
  Serial.begin(9600); // Inicia o Monitor Serial


  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando...");
  }
 
  Serial.println("Conectado a rede wifi");
}

void loop() {
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delay(1000);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}
