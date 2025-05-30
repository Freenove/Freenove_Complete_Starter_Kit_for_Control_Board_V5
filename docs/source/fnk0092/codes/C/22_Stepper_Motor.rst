##############################################################################
Chapter Stepper Motor 
##############################################################################

A Stepper motor is a kind of motor that can rotate a certain angle at a time, with which we can achieve mechanical movement at a higher accuracy more easily.

Project Drive Stepper Motor
***************************************

Now, try to drive a stepper motor.

Component List
=============================

Component List
============================

.. table::
    :align: center

    +-----------------------------------------------------------+
    | Control board x1                                          |
    |                                                           |
    | |Chapter01_00|                                            |
    +--------------------------+--------------------------------+
    | Breadboard x1            | GPIO Extension Board x1        |
    |                          |                                |
    | |Chapter02_00|           | |Chapter02_01|                 |
    +------------------+-------+--------------------------------+
    | USB cable x1     | Jumper M/M x3                          |
    |                  |                                        |
    | |Chapter01_02|   | |Chapter01_03|                         |
    +------------------+--------------------+-------------------+
    | ULN2003 stepper motor driver x1       | Stepper motor x1  |
    |                                       |                   |
    |                                       |                   |
    |                                       |                   |
    | |Chapter22_01|                        |  |Chapter22_00|   |
    +---------------------------------------+-------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter01_03| image:: ../_static/imgs/1_LED_Blink/Chapter01_03.png
.. |Chapter02_00| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_00.png
.. |Chapter02_01| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_01.png
.. |Chapter21_00| image:: ../_static/imgs/21_Digital_Display/Chapter21_00.png
.. |Chapter22_01| image:: ../_static/imgs/22_Stepper_Motor/Chapter22_01.png
.. |Chapter22_00| image:: ../_static/imgs/22_Stepper_Motor/Chapter22_00.png

Component Knowledge
==============================

Stepper Motor
---------------------------

Stepper Motors are an open-loop control device, which converts an electronic pulse signal into angular displacement or linear displacement. In a non-overload condition, the speed of the motor and the location of the stops depends only on the pulse signal frequency and number of pulses and is not affected by changes in load as with a DC Motor. A small Four-Phase Deceleration Stepper Motor is shown here:

.. image:: ../_static/imgs/22_Stepper_Motor/Chapter22_02.png
    :align: center

The electronic schematic diagram of a Four-Phase Stepper Motor is shown below:

.. image:: ../_static/imgs/22_Stepper_Motor/Chapter22_03.png
    :align: center

The outside case or housing of the Stepper Motor is the Stator and inside the Stator is the Rotor. There are a specific number of individual coils, usually an integer multiple of the number of phases the motor has, when the Stator is powered ON, an electromagnetic field will be formed to attract a corresponding convex diagonal groove or indentation in the Rotor’s surface. The Rotor is usually made of iron or a permanent magnet. Therefore, the Stepper Motor can be driven by powering the coils on the Stator in an ordered sequence (producing a series of "steps" or stepped movements).

A common drive sequence is as follows:

.. image:: ../_static/imgs/22_Stepper_Motor/Chapter22_04.png
    :align: center

In the sequence above, the Stepper Motor rotates once at a certain angle, which is called a "step". By controlling the number of rotational steps, you can then control the Stepper Motor’s rotation angle. By defining the time between two steps, you can control the Stepper Motor’s rotation speed.  

There are other methods to control Stepper Motors, such as: connect A phase, then connect A B phase, the stator will be located in the center of A B, which is called a half-step. We can use this way to improve the stepper motor’s stability and reduce noise at the same time. If you are interested in it, you can learn this method yourself by searching related knowledge.

The stator in the Stepper Motor we have supplied has 32 magnetic poles. Therefore, to complete one full revolution requires 32 full steps. The rotor (or output shaft) of the Stepper Motor is connected to a speed reduction set of gears and the reduction ratio is 1:64. Therefore, the final output shaft (exiting the Stepper Motor’s housing) requires 32 X 64 = 2048 steps to make one full revolution.

ULN2003 stepper motor driver 
---------------------------------------

A ULN2003 Stepper Motor Driver is used to convert weak signals into more powerful control signals in order to drive the Stepper Motor. In the illustration below, the input signal IN1-IN4 corresponds to the output signal A-D, and 4 LEDs are integrated into the board to indicate the state of these signals. The PWR interface can be used as a power supply for the Stepper Motor. By default, PWR and VCC are connected.

.. image:: ../_static/imgs/22_Stepper_Motor/Chapter22_05.png
    :align: center

Circuit
====================

Use pin 11, 10, 9, 8 on the control board to control the ULN2003 stepper motor driver, and connect it to the stepper motor.

.. list-table:: 
   :align: center

   * -  Schematic diagram
   * -  |Chapter22_06|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter22_07|

.. |Chapter22_06| image:: ../_static/imgs/22_Stepper_Motor/Chapter22_06.png
.. |Chapter22_07| image:: ../_static/imgs/22_Stepper_Motor/Chapter22_07.png

Sketch
=======================

Sketch Drive_Stepper_Motor
--------------------------------------------------

Now write code to control the stepper motor through ULN2003 stepper motor driver.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_22.1.1_Drive_Stepper_Motor/Sketch_22.1.1_Drive_Stepper_Motor.ino
    :linenos: 
    :language: c
    :lines: 1-49
    :dedent:

In the code, we define a function to make the motor rotate for a step. And the parameter determines the rotation direction of the stepper motor.

.. code-block:: c
    :linenos:

    void moveOneStep(bool dir) {
        ...
    }

A variable is defined in this function and we use four low bits to show the state of 4 ports. These ports are connected in order, so the variable can be assigned to 0x01 and we can use the shifting method to change the bit of the connected port.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_22.1.1_Drive_Stepper_Motor/Sketch_22.1.1_Drive_Stepper_Motor.ino
    :linenos: 
    :language: c
    :lines: 36-44
    :dedent:

Then change the state of the port according to the above variables.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_22.1.1_Drive_Stepper_Motor/Sketch_22.1.1_Drive_Stepper_Motor.ino
    :linenos: 
    :language: c
    :lines: 45-48
    :dedent:

We define a function to control the step motor to rotate several steps and control the direction and speed through parameters. Call it directly in the loop () function.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_22.1.1_Drive_Stepper_Motor/Sketch_22.1.1_Drive_Stepper_Motor.ino
    :linenos: 
    :language: c
    :lines: 28-33
    :dedent:

Verify and upload the code, and you will see the step motor rotate a full turn, and then repeat this process in a reverse direction.

.. image:: ../_static/imgs/22_Stepper_Motor/Chapter22_08.png
    :align: center