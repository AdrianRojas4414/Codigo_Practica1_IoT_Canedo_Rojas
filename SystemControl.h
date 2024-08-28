#include "Led.h"
#include "Sensor.h"
class SystemControl {
private:
    Sensor sensor;
    Led leds[4];

public:
    SystemControl(unsigned char pinLed1, unsigned char pinLed2, 
                  unsigned char pinLed3, unsigned char pinLed4, 
                  unsigned char triggerPin, unsigned char echoPin)
      			    : sensor(triggerPin, echoPin), leds{(pinLed1),(pinLed2),
                                                    (pinLed3),(pinLed4)} {
    }

    void checkDistance() {
        float distance = sensor.calculateDistance();
        if (distance < 100) {
            leds[0].turnOn();
            (distance < 75) ? leds[1].turnOn(): leds[1].turnOff();
            (distance < 50) ? leds[2].turnOn() : leds[2].turnOff();
            (distance < 25) ? leds[3].turnOn() : leds[3].turnOff();
        }
        else
          blinkLeds();
    }

    void blinkLeds() {
      for (int i = 0; i < 4; ++i) {
        leds[i].startBlink(100);
        leds[i].updateBlink();
      }
    }
  
  	void printDistance() {
    	Serial.print(sensor.calculateDistance());
  		Serial.println("cm");
    }
};