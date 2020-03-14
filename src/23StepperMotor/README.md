

    News
    Articles
    Tutorials
    Digi-Key Store
    Projects
    Forum
    Contact

Interfacing Stepper Motor with Arduino Uno
Arduino

ByAswinth Raj Aug 15, 2017
15
Arduino Stepper Motor Control Tutorial

Stepper motors are increasingly taking its position in the world of the electronics. Starting from a normal Surveillance camera to a complicated CNC machines/Robot these Stepper Motors are used everywhere as actuators since they provide accurate controlling. In this tutorial we will learn about the most commonly/cheaply available stepper motor 28-BYJ48 and how to interface it with Arduino using ULN2003 stepper module.
Stepper Motors:

Let us take a look at this 28-BYJ48 Stepper motor.

Okay, so unlike a normal DC motor this one has five wires of all fancy colors coming out of it and why is it so? To understand this we should first know how a stepper works and what its specialty is. First of all steppers motors do not rotate, they step and so they also known as step motors. Meaning, they will move only one step at a time. These motors have a sequence of coils present in them and these coils have to be energized in a particular fashion to make the motor rotate. When each coil is being energized the motor takes a step and a sequence of energization will make the motor take continuous steps, thus making it to rotate. Let us take a look at the coils present inside the motor to know exactly know from where these wires come from.

As you can see the motor has Unipolar 5-lead coil arrangement. There are four coils which have to be energized in a particular sequence. The Red wires will be supplied with +5V and the remaining four wires will be pulled to ground for triggering the respective coil. We use a microcontroller like Arduino energize these coils in a particular sequence and make the motor perform the required number of steps.

So now, why is this motor called the 28-BYJ48? Seriously!!! I don’t know. There is no technical reason for this motor for being named so; maybe we should dive much deeper into it. Let us look at some of the important technical data obtained from the datasheet of this motor in the picture below.

Technical Data from the Datasheet of Stepper Motor

That is a head full of information, but we need to look at few important ones to know what type of stepper we are using so that we can program it efficiently. First we know that it is a 5V Stepper motor since we energize the Red wire with 5V. Then, we also know that it is a four phase stepper motor since it had four coils in it. Now, the gear ratio is given to be 1:64. This means the shaft that you see outside will make one complete rotation only if the motor inside rotates for 64 times. This is because of the gears that are connected between the motor and output shaft, these gears help in increasing the torque.

Another important data to notice is the Stride Angle: 5.625°/64. This means that the motor when operates in 8-step sequence will move 5.625 degree for each step and it will take 64 steps (5.625*64=360) to complete one full rotation.
Calculating the Steps per Revolution for Stepper Motor:

It is important to know how to calculate the steps per Revolution for your stepper motor because only then you can program it effectively.

In Arduino we will be operating the motor in 4-step sequence so the stride angle will be 11.25° since it is 5.625°(given in datasheet) for 8 step  sequence it will be 11.25° (5.625*2=11.25).

     Steps per revolution = 360/step angle

Here, 360/11.25 = 32 steps per revolution.
Why so we need Driver modules for Stepper motors?

Most stepper motors will operate only with the help of a driver module. This is because the controller module (In our case Arduino) will not be able to provide enough current from its I/O pins for the motor to operate. So we will use an external module like ULN2003 module as stepper motor driver. There are a many types of driver module and the rating of one will change based on the type of motor used. The primary principle for all driver modules will be to source/sink enough current for the motor to operate.
Arduino Stepper Motor Control Circuit Diagram and Explanation: 

The circuit Diagram for the arduino stepper motor control project is shown above. We have used the 28BYJ-48 Stepper motor and the ULN2003 Driver module. To energise the four coils of the stepper motor we are using the digital pins 8,9,10 and 11. The driver module is powered by the 5V pin of the Arduino Board.

But, power the driver with External Power supply when you are connecting some load to the steppe motor. Since I am just using the motor for demonstration purpose I have used the +5V rail of the Arduino Board. Also remember to connect the Ground of the Arduino with the ground of the Diver module.
Code for Arduino Board:

Before we start programming with our Arduino, let us understand what should actually happen inside the program. As said earlier we will be using 4-step sequence method so we will have four steps to perform for making one complete rotation.

Step
	

Pin Energized
	

Coils Energized

Step 1
	

8 and 9
	

A and B

Step 2
	

9 and 10
	

B and C

Step 3
	

10 and 11
	

C and D

Step 4
	

11 and 8
	

D and A
 

The Driver module will have four LED using which we can check which coil is being energised at any given time. The video which shows the sequence of energization can be found at the end of this tutorial.

