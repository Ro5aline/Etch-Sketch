// x knob
#define SENSORPINA A0 
// y knob
#define SENSORPINB A1 
//Reset Button
const int buttonPin = 3;
//time
unsigned long targetTime=0;
const unsigned long interval=250;
//
void setup(){
// serial connection with a baudrate of 115200
  pinMode(SENSORPINA, INPUT);
  pinMode(SENSORPINB, INPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(115200); 
}
void loop(){
  if(millis()>=targetTime)
  {
    if (digitalRead(buttonPin) == 1)
    {
        Serial.println("rst");
      }
    targetTime= millis()+interval;
    //convert values into a string
    String x = String(analogRead(SENSORPINA));
    String y = String(analogRead(SENSORPINB));
    //combine into a string
    String cord = x + "," + y + ",";
    //Send the string over serial
    Serial.println(cord);
    delay(10);
  }
}
