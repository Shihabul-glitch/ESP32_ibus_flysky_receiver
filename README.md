# ESP32_ibus_flysky_receiver
connect the ibus pin of flysky receiver to GPIO 5.
change the max_channel_num if necessary. Currently 6 channel is used.
dual core is working perfectly.
supply GND and 5V to any working pin of the receiver.
this code is writen in arduino IDE for esp core 3.x

# Note
The ibus signal decoding code is not written by me. I have just implemented it to ESP32 with HardwareSerial and ensured Dual Core performence.

I have actually forget the main code owner. He was a good man from youtube.


# Flysky ibus:
The signal from oscilloscope shows that:
The ibus of flysky gives data each 7 milliseconds. Meaning the data rate is 150 hz. ibus is much more faster than the ppm signal which gives data at only 50 hz in case of flysky.
The ibus signal has an data period of 4 millisecond and idle period of 3 milliseconds. In idle period the signal stays high. 
