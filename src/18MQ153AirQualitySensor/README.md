4. MQ-135 Gas sensor
The MQ-135 gas sensor senses the gases like ammonia nitrogen, oxygen, alcohols, aromatic compounds, sulfide and smoke. The operating voltage of this gas sensor is from 2.5V to 5.0V. MQ-135 gas sensor can be implementation to detect the smoke, benzene, steam and other harmful gases.

Working Principle And Circuit Diagram
The MQ-135 alcohol sensor consists of a tin dioxide (SnO2), a perspective layer inside Aluminium Oxide micro tubes (measuring electrodes) and a heating element inside a tubular casing. The end face of the sensor is enclosed by a stainless steel net and the back side holds the connection terminals. Ethyl alcohol present in the breath is oxidized into acetic acid passing through the heat element. With the ethyl alcohol cascade on the tin dioxide sensing layer, the resistance decreases. By using the external load resistance the resistance variation is converted into a suitable voltage variation.

It has lower conductivity compare to clean air and due to air pollution the conductivity is increases. The air quality sensor detects ammonia, nitrogen oxide, smoke, CO2 and other harmful gases. The air quality sensor has a small potentiometer that permits the adjustment of the load resistance of the sensor circuit.

The air quality sensor is a signal output indicator instruction. It has two outputs: analog output and TTL output. The TTL output is low signal light which can be accessed through the IO ports on the microcontroller. The analog output is an concentration, i.e. increasing voltage is directly proportional to increasing concentration. The resistance of the sensor decreases as the concentration of the target gas is increased in PPM while for clean air its resistance remains constant.

The VCC and Ground terminals of the sensor are connected to the common VCC and Ground. The Analog Output pin of the sensor is connected to the A0 pin of the Arduino. The analog output voltage from the sensor can be assumed directly proportional to the concentration of CO2 gas in PPM under standard conditions. The analog voltage is sensed from the sensor and converted to a digital value in range from 0 to 1023 by the inbuilt ADC channel of the controller. The digitized value is hence equal to the gas concentration in PPM.


Interfacing of MQ135 Gas Sensor with Arduino : In today’s world, we encounter different scenario where we see different gasses being emitted in atmosphere such as home appliances like air conditioner and industrial chimneys. Monitoring of these gasses is very important with safety point of view. Gas Sensors are very helpful in accomplishing this task. Small nose like sensor spontaneously respond to the alteration of gas concentration and keep our systems updated for special tasks.MQ135 gas sensor interfacing with Arduino Uno

In this tutorial we will learn how to interface MQ-135 Gas Sensor with Arduino Board? We will explore what is Gas Sensor? How it works? What is its pin configuration and how to interface it with Arduino? Our today’s tutorial consists of following sections:

    What is MQ-135 and how does it work?
    Pin Configuration.
    Required Components.
    Wiring Connections.
    Testing the Circuit.
    Code for Arduino.

What is MQ-135 gas sensor and how does it work?

The gas sensor module consists of a steel exoskeleton under which a sensing element is housed. This sensing element is subjected to current through connecting leads. This current is known as heating current through it, the gases coming close to the sensing element get ionized and are absorbed by the sensing element. This changes the resistance of the sensing element which alters the value of the current going out of it.
Pin Configuration MQ-135 gas sensor

From left to right first pins are as follows:

A0        Analog output

D0        Digital output

GND     Ground

Vcc      Supply (5V)
Specifications of MQ-135 gas sensor

    Wide detecting scope
    Fast response and High sensitivity
    Stable and long life Simple drive circuit
    Used in air quality control equipment for buildings/offices, is suitable for detecting
    of NH3, NOx, alcohol, Benzene, smoke, CO2, etc.
    Size: 35mm x 22mm x 23mm (length x width x height)
    Working voltage: DC 5 V
    Signal output instruction.
    Dual signal output (analog output, and high/low digital output)
    0 ~ 4.2V analog output voltage, the higher the concentration the higher the voltage.

Required Components:

Following Components are required for this project:

    Arduino UNO
    Breadboard
    MQ-2 Gas sensor module

interfacing of MQ-135 gas sensor with Arduino

Wire the circuit as follows:

Arunio A0 pin              with                 Sensor A0

Aruino D0 pin              with                 Sensor D0

Arduino 5Vpin             with                 Sensor Vcc

Arduino GND pin         with                 Sensor GNDInterfacing of MQ-135 Gas Sensor with Arduino

