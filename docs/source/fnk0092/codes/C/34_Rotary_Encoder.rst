##############################################################################
Chapter Rotary Encoder
##############################################################################

In this chapter, we will learn how to use rotary encoder.

Project Rotary Encoder
***************************************

This project uses a rotary encoder to make a simple counter.

Component List
===============================

+------------------------------------------------------+
| Control board x1                                     |
|                                                      |
| |Chapter01_00|                                       |
+--------------------------+---------------------------+
| Breadboard x1            | GPIO Extension Board x1   |
|                          |                           |
| |Chapter02_00|           | |Chapter02_01|            |
+------------------+-------+---------------------------+
| USB cable x1     | Jumper M/M x8                     |
|                  |                                   |
| |Chapter01_02|   | |Chapter01_03|                    |
+------------------+-----------------------------------+
| Rotary encoder x1                                    |
|                                                      |
| |Chapter34_00|                                       |
+------------------------------------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter01_03| image:: ../_static/imgs/1_LED_Blink/Chapter01_03.png
.. |Chapter02_00| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_00.png
.. |Chapter02_01| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_01.png
.. |Chapter34_00| image:: ../_static/imgs/34_Rotary_Encoder/Chapter34_00.png   

Component knowledge
=============================

Rotary Encoder
-----------------------------

A rotary encoder is a rotary sensor that converts the rotational displacement into a periodic electrical signal, and then converts the electrical signal into a count pulse, and uses the number of pulses to indicate the magnitude of the rotational displacement. It drives the internal grating disc to rotate through the rotation of the knob. Many slits are preset on the grating disc. The rotation of the grating disc causes the light passing through the slits to produce pulse changes. After the signal is processed by the subsequent circuit, it is output as a pulse signal. Finally, The rotary displacement of the knob can be obtained through the output of the signal pin. The encoder generates pulse signals through the configuration of the internal light source and photosensitive element. 

The working principle of the encoder and the schematic diagram of the output waveform are as follows:

.. image:: ../_static/imgs/34_Rotary_Encoder/Chapter34_01.png
    :align: center

A rotary encoder gives two-phase square waves, which are 90° out of phase, commonly referred to as A channel and B channel. One of the channels gives the information related to the rotation speed. The information of the rotation direction is obtained by sequentially comparing the signals of the two channels. There is also a special signal called Z or zero channel, which gives the absolute zero position of the encoder. This signal is a square wave that coincides with the center line of the A channel square wave.

The following is the internal cross-sectional structure diagram of the encoder:

.. image:: ../_static/imgs/34_Rotary_Encoder/Chapter34_02.png
    :align: center

The number of pulses per revolution of the rotary encoder in this project is 20. Its working voltage is 5V. The sensor has 5 pins: SW, CLK, DT, power supply positive pin and power supply negative pin. Among them, the SW pin is the input signal pin, the rotary encoder sensor itself is also a button, when the button is pressed, the SW pin will jump from high level to low level. The CLK pin is a rotation signal pin. When not rotating, this pin outputs a high level, and when rotating, it outputs a low level. The DT pin is used to determine the direction of rotation. If this pin is high when it is not rotating, and becomes low when it is rotating, it means that clockwise rotation has occurred. When this pin is high when it is rotating, it means that counterclockwise rotation has occurred. When the positive and negative pins of the module are connected to a suitable power supply, the module starts to work. At this time, three pins on the development board need to be used to read the SW, CLK and DT of the module respectively. Then according to the above principle, the state of the rotary encoder can be determine. 

For example, when you turn the encoder clockwise by hand, the CLK outputs low level, and the DT changes from high level to low level. When you rotate the encoder counterclockwise by hand, the CLK outputs low level, and the DT changes from low level to high level. When you press the rotary encoder by hand, the SW signal outputs low level.

Circuit
============================

.. list-table:: 
   :width: 100%
   :align: center

   * -  Schematic diagram
   * -  |Chapter34_03|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter34_04|

.. |Chapter34_03| image:: ../_static/imgs/34_Rotary_Encoder/Chapter34_03.png
.. |Chapter34_04| image:: ../_static/imgs/34_Rotary_Encoder/Chapter34_04.png

Sketch
==========================

Sketch Rotary_Encoder
--------------------------

After the program is executed, the rotary encoder can count the number of output pulses during the forward and reverse rotation. When the rotary encoder is rotated clockwise by hand, the count value will increase. When the rotary encoder is rotated counterclockwise by hand , the count value will decrease. When the rotary encoder is pressed by hand, it can be reset to the initial state, that is, the count starts from 0.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_34.1.1_Rotary_Encoder/Sketch_34.1.1_Rotary_Encoder.ino
    :linenos: 
    :language: c
    :lines: 1-61
    :dedent:

