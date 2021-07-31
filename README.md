# A.T.A.R.I 

# [ All Terrain Arduino Robotic Interface ]

# Introduction

An offroad robot that uses an Arduino nano board with an L298N driver with a hc-06 bluetooth module.
This robot uses three rgb led modules.
One as a headlight another for a break light and a third to make the robot look like a high end gaming pc.

# Chasis

You can use any rc car chasis of your choice that has 2 motors.
A motor that can drive the back wheels, Forward or reverse.
A second motor that turns the left wheels left or right.

# How it works.

The controls of the robot is just like a regular rc car but you can change the speed of the robot,
plus you can control the lights to drive at night. It includes a buzzer which can be toggled wirelessly.
The RGB light cycles automatically and uses the "#random" 
function. It then selects the colour values from a range of o to 255. Each number resembles a different colour
but their is a bug where only certain colours are shown.

When the robot is powered on it will play every nerds favourite tune of retrogaming, The startup of the original
Super Mario bros for the NES.

ONce booted the RGB should start.

# Batteries

The robot is powered by 2 battery packs, A powerpank which plugs directly into the Arduino and a seperate battery pack that is supplying power to the L298N motor driver.
In my case I use two 3.7 volt with 9800 MAh Lithium ions but you can use your own depending on your motors on your chasis.

# How does Bluetooth work with Arduino

HC 05/06 works on serial communication. The Android app is designed to send serial data to the Arduino Bluetooth module when a button is pressed on the app. The Arduino Bluetooth module at the other end receives the data and sends it to the Arduino through the TX pin of the Bluetooth module (connected to RX pin of Arduino). The code uploaded to the Arduino checks the received data and compares it. If the received data is 1 or any specified command, for an example a LED turns ON. The LED turns OFF when the received data is 0. 

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

# Batteries (7 volts or higher / Amperiige of your choice.

# Jumper leads

* ![images (2)](https://user-images.githubusercontent.com/82398683/127673967-6dea656f-fca5-4ad1-bbd2-fc0fd8656428.jpg)

# Arduino IDE

# USB 2.0 A to USB 2.0 Mini B cable

* ![BE-01-0487-650x489 (1)](https://user-images.githubusercontent.com/82398683/127674380-77493e7c-fb12-492c-935a-e1177294504f.jpg)

# RC chasis of your choice

*![2_21_4](https://user-images.githubusercontent.com/82398683/127676134-1a31c811-a375-4d18-9232-0b535d3abe7c.jpg)

# Assembly
The code has comments that will explain how to assemble the robot.

# Bluetooth app


https://play.google.com/store/apps/new?hl=en_ZA&gl=US 