In this tutorial we are going to write the arduino stepper motor code and for that we will program the Arduino in such a way that we can enter the number of steps to be taken by the stepper motor through the serial monitor of the Arduino. The complete program can be found at the end of the tutorial few important lines are explained below.

The number of steps per revolution for our stepper motor was calculated to be 32; hence we enter that as shown in the line below

#define STEPS 32

Next you have to create instances in which we specify the pins to which we have connected the Stepper motor.

Stepper stepper (STEPS, 8, 10, 9, 11);

Note: The pins number are disordered as 8,10,9,11 on purpose. You have to follow the same pattern even if you change the pins to which your motor is connected.

Since we are using the Arduino stepper library, we can set the speed of the motor using the below line. The speed can range between 0 to 200 for 28-BYJ48 stepper motors.

stepper.setSpeed(200);

Now, to make the motor move one step we can use the following line.

stepper.step(val);

The number of steps to be moved will be provided by the variable “val”. Since we have 32 steps and 64 as the gear ratio we need to move 2048 (32*64=2048), to make one complete rotation.

The value of the variable “val” can be entered by the user using the serial monitor.
Working of Stepper Motor with Arduino:

Once the connection is made the hardware should look something like this in the picture below.

Now, upload the below program in your Arduino UNO and open the serial monitor. As discussed earlier we will have to make 2048 steps to make one complete rotation, so when we enter 2048 the motor will make one complete rotation in clockwise direction by making 2048 steps. To rotate in anti-clockwise just enter the number with “–“negative sign. So, entering  -1024 will make the motor to rotate half the way in anti-clock wise direction. You can enter any desired values, like entering 1will make the motor to take only one step.

Hope you understood the project and enjoyed building it. The complete working of the project is shown in the video below. If you have any doubts post them on the comment section below our on our forums.  
Code

// Arduino stepper motor control code

#include <Stepper.h> // Include the header file

// change this to the number of steps on your motor
#define STEPS 32

// create an instance of the stepper class using the steps and pins
Stepper stepper(STEPS, 8, 10, 9, 11);

int val = 0;

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(200);
}

void loop() {

  if (Serial.available()>0)
  {
    val = Serial.parseInt();
    stepper.step(val);
    Serial.println(val); //for debugging
  }
 

}
Video

    TAGS
    arduino
    arduino uno
    stepper motor
    motors

Recommended Posts
IoT Device Security Conference 2020
Proactive Ecosystem Collaboration for Autonomous Driving Systems
The Current State of Machine Vision Technology
The Buffer/Driver: What Is It, and Do I Need One?
Embedded Insiders: Recapping the 2020 Consumer Electronics Show
Dealing with Legacy in Industrial IoT
Introduction to the SPI Interface
Dev Kit Weekly: Renesas EK-RA6M3G Graphics Evaluation Kit
Get Our Weekly Newsletter!

Subscribe below to receive most popular news, articles and DIY projects from Circuit Digest
Email Address *
Name
Country
Related Content
Digital Keypad Security Door Lock using Arduino
Coin Sorting Machine using Arduino
Build your own Adjustable Electronic DC Load using Arduino
Smart Restaurant Menu Ordering System using Arduino
Make a Buzz Wire Game with an Arduino
AC Fan Speed Control using Arduino and TRIAC
Long Range Arduino Based Walkie Talkie using nRF24L01
Fastest Arduino RC Car using Coreless DC Motors and nRF24L01 RF module
Previous post
Raspberry Pi Motion Sensor Alarm using PIR Sensor
Next post
AC Voltmeter using Arduino
Comments

    priya mane
    Oct 28, 2017
        Log in or register to post comments 

    nice article about Interfacing Stepper Motor with Arduino Uno
    Thanks for sharing

    Shahroz Shabbir
    Oct 31, 2017
        Log in or register to post comments 

    seems good (Y) and simple concept explained well.

    Michael MacDonald
    Mar 06, 2018
        Log in or register to post comments 

    The circuit diagram is incorrect. I had it wired how you have it in the diagram and ran the code and it does nothing. I then noticed the way it is wired in the actual real pictures is also different from the diagram. I then moved the wires around to follow the one in the real pictures of the circuit and it worked. The correct wiring should be:
    Blue - Pin 8
    Pink/Purple - Pin 9
    Yellow - Pin 10
    Orange - Pin 11

    Aswinth Raj
    Mar 07, 2018
        Log in or register to post comments 

    Thanks for pointing it out Michael, and sorry for the mistake.

    Chas
    Aug 20, 2018
        Log in or register to post comments 

    Hi,
    I'm confused now, the sequence you list is not the same as either the picture or diagram, so I'm struggling to decide which one I need to follow. Is there any chance you could please list the shield's IN pin number to the Arduino pin number (i.e. Shield IN1 to Arduino Pin 8 or whatever pin it should be)?

    Many Thnaks

    Pragati
    Mar 31, 2018
        Log in or register to post comments 

    Hey, thanks a lot! This helped me to understand the working of the stepper as well as the coding for the same.

    Manuel
    Apr 14, 2018
        Log in or register to post comments 

    DO you need to download the stepper.h file my code wont compile.

    muditha
    Apr 26, 2018
        Log in or register to post comments 

    my stepper motor not working anti click wise.
    What is the reason?

    blue
    May 04, 2018
        Log in or register to post comments 

    The stepper motor itself seems to get incredibly hot while idle (not moving) is there a way to cut the power off to it when it's not in use?

    sourajit das
    Jun 04, 2018
        Log in or register to post comments 

    Thanks for sharing

    Michau
    Jul 04, 2018
        Log in or register to post comments 

    Everything work fine, but the questions is what about other variables? I think about setSpeed, moveTo, setAcceleration, setMaxSpeed or clockwise. For me is more difficult because, I can send only one parameter(one of them)

    gvg
    Jul 24, 2018
        Log in or register to post comments 

    Is this the maximum speed as seen in the video for this motor?

    gvg
    Jul 24, 2018
        Log in or register to post comments 

    It looks like the speed can range between 0 to 1000 for 28-BYJ48 stepper motors.

    Aswinth Raj
    Jul 27, 2018
        Log in or register to post comments 

    yup speed can be increased

    Desmond Hakurekwi
    Aug 16, 2018
        Log in or register to post comments 

    i copied the code and tried to run it on my arduiono IDE but it showed me the following error:

    class hardware serial has no member named parseint

    i am using the code to run a stepper motor for my final year project at college. your assistance will be greatly appreciated. kind regards

