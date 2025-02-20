##############################################################################
Chapter ADC
##############################################################################

Previously we have learned about the digital ports of the control board and tried to output and input signals. Now, let's learn how to use the analog-to-digital converter (ADC) on the control board. By default, the resolution of the control board ADC is set to 10 bits, which can be updated to 12 bits (0-4096) and 14 bits (0-16383) to improve the accuracy of analog readings.

Project ADC
***************************

ADC is used to convert analog signals into digital signals. Control chip on the control board has integrated this function. Now let us try to use this function to convert analog signals into digital signals.

Component List
==============================

+------------------------------------------------------+
| Control board x1                                     |
|                                                      |
| |Chapter01_00|                                       |
+--------------------------+---------------------------+
| Breadboard x1            | GPIO Extension Board x1   |
|                          |                           |
| |Chapter02_00|           | |Chapter02_01|            |
+------------------+-------+---------------------------+
| USB cable x1     | Jumper M/M x3                     |
|                  |                                   |
| |Chapter01_02|   | |Chapter01_03|                    |
+------------------+-----------------------------------+
| Rotary potentiometer x1                              |
|                                                      |
| |Chapter08_00|                                       |
+------------------------------------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter01_03| image:: ../_static/imgs/1_LED_Blink/Chapter01_03.png
.. |Chapter01_04| image:: ../_static/imgs/1_LED_Blink/Chapter01_04.png
.. |Chapter08_00| image:: ../_static/imgs/8_ADC/Chapter08_00.png
.. |Chapter02_00| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_00.png
.. |Chapter02_01| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_01.png

Circuit Knowledge
================================

ADC
------------------------------

An ADC is an electronic integrated circuit used to convert analog signals such as voltages to digital or binary form consisting of 1s and 0s.The onboard ADC module is set to 10 bits by default, which means the resolution is 2^10=1024, so its range (at 5V) will be evenly divided into 1024 parts. By default, the resolution of the onboard  ADC is set to 10 bits, which can be updated to 12 bits (0-4096) and 14 bits (0-16383) resolution to improve the accuracy of the analog readings. Any analog value can be mapped to one digital value using the resolution of the converter. So the more bits the ADC has, the denser the partition of analog will be and the greater the precision of the resulting conversion.

.. image:: ../_static/imgs/8_ADC/Chapter08_01.png
    :align: center

Subsection 1: the analog in rang of 0V-5/1024V corresponds to digital 0;

Subsection 2: the analog in rang of 5 /1024V-2*5/1024V corresponds to digital 1;

The following analog signal will be divided accordingly.

Component Knowledge
================================

Potentiometer
--------------------------------

Potentiometer is a resistive element with three Terminal parts. Unlike the resistors that we have used thus far in our project which have a fixed resistance value, the resistance value of a potentiometer can be adjusted. A potentiometer is often made up by a resistive substance (a wire or carbon element) and movable contact brush. When the brush moves along the resistor element, there will be a change in the resistance of the potentiometer's output side (3) (or change in the voltage of the circuit that is a part). The illustration below represents a linear sliding potentiometer and its electronic symbol on the right.

.. image:: ../_static/imgs/8_ADC/Chapter08_02.png
    :align: center

Between potentiometer pin 1 and pin 2 is the resistive element (a resistance wire or carbon) and pin 3 is connected to the brush that makes contact with the resistive element. In our illustration, when the brush moves from pin 1 to pin 2, the resistance value between pin 1 and pin 3 will increase linearly (until it reaches the highest value of the resistive element) and at the same time the resistance between pin 2 and pin 3 will decrease linearly and conversely down to zero. At the midpoint of the slider the measured resistance values between pin 1 and 3 and between pin 2 and 3 will be the same.

In a circuit, both sides of resistive element are often connected to the positive and negative electrodes of power. When you slide the brush "pin 3", you can get variable voltage within the range of the power supply.

.. image:: ../_static/imgs/8_ADC/Chapter08_03.png
    :align: center

Rotary potentiometer
-------------------------------

Rotary potentiometer and linear potentiometer have the same function; the only difference being the physical action being a rotational rather than a sliding movement.

.. image:: ../_static/imgs/8_ADC/Chapter08_04.png
    :align: center

Circuit
===============================

Use pin A0 on the control board to detect the voltage of rotary potentiometer.

.. list-table:: 
   :width: 100%
   :align: center

   * -  Schematic diagram
   * -  |Chapter08_05|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter08_06|

.. |Chapter08_05| image:: ../_static/imgs/8_ADC/Chapter08_05.png
.. |Chapter08_06| image:: ../_static/imgs/8_ADC/Chapter08_06.png

Sketch
==============================

Sketch ADC
-----------------------------

Now, write code to detect the voltage of rotary potentiometer, and send the data to Serial Monitor window of Arduino IDE through serial port. The code here demonstrates how to set the ADC to 14 bits precision.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_8.1.1_ADC/Sketch_8.1.1_ADC.ino
    :linenos: 
    :language: c
    :lines: 1-30
    :dedent:

From the code, we get the ADC value of pin A0, then convert it into voltage and sent to the serial port.

Verify and upload the code, open the Serial Monitor, and then you will see the original ADC value and converted voltage sent from control board.

Turn the rotary potentiometer shaft, and you can see the voltage change.

.. image:: ../_static/imgs/8_ADC/Chapter08_07.png
    :align: center

If you want to change the resolution of th ADC, you only need to modify the parameter of the function analogReadResolution(int bits); among which, bits is the bit number of the ADC. If the parameter is not set, it will be 10 bits by default. As this project applies 10-bit ADC, you do not need to set the parameter for this function.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_8.1.1_ADC/Sketch_8.1.1_ADC.ino
    :linenos: 
    :language: c
    :lines: 13-15
    :dedent:

Read the ADC value and calculate the voltage based on the set ADC bit number.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_8.1.1_ADC/Sketch_8.1.1_ADC.ino
    :linenos: 
    :language: c
    :lines: 19-24
    :dedent:

Project Control LED by Potentiometer
***********************************************

In the previous section, we have finished reading ADC value and converting it into voltage. Now, we will try to use potentiometer to control the brightness of LED.

Component List
=============================

+----------------------------------------------------------------------------------+
| Control board x1                                                                 |
|                                                                                  |
| |Chapter01_00|                                                                   |
+----------------------------------------+-----------------------------------------+
| Breadboard x1                          | GPIO Extension Board x1                 |
|                                        |                                         |
| |Chapter01_01|                         |  |Chapter02_01|                         |
+------------------+---------------------+-----------------------------------------+
| USB cable x1     | Jumper M/M x2                                                 |
|                  |                                                               |
| |Chapter01_02|   | |Chapter01_03|                                                |
+------------------+------------------+--------------------------------------------+
| LED x1           | Resistor 220Ω x1 | Rotary                                     |
|                  |                  |                                            |
|                  |                  | potentiometer x1                           |
|                  |                  |                                            |
| |Chapter01_04|   | |Chapter01_05|   | |Chapter08_00|                             |
+------------------+------------------+--------------------------------------------+

.. |Chapter01_05| image:: ../_static/imgs/1_LED_Blink/Chapter01_05.png

Circuit
==========================

Use pin A0 on control board to detect the voltage of rotary potentiometer, and use pin 9 to control one LED.

.. list-table:: 
   :width: 100%
   :align: center

   * -  Schematic diagram
   * -  |Chapter08_08|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter08_09|

.. |Chapter08_08| image:: ../_static/imgs/8_ADC/Chapter08_08.png
.. |Chapter08_09| image:: ../_static/imgs/8_ADC/Chapter08_09.png

Sketch
============================

Sketch Control_LED_by_Potentiometer
----------------------------

