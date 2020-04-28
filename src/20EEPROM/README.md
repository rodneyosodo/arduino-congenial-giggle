Computers and microcontrollers need memory to store data, either permanently or temporarily, and while this memory can come in a variety of forms it can be divided into two basic types – volatile and nonvolatile.

Volatile memory is usually in the form of RAM or Random Access Memory.  This is the “working” memory for your device, it holds temporary data used during program operation. Once the power is removed the memory is erased.

EEPROM with Arduino

Nonvolatile memory, as you may have guessed by now, retains its data even after being powered-down. There are a variety of different types of non-volatile memory, and today we will be examining one of them – the Electrically Erasable Programmable Read-Only Memory or EEPROM.

Specifically, we will be looking at how to use EEPROM with an Arduino.
Understanding EEPROMs

There are many other forms of non-volatile memory, including Flash memory, SD Cards, USB drives, hard disk drives, and SSDs.  So where does the EEPROM fit in all of this?

Compared to the aforementioned memory types an EEPROM has a very small amount of storage, in fact, EEPROM capacities are commonly measured in Bits as opposed to Bytes. Since they only store a small amount of data they don’t consume a great deal of current, making them ideal for battery and low-powered applications. 

EEPROMs were developed in the early 1970s and the first EEPROM was patented by NEC in 1975. 
Non-Volatile Memory Types

An EEPROM is constructed using an array of floating-gate transistors, with two transistors per bit. It is part of the ROM, or Read-Only Memory, family of devices.

EEPROMs are similar to Flash Memory, the difference being that Flash Memory is larger and uses larger data blocks. This comes at the expense of the number or rewrites or “write cycles”, Flash Memory can only be rewritten about 10,000 times.

The Arduino microcontrollers use Flash Memory to store the programs (sketches) that are uploaded to it. Arduino also has internal EEPROM, as we will see shortly.

EEPROM Family

Other members of the ROM family include the following:

    ROM – Read-Only Memory. These chips are programmed during manufacture and cannot be altered.
    PROM – Programmable Read-Only Memory.  These chips can be programmed using a special device, however, they can not be erased and reprogrammed.
    EPROM – Erasable Programmable Read-Only Memory.  Like a PROM, an EPROM requires a special programming device. This type of memory chip can be erased using ultraviolet light and then reused.

As it requires no external programming or “burning” device an EEPROM is the easiest of these devices to use.
EEPROM Limitations

With all of their wonderful features, there are also some limitations that need to be considered when using an EEPROM in your design.

EEPROM Limitations

As with Flash Memory, EEPROMs have a limited number of write cycles. You can read from them as much as you want, but you can only write or rewrite the data a given number of times.

The limit on write cycles for common EEPROMs is from about 100,000 to 2 million write cycles.

A few hundred thousand or even a couple of million write cycles may sound like a lot, but consider how fast a modern microcontroller or microprocessor can write data and you’ll soon realize that it can become a severe limitation.  If you were to rewrite to the EEPROM every second and it has a write cycle capacity of 100,000 writes then you’d exceed that capacity in a little over one day!

When designing using EEPROMs you will want to write to the device as little as possible. Another technique, which we will examine in a while, is to read the bit first before it is written – no sense rewriting it if it is already the correct value.

Another EEPROM limitation is data retention time. While EEPROM technology is constantly improving todays EEPROMs can retain data for about 10 years at room temperature before it becomes corrupted.  Rewriting that data will start the counter again, prolonging the life of the EEPROM.

And finally, an obvious limitation of sorts is the EEPROM storage capacity, which is quite small when compared to other memory devices. But, as the most common use of EEPROMs is to retain configuration and calibration data, this is seldom an issue.
EEPROM with Arduino – Two Types

Adding EEPROM to our Arduino designs can allow our projects to retain data after being powered down. This can be very useful for applications that require calibration, or the storage of a user’s favorite settings.
Internal EEPROM

We can add EEPROM capability to our Arduino projects quite easily. In fact, the Arduino already has some internal EEPROM that we can use in our programs.  The amount of memory depends upon which Arduino model we are using.

The following table illustrates the amount of internal EEPROM in some popular Arduino models:


## Arduino Uno
What we need Arduino Uno and Potentiometer
Connect the potentiometer to the arduino

Middle will be connected to A0
