Log in or register to post Comment

TI INA293 High-Precision Current Sense Amplifiers

Measure voltage drops across shunt resistors from -4V to 110V.

TI TPS7A24 Low-Dropout Linear Voltage Regulator

Supports a 2.4V to 18V input voltage range with ultra-low quiescent current (IQ). 

Panasonic SVPT Conductive Polymer Aluminum Solid Capacitors

Feature low ESR range from 15–24mΩ and cover a capacitance range of 100µF to 5600µF.

ON Semiconductor NxHL080N120SC1 N-Ch SiC MOSFETs

1200V, 80mΩ MOSFETs that provide superior switching performance and high reliability. 

Microchip VC-801 CMOS Crystal Oscillators (XO)

Quartz stabilized square wave generator with a CMOS output. 

MAX17634x Synchronous Step-Down DC-DC Converter

Comes with integrated MOSFETs and operates over an input-voltage range of 4.5V to 36V. 

Coilcraft 1812CAN Common Mode Choke Inductors

Designed for CAN or CAN FD in automotive or general industrial automation applications.

    Analog Devices ADPD188BI Integrated Optical Module

    Complete photometric systems for smoke detection using optical dual-wavelength technology.






    News
    Articles
    Projects

STM32L4x5 – New Ultra Low Power Microcontrollers for Industrial, Medical and Smart Home Applications
Mitsubishi’s Compact LiDAR Solution with MEMS Offers Extra-Wide Scanning and Improved Accuracy
Wideband 18GHz RF and Microwave Synthesizer for 5G and Broadband Wireless Applications
Low-power Smart Wearable Device with 5DoF Gesture Ring and Wristband for Precise and Fine Finger Tracking
40A SWIFT DC/DC Buck Converter for High Current FPGA and Processor Power Supplies
FEATURED
PRODUCTS

Start your automotive design today with TI mmWave sensors

From long-range radar and lane-change assist to vital sign monitoring and child detection, TI mmWave sensors can be the primary sensing product in...
Kick-start your Wi-Fi development

Ramp to production in as little as 6 months with the newest SimpleLink™ Wi-Fi® LaunchPad™ development kits.
The CLB can customize what you need within your design.

Integrate custom logic and augment peripheral capability with C2000™ MCUs configurable logic block (CLB) peripheral.

    The next-generation TI mmWave sensor for ADAS

    Solve long-range ADAS challenges with the second-generation AWR2243.


Connect with us on social media and stay updated with latest news, articles and projects!

Categories

    Embedded Electronics
    Power Electronics
    Analog Electronics
    Internet of Things
    Audio Electronics
    Electric Vehicles
    Events

Popular

    Robotics
    555 Circuits
    Arduino Projects
    Raspberry Pi Projects
    Electronics News
    Electronics Forum
    Calculators

Newsletter

Sign Up for Latest News
Copyright © 2020 Circuit Digest. All rights reserved.
Privacy Policy |Cookie Policy |Terms of Use |Contact Us |Advertise
