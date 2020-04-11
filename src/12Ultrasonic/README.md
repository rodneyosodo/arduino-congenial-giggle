How HC-SR04 Ultrasonic Sensor Works & Interface It With Arduino
Tutorial Interfacing HC-SR04 Ultrasonic Sensor with Arduino Uno

Give your next Arduino project bat-powers with a HC-SR04 Ultrasonic Distance Sensor that can report the range of objects up to 13 feet away. Which is really good information to have if you’re trying to avoid your robot driving into a wall! They are low power (suitable for battery powered devices), inexpensive, easy to interface with and are insanely popular among hobbyists. And as a bonus it even looks cool, like a pair of Wall-E Robot eyes for your latest robotic invention!
What is Ultrasound?

Ultrasound is high-pitched sound waves with frequencies higher than the audible limit of human hearing.
Ultrasonic Frequency Range Spectrum

Human ears can hear sound waves that vibrate in the range from about 20 times a second (a deep rumbling noise) to about 20,000 times a second (a high-pitched whistling). However, ultrasound has a frequency of over 20,000 Hz and is therefore inaudible to humans.
HC-SR04 Hardware Overview

At its core, the HC-SR04 Ultrasonic distance sensor consists of two ultrasonic transducers. The one acts as a transmitter which converts electrical signal into 40 KHz ultrasonic sound pulses. The receiver listens for the transmitted pulses. If it receives them it produces an output pulse whose width can be used to determine the distance the pulse travelled. As simple as pie!

The sensor is small, easy to use in any robotics project and offers excellent non-contact range detection between 2 cm to 400 cm (that’s about an inch to 13 feet) with an accuracy of 3mm. Since it operates on 5 volts, it can be hooked directly to an Arduino or any other 5V logic microcontrollers.

Here are complete specifications:
Operating Voltage	DC 5V
Operating Current	15mA
Operating Frequency	40KHz
Max Range	4m
Min Range	2cm
Ranging Accuracy	3mm
Measuring Angle	15 degree
Trigger Input Signal	10µS TTL pulse
Dimension	45 x 20 x 15mm
HC-SR04 Ultrasonic Sensor Pinout

Let’s take a look at its Pinout.
HC-SR04 Ultrasonic Distance Sensor Pinout

VCC is the power supply for HC-SR04 Ultrasonic distance sensor which we connect the 5V pin on the Arduino.

Trig (Trigger) pin is used to trigger the ultrasonic sound pulses.

Echo pin produces a pulse when the reflected signal is received. The length of the pulse is proportional to the time it took for the transmitted signal to be detected.

GND should be connected to the ground of Arduino.
How Does HC-SR04 Ultrasonic Distance Sensor Work?

It all starts, when a pulse of at least 10 µS (10 microseconds) in duration is applied to the Trigger pin. In response to that the sensor transmits a sonic burst of eight pulses at 40 KHz. This 8-pulse pattern makes the “ultrasonic signature” from the device unique, allowing the receiver to differentiate the transmitted pattern from the ambient ultrasonic noise.

The eight ultrasonic pulses travel through the air away from the transmitter. Meanwhile the Echo pin goes HIGH to start forming the beginning of the echo-back signal.

In case, If those pulses are not reflected back then the Echo signal will timeout after 38 mS (38 milliseconds) and return low. Thus a 38 mS pulse indicates no obstruction within the range of the sensor.
HC-SR04 Ultrasonic Sensor Working - Echo when no Obstacle

If those pulses are reflected back the Echo pin goes low as soon as the signal is received. This produces a pulse whose width varies between 150 µS to 25 mS, depending upon the time it took for the signal to be received.
HC-SR04 Ultrasonic Sensor Working - Echo reflected from Obstacle

The width of the received pulse is then used to calculate the distance to the reflected object. This can be worked out using simple distance-speed-time equation, we learned in High school. In case you forgot, an easy way to remember the distance, speed and time equations is to put the letters into a triangle.
Distance Speed Time Formula Triangle

Let’s take an example to make it more clear. Suppose we have an object in front of the sensor at an unknown distance and we received a pulse of width 500 µS on the Echo pin. Now let’s calculate how far the object from the sensor is. We will use the below equation.

Distance = Speed x Time

Here, we have the value of Time i.e. 500 µs and we know the speed. What speed do we have? The speed of sound, of course! Its 340 m/s. We have to convert the speed of sound into cm/µs in order to calculate the distance. A quick Google search for “speed of sound in centimeters per microsecond” will say that it is 0.034 cm/µs. You could do the math, but searching it is easier. Anyway, with that information, we can calculate the distance!

Distance = 0.034 cm/µs x 500 µs

But this is not done! Remember that the pulse indicates the time it took for the signal to be sent out and reflected back so to get the distance so, you’ll need to divide your result in half.

Distance = (0.034 cm/µs x 500 µs) / 2

Distance = 8.5 cm

So, now we know that the object is 8.5 centimeters away from the sensor.
Wiring – Connecting HC-SR04 to Arduino Uno

Now that we have a complete understanding of how HC-SR04 ultrasonic distance sensor works, we can begin hooking it up to our Arduino!

Connecting the HC-SR04 to the Arduino is pretty easy. Start by placing the sensor on to your breadboard. Connect VCC pin to the 5V pin on the Arduino and connect GND pin to the Ground pin on the Arduino.

When you’re done you should have something that looks similar to the illustration shown below.
Arduino Wiring Fritzing Normal Mode Connections with HC-SR04 Ultrasonic Sensor
Wiring HC-SR04 Ultrasonic Sensor to Arduino UNO – Normal Mode

So now that we’ve hooked up our ultrasonic distance sensor it’s time to write some code and test it out.
Arduino Code – Using NewPing Library

Instead of triggering the ultrasonic sensor and measuring the received signal pulse width manually, we will use a special library. There are quite a few of them available, the most versatile is one called “NewPing”.

Download the library first, by visiting the Bitbucket repo or, just click this button to download the zip:
NewPing_v1.9.0.zip

To install it, open the Arduino IDE, go to Sketch > Include Library > Add .ZIP Library, and then select the NewPing ZIP file that you just downloaded. If you need more details on installing a library, visit this Installing an Arduino Library tutorial.

The NewPing library is quite advanced and it considerably improves upon the accuracy of our original sketch. It also supports up to 15 ultrasonic sensors at once and it can directly output in centimetres, inches or time duration.

Here is our sketch rewritten to use the NewPing library:

// This uses Serial Monitor to display Range Finder distance readings

// Include NewPing Library
#include "NewPing.h"

// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN 9
#define ECHO_PIN 10

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400	

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance;

void setup() 
{
	Serial.begin(9600);
}

void loop() 
{
	// Send ping, get distance in cm
	distance = sonar.ping_cm();
	
	// Send results to Serial Monitor
	Serial.print("Distance = ");
	
	if (distance >= 400 || distance <= 2) 
	{
		Serial.println("Out of range");
	}
	else 
	{
		Serial.print(distance);
		Serial.println(" cm");
	}
	delay(500);
}

HC-SR04 Ultrasonic Sensor Arduino Distance Measurement Sketch Output on Serial Monitor
Output on Serial Monitor
Code Explanation:

The above sketch is simple and works well but it only has a resolution down to one centimeter. If you want to bring back the decimal point values you can use NewPing in duration mode instead of in distance mode. You need to replace this line

// Send ping, get distance in cm
distance = sonar.ping_cm();

with below lines

duration = sonar.ping();
distance = (duration / 2) * 0.0343;

To improve the accuracy of your HC-SR04 to the next level, there’s another function in NewPing library called “iterations”. To iterate means to go over something more than once, and that’s precisely what the iteration mode does. It takes many duration measurements instead of just one, throws away any invalid readings and then averages the remaining ones. By default it takes 5 readings but you can actually specify as many as you wish.

int iterations = 5;
duration = sonar.ping_median(iterations);

Arduino Project
Contactless Distance Finder

Let’s create a quick project to demonstrate how a simple ultrasonic sensor can be turned into a Sophisticated Contactless Distance Finder. In this project we will use a 16×2 Character LCD to display a horizontal bar to graphically represent distance to the object with the value on the bottom line.

In case you are not familiar with 16×2 character LCDs, consider reading (at least skimming) below tutorial.
Tutorial Interfacing 16x2 character LCD with Arduino Uno
Interfacing 16×2 Character LCD Module with Arduino
Want your Arduino projects to display status messages or sensor readings? Then these LCD displays might be the perfect fit. They are extremely common and...

Next, we need to make connections to the LCD as shown below.
Arduino Wiring Fritzing Connections with HC-SR04 Ultrasonic Sensor and 16x2 LCD
Wiring HC-SR04 Ultrasonic Sensor and 16×2 LCD to Arduino UNO

Before we get to uploading code and playing with the sensor, we need to install the library called LCDBarGraph. This library helps draw horizontal bargraph on the LCD, where the length of the bar is proportional to the values provided.

Download the library first, by visiting the Arduino Playground or, just click this button to download the zip:
LcdBarGraph-1.5.zip

Once you install the library, try the below sketch out.

// includes the LiquidCrystal Library
#include <LiquidCrystal.h> 

// includes the LcdBarGraph Library
#include <LcdBarGraph.h>

// Maximum distance we want to ping for (in centimeters).
#define max_distance 200

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

LcdBarGraph lbg(&lcd, 16, 0, 1); // Creates an LCD Bargraph object.

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup() 
{
	lcd.begin(16,2); // Initializes the interface to the LCD screen
	
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

void loop() 
{
	// Write a pulse to the HC-SR04 Trigger Pin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	
	// Measure the response from the HC-SR04 Echo Pin
	duration = pulseIn(echoPin, HIGH);
	
	// Determine distance from duration
	// Use 343 metres per second as speed of sound
	distance= duration*0.034/2;
	
	// Prints "Distance: <value>" on the first line of the LCD
	lcd.setCursor(0,0);
	lcd.print("Distance: "); 
	lcd.print(distance);
	lcd.print(" cm");

	// Draws bargraph on the second line of the LCD
	lcd.setCursor(0,1);
	lbg.drawValue(distance, max_distance);
	delay(500);
}

This is how the output looks like.
HC-SR04 Ultrasonic Sensor Arduino Distance Measurement Bargraph Output on 16x2 LCD
Bargraph Output on 16×2 Character LCD
Code Explanation:

First you need to set up the LiquidCrystal library as usual. After this you can create LcdBarGraph instance with the just created LiquidCrystal instance. You should pass the reference of the LiquidCrystal to the constructor of the LcdBarGraph.

The constructor of the LcdBarGraph takes three more parameters. Second one is Number of character columns in the LCD (In our case that’s 16). The last two parameters are optional and allow custom positioning of the bar.

// creating bargraph instance
LcdBarGraph lbg(&lcd, 16, 0, 1);

Now once we calculate the distance from the sensor, we can use drawValue(value, maxValue) function to display the bargraph. This draws a bargraph with a value between 0 and maxValue.

//display bargraph
lbg.drawValue(distance, max_distance);

Interfacing HC-SR04 with 3-Wire Mode

3-Wire Mode is something you only require one connection to a single Arduino digital I/O pin instead of two. If you don’t know, there are many ultrasonic sensors out there that only operate in 3-Wire Mode like awesome parallax ping))) sensor.

In 3-Wire mode the single I/O pin is used as both an input and as an output. This is possible because there is never a time when both the input and output are being used. By eliminating one I/O pin requirement we can save a connection to our Arduino and use it for something else. It also is useful when using a chip like the ATtiny85 which has a limited number of I/O pins.

Here’s how you can hook the HC-SR04 sensor up to the Arduino using 3-Wire mode.
Arduino Wiring Fritzing 3 Wire Mode Connections with HC-SR04 Ultrasonic Sensor
Wiring HC-SR04 Ultrasonic Sensor to Arduino UNO – 3 Wire Mode

As you can see all you need to do is, connect both the trigger and echo to Arduino pin 9.Note that the only difference you need to do in the sketch is to define pin 9 for both the Trigger and Echo pin values. The rest of the sketch is identical.

#define TRIGGER_PIN 9 // Trigger and Echo both on pin 9
#define ECHO_PIN 9

What are the limitations?

In terms of accuracy and overall usefulness, HC-SR04 ultrasonic distance sensor is really great, especially compared to other low-cost distance detection sensors. That doesn’t mean that the HC-SR04 sensor is capable of measuring “everything”. Following diagrams shows a few situations that the HC-SR04 is not designed to measure:

a) The distance between the sensor and the object/obstacle is more than 13 feet.
HC-SR04 Limitation - cannot measure distance more than 13 feet

b) The object has its reflective surface at a shallow angle so that sound will not be reflected back towards the sensor.
HC-SR04 Limitation - cannot detect object at a shallow angle

c) The object is too small to reflect enough sound back to the sensor. In addition, if your HC-SR04 sensor is mounted low on your device, you may detect sound reflecting off of the floor.
HC-SR04 Limitation - cannot detect small objects

d) While experimenting with the sensor, we discovered that some objects with soft, irregular surfaces (such as stuffed animals) absorb rather than reflect sound and therefore can be difficult for the HC-SR04 sensor to detect.
HC-SR04 Limitation - cannot detect soft irregular surface object
Effect of Temperature on Distance Measurement

Though the HC-SR04 is reasonably accurate for most of our projects such as intruder detection or proximity alarms; But there are times you might want to design a device that is to be used outdoors or in an unusually hot or cold environment. If this is the case, you might want to take into account the fact that the speed of sound in air varies with temperature, air pressure and humidity.

Since the speed of sound factors into our HC-SR04 distance calculation this could affect our readings. If the temperature (°C) and Humidity is already known, consider the below formula:

Speed of sound m/s = 331.4 + (0.606 * Temp) + (0.0124 * Humidity)