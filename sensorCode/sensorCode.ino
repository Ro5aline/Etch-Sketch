//A0 ACC A1 POT
// x knob
#define SENSORPINA A0 
// y knob
#define SENSORPINB A1 
//Reset Button
const int buttonPin = 3;
//time
unsigned long targetTime=0;
const unsigned long interval=250;
//push button
int buttonState = 0;
// serial connection with a baudrate of 115200
void setup(){
	Serial.begin(115200);	
	pinMode(SENSORPINA, INPUT)
	pinMode(SENSORPINB, INPUT)
//attachInterrupt(buttonPin,ButtonPressed,RISING)
	
}
void loop(){
//interupt reset
	buttonState = digitalRead(buttonPin);
	if(buttonState == HIGH)
//rest
		
	else
//Etching
	if(millis()>=targetTime){
		targetTime= millis()+interval;
		//convert values into a string
		String x = String(analogRead(SENSORPINA));
		String y = String(analogRead(SENSORPINB));
		//combine into a string
		String cord = x + "," + y + ",";
		//Send the string over serial
	}
// Reset
void ButtonPressed
}