Function rotaryDeal() is used to determine whether the rotary encoder is rotating, and when there is rotation, determine whether it is rotating clockwise or counterclockwise. Use variable previousCounterValue to record the number of rotations. When rotating clockwise, the variable increases, and when rotating counterclockwise, the variable decreases.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_34.1.1_Rotary_Encoder/Sketch_34.1.1_Rotary_Encoder.ino
    :linenos: 
    :language: c
    :lines: 17-38
    :dedent:

Read the SW signal pin of the rotary encoder, and determine whether the rotary encoder is pressed. If it is pressed, the variable previousCounterValue is cleared.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_34.1.1_Rotary_Encoder/Sketch_34.1.1_Rotary_Encoder.ino
    :linenos: 
    :language: c
    :lines: 48-60
    :dedent:

Project Rotary Encoder and LED
*********************************************

This project uses a rotary encoder to adjust the LEDs to emit different brightness.

Component List
===========================

Component List
=============================

+------------------------------------------------------+
| Control board x1                                     |
|                                                      |
| |Chapter01_00|                                       |
+--------------------------+---------------------------+
| Breadboard x1            | GPIO Extension Board x1   |
|                          |                           |
| |Chapter02_00|           | |Chapter02_01|            |
+------------------+-------+---------------------------+
| USB cable x1     | Jumper x8                         |
|                  |                                   |
| |Chapter01_02|   | |Chapter01_03|                    |
+------------------+-----------------------------------+
| Rotary encoder x1                                    |
|                                                      |
| |Chapter34_00|                                       |
+-------------------+----------------------------------+
| LED x1            |  Resistor 220Ω x1                |
|                   |                                  |
| |Chapter29_01|    |   |Chapter29_02|                 |
+-------------------+----------------------------------+        

.. |Chapter29_01| image:: ../_static/imgs/29_High-sensitivity_microphone_sensor/Chapter29_01.png  
.. |Chapter29_02| image:: ../_static/imgs/29_High-sensitivity_microphone_sensor/Chapter29_02.png  

Circuit
=============================

.. list-table:: 
   :width: 100%
   :align: center

   * -  Schematic diagram
   * -  |Chapter34_05|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter34_06|

.. |Chapter34_05| image:: ../_static/imgs/34_Rotary_Encoder/Chapter34_05.png
.. |Chapter34_06| image:: ../_static/imgs/34_Rotary_Encoder/Chapter34_06.png

Sketch
=============================

Sketch Rotary_Encoder_and_LED
------------------------------

After the program is executed, the rotary encoder can count the number of output pulses during forward and reverse rotation. Adjust the LED to emit different brightness by the number of rotations. When the rotary encoder is rotated clockwise by hand, the brightness of the led will increase, when the rotary encoder is rotated counterclockwise by hand, the brightness of the led will decrease, and when the rotary encoder is pressed by hand, the led will turn off.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_34.2.1_Rotary_Encoder_and_LED/Sketch_34.2.1_Rotary_Encoder_and_LED.ino
    :linenos: 
    :language: c
    :lines: 1-73
    :dedent:

Function rotaryDeal() is used to determine whether the rotary encoder is rotating, and when there is rotation, determine whether it is rotating clockwise or counterclockwise. Use variable previousCounterValue to record the number of rotations. When rotating clockwise, the variable increases, and when rotating counterclockwise, the variable decreases.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_34.2.1_Rotary_Encoder_and_LED/Sketch_34.2.1_Rotary_Encoder_and_LED.ino
    :linenos: 
    :language: c
    :lines: 19-41
    :dedent:

Read the SW signal pin of the rotary encoder, and determine whether the rotary encoder is pressed. If it is pressed, the variable previousCounterValue is cleared.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_34.2.1_Rotary_Encoder_and_LED/Sketch_34.2.1_Rotary_Encoder_and_LED.ino
    :linenos: 
    :language: c
    :lines: 53-59
    :dedent:

The variable previousCounterValue is limited here, and the PWM duty cycle of ledPin is set to previousCounterValue. The duty cycle of PWM should be less than or equal to 100.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_34.2.1_Rotary_Encoder_and_LED/Sketch_34.2.1_Rotary_Encoder_and_LED.ino
    :linenos: 
    :language: c
    :lines: 60-72
    :dedent: