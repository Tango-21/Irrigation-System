# Irrigation-System
This repository is for code needed to run a home garden irrigation system using an Arduino Uno, Soil Hygrometer (SH), and 12V water pump.

So far the system takes an analogue reading from the SH, and maps it from 0-1023 -> 0-100% then prints the 'Moisture level' to Serial.

Version history:
0.1.1 - the 10 previous moisture readings are saved to an array. The 11th reading overwrites the first, the 12th overwrites the 2nd etc. 
