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

* Breadboard![breadboard] 

 

![breadboard](https://user-images.githubusercontent.com/82398683/127671520-c9029e0e-137c-4c38-9847-a36f4aaffecd.jpg)


