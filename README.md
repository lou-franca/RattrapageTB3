# Rattrapage TB3
As I couldn't get acess to the API developed for the Web Rattrapage in time, this code uses the JSON placeholder API from source #7, as it serves mostly all necessary purposes, albeit more simple, as it doesn't have any stored arrays that could act as the multiple choice options, so this aspect had to be ignored. The format is the following:
```
{
  "userId": 1,
  "id": 1,
  "title": "delectus aut autem",
  "completed": false
}
```
I considered _userId_ as the correct answer to the question, _id_ the question ID and _title_ the question itself. The answer given by the students is modeled as a random number between 0 and 3.

# Sources
1 (delay) - [https://www.arduino.cc/reference/en/language/functions/time/delay/](https://www.arduino.cc/reference/en/language/functions/time/delay/)  
2 (comparison) - [https://www.arduino.cc/reference/en/language/structure/comparison-operators/equalto/](https://www.arduino.cc/reference/en/language/structure/comparison-operators/equalto/) 
3 (random) - [https://www.arduino.cc/reference/en/language/functions/random-numbers/random/](https://www.arduino.cc/reference/en/language/functions/random-numbers/random/)  
4 (arduinojson) - [https://arduinojson.org/v6/how-to/use-arduinojson-with-httpclient/](https://arduinojson.org/v6/how-to/use-arduinojson-with-httpclient/)  
5 (githttp) - [https://github.com/amcewen/HttpClient](https://github.com/amcewen/HttpClient)  
6 (jsonassistant) - [https://arduinojson.org/v6/assistant/#/step1](https://arduinojson.org/v6/assistant/#/step1)  
7 (apiplaceholder) - [https://jsonplaceholder.typicode.com/guide/](https://jsonplaceholder.typicode.com/guide/)  
8 (debugjson) - [https://arduinojson.org/troubleshooter/](https://arduinojson.org/troubleshooter/)  

# Important

- To run the code on the ESP32 we were given, it was necessary to install the URL https://dl.espressif.com/dl/package_esp32_index.json in Additional boards manager URLs.
- The library used to extract the data from the API needs to be manually installed and imported in the Arduino IDE. You can find the installation tutorial in source #5.
