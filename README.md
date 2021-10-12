# A.T.A.R.I 

# [ All Terrain Arduino Robotic Interface ]

# Introduction

An offroad robot that uses an Arduino nano board with an L298N driver with a hc-06 bluetooth module.
This robot uses three rgb led modules.
One as a headlight another for a break light and a third to make the robot look like a high end gaming pc.

# Chasis

You can use any rc car chasis of your choice that has 2 motors.
A motor that can drive the back wheels, Forward or reverse.
A second motor that turns the front wheels left or right.

# How it works.

The controls of the robot is just like a regular rc car but you can change the speed of the robot,
plus you can control the lights to drive at night. It includes a buzzer which can be toggled wirelessly.
The RGB light cycles automatically and uses the "random" 
function. It then selects the colour values from a range of o to 255. Each number resembles a different colour
but their is a bug where only certain colours are shown.

When the robot is powered on it will play every nerds favourite tune of retrogaming, The startup of the original
Super Mario bros from the classic NES console.


# Batteries

The robot is powered by 2 battery packs, A powerpank which plugs directly into the Arduino and a seperate battery pack that is supplying power to the L298N motor driver.
In my case I use four 3.7 volt two 18650 battries with 3000 MAh and two 26650 batteries with 9800 MAh Lithium ions but you can use your own depending on your motors on your chasis.

# How does Bluetooth work with Arduino

HC 05/06 works on serial communication. The Android app is designed to send serial data to the Arduino Bluetooth module when a button is pressed on the app. The Arduino Bluetooth module at the other end receives the data and sends it to the Arduino through the TX pin of the Bluetooth module (connected to RX pin of Arduino). The code uploaded to the Arduino checks the received data and compares it. If the received data is 1 or any specified command, for an example a LED turns ON. The LED turns OFF when the received data is 0. 

# How a L298N works

The L298N is a dual H-Bridge motor driver which allows speed and direction control of two DC motors at the same time. The module can drive DC motors that have voltages between 5 and 35V, with a peak current up to 2A.

# L298N Dual H-Bridge Motor Driver

Let’s take a closer look at the pinout of L298N module and explain how it works. The module has two screw terminal blocks for the motor A and B, and another screw terminal block for the Ground pin, the VCC for motor and a 5V pin which can either be an input or output.

# L298N motor driver pinout

This depends on the voltage used at the motors VCC. The module have an onboard 5V regulator which is either enabled or disabled using a jumper. If the motor supply voltage is up to 12V we can enable the 5V regulator and the 5V pin can be used as output, for example for powering our Arduino board. But if the motor voltage is greater than 12V we must disconnect the jumper because those voltages will cause damage to the onboard 5V regulator. In this case the 5V pin will be used as input as we need connect it to a 5V power supply in order the IC to work properly.


 
We can note here that this IC makes a voltage drop of about 2V. So for example, if we use a 12V power supply, the voltage at motors terminals will be about 10V, which means that we won’t be able to get the maximum speed out of our 12V DC motor.

# L298N voltage drop

Next are the logic control inputs. The Enable A and Enable B pins are used for enabling and controlling the speed of the motor. If a jumper is present on this pin, the motor will be enabled and work at maximum speed, and if we remove the jumper we can connect a PWM input to this pin and in that way control the speed of the motor. If we connect this pin to a Ground the motor will be disabled.

# L298N motor driver Block Diagram Current Flow How It Works

Next, the Input 1 and Input 2 pins are used for controlling the rotation direction of the motor A, and the inputs 3 and 4 for the motor B. Using these pins we actually control the switches of the H-Bridge inside the L298N IC. If input 1 is LOW and input 2 is HIGH the motor will move forward, and vice versa, if input 1 is HIGH and input 2 is LOW the motor will move backward. In case both inputs are same, either LOW or HIGH the motor will stop. The same applies for the inputs 3 and 4 and the motor B etc.

# More details about the L298N

https://www.teachmemicro.com/use-l298n-motor-driver/

# Parts needed

# Breadboard

* ![breadboard](https://user-images.githubusercontent.com/82398683/127671656-f9e62d1d-fa0b-447b-95b4-b6ba1ad2a97a.jpg)

# L298N

* ![L298N-Module-Pinout](https://user-images.githubusercontent.com/82398683/127672154-277cac67-bf73-450f-b9e5-dc42ed50596c.jpg)

# Arduino Nano

* ![Arduino-Nano-3 0](https://user-images.githubusercontent.com/82398683/127672410-e96319b3-2582-42f8-99f3-f3f3e5a1fe02.jpg)

# HC-06 Bluetooth module

* ![slave-wireless-hc-06-bluetooth-slave-module](https://user-images.githubusercontent.com/82398683/127672620-f62c6021-84cd-4932-942f-e80fc319c94b.jpg)

# RGB LED module x 2

* ![KY-009_RGB_full_color_LED_SMD_arduino_module](https://user-images.githubusercontent.com/82398683/127672895-bbf87022-504c-4b7f-9e8a-2a6628627c2a.jpg)


# 2 Colour led module

* ![download](https://user-images.githubusercontent.com/82398683/127743863-cb4527b8-85e8-4f5d-87fe-7545c5a9a578.jpg)


# Buzzer Module

* ![images](https://user-images.githubusercontent.com/82398683/127673218-8c39d16a-7465-40f4-8fd7-95daede3dde2.jpg)

# Powerbank

# Battery pack of your choice

# Batteries (7 volts or higher / Amperige of your choice but I recommend 25600 MAh in total for my robot depending on the size of your motors.

# Jumper leads (All types are required for this project depending on the size of your chasis.)

* ![images (2)](https://user-images.githubusercontent.com/82398683/127673967-6dea656f-fca5-4ad1-bbd2-fc0fd8656428.jpg)

# Arduino IDE

https://www.arduino.cc/en/software 

# USB 2.0 A to USB 2.0 Mini B cable

* ![BE-01-0487-650x489 (1)](https://user-images.githubusercontent.com/82398683/127674380-77493e7c-fb12-492c-935a-e1177294504f.jpg)

# RC chasis of your choice

*![2_21_4](https://user-images.githubusercontent.com/82398683/127676134-1a31c811-a375-4d18-9232-0b535d3abe7c.jpg)

# Assembly
The code has comments that will explain how to assemble the robot.

# Bluetooth app


https://play.google.com/store/apps/new?hl=en_ZA&gl=US 

# The insides of my robot.

![WhatsApp Image 2021-08-01 at 1 57 44 PM](https://user-images.githubusercontent.com/82398683/127770087-614c2b12-72d8-4287-be01-f7a6b1ef90c7.jpeg)

# This project is still being developed and the image of the finished product of the robot will be uploaded once it is complete.
















