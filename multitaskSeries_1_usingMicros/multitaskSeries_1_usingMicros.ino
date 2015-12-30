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
	uint32_t targetTime = 0;
	uint8_t targetReached = 0;
		// These maintin the current State
	uint8_t LEDstate = LOW;
	uint32_t prevMillis = 0;

	private:
	uint8_t timeElapsed(uint32_t target) {
		targetTime = target;

		unsigned long currMillis = millis();
		if (currMillis - prevMillis >= targetTime) {
			prevMillis = currMillis;
			targetReached = 1;
		}
		else {
			targetReached = 0;
		}
		return targetReached;
	}

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
		
		if ((LEDstate) && timeElapsed(tON)) {
			LEDstate = LOW;
			digitalWrite(eLED, LEDstate);
		}
		else if ((LEDstate == LOW) && timeElapsed(tOFF)) {
			LEDstate = HIGH;
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
	led2.blink(300, 50);
	
}
