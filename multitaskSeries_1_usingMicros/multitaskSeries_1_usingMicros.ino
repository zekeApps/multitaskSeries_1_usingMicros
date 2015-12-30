/*
 Name:		multitaskSeries_1_usingMicros.ino
 Created:	12/29/2015 3:59:13 PM
 Author:	gonzaleze
*/


class Blinker {
	// Class Member Variables
	// Thses are initialized a startup
	uint8_t eLED = 13;
	uint32_t tON = 10;
	uint32_t tOFF = 300;
		// These maintin the current State
	uint8_t LEDstate = LOW;
	uint32_t prevMillis = 0;
	public:
	Blinker(uint8_t pin) {
		eLED = pin;
		pinMode(eLED, OUTPUT);
		

		LEDstate = LOW;
		prevMillis = 0;
	}

	void blink(uint32_t on, uint32_t off) {
		tON = on;
		tOFF = off;
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
};

Blinker led1(13);
Blinker led2(12);

// the setup function runs once when you press reset or power the board
void setup() {
}

// the loop function runs over and over again until power down or reset
void loop() {
	led1.blink(10, 400);
	led2.blink(500, 500);
}
