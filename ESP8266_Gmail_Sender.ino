#include <ESP8266WiFi.h>
#include "Gsender.h"
#include <Ultrasonic.h>
#include <NTPClient.h>
#include <Time.h>
#include <TimeLib.h>
#include <Timezone.h>
#include <WifiUDP.h>
#include <String.h>

//Definições do NTP
#define NTP_OFFSET   60 * 60      // In seconds
#define NTP_INTERVAL 60 * 1000    // In miliseconds
#define NTP_ADDRESS  "br.pool.ntp.org"  // change this to whatever pool is closest (see ntp.org)

//Configuração do cliente NTP UDP
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);

Ultrasonic ultrasonic(D7, D8);
#pragma region Globals
const char* ssid = "UFABC";                 // Nome da Rede Wi-Fi
const char* password = "85265";              // Senha da Rede Wifi
uint8_t connection_state = 0;                    // Conectado ou não a rede
uint16_t reconnect_interval = 10000;             // Timeout para reconectar
#pragma endregion Globals


//Configuração para o relógio
String date;
String t;
int h;
const char * days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"} ;
const char * months[] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"} ;
const char * ampm[] = {"AM", "PM"} ;





uint8_t WiFiConnect(const char* nSSID = nullptr, const char* nPassword = nullptr)
{
    static uint16_t attempt = 0;
    Serial.print("Conectando a rede ");
    if(nSSID) {
        WiFi.begin(nSSID, nPassword);  
        Serial.println(nSSID);
    } else {
        WiFi.begin(ssid, password);
        Serial.println(ssid);
    }

    uint8_t i = 0;
    while(WiFi.status()!= WL_CONNECTED && i++ < 50)
    {
        delay(200);
        Serial.print(".");
    }
    ++attempt;
    Serial.println("");
    if(i == 51) {
        Serial.print("Conexão: TIMEOUT na tentativa: ");
        Serial.println(attempt);
        if(attempt % 2 == 0)
            Serial.println("Verifique se a rede está disponível ou se o SSID e senha estão corretos\r\n");
        return false;
    }
    Serial.println("Conexão: ESTABELECIDA");
    Serial.print("Endereço de IP: ");
    Serial.println(WiFi.localIP());
    Serial.println("---------------------");
    return true;
}

void Awaits()
{
    uint32_t ts = millis();
    while(!connection_state)
    {
        delay(50);
        if(millis() > (ts + reconnect_interval) && !connection_state){
            connection_state = WiFiConnect();
            ts = millis();
        }
    }
}

void setup()
{
    Serial.begin(9600);
    connection_state = WiFiConnect();
    if(!connection_state)  // Se não estiver conectado
        Awaits();          // Loop infinito para tentar reconetar

    
}

void loop(){

  //Definição dos limites dos sensores
  int LDR,Dist;
  LDR = 80;         //Limite de Luminosidade
  Dist = 15;        //Limite de Distância


  //Leitura dos sensores
  //Ultrassonico
  float cmMsec;


  
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  //-----------------------------------------------------------//
  
  //Exibição no Monitor Serial
  //Ultrassonico
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  //-----------------------------------------------------------//

  //Relógio
  date = "";  // clear the variables
  t = "";
    
  // update the NTP client and get the UNIX UTC timestamp 
  timeClient.update();
  unsigned long epochTime =  timeClient.getEpochTime();

  // convert received time stamp to time_t object
  time_t local, utc;
  utc = epochTime;

  // Then convert the UTC UNIX timestamp to local time
  TimeChangeRule usEDT = {"EDT", Second, Sun, Mar, 2, -300};  //UTC - 5 hours - change this as needed
  TimeChangeRule usEST = {"EST", First, Sun, Nov, 2, -360};   //UTC - 6 hours - change this as needed
  Timezone usEastern(usEDT, usEST);
  local = usEastern.toLocal(utc);

  // now format the Time variables into strings with proper names for month, day etc
  date += days[weekday(local)-1];
  date += ", ";
  date += months[month(local)-1];
  date += " ";
  date += day(local);
  date += ", ";
  date += year(local);

  // format the time to 12-hour format with AM/PM and no seconds
  h = hour(local);
      h=(h+1);
      if (h==24)
      h=00;
     t+=h;
    t += ":";
  if(minute(local) < 10)  // add a zero if minute is under 10
    t += "0";
  t += minute(local);

  // Display the date and time
  Serial.println("");
  Serial.print("Data: ");
  Serial.print(date);
  Serial.println("");
  Serial.print("Hora: ");
  Serial.print(t);
  Serial.println();

  //-----------------------------------------------------------//
  //LDR
  int sensorValue;
  
 if (h<6 || h>18){
  
  sensorValue=610;
  Serial.print ("CONDIÇÃO 1");
  Serial.println();
  Serial.print("HORA h:");
  Serial.print(h);
 }  else{
  
  sensorValue = analogRead(A0);
  Serial.print ("CONDIÇÃO 2");
  Serial.println();
  Serial.print("HORA h:");
  Serial.print(h);
 }
    
  Serial.println();
  Serial.print("LDR: ");
  Serial.print(sensorValue);
  Serial.println();

  Serial.println();
  Serial.println("---------------------");
  Serial.println();

  //-----------------------------------------------------------//

  //Trigger
  //       LDR               Ultrasonico
  if ((sensorValue > LDR ) && (cmMsec > Dist )) {

    Serial.println("ARMARIO ABERTO");
    Serial.println("ENVIANDO ALERTA");

    
    Gsender *gsender = Gsender::Instance();    
    String subject = "Seu Armário foi aberto";
    if(gsender->Subject(subject)->Send("brunohiroyukioda@hotmail.com", "A porta do seu armário foi aberta às "+ t +" horas")) {
        Serial.println("Mensagem Enviada.");
        Serial.println("---------------------------");
    } else {
        Serial.print("Erro ao enviar o email: ");
        Serial.println(gsender->getError());
    }
    
  }

    while  ((sensorValue > LDR ) && (cmMsec > Dist)){
      Serial.println ("TO TRAVADO");

      //Novas Leituras
      //Ultrassonico
     
      microsec = ultrasonic.timing();
      cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
    
      //LDR
      sensorValue = analogRead(A0);

      //DEBUG DOS SENSORES TRAVOS
      //Ultrassonico
      Serial.print("Distancia em cm: ");
      Serial.print(cmMsec);

      //LDR
      Serial.println();
      Serial.print("LDR: ");
      Serial.print(sensorValue);
      Serial.println();
      Serial.println("---------------------");
      Serial.println();

      delay (2000);
    }
  
  delay(2000);
  
  
  }

