int sensorPin = A0;
int reading;
int percentage;
int memory[10];
int memoryIndex = 0;
int squirtScore = 0;
int squirtThreshold = 5;
int percentageThreshold = 50;

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

  reading = analogRead(sensorPin);
  //'reading' is defined as the analogue (0-1023) value from the Sensor

  percentage = map(reading, 1023, 0, 0, 100);

  if(memoryIndex > 9)
  {
  Serial.println(memory[0]);
  Serial.println(memory[1]);
  Serial.println(memory[2]);
  Serial.println(memory[3]);
  Serial.println(memory[4]);
  Serial.println(memory[5]);
  Serial.println(memory[6]);
  Serial.println(memory[7]);
  Serial.println(memory[8]);
  Serial.println(memory[9]);
   //Print the memory array - Remove this for live version
  
  memoryIndex = 0;
  }
  //Loops 'memoryIndex' back to 0 to overwrite the oldest readings.

   memory[memoryIndex] = percentage;
  //The 'percentage' value is saved to the 'memoryIndex' position. This starts at 0.


  Serial.print("Memory position: "); Serial.println(1+memoryIndex); 

  Serial.print("Moisture level: "); Serial.print(percentage); Serial.println("%");
  //Print: "Moisture level: XX %" to the serial monitor. 

  Serial.println("-");

memoryIndex++;
  //+1 to the 'memoryIndex' value. This puts the next reading in the next memory position.

  
//Below uses the previous 10 readings to determine the squirt score.  
int squirtScore = 0;
int squirtThreshold = 5;
  
  if(memory[0] > percentageThreshold)
{
  {
 squirtScore++;
 }
  if(memory[1] > percentageThreshold)
{
 squirtScore++;
 }
  if(memory[2] > percentageThreshold)
{
 squirtScore++;
 }
  if(memory[3] > percentageThreshold)
{
 squirtScore++;
 }
  if(memory[4] > percentageThreshold)
{
 squirtScore++;
 }
  if(memory[5] > percentageThreshold)
{
 squirtScore++;
 }
  if(memory[6] > percentageThreshold)
{
 squirtScore++;
 }
  if(memory[7] > percentageThreshold)
{
 squirtScore++;
 }
  if(memory[8] > percentageThreshold)
{
 squirtScore++;
 }
  if(memory[9] > percentageThreshold)
{
 squirtScore++;
  }
} ;

 Serial.print("Squirt Score: "); Serial.print(squirtScore); 
  
  delay(5000);
  //Eventually, this should be increased to at least 5 minutes (300000)
  ;
}
