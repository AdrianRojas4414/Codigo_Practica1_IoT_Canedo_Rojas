class Sensor {
private:
  unsigned char triggerPin;
  unsigned char echoPin;

public:
  Sensor(unsigned char triggerPin, unsigned char echoPin) {
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
  }

  float calculateDistance() {
    pinMode(triggerPin, OUTPUT);
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    return 0.01723 * pulseIn(echoPin, HIGH);
  }
};