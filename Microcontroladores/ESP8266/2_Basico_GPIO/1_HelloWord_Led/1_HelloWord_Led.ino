int ledPin = 14; // GPIO13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Setup");
  delay(10); 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
} 


void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(".");
    digitalWrite(ledPin, HIGH);
    delay(1000); 
    digitalWrite(ledPin, LOW);
    delay(1000); 
}
