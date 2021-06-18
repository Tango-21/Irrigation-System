int sensorPin = A0;
int reading;
int percentage;

void setup() {

  Serial.begin(9600);
  //Establishes communications with the computer. Bitrate of 9600

  pinMode(13, OUTPUT);
  //The LED will light up when the sketch is running.

  digitalWrite(13, HIGH);

  Serial.print("Reading from the sensor...");

  delay(1500)
  ;
}

void loop() {

  reading = analogRead(sensorPin);
  //'reading' is defined as the analogue (0-1023) value from the Sensor

  percentage = map(reading, 1023, 0, 0, 100);
  
  Serial.println("Moisture level:"); Serial.println(percentage); Serial.println("%");
  //Print "Moisture level: XX %" to the serial monitor.

  delay(5000);

  ;
}
