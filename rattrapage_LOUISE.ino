// #include <ArduinoJson.h>
#include "WiFi.h"
// #include "Fetch.h"

const char* ssid = "Camifi"; 
const char* password = "camis123"; 

int freq;
int userAnswer;
int correctAnswer;

int ledPin = 26;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  pinMode(ledPin, OUTPUT);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");


  // Function to fetch data from an API (Sources: #4 and #5 (fetch and getexample))
  // RequestOptions options;
  // options.method = "GET";
    
  // Response correctAnswer = fetch("https://backend/api/answer", options);

  correctAnswer = random(0,4); //Random number as I don't have the API, if you did the resut would be the output Response correctAnswer
  userAnswer = random(0,4); //Source: REF#3 (random)

  //Source: REF#2 (comparison)
    if (userAnswer==correctAnswer) { 
      freq = 650;
      Serial.println("Correct answer");
  } else {
      freq = 200;
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

  Serial.println("User answer:");
  Serial.println(userAnswer);
  Serial.println("Correct answer:");
  Serial.println(correctAnswer);
}


void loop() {

}