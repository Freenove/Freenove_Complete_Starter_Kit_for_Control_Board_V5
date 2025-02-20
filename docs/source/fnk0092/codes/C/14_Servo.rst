##############################################################################
Chapter Servo
##############################################################################

Earlier, we have used control board and L293D module to control the motor speed and steering. Now, we will use another motor, servo, which can rotate to a certain angle.

Project Servo Sweep
**********************************

First, let's get the servo to rotate.

Component List
================================

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
| Servo x1                                             |
|                                                      |
| |Chapter14_00|                                       |
+------------------------------------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter01_03| image:: ../_static/imgs/1_LED_Blink/Chapter01_03.png
.. |Chapter02_00| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_00.png
.. |Chapter02_01| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_01.png
.. |Chapter14_00| image:: ../_static/imgs/14_Servo/Chapter14_00.png   

Component Knowledge
===============================

Servo
-------------------------------

Servo is a compact package which consists of a DC Motor, a set of reduction gears to provide torque, a sensor and control circuit board. Most Servos only have a 180-degree range of motion via their "horn". Servos can output higher torque than a simple DC Motor alone and they are widely used to control motion in model cars, model airplanes, robots, etc. Servos have three wire leads which usually terminate to a male or female 3-pin plug. Two leads are for electric power: Positive (2-VCC, Red wire), Negative (3-GND, Brown wire), and the signal line (1-Signal, Orange wire) as represented in the Servo provided in your Kit.

.. image:: ../_static/imgs/14_Servo/Chapter14_01.png
    :align: center

We will use a 50Hz PWM signal with a duty cycle in a certain range to drive the Servo. The lasting time 0.5ms-2.5ms of PWM single cycle high level corresponds to the Servo angle 0 degrees - 180 degree linearly. Part of the corresponding values are as follows:

+-----------------+-------------+
| High level time | Servo angle |
+-----------------+-------------+
| 0.5ms           | 0 degree    |
+-----------------+-------------+
| 1ms             | 45 degree   |
+-----------------+-------------+
| 1.5ms           | 90 degree   |
+-----------------+-------------+
| 2ms             | 135 degree  |
+-----------------+-------------+
| 2.5ms           | 180 degree  |
+-----------------+-------------+

When you change the servo signal, the servo will rotate to the designated position.

Circuit
========================

Use pin 3 of the control board to drive the servo. 

Pay attention to the color of servo lead wire: VCC (red), GND (brown), and signal line (orange). The wrong connection can cause damage to servo.

.. list-table:: 
   :width: 100%
   :align: center

   * -  Schematic diagram
   * -  |Chapter14_02|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter14_08|

.. |Chapter14_02| image:: ../_static/imgs/14_Servo/Chapter14_02.png
.. |Chapter14_08| image:: ../_static/imgs/14_Servo/Chapter14_08.png

Sketch
==========================

Sketch Servo_Sweep
------------------------

Now, write the code to control servo, making it sweep in the motion range continuously.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_14.1.1_Servo_Sweep/Sketch_14.1.1_Servo_Sweep.ino
    :linenos: 
    :language: c
    :lines: 1-29
    :dedent:

Servo uses the Servo library, like the following reference to Servo library:

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_14.1.1_Servo_Sweep/Sketch_14.1.1_Servo_Sweep.ino
    :linenos: 
    :language: c
    :lines: 8-8
    :dedent:

Servo library provides the Servo class that controls it. Different from previous Serial class, the Servo class must be instantiated before you use it: 

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_14.1.1_Servo_Sweep/Sketch_14.1.1_Servo_Sweep.ino
    :linenos: 
    :language: c
    :lines: 10-10
    :dedent:

The code above defines an object of Servo type, myservo.

.. py:function:: Servo Class	
    
    Servo class must be instantiated when used, that is, define an object of Servo type, for example:
    
    Servo myservo;
    
    Most other boards can define 12 objects of Servo type, namely, they can control up to 12 servos.
    
    The function commonly used in the servo class is as follows: 
    
    myservo.attach(pin): Initialize the servo, the parameter is the port connected to servo signal line;
    
    myservo.write(angle): Control servo to rotate to the specified angle; parameter here is to specify the angle.

After the Servo object is defined, it can refer to the function, such as initializing the servo:

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_14.1.1_Servo_Sweep/Sketch_14.1.1_Servo_Sweep.ino
    :linenos: 
    :language: c
    :lines: 16-16
    :dedent:

After initializing the servo, you can control the servo to rotate to a specific angle: 

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_14.1.1_Servo_Sweep/Sketch_14.1.1_Servo_Sweep.ino
    :linenos: 
    :language: c
    :lines: 22-22
    :dedent:

In the loop () function, we use the loop to control the servo to rotate from 0 degrees to 180 degrees, and then from 180 degrees to 0 degrees, then repeat the cycle all the time.

Verify and upload the code, the servo starts to sweep continuously. 

.. image:: ../_static/imgs/14_Servo/Chapter14_03.png
    :align: center

Project Control Servo with Potentiometer
****************************************************

In the previous section, we've made the servo sweep continuously. Now, we will use a potentiometer to control the servo's angle.

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
+------------------+------+----------------------------+
| Servo x1                | Rotary potentiometer x1    |
|                         |                            |
| |Chapter14_00|          |  |Chapter14_04|            |
+-------------------------+----------------------------+

.. |Chapter14_04| image:: ../_static/imgs/14_Servo/Chapter14_04.png

Circuit
===========================

Use pin A0 of the control board to detect the voltage of rotary potentiometer, and pin 3 to drive the servo.

.. list-table:: 
   :width: 100%
   :align: center

   * -  Schematic diagram
   * -  |Chapter14_05|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter14_06|

.. |Chapter14_05| image:: ../_static/imgs/14_Servo/Chapter14_05.png
.. |Chapter14_06| image:: ../_static/imgs/14_Servo/Chapter14_06.png

Sketch
============================

Sketch Servo_Sweep
----------------------

Now, write the code to detect the voltage of rotary potentiometer, and control servo to rotate to a different angle according to that. 

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_14.1.1_Servo_Sweep/Sketch_14.1.1_Servo_Sweep.ino
    :linenos: 
    :language: c
    :lines: 1-25
    :dedent:

In the code, we obtain the ADC value of pin A0, and map it to the servo angle.

Verify and upload the code, turn the potentiometer shaft, then the servo will rotate to a corresponding angle.

.. image:: ../_static/imgs/14_Servo/Chapter14_07.png
    :align: center