When no gas digital output is 1 and analog output gives 1023 max value. When gas is present digital output is 0 and analogue output is much less than 1023. Using potentiometer on chip we can control the turning OFF point of digital pin at some value of analog pin. The sensor needs a load-resistor at the output to ground. Its value could be from 2kOhm to 47kOhm. The lower the value, the less sensitive is the sensor. The higher the value, the less accurate is sensor for higher concentrations of gas. If only one specific gas is measured, the load-resistor can be calibrated by applying a known concentration of that gas. If the sensor is used to measure any gas (like in a air quality detector) the load-resistor could be set for a value of about 1V output with clean air. Choosing a good value for the load-resistor is only valid after the burn-in time

NOTE: Don’t touch the sensor, it will be very hot.

Testing the Circuit:

    After hardware connection, insert the sample sketch into the Arduino IDE.
    Using a USB cable, connect the ports from the Arduino to the computer.
    Upload the program.
    See the results in the serial monitor.

Code for interfacing of MQ-135 gas sensor with Arduino

int sensorValue;
int digitalValue;
void setup()
{

Serial.begin(9600); // sets the serial port to 9600
pinMode(13, OUTPUT);
pinMode( 3, INPUT);

}


void loop()

{

sensorValue = analogRead(0); // read analog input pin 0

digitalValue = digitalRead(2); 
if(sensorValue>400)
{
digitalWrite(13, HIGH);
}
else
digitalWrite(13, LOW);
Serial.println(sensorValue, DEC); // prints the value read
Serial.println(digitalValue, DEC);

delay(1000); // wait 100ms for next reading

}

Result:

On serial monitor you can see values of analog pin being detected. Currently in my case they are around about 150 which indicate normal air.

    Normal air returns approximately 100-150
    Alcohol returns approximately 700
    Lighter gas returns approximately 750


Measuring Units

The three basic units of measure used in reporting air pollution data are micrograms per cubic meter, parts per million (PPM), and the micron (JL). Micro grams per cubic meter and parts per million are measures of concentration. Both microgram per meter cube and ppm are used to indicate the concentration of a gaseous pollutant. There is an advantage to the unit ppm that frequently makes it the unit of choice.PPM is a volume-to-volume ratio.

Note:- PPM in Air, is a volume-to-volume ratio.

PPM in water and wastewater, is a mass-to-mass ratio.

Changes in temperature and pressure do not change the ratio of the volume of pollutant gas to the volume of air that contains it.

1.What is PPM

Parts per million (PPM) is a unit of measurement used for expressing a very dilute concentration level of pollutants in the air, water and other fluids or one item in a million of anything of the same size.

Converting air pollutant concentration

1. Converting Micro grams per cubic meter to PPM

ppmv = mg/m^3 x (0.08205 x T) / M 

2. Converting PPM to Micro grams per cubic meter

mg/m^3 = ppmv x M /(0.08205 x T)

Where,

    mg/m^3 = Microgram of pollutant per cubic meter of air
    ppmv = Air pollutant concentration, in parts per million by volume
    T = Ambient temperature in kelvin
    0.08205 = Universal gas constant
    M = Molecular weight of air pollutant

2. What is PM level
Particulate matter (PM) in the atmospheric air or in any other gas cannot be expressed in terms of ppmv, volume percent or mole percent. PM is most expressed as mg/m^3 of air or other gas at a specified temperature and pressure.

Note:- One volume percent = 10, 000 ppmv (parts per million by volume) with a million being defined as 10^6.

Care must be taken with the concentrations expressed as parts per billion by volume (ppbv) to differentiate between the British billion which is 10^12 and the USA billion which is 10^9.

Particulate matter is the sum of all solid and liquid particles suspended in air many of which are hazardous. This complex mixture includes both organic and inorganic particles.

Based on size, particulate matter is often divided into two groups.

1. Coarse particles (PM 10-2.5) such as those found near roadways and dusty industries range in diameter from 2.5 to 10 micrometers (or microns). The existing coarse particle standard (known as PM 10) includes all particles less than 10 microns in size.

2. "Fine particles" (or PM 2.5) are those found in smoke and haze have diameters less than 2.5 microns. PM 2.5 is referred to as "primary" if it is directly emitted into the air as solid or liquid particles, and is called "secondary" if it is formed by chemical reactions of gases in the atmosphere.