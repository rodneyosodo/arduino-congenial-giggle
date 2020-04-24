Interface 4×3 & 4×4 Membrane Keypad with Arduino
Tutorial for Interfacing 4x3 4x4 Membrane Keypad Interfacing with Arduino

Matrix keypads are the kind of keypads you see on cell phones, calculators, microwaves ovens, door locks, etc. They’re practically everywhere.

However, in DIY electronics, they are a great way to let users interact with your project and are often needed to navigate menus, punch in passwords and control robots.
Hardware Overview – Membrane Keypad

Membrane keypads are made of a thin, flexible membrane material. They do come in may sizes 4×3, 4×4, 4×1 etc. Regardless of their size, they all work in the same way.

One of the great thing about them is that they come with an adhesive backing so you can attach it to nearly anything. You just have to peel the paper backing off.
4x3 & 4x4 Keypads

Let’s take 4×4 keypad as an example. It has total 16 keys. Beneath each key is a special membrane switch.

All these membrane switches are connected to each other with conductive trace underneath the pad forming a matrix of 4×4 grid.
Internal Conductive Traces of 4x3 Membrane Keypad On Back Side

If you had used 16 individual push buttons, you would have required 17 input pins (one for each key and a ground pin) in order to make them work. However, with matrix arrangement, you only need 8 microcontroller pins (4-columns and 4-rows) to scan through the pad.
Pinout of 4×3 & 4×4 Membrane Keypad

The pinout of 4×3 & 4×4 membrane keypad is as follows.
4x3 Membrane Keypad Pinout
4x4 Mambrane Keypad Pinout
How keypad works & How to scan them?

The working principle is very simple. Pressing a button shorts one of the row lines to one of the column lines, allowing current to flow between them. For example, when key ‘4’ is pressed, column 1 and row 2 are shorted.
4x3 Membrane Keypad Working

A microcontroller can scan these lines for a button-pressed state. To do this, it follows below procedure.

    Microcontroller sets all the column and row lines to input.
    Then, it picks a row and sets it HIGH.
    After that, it checks the column lines one at a time.
    If the column connection stays LOW, the button on the row has not been pressed.
    If it goes HIGH, the microcontroller knows which row was set HIGH, and which column was detected HIGH when checked.
    Finally, it knows which button was pressed that corresponds to detected row & column.

Wiring 4×3 & 4×4 Membrane Keypad with Arduino

Now that we know everything about the membrane keypad, we can begin hooking it up with Arduino.

The connections are pretty straightforward. Start by connecting pin 1 of keypad to digital pin 9 on Arduino. Now keep on connecting the pins leftwards like 2 with 8, 3 with 7 etc.
Wiring 4x3 Membrane Keypad with Arduino
Wiring 4×3 Membrane Keypad with Arduino
Wiring 4x4 Membrane Keypad with Arduino
Wiring 4×4 Membrane Keypad with Arduino
Installing Keypad Library

In order to determine which key was pressed, we need to continuously scan rows & columns. Fortunately, Keypad.h was written to hide away this unnecessary complexity so that we can issue simple commands to know which key was pressed.

To install the library navigate to the Sketch > Include Library > Manage Libraries…Wait for Library Manager to download libraries index and update list of installed libraries.
Arduino Library Installation - Selecting Manage Libraries in Arduino IDE

Filter your search by typing ‘keypad’. There should be a couple entries. Look for Keypad by Mark Stanley, Alexander Brevig. You have to scroll a little bit. Click on that entry, and then select Install.
Arduino Keypad Library Installation
Arduino Code

The following sketches will give you complete understanding on how to detect key presses with 4×3 & 4×4 membrane keypad and can serve as the basis for more practical experiments and projects.
Code for 4×3 Keypad

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();// Read the key
  
  // Print if key pressed
  if (key){
    Serial.print("Key Pressed : ");
    Serial.println(key);
  }
}

Code for 4×4 Keypad

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();// Read the key
  
  // Print if key pressed
  if (key){
    Serial.print("Key Pressed : ");
    Serial.println(key);
  }
}

Here’s how the output looks like in the serial monitor.
4x3 & 4x4 Keypad Arduino interfacing Output On Serial Monitor
Code Explanation

The sketch starts by including Keypad.h library and defining number of rows & columns on the keypad you wish to use.

Next, we define a 2-dimensional keymap array keys[ROWS][COLS] which holds characters to be printed when a particular button is pressed on the keypad.

In our sketch, the characters are laid out just as they appear on the keypad. But actually you can define these to be anything you want. For example, if you are planning on creating a calculator project, you would just change the array definition to this:

char keys[ROWS][COLS] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'9','0','+','-'},
  {'.','*','/','='}
};

Next, we create an object of keypad library. The constructor Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS ) takes five parameters.

    makeKeymap(keys) initializes the internal keymap to be equal to the user defined keymap.
    rowPins and colPins are the arduino pins to which rows & columns of keypad connected.
    ROWS and COLS are the number of rows & columns of the keypad.

Once a keypad object is created, we can issue a simple command getKey() to check which key is pressed, if any.
Other useful functions in Keypad library

There are a few useful functions you can use with Keypad object. Few of them are listed below:

    char waitForKey() Waits forever until someone presses a key. Warning – It blocks all other code until a key is pressed. That means no blinking LED’s, no LCD screen updates, no nothing with the exception of interrupt routines.
    KeyState getState() Returns the current state of any of the keys. The four states are IDLE, PRESSED, RELEASED and HOLD.
    boolean keyStateChanged() Let’s you know when the key has changed from one state to another. For example, instead of just testing for a valid key you can test for when a key was pressed.
    setHoldTime(unsigned int time) Sets the amount of milliseconds the user will have to hold a button until the HOLD state is triggered.
    setDebounceTime(unsigned int time) Sets the amount of milliseconds the keypad will wait until it accepts a new keypress/keyEvent.
    addEventListener(keypadEvent) Triggers an event if the keypad is used.