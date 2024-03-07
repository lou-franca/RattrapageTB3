#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define ledPin 26
 
const char* ssid = "Lou"; // Please change to the name of you Wifi network
const char* password = "0804loulou"; // as well as its password

int freq;

void setup() {

  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  WiFi.begin(ssid, password);

  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");


  // Function to get data from an API (Sources: #4 and #5 (arduinojson and githttp))
  WiFiClient client; 
  HTTPClient http;

  http.useHTTP10(true);
  http.begin(client, "http://jsonplaceholder.typicode.com/todos/1"); //Source: #7 (apiplaceholder)
  http.GET();


  // Processing the Json document (Source: #6 (jsonassistant))

  StaticJsonDocument<128> doc;

  DeserializationError error = deserializeJson(doc, http.getStream());

 /* Debug from ChatGPT and JSON Troubleshooter (Source: #8 (jsondebug)) 
 I was getting the error code -2 and InvalidInput. 
 This helped me realize that I was using an https API, and for that I needed to use WifiClientSecure.
 My solution was to change the placeholder API to http.

  // Debug HTTP status code
  int statusCode = http.GET();
  Serial.print("HTTP status code: ");
  Serial.println(statusCode);

  // Debug http.getStream()
  Serial.println("Response from server:");
  while (http.getStream().available()) {
    char c = http.getStream().read();
    Serial.print(c);
  }

  // Debug deserializeJson()
  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }
  */

  int correctAnswer = doc["userId"];
  int id = doc["id"]; 
  const char* question = doc["title"]; 
  int userAnswer = random(0,4); //Source: REF#3 (random)

  //Source: REF#2 (comparison)
    if (userAnswer==correctAnswer) { 
      freq = 1200;
      Serial.println("Correct answer");
  } else {
      freq = 300;
      Serial.println("Wrong answer");
  }

  //Source: REF#1 (delay)
  digitalWrite(ledPin, HIGH); 
  delay(freq);               
  digitalWrite(ledPin, LOW);  
  delay(freq);
  digitalWrite(ledPin, HIGH); 
  delay(freq);               
  digitalWrite(ledPin, LOW);  
  delay(freq);    

  Serial.println("Question ID " + String(id) + ": " + String(question));
  Serial.println("User answer: " + String(userAnswer));
  Serial.println("Correct answer: " + String(correctAnswer));

  http.end();
}


void loop() {

}