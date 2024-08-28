class Led {
  private:
    const unsigned char OFF = 0;
    const unsigned char ON = 1;

    unsigned char pin;
    unsigned int interval;
    unsigned long previousMillis;

    unsigned char state;
    unsigned char isBlinking;

  public:
    Led(unsigned char pin) {
      this->pin = pin;
      previousMillis = 0;
      pinMode(pin, OUTPUT);
      turnOff();
    }

    void turnOff() {
      state = OFF;
      isBlinking = 0;
	    digitalWrite(pin, state);
    }

    void turnOn() {
      state = ON;
      isBlinking = 0;
  	  digitalWrite(pin, state);
    }

    void startBlink(unsigned int interval) {
      this->interval = interval;
      isBlinking = 1;
	    state = OFF;
      digitalWrite(pin, state);
    }
  
    void updateBlink() {
    unsigned long currentMillis = millis();
    if (isBlinking && (currentMillis - previousMillis >= interval)) {
      previousMillis = currentMillis;
      state = !state;
      digitalWrite(pin, state);
    }
  }
};