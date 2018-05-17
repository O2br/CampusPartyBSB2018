#define Photoresistor A0
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("OLa Mundo");
} 

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(".");
   int val=analogRead(Photoresistor);
   Serial.print("Luminisidade:");
   Serial.println(val);
}
