/*
 Name:		multitaskSeries_1_usingMicros.ino
 Created:	12/29/2015 3:59:13 PM
 Author:	gonzaleze
*/
uint8_t eLED = 13;
uint32_t tON = 250;
uint32_t tOFF = 500;

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(eLED, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	digitalWrite(eLED, HIGH);
	delay(tON);
	digitalWrite(eLED, LOW);
	delay(tOFF);
}
