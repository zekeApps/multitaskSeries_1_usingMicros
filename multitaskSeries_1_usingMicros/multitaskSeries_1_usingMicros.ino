/*
 Name:		multitaskSeries_1_usingMicros.ino
 Created:	12/29/2015 3:59:13 PM
 Author:	gonzaleze
*/
uint8_t eLED = 13;
uint8_t LEDstate = LOW;
uint32_t prevMillis = 0;
uint32_t tON = 10;
uint32_t tOFF = 300;

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(eLED, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	unsigned long currMillis = millis();

	if ((LEDstate) && (currMillis - prevMillis >= tON)) {
		LEDstate = LOW;
		prevMillis = currMillis;
		digitalWrite(eLED, LEDstate);
	}
	else if ((LEDstate == LOW) && (currMillis - prevMillis >= tOFF)) {
		LEDstate = HIGH;
		prevMillis = currMillis;
		digitalWrite(eLED, LEDstate);
	}
}
