#include <PubSubClient.h>
#include <ESP8266WiFi.h>

const char* ssid = "arduinoday"; // rede wifi
const char* password = "abcdefghijklm"; // senha da rede wifi

char* topic = "/arduinoday/esp8266";
//char* server = "climaserver.webhop.me";
char* server = "arduinoday.o2br.net";
char* hellotopic = "hello_topic";

#define REPORT_INTERVAL 5 // in sec
uint8_t mac[6];
String clientName;
WiFiClient wifiClient;

void callback(char* topic, byte* payload, unsigned int length);

PubSubClient client(server, 1883, callback, wifiClient);


void setup() {
  Serial.begin(115200);
  Serial.println("Setup test!");
  delay(20);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  clientName += "esp8266-";
  WiFi.macAddress(mac);
  clientName += macToStr(mac);
  clientName += "-";
  clientName += String(micros() & 0xff, 16);

  Serial.print("Connecting to ");
  Serial.print(server);
  Serial.print(" as ");
  Serial.println(clientName);

  if (client.connect((char*) clientName.c_str())) {
      Serial.println("Connected to MQTT broker");
      Serial.print("Topic is: ");
      Serial.println(topic);
      if (client.publish(hellotopic, "hello from ESP8266")) {
        Serial.println("Publish ok");
      } else {
        Serial.println("Publish failed");
      }
      
  } else {
      Serial.println("MQTT connect failed");
      Serial.println("Will reset and try again...");
      abort();
  }

}

void loop() {

  String  payload = "{\"macAddress\":\"";
          payload += macToStr(mac);
          payload += "\"}";

    sendTemperature(payload);

  int cnt = REPORT_INTERVAL;
  while (cnt--)
    delay(1000);
 
}


void sendTemperature(String payload) {
  if (!client.connected()) {
    if (client.connect((char*) clientName.c_str())) {
      Serial.println("Connected to MQTT broker again");
      Serial.print("Topic is: ");
      Serial.println(topic);
    }
    else {
      Serial.println("MQTT connect failed");
      Serial.println("Will reset and try again...");
      abort();
    }
  }  
  if (client.connected()) {
    Serial.print("Sending payload: ");
    Serial.println(payload);
    if (client.publish(topic, (char*) payload.c_str())) {
      Serial.println("Publish ok");
    }
    else {
      Serial.println("Publish failed");
    }  
  }
}


void callback(char* topic, byte* payload, unsigned int length) {
// handle message arrived
}

String macToStr(const uint8_t* mac) {
  String result;
  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);
     if (i < 5)
      result += ':';
  }
  return result;
}
