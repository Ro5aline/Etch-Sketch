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
	attachInterrupt
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
		Serial.println(analogRead(SENSORPINA));
		Serial.println(analogRead(SENSORPINB));
		//convert values into a string
		Xaxis = String()
		//combine into a string
		String data = x	
		//TODO: send the string over serial


	}
// Reset
if ()
}
