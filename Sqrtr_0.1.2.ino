int sensorPin = A0;
int moistureReading;
int moistureRating;
  // The reading from the Moisture Detector expressed as a percentage.
int memory[10];
int memoryIndex = 0;
int squirtScore = 0;
  //The Squirt Score is determined by how many of the last 10 Moisture Ratings has a +1 to Squirt Score.


//CONFIG SETTINGS
int squirtThreshold = 5;
  //The number of cycles out of the last 10 to activate a Squirt.
int moistureThreshold = 40;
  //The value below which a Moisture Reading causes a +1 to Squirt Score.
int cycleTime = 7500 ;
  //Time in miliseconds.
  //The delay between begining cycles. This can be used to control the total length of time between readings & thus minimum time between Squirts.
int squirtTime = 5000 ;
  //Time in miliseconds.
  //The length of a Squirt.

void setup() {

  Serial.begin(9600);
  //Establishes communications with the computer. Bitrate of 9600

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  //The LED will light up when the sketch is running.
  
  Serial.println("Reading from the sensor...");

  delay(1500)
  ;
}


void loop() {

//SENSOR READING & STORAGE
  moistureReading = analogRead(sensorPin);
  //'reading' is defined as the analogue (0-1023) value from the Sensor
  moistureRating = map(moistureReading, 1023, 0, 0, 100);
  
  memory[memoryIndex] = moistureRating;
  //The 'moistureRating' value is saved to the 'memoryIndex' position. This starts at 0.


//SQUIRT SCORING
  if(memory[0] > moistureThreshold)
  {
 squirtScore++;
 }
  if(memory[1] > moistureThreshold)
{
 squirtScore++;
 }
  if(memory[2] > moistureThreshold)
{
 squirtScore++;
 }
  if(memory[3] > moistureThreshold)
{
 squirtScore++;
 }
  if(memory[4] > moistureThreshold)
{
 squirtScore++;
 }
  if(memory[5] > moistureThreshold)
{
 squirtScore++;
 }
  if(memory[6] > moistureThreshold)
{
 squirtScore++;
 }
  if(memory[7] > moistureThreshold)
{
 squirtScore++;
 }
  if(memory[8] > moistureThreshold)
{
 squirtScore++;
 }
  if(memory[9] > moistureThreshold)
{
 squirtScore++;
  } ;

//OUTPUTS - Serial Monitor
 
 Serial.println("============");
 Serial.print("Memory position: "); Serial.println(1+memoryIndex); 
    //Probably hide this later.
 Serial.print("Moisture Rating: "); Serial.print(moistureRating); Serial.println("%");
  //Print: "Moisture level: XX %" to the serial monitor. 
 Serial.print("Squirt Score: "); Serial.print(squirtScore); Serial.print("/ 10 (Threshold: "); Serial.print(squirtThreshold); Serial.println(")");
 Serial.println("");

if (memoryIndex == 9) {   
  Serial.println("The last 10 Moisture Ratings:");
  Serial.print(memory[0]); Serial.println("%");
  Serial.print(memory[1]); Serial.println("%");
  Serial.print(memory[2]); Serial.println("%");
  Serial.print(memory[3]); Serial.println("%");
  Serial.print(memory[4]); Serial.println("%");
  Serial.print(memory[5]); Serial.println("%");
  Serial.print(memory[6]); Serial.println("%");
  Serial.print(memory[7]); Serial.println("%");
  Serial.print(memory[8]); Serial.println("%");
  Serial.print(memory[9]); Serial.println("%");
}


//OUTPUTS - Squirt mode
//Code to follow. LED initially, pump eventually
//if(squirtScore >= scquirtThreshold) {
//digitalWrite(PIN, HIGH);
//delay(squirtTime);
//digitalWrite(PIN, LOW);
//  }


//CYCLE & RESET memoryIndex
 memoryIndex++;
  //+1 to the 'memoryIndex' value. This puts the next reading in the next memory position.

 if(memoryIndex > 9)
  {  
  memoryIndex = 0;
  }
  //Resets 'memoryIndex' back to 0 to overwrite the oldest readings.

squirtScore = 0;
  //Resets Squrt Score before the next cycle
 
 delay(cycleTime);
  //Eventually, this should be increased to at least 5 minutes (300000)
  ;
}