Now, write the code to detect the voltage of rotary potentiometer, and control LED to emit light with different brightness according to that.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_8.2.1_Control_LED_by_Potentiometer/Sketch_8.2.1_Control_LED_by_Potentiometer.ino
    :linenos: 
    :language: c
    :lines: 1-19
    :dedent:

In the code, we get the ADC value of pin A0 and map it to PWM duty cycle of LED pin port. According to different LED brightness, we can see the changes of voltage easily.

Verify and upload the code, turn the rotary potentiometer shaft, you will see the LED brightness change.

.. image:: ../_static/imgs/8_ADC/Chapter08_10.png
    :align: center

Project Control LED by Potentiometer
***********************************************

In the previous section, we have finished reading ADC value and converted it into LED brightness. There are many components, especially the sensor whose output is analog. Now, we will try to use photoresistor to measure the brightness of light.

Component List
=============================================

+------------------------------------------------------+
| Control board x1                                     |
|                                                      |
| |Chapter01_00|                                       |
+--------------------------+---------------------------+
| Breadboard x1            | GPIO Extension Board x1   |
|                          |                           |
| |Chapter02_00|           | |Chapter02_01|            |
+------------------+-------+---------------------------+
| USB cable x1     | Jumper M/M x4                     |
|                  |                                   |
| |Chapter01_02|   | |Chapter01_03|                    |
+------------------+-----------------------------------+
| LED x1           | Resistor 220Ω x1                  |
|                  |                                   |
| |Chapter01_04|   | |Chapter01_05|                    |
+------------------+-----------------------------------+
| Resistor 10kΩ x1 | Photoresistor x1                  |
|                  |                                   |
| |Chapter05_00|   | |Chapter08_11|                    |
+------------------+-----------------------------------+

.. |Chapter01_06| image:: ../_static/imgs/1_LED_Blink/Chapter01_06.png
.. |Chapter05_00| image:: ../_static/imgs/5_Control_LED_with_Push_Button_Switch/Chapter05_00.png
.. |Chapter08_11| image:: ../_static/imgs/8_ADC/Chapter08_11.png

Component Knowledge
==============================

Photoresistor
------------------------------------

A Photoresistor is simply a light sensitive resistor. It is an active component that decreases resistance with respect to receiving luminosity (light) on the component's light sensitive surface. A Photoresistor's resistance value will change in proportion to the ambient light detected. With this characteristic, we can use a Photoresistor to detect light intensity. The Photoresistor and its electronic symbol are as follows.

.. image:: ../_static/imgs/8_ADC/Chapter08_12.png
    :align: center

The circuit below is often used to detect the change of photoresistor's resistance value:

.. image:: ../_static/imgs/8_ADC/Chapter08_13.png
    :align: center

In the above circuit, when a photoresistor's resistance value changes due to a change in light intensity, the voltage between the photoresistor and resistor R1 will also change, so the intensity of the light can be obtained by measuring the voltage.

Circuit
==========================

Use pin A0 on control board to detect the voltage of photoresistor, and use pin 9 to control one LED.

.. list-table:: 
   :width: 100%
   :align: center

   * -  Schematic diagram
   * -  |Chapter08_14|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter08_15|

.. |Chapter08_14| image:: ../_static/imgs/8_ADC/Chapter08_14.png
.. |Chapter08_15| image:: ../_static/imgs/8_ADC/Chapter08_15.png

Sketch
==========================

Sketch Control_LED_through_Photoresistor
---------------------------

Now, write code to detect the voltage of rotary potentiometer, and control LED to emit light with different brightness according to that.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_8.3.1_Control_LED_through_Photoresistor/Sketch_8.3.1_Control_LED_through_Photoresistor.ino
    :linenos: 
    :language: c
    :lines: 1-19
    :dedent:

In the code, we get the ADC value of pin A0, map it to PWM duty cycle of LED pin port. According to the brightness of LED, we can see the changes of voltage easily.

Verify and upload the code, cover photoresistor with your hand, then you can see the LED brightness change.

.. image:: ../_static/imgs/8_ADC/Chapter08_16.png
    :align: center