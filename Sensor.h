class Sensor {
private:
  unsigned char triggerPin;
  unsigned char echoPin;

public:
  Sensor(unsigned char triggerPin, unsigned char echoPin) {
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
  }

  float calculateDistance() { // Reads the echo pin, and returns the sound wave travel time in microseconds
    pinMode(triggerPin, OUTPUT);  // Clear the trigger
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH); // Sets the trigger pin to HIGH state for 10 microseconds
    delayMicroseconds(10); // If the object is at a higher distance, increase the wait time
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    return 0.01723 * pulseIn(echoPin, HIGH);  // Measure the ping time in cm
  }
};