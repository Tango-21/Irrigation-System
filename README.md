# Irrigation-System
This repository is for the code needed to run a home garden irrigation system called Squirter. The system uses an Arduino Uno, Soil Hygrometer (SH), and 12V water pump.

Functionality so far:
- The system takes an analogue reading from the SH, and maps it from 0-1023 -> 0-100% then prints the 'Moisture Rating' to Serial.
- 'Moisture Ratings' are sequentially saved to a 10 value array, before looping back and overwriting the oldest reading.
- Squirt Scores - Use previous 10 readings to determine whether or not to Squirt (trigger the pump/light up led)

Roadmap:

- Pump testing, using led
- emergency squirt

Version history:
- 0.1 - Take reading from SH, map it to a % value, print reading to Serial.
- 0.1.1 - the 10 previous moisture readings are saved to an array. The 11th reading overwrites the first, the 12th overwrites the 2nd etc. 
- 0.1.2 - Easily configurable settings. Displays the last 10 readings evrery 10 readings. Introduction of Squirt Scores to determine when to Squirt.


Calibration Notes:
Moisture level      Qualitative Notes

65 - 70%            Moist, but not wet. Surface soil not yet dried.
47 - 50%            Surface soil is dry. Slightly damp when youre knuckle deep.
