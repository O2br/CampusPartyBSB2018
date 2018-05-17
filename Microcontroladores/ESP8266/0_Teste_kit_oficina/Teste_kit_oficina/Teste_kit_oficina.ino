//int ledPin = 13; // GPIO13
#define Photoresistor A0
 int R = 16; 
 int G = 5;
 int B = 2;
 int ledPin = 14; // GPIO13

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println("Setup");
    delay(10); 
    pinMode(R, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(ledPin, OUTPUT);
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    digitalWrite(ledPin, LOW);
    
} 


void loop() {
    int val=analogRead(Photoresistor);
    Serial.print("Luminisidade:");
    Serial.println(val);
    digitalWrite(ledPin, HIGH);
    delay(1000); 
    digitalWrite(ledPin, LOW);
    delay(1000); 
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    delay(1000);
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
    delay(1000);
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
    delay(1000);
}
