#include <Bridge.h>
#include <BridgeHttpClient.h>
  BridgeHttpClient client;
  
#include <ArduinoJson.h>

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin(); // Initialize Bridge
  digitalWrite(13, HIGH);

  SerialUSB.begin(9600);
  while (!SerialUSB); // wait for the serial connection
 
  //BridgeHttpClient client;

  // Add request headers
  // REPLACE THE XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX WITH YOUR AIO KEY!!!
  /*client.addHeader("X-Auth-Token: 676c4fd4072848a98d9be8baedf10382");
  client.addHeader("Accept: application/json");

  // Using HTTPS and peer cert. will not be able to auth.
  client.enableInsecure();

  // Adafruit IO REST API call
  client.get("http://api.football-data.org/v2/competitions/PL/matches/?matchday=30");
  //client.get("https://api.football-data.org/v2/competitions/CL/matches");
  // Collect the response body into this string for parsing
  String response;

  while (client.available() > 0) {
    char c = client.read();
    response += c;
  }
  SerialUSB.println(response);
  
  // Parse the list of feeds and print the name and ids, limited to 4 feeds
  const int JSON_BUFFER = JSON_ARRAY_SIZE(4) + 4*JSON_OBJECT_SIZE(14);
  StaticJsonBuffer<JSON_BUFFER> jsonBuffer;

  JsonArray& array = jsonBuffer.parseArray(response);
  if (!array.success()) {
    SerialUSB.println("parseArray() failed");
    while (1) {}
  }

  // List the feed names and Ids
  SerialUSB.println("Your Adafruit IO Feed Name/Id listing:");
  for (JsonArray::iterator it=array.begin(); it!=array.end(); ++it) {
    JsonObject& feed = it->as<JsonObject&>();
    feed["name"].printTo(SerialUSB);
    SerialUSB.print("/");
    feed["id"].printTo(SerialUSB);
    SerialUSB.println();
   
   }*/
}

void loop() {
  // Do nothing
   // Adafruit IO REST API call
  client.addHeader("X-Auth-Token: 676c4fd4072848a98d9be8baedf10382");
  client.addHeader("Accept: application/json");  
  client.enableInsecure();
  //client.get("http://api.football-data.org/v2/competitions/PL/matches/?matchday=30");
    client.get("http://api.football-data.org/v2/matches?status='IN_PLAY'");
  //client.get("https://api.football-data.org/v2/competitions/CL/matches");
  // Collect the response body into this string for parsing
  String response2;

  while (client.available() > 0) {
    char c = client.read();
    response2 += c;
    

    }
        SerialUSB.println(response2);


        
    delay(10000);
}
