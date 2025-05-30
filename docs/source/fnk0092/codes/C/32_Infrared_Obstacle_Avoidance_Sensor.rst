##############################################################################
Chapter Infrared Obstacle Avoidance Sensor
##############################################################################

In this chapter, we will learn how to use infrared obstacle avoidance sensor.

Project Infrared obstacle avoidance sensor and LED
*****************************************************************

This project uses infrared obstacle avoidance sensor to change the state of LED.

Component List
====================================

.. table::
    :align: center

    +------------------------------------------------------+
    | Control board x1                                     |
    |                                                      |
    | |Chapter01_00|                                       |
    +--------------------------+---------------------------+
    | Breadboard x1            | GPIO Extension Board x1   |
    |                          |                           |
    | |Chapter02_00|           | |Chapter02_01|            |
    +------------------+-------+---------------------------+
    | USB cable x1     | Jumper x5                         |
    |                  |                                   |
    | |Chapter01_02|   | |Chapter01_03|                    |
    +------------------+-----------------------------------+
    | Infrared obstacle avoidance sensor x1                |
    |                                                      |
    | |Chapter32_00|                                       |
    +-------------------+----------------------------------+
    | LED x1            |  Resistor 220Ω x1                |
    |                   |                                  |
    | |Chapter29_01|    |   |Chapter29_02|                 |
    +-------------------+----------------------------------+        

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter01_03| image:: ../_static/imgs/1_LED_Blink/Chapter01_03.png
.. |Chapter02_00| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_00.png
.. |Chapter02_01| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_01.png
.. |Chapter32_00| image:: ../_static/imgs/32_Infrared_Obstacle_Avoidance_Sensor/Chapter32_00.png  
.. |Chapter29_01| image:: ../_static/imgs/29_High-sensitivity_microphone_sensor/Chapter29_01.png  
.. |Chapter29_02| image:: ../_static/imgs/29_High-sensitivity_microphone_sensor/Chapter29_02.png  

Component knowledge
==============================

Infrared obstacle avoidance sensor
------------------------------------------

The infrared obstacle avoidance sensor module is a distance adjustable obstacle avoidance sensor. The sensor has strong adaptability to ambient light and high precision. It has a pair of infrared emitting and receiving tubes. The transmitting tube emits infrared rays of a certain frequency. When the detection direction encounters an obstacle (reflecting surface), the infrared rays are reflected back and are received by the receiving tube. The indicator light is on at this time. After the circuit processing, the signal output pin outputs digital signal. The detection distance can be adjusted by the potentiometer knob, the effective distance is 2 ~ 30cm, and the detection angle is 35°. 

This module has 3 pins: signal pin, power positive pin and power negative pin. When the positive and negative pins of the module are connected to a suitable power supply, the module starts to work. At this time, only one pin on the development board is needed to read the output signal of the module. When the module is in use, the detection distance can be adjusted to a suitable value through the potentiometer knob. You can use your hand to block the module at a certain distance. When the infrared obstacle avoidance sensor is blocked, the signal pin outputs a low level; if the infrared obstacle avoidance sensor is not blocked, it outputs a high level.

Below is the pinout of infrared obstacle avoidance sensor.

:orange:`Pin description:`

.. table::
    :class: freenove-ow

    +--------+------------------------------+
    | symbol |           Function           |
    +========+==============================+
    | OUT    | Output control signal        |
    +--------+------------------------------+
    | VCC    | Power supply pin, +3.3V~5.0V |
    +--------+------------------------------+
    | GND    | GND                          |
    +--------+------------------------------+

Please do not use the voltage beyond the power supply range to avoid damage to the infrared obstacle avoidance sensor.

Circuit
========================

.. list-table:: 
   :align: center

   * -  Schematic diagram
   * -  |Chapter32_01|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter32_02|

.. |Chapter32_01| image:: ../_static/imgs/32_Infrared_Obstacle_Avoidance_Sensor/Chapter32_01.png
.. |Chapter32_02| image:: ../_static/imgs/32_Infrared_Obstacle_Avoidance_Sensor/Chapter32_02.png

