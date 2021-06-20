# Irrigation-System
This repository is for the code needed to run a home garden irrigation system using an Arduino Uno, Soil Hygrometer (SH), and 12V water pump.

Functionality so far:
- The system takes an analogue reading from the SH, and maps it from 0-1023 -> 0-100% then prints the 'Moisture level' to Serial.
- 'Moisture level' readings are sequentially saved to a 10 value array, before looping back and overwriting the oldest reading.

Roadmap:
- Use previous 10 readings to determing whether or not to trigger the pump
- Pump testing

Version history:
0.1 - Take reading from SH, map it to a % value, print reading to Serial.
0.1.1 - the 10 previous moisture readings are saved to an array. The 11th reading overwrites the first, the 12th overwrites the 2nd etc. 
