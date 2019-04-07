#include <WiFi.h>
#include "Gsender_32.h"
#include <WiFiClientSecure.h>

#pragma region Globals
const char* ssid = "REDE 3 2.4G";                           // WIFI network name
const char* password = "ponto1244";                       // WIFI network password
uint8_t connection_state = 0;                    // Connected to WIFI or not
uint16_t reconnect_interval = 10000;             // If not connected wait time to try again
#pragma endregion Globals

String address[] = {"brunohiroyukioda@hotmail.com", "herobrine813@gmail.com"};

uint8_t WiFiConnect(const char* nSSID = nullptr, const char* nPassword = nullptr)
{
  static uint16_t attempt = 0;
  Serial.print("Conectando a rede ");
  if (nSSID) {
    WiFi.begin(nSSID, nPassword);
    Serial.println(nSSID);
  } else {
    WiFi.begin(ssid, password);
    Serial.println(ssid);
  }

  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED && i++ < 50)
  {
    delay(200);
    Serial.print(".");
  }
  ++attempt;
  Serial.println("");
  if (i == 51) {
    Serial.print("Conexão: TIMEOUT na tentativa: ");
    Serial.println(attempt);
    if (attempt % 2 == 0)
      Serial.println("Verifique se a rede está dispoível ou se o SSD e Senha estão corretos\r\n");
    return false;
  }
  Serial.println("Conexão: ESTABELECIDA");
  Serial.print("Endereço de IP: ");
  Serial.println(WiFi.localIP());
  return true;
}

void Awaits()
{
  uint32_t ts = millis();
  while (!connection_state)
  {
    delay(200);
    if (millis() > (ts + reconnect_interval) && !connection_state) {
      connection_state = WiFiConnect();
      ts = millis();
    }
  }
}

//Ultrassônico:

// Define o numero dos pinos do ultrassonico
const int trigPin = 22;
const int echoPin = 23;

// Define as variáveis
long duration;
int distance;

//--------------------------------------------//s


void setup()
{
  Serial.begin(9600);
  connection_state = WiFiConnect();
  if (!connection_state) // if not connected to WIFI
  {
    Awaits(); // constantly trying to connect
  }

  //Ultrassônico
  pinMode(trigPin, OUTPUT); // Difine o trigPin como Output
  pinMode(echoPin, INPUT); // Define o echoPin como Input
  

}

void loop() {

  //Ultrassônico:
	// Clears the trigPin
  digitalWrite(trigPin, LOW);
  delay(2000);
  
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

  if (distance < 15){
    
    Serial.print("ARMÁRIO ABERTO ");
    Gsender *gsender = Gsender::Instance();    // Getting pointer to class instance
    String subject = "Seu armário foi aberto.";
    if (gsender->Subject(subject)->Send(2, address, "A porta do seu armário foi aberta"))
    {
      Serial.println("Mensagem enviada.");
    }
    else
    {
      Serial.print("Erro ao enviar a mensagem: ");
      Serial.println(gsender->getError());
    }  
  }
	
	while (distance < 15){
  
    Serial.println ("TO TRAVADO");

    //NOVA LEITURA PARA DESTRAVAR

    //Ultrassônico:
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delay(2000);
  
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
	
	
	
	
	
}
