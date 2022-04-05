#include <SPI.h>
//#include "WiFly.h" //include the WiFly experimental library
//#include "Credentials.h"

#include <Bridge.h>
#include <HttpClient.h>

//HttpClient client("api.football-data.org", 80);
HttpClient client("api.football-data.org", 80);

void setup(){

  /*Serial.begin(9600);
  Serial.println("Serial Begun :D");
  //WiFly.begin();

  if (!WiFly.join(ssid, passphrase)) {
    Serial.println("Association failed.");
    while (1) {
      // Hang on failure.*/
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  SerialUSB.begin(9600);

  while (!SerialUSB); // wait for a serial connection
    Serial.print("connecting to server...");
  if(client.connect()){
    Serial.println("connected");
    client.print("GET http://api.football-data.org/v2/competitions/PL/matches/?matchday=22&X-Auth-Token=676c4fd4072848a98d9be8baedf10382");
    Serial.print("GET http://api.football-data.org/v2/competitions/PL/matches/?matchday=22&X-Auth-Token=676c4fd4072848a98d9be8baedf10382");
    client.println(" HTTP/1.1");
    Serial.println(" HTTP/1.1");
    client.println("Host: api.football-data.org");
    Serial.println("Host: api.football-data.org");
    client.println("X-Auth-Token: 676c4fd4072848a98d9be8baedf10382");
    Serial.println("X-Auth-Token: 676c4fd4072848a98d9be8baedf10382");  
    client.println("Connection: close");
    Serial.println("Connection: close");
    client.println();
  } else{
    Serial.println("connection failed");
  }
       
    }
void loop()  { 

  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    for(;;)
      ;
  }

  
 /* HttpClient client;
  //client.get("api.football-data.org", 80);
  String payload="";
  //client.get("api.football-data.org");
  //client.get("http://api.football-data.org/v2/competitions/PL/matches/?matchday=22?X-Auth-Token=676c4fd4072848a98d9be8baedf10382");
  client.get("https://api.football-data.org/v2/competitions/CL/matches/?matchday=22?X-Auth-Token=676c4fd4072848a98d9be8baedf10382");
  //client.get("http://api.football-data.org/v2/competitions/PL/matches/?matchday=22&X-Auth-Token=676c4fd4072848a98d9be8baedf10382");
  Serial.print("connecting to server...");
  if(client.available()){
    Serial.println("connected");

    client.print("GET http://api.football-data.org/v2/competitions/PL/matches/?matchday=22&X-Auth-Token=676c4fd4072848a98d9be8baedf10382");
    /*Serial.print("GET http://api.football-data.org/v2/competitions/PL/matches/?matchday=22&X-Auth-Token=676c4fd4072848a98d9be8baedf10382");
    client.println(" HTTP/1.1");
    Serial.println(" HTTP/1.1");
    client.println("Host: api.football-data.org");
    Serial.println("Host: api.football-data.org");
    client.println("X-Auth-Token: '676c4fd4072848a98d9be8baedf10382'");
    Serial.println("X-Auth-Token: '676c4fd4072848a98d9be8baedf10382'"); 
    c = client.read();
    Serial.println(c); 
    
    client.println("Connection: close");
    Serial.println("Connection: close");
    client.println();
    char c = client.read();
    payload += c;
    Serial.println(c);
  } else{
    Serial.println("connection failed");
  }
  Serial.println(payload);*/
}