:red:`Please check the pin sequence of your sensor, and connect the circuit accordingly to avoid irrevisible damage to the board.`

Sketch
=======================

Sketch Infrared_obstacle_avoidance_sensor_and_LED
--------------------------------------------------------------

After the program is executed, when you block the sensor with your hand at a certain distance or the sensor encounters an obstacle, the LED will turn on, and when the sensor is not blocked or the sensor does not encounter an obstacle, the LED will turn off.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_32.1.1_Infrared_obstacle_avoidance_sensor_and_LED/Sketch_32.1.1_Infrared_obstacle_avoidance_sensor_and_LED.ino
    :linenos: 
    :language: c
    :lines: 1-25
    :dedent:

Project Infrared obstacle avoidance sensor and buzzer
******************************************************************

This project uses an infrared obstacle avoidance sensor to make a simple reminder.

Component List
=================================

.. table::
    :align: center

    +--------------------------------------------------------------------+
    | Control board x1                                                   |
    |                                                                    |
    | |Chapter01_00|                                                     |
    +--------------------------+-----------------------------------------+
    | Breadboard x1            | GPIO Extension Board x1                 |
    |                          |                                         |
    | |Chapter02_00|           | |Chapter02_01|                          |
    +------------------+-------+-----------------------------------------+
    | USB cable x1     | Jumper x5                                       |
    |                  |                                                 |
    | |Chapter01_02|   | |Chapter01_03|                                  |
    +------------------+-------------------------------------------------+
    | Infrared obstacle avoidance sensor x1                              |
    |                                                                    |
    | |Chapter32_00|                                                     |
    +-------------------+------------------------------------------------+
    | LED x1            |  Resistor 220Ω x1                              |
    |                   |                                                |
    | |Chapter29_01|    |   |Chapter29_02|                               |
    +-------------------+-------------------+----------------------------+      
    | Active buzzer x1  |  NPN transistorx1 |  Resistor 1kΩx1            |
    |                   |                   |                            |
    |                   |  (S8050)          |                            |
    |                   |                   |                            |
    | |Chapter32_05|    |   |Chapter32_04|  |   |Chapter10_10|           |
    +-------------------+-------------------+----------------------------+      

.. |Chapter32_03| image:: ../_static/imgs/32_Infrared_Obstacle_Avoidance_Sensor/Chapter32_03.png  
.. |Chapter32_04| image:: ../_static/imgs/32_Infrared_Obstacle_Avoidance_Sensor/Chapter32_04.png
.. |Chapter32_05| image:: ../_static/imgs/32_Infrared_Obstacle_Avoidance_Sensor/Chapter32_05.png
.. |Chapter10_10| image:: ../_static/imgs/10_Buzzer/Chapter10_10.png

Circuit
========================

.. list-table:: 
   :align: center

   * -  Schematic diagram
   * -  |Chapter32_06|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter32_07|

.. |Chapter32_06| image:: ../_static/imgs/32_Infrared_Obstacle_Avoidance_Sensor/Chapter32_06.png
.. |Chapter32_07| image:: ../_static/imgs/32_Infrared_Obstacle_Avoidance_Sensor/Chapter32_07.png

Sketch
====================

Sketch Infrared_obstacle_avoidance_sensor_and_buzzer
---------------------------------------------------------

After the program is executed, when you block the sensor with your hand at a certain distance or the sensor encounters an obstacle, the buzzer will sound a reminder, and the LED will flash to remind you.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_32.2.1_Infrared_obstacle_avoidance_sensor_and_buzzer/Sketch_32.2.1_Infrared_obstacle_avoidance_sensor_and_buzzer.ino
    :linenos: 
    :language: c
    :lines: 1-36
    :dedent:

The pins that support the attachInterrupt() function on this control board are 2 and 3. For more details,you may refer to :

`attatachInterrupt() En |Arduino Document <https://docs.arduino.cc/language-reference/en/functions/external-interrupts/attachInterrupt/#digital-pins-with-interrupts>`_