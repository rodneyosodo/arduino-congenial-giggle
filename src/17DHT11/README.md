Interface DHT11 Module With Arduino
Tutorial for Interfacing DHT11 Module with Arduino

Give your next Arduino project the ability to sense the world around it with the inexpensive DHT11 digital temperature & humidity sensor module from AOSONG.

This sensor is pre-calibrated and don’t require extra components so you can start measuring relative humidity and temperature right away.
How DHT11 Measures Temperature and Humidity
The DHT11 measures relative humidity. Relative humidity is the amount of water vapor in air vs. the saturation point of water vapor in air. At the saturation point, water vapor starts to condense and accumulate on surfaces forming dew.

he DHT11 detects water vapor by measuring the electrical resistance between two electrodes. The humidity sensing component is a moisture holding substrate with electrodes applied to the surface. When water vapor is absorbed by the substrate, ions are released by the substrate which increases the conductivity between the electrodes. The change in resistance between the two electrodes is proportional to the relative humidity. Higher relative humidity decreases the resistance between the electrodes, while lower relative humidity increases the resistance between the electrodes.

The DHT11 measures temperature with a surface mounted NTC temperature sensor (thermistor) built into the unit. To learn more about how thermistors work and how to use them on the Arduino, check out our Arduino Thermistor Temperature Sensor Tutorial.

Inside the DHT11, there is a humidity sensing component along with a Thermistor.
inside dht11 sensor front

Humidity sensing component has two electrodes with moisture holding substrate sandwiched between them.

The ions are released by the substrate as water vapor is absorbed by it, which in turn increases the conductivity between the electrodes.

The change in resistance between the two electrodes is proportional to the relative humidity. Higher relative humidity decreases the resistance between the electrodes, while lower relative humidity increases the resistance between the electrodes.
Internal Structure of Humidity Sensor in DHT11 DHT22

DHt11 also contains a NTC/Thermistor to measure temperature. A thermistor is a thermal resistor whose resistance changes drastically with temperature. The term “NTC” means “Negative Temperature Coefficient”, which means that the resistance decreases with increase of the temperature.
NTC Thermistor Temperature Resistance Characteristic Curve

On the other side, there is a small PCB with an 8-bit SOIC-14 packaged IC. This IC measures and processes the analog signal with stored calibration coefficients, does analog to digital conversion and spits out a digital signal with the temperature and humidity.
inside dht11 sensor back
DHT11 Module Hardware Overview

At the heart of the module is the digital temperature & humidity sensor manufactured by AOSONG – DHT11.
DHT11 Sensor

DHT11 can measure temperature from 0°C to 50°C with ±2.0°C accuracy, and humidity from 20 to 80% with 5% accuracy.
dht11 module hardware overview front

Note that the sampling rate of the DHT11 is 1Hz, meaning you can get new data from it once every second.
Supporting Circuitry

The module comes with all the essential supporting circuitry, so it should be ready to run without any extra components.
dht11 module hardware overview back

The DHT11 sensors usually require external pull-up resistor of 10KΩ between VCC and Out pin for proper communication between sensor and the Arduino. However, the module has a built-in pull-up resistor, so you need not add it.

The module also has a decoupling capacitor for filtering noise on the power supply.
DHT11 Module Pinout

The DHT11 module is fairly easy to connect. It has only three pins:
dht11 module pinout

+ (VCC) pin supplies power for the sensor. 5V supply is recommended, although the supply voltage ranges from 3.3V to 5.5V. In case of 5V power supply, you can keep the sensor as long as 20 meters. However, with 3.3V supply voltage, cable length shall not be greater than 1 meter. Otherwise, the line voltage drop will lead to errors in measurement.

Out pin is used to communication between the sensor and the Arduino.

– (GND) should be connected to the ground of Arduino.
Wiring DHT11 Module to Arduino

Let’s hook the DHT11 module up to the Arduino.

Connections are fairly simple. Start by connecting + (VCC) pin to the 5V output on the Arduino and connect – (GND) to ground. Finally, connect the Out pin to the digital pin #8.

The following diagram shows you how to wire everything.
wiring dht11 module with arduino
Installing DHT library

DHT11 sensors have their own single wire protocol for transferring the data. This protocol requires precise timing. Fortunately, DHT Library was written to hide away all the complexities so that we can issue simple commands to read the temperature and humidity data.

Open your Arduino IDE and go to Sketch > Include Library > Manage Libraries. The Library Manager should open.

Search for “DHT” on the Search box and install the DHT library from Adafruit.
After installing the DHT library from Adafruit, type “Adafruit Unified Sensor” in the search box. Scroll all the way down to find the library and install it.

Download the library first, by visiting the GitHub repo or, just click this button to download the zip:
DHTlib.zip

To install it, open the Arduino IDE, go to Sketch > Include Library > Add .ZIP Library, and then select the DHTlib ZIP file that you just downloaded.
Arduino Code – Basic Example

Once you have the library installed, you can copy this sketch into the Arduino IDE.

The following test sketch will print the temperature and relative humidity values on the serial monitor. Try the sketch out; and then we will explain it in some detail.

#include <dht.h>	// Include library
#define outPin 8	// Defines pin number to which the sensor is connected

dht DHT;			// Creates a DHT object

void setup() {
	Serial.begin(9600);
}

void loop() {
	int readData = DHT.read11(outPin);

	float t = DHT.temperature;	// Read temperature
	float h = DHT.humidity;		// Read humidity

	Serial.print("Temperature = ");
	Serial.print(t);
	Serial.print("°C | ");
	Serial.print((t*9.0)/5.0+32.0);	// Convert celsius to fahrenheit
	Serial.println("°F ");
	Serial.print("Humidity = ");
	Serial.print(h);
	Serial.println("% ");
	Serial.println("");

	delay(2000); // wait two seconds
}

Once the sketch is uploaded, open a Serial Monitor window to see the output from the Arduino.
dht11 module output
Code Exaplanation:

The sketch starts by including DHT library and defining the Arduino pin number to which our sensor’s Out pin is connected. Then we create a DHT object to access special functions related to the library.

#include <dht.h>
#define outPin 8
dht DHT;

In the ‘setup’ function; we initiate the serial communication as we will use the serial monitor to print the results.

void setup() {
  Serial.begin(9600);
}

In the ‘loop’ function; we will use the read11() function which reads the data from the sensor. It takes sensor’s Data pin number as a parameter.

int readData = DHT.read11(outPin);

Once the humidity and temperature values are calculated, we can access them by:

float t = DHT.temperature;	// Read temperature
float h = DHT.humidity;		// Read humidity

The DHT object returns temperature value in Celsius (°C). It can be converted in to Fahrenheit (°F) using a simple formula:

T(°F) = T(°C) × 9/5 + 32

Serial.print((t * 9.0) / 5.0 + 32.0);

Arduino Code – Displaying Results on LCD