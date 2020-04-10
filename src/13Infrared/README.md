How to Set Up an IR Remote and Receiver on an Arduino

Posted by Krishna Pattabiraman | Arduino | 38
How to Set Up an IR Remote and Receiver on an Arduino

Infrared (IR) communication is a widely used and easy to implement wireless technology that has many useful applications. The most prominent examples in day to day life are TV/video remote controls, motion sensors, and infrared thermometers.
PCBWay Ad

There are plenty of interesting Arduino projects that use IR communication too. With a simple IR transmitter and receiver, you can make remote controlled robots, distance sensors, heart rate monitors, DSLR camera remote controls, TV remote controls, and lots more.

In this tutorial I’ll first explain what infrared is and how it works. Then I’ll show you how to set up an IR receiver and remote on an Arduino. I’ll also show you how to use virtually any IR remote (like the one for your TV) to control things connected to the Arduino.

Now let’s get into the details…
What is Infrared?

Infrared radiation is a form of light similar to the light we see all around us. The only difference between IR light and visible light is the frequency and wavelength. Infrared radiation lies outside the range of visible light, so humans can’t see it:

Arduino IR Tutorial - Electromagnetic Spectrum Diagram

Because IR is a type of light, IR communication requires a direct line of sight from the receiver to the transmitter. It can’t transmit through walls or other materials like WiFi or Bluetooth.
How IR Remotes and Receivers Work

A typical infrared communication system requires an IR transmitter and an IR receiver. The transmitter looks just like a standard LED, except it produces light in the IR spectrum instead of the visible spectrum. If you have a look at the front of a TV remote, you’ll see the IR transmitter LED:

Arduino IR Remote Tutorial - Transmitting LED on Remote

The same type of LED is used in IR transmitter breakout boards for the Arduino. You can see it at the front of this Keyes IR transmitter:

Arduino IR Remote Tutorial - IR Transmitter LED 2

The IR receiver is a photodiode and pre-amplifier that converts the IR light into an electrical signal. IR receiver diodes typically look like this:

Arduino IR Remote Tutorial - Two IR Receiver Diodes

Some may come on a breakout board like this:

Arduino IR Remote Tutorial - IR Receiver Breakout Board
IR Signal Modulation

IR light is emitted by the sun, light bulbs, and anything else that produces heat. That means there is a lot of IR light noise all around us. To prevent this noise from interfering with the IR signal, a signal modulation technique is used.

In IR signal modulation, an encoder on the IR remote converts a binary signal into a modulated electrical signal. This electrical signal is sent to the transmitting LED. The transmitting LED converts the modulated electrical signal into a modulated IR light signal. The IR receiver then demodulates the IR light signal and converts it back to binary before passing on the information to a microcontroller:

Arduino IR Remote Receiver Tutorial - IR Signal Modulation

The modulated IR signal is a series of IR light pulses switched on and off at a high frequency known as the carrier frequency. The carrier frequency used by most transmitters is 38 kHz, because it is rare in nature and thus can be distinguished from ambient noise. This way the IR receiver will know that the 38 kHz signal was sent from the transmitter and not picked up from the surrounding environment.

The receiver diode detects all frequencies of IR light, but it has a band-pass filter and only lets through IR at 38 kHz. It then amplifies the modulated signal with a pre-amplifier and converts it to a binary signal before sending it to a microcontroller.
IR Transmission Protocols

The pattern in which the modulated IR signal is converted to binary is defined by a transmission protocol. There are many IR transmission protocols. Sony, Matsushita, NEC, and RC5 are some of the more common protocols.

The NEC protocol is also the most common type in Arduino projects, so I’ll use it as an example to show you how the receiver converts the modulated IR signal to a binary one.

Logical ‘1’ starts with a 562.5 µs long HIGH pulse of 38 kHz IR followed by a 1,687.5 µs long LOW pulse. Logical ‘0’ is transmitted with a 562.5 µs long HIGH pulse followed by a 562.5 µs long LOW pulse:

Arduino IR Remote Receiver Tutorial - NEC Protocol

This is how the NEC protocol encodes and decodes the binary data into a modulated signal. Other protocols differ only in the duration of the individual HIGH and LOW pulses.
IR Codes

Each time you press a button on the remote control, a unique hexadecimal code is generated. This is the information that is modulated and sent over IR to the receiver. In order to decipher which key is pressed, the receiving microcontroller needs to know which code corresponds to each key on the remote.

Different remotes send different codes for the keypresses, so you’ll need to determine the code generated for each key on your particular remote. If you can find the datasheet, the IR key codes should be listed. If not though, there is a simple Arduino sketch that will read most of the popular remote controls and print the hexadecimal codes to the serial monitor when you press a key. I’ll show you how to set that up in a minute, but first we need to connect the receiver to the Arduino…
How to Connect an IR Receiver to the Arduino

There are several different types of IR receivers, some are stand-alone, and some are mounted on a breakout board. Check the datasheet for your particular IR receiver since the pins might be arranged differently than the HX1838 IR receiver and remote set I am using here. However, all IR receivers will have three pins: signal, ground, and Vcc.

Lets get started with the hardware connections. The pin layout on most breakout boards looks like this:

IR Receiver Breakout Board Pinout Diagram

The pinout of most stand-alone diodes is like this:

IR Receiver Stand-Alone Pinout Diagram

To connect a breakout board mounted IR receiver, hook it up to the Arduino like this:

Arduino IR Remote Receiver - Breakout Board Wiring Diagram

To connect a stand-alone receiver diode, wire it like this:

Arduino IR Remote Receiver - Stand-Alone IR Receiver Wiring Diagram
Programming the IR Receiver

Once you have the receiver connected, we can install the Arduino library and start programming. In the examples below, I’ll show you how to find the codes sent by your remote, how to find the IR protocol used by your remote, how to print key presses to the serial monitor or an LCD, and finally, how to control the Arduino’s output pins with a remote.
Install the IRremote Library

We’ll be using the IRremote library for all of the code examples below. You can download a ZIP file of the library from here.

To install the library from the ZIP file, open up the Arduino IDE, then go to Sketch > Include Library > Add .ZIP Library, then select the IRremote ZIP file that you downloaded from the link above.
Find the Codes for Your Remote

To find the key codes for your remote control, upload this code to your Arduino and open the serial monitor:

Now press each key on your remote and record the hexadecimal code printed for each key press.

Arduino IR Remote Receiver - Finding Remote HEX Codes

Using the program above, I derived a table of keys and their corresponding codes from the remote that came with my HX1838 IR receiver and remote set. Note that you will receive a 0XFFFFFFFF code when you press a key continuously.
 Key	 Code
 CH-	 0xFFA25D
 CH	 0xFF629D
 CH+	 0xFFE21D
 <<	 0xFF22DD
 >>	 0xFF02FD
 >||	 0xFFC23D
 –	 0xFFE01F
 +	 0xFFA857
 EQ	 0xFF906F
 100+	 0xFF9867
 200+	 0xFFB04F
 0	 0XFF6897
 1	 0xFF30CF
 2	 0xFF18E7
 3	 0xFF7A85
 4	 0xFF10EF
 5	 0xFF38C7
 6	 0xFF5AA5
 7	 0xFF42BD
 8	 0xFF4AB5
 9	 0xFF52AD
Find the Protocol Used by Your Remote

Knowing which protocol your remote uses can be useful if you want to work on some more advanced projects. Or you might just be curious. The program below will identify the protocol used by your remote. It even works on most remote controls around your house.

Print Keys to the Serial Monitor

I extended the code above to print the key value instead of the hexadecimal code:

If your remote sends different codes than the ones in the table above, just replace the hex code in each line where it says:

case 0xFFA25D:
Serial.println(“CH-“);

In these lines, when the hex code 0xFFA25D is received, the Arduino prints “CH-“.
How the Code Works

For any IR communication using the IRremote library, first we need to create an object called irrecv and specify the pin number where the IR receiver is connected (line 3). This object will take care of the protocol and processing of the information from the receiver.

The next step is to create an object called results , from the decode_results class, which will be used by the irrecv object to share the decoded information with our application (line 5).

In the void setup() block, first we configure the serial monitor baud rate. Next we start the IR receiver by calling the IRrecv member function enableIRIn() (line 10).

The irrecv.blink13(true) function on line 11 will blink the Arduino’s on board LED every time the receiver gets a signal from the remote control, which is useful for debugging.

In the void loop() block, the function irrecv.decode will return true if a code is received and the program will execute the code in the if statement. The received code is stored in results.value. Then I used a switch to handle each IR code and print the corresponding key value.

Before the switch block starts there is a conditional block:

if (results.value == 0XFFFFFFFF)
results.value = key_value;

If we receive 0XFFFFFFFF from the remote, it means a repetition of the previous key. So in order to handle the repeat key pattern, I am storing the hex code in a global variable key_value every time a code is received:

key_value = results.value;

When you receive a repeat pattern, then the previously stored value is used as the current key press.

At the end of the void loop() section, we call irrecv.resume() to reset the receiver and prepare it to receive the next code.