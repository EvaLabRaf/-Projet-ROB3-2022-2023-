# Rapport de séance du mardi 16/01/2023

### Goal of the session: Allow the laser to scan the obstacles

I want to find a way to scan the obstacles to make a decision to avoid them.

I found a 2 axis arm where I can mount the laser: 

<br />

![](Annexes/2023-01-16_Support1.jpg)

![](Annexes/2023-01-16_Support4.jpg)

<br />

So I created an adaptator on fusion360: 

<br />

![](Annexes/2023-01-16_Adaptator1.jpg)

![](Annexes/2023-01-16_Adaptator2.jpg)

![](Annexes/2023-01-16_Adaptator3.jpg)

<br />

![](Annexes/2023-01-16_Support2.jpg)

![](Annexes/2023-01-16_Support3.jpg)

<br />

Then I coded a function scan, to sweep on an angle of 40° in height and 120° on side. For a total of 48 measurement.

<br />

![](Annexes/2023-01-16_ArmCode.jpg)