#include <CapacitiveSensor.h>
CapacitiveSensor csense = CapacitiveSensor(12, 13);
void setup() {
  Serial.begin(115200);
  Serial.println("Setup");
} 

void loop() {
  Serial.println(csense.capacitiveSensor(10));
}
//Referencias
//http://forum.arduino.cc/index.php?topic=462160.0
//https://github.com/PaulStoffregen/CapacitiveSensor/issues/6
//https://maker.pro/projects/arduino/touch-controlled-light-using-arduino
//http://www.instructables.com/id/How-To-Use-Touch-Sensors-With-Arduino/
