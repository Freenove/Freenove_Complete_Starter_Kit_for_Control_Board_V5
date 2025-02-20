##############################################################################
Chapter Matrix Keypad
##############################################################################

We've already learned and used a push button switch before, now let us try to use a keypad, a device integrated with a number of Push Button Switches as Keys for the purposes of Input.

Project Get Input Characters
****************************************

First, try to understand the keypad, and get the input characters.

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
| 4x4 keypad x1                                        |
|                                                      |
| |Chapter23_00|                                       |
+------------------------------------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter01_03| image:: ../_static/imgs/1_LED_Blink/Chapter01_03.png
.. |Chapter02_00| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_00.png
.. |Chapter02_01| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_01.png
.. |Chapter23_00| image:: ../_static/imgs/23_Matrix_Keypad/Chapter23_00.png   

Component Knowledge
============================

4x4 keypad
-------------------------

A Keypad Matrix is a device that integrates a number of keys in one package. As is shown below, a 4x4 Keypad Matrix integrates 16 keys (think of this as 16 Push Button Switches in one module):

.. image:: ../_static/imgs/23_Matrix_Keypad/Chapter23_01.png
    :align: center

Similar to the integration of an LED Matrix, the 4x4 Keypad Matrix has each row of keys connected with one pin and this is the same for the columns. Such efficient connections reduce the number of processor ports required. The internal circuit of the Keypad Matrix is shown below.

.. image:: ../_static/imgs/23_Matrix_Keypad/Chapter23_02.png
    :align: center

The method of usage is similar to the Matrix LED, by using a row or column scanning method to detect the state of each key’s position by column and row. Take column scanning method as an example, send low level to the first 1 column (Pin1), detect level state of row 5, 6, 7, 8 to judge whether the key A, B, C, D are pressed. Then send low level to column 2, 3, 4 in turn to detect whether other keys are pressed. Therefore, you can get the state of all of the keys.

Circuit
=======================

Use pin 11-4 on control board to connect 4x4 keypad.

.. list-table:: 
   :width: 100%
   :align: center

   * -  Schematic diagram
   * -  |Chapter23_03|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter23_04|

.. |Chapter23_03| image:: ../_static/imgs/23_Matrix_Keypad/Chapter23_03.png
.. |Chapter23_04| image:: ../_static/imgs/23_Matrix_Keypad/Chapter23_04.png

Sketch
==========================

Sketch Get_Input_Characters
-------------------------

Before writing code, we need to import the library needed.

Click "Add .ZIP Library..." and then find Keypad.zip in libraries folder (this folder is in the folder unzipped form the ZIP file we provided). This library can facilitate our operation of keypad.
 
You can also type "Keypad" into the library search bar to install the library.

.. image:: ../_static/imgs/23_Matrix_Keypad/Chapter23_05.png
    :align: center

Now write the code to obtain the keypad characters, and send them to the serial port.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_23.1.1_Get_Input_Characters/Sketch_23.1.1_Get_Input_Characters.ino
    :linenos: 
    :language: c
    :lines: 1-36
    :dedent:

In the code, we use a Keypad class provided by the Keypad library to operate the keypad. The following code is to instantiate a keypad object, and the last two parameters represent the number of the row and column of the keypad.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_23.1.1_Get_Input_Characters/Sketch_23.1.1_Get_Input_Characters.ino
    :linenos: 
    :language: c
    :lines: 22-22
    :dedent:

The two-dimensional arrays record the keypad characters, and these characters can be returned when you press the keyboard.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_23.1.1_Get_Input_Characters/Sketch_23.1.1_Get_Input_Characters.ino
    :linenos: 
    :language: c
    :lines: 11-16
    :dedent:

These two arrays record the row and column's connection pins of keypad.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_23.1.1_Get_Input_Characters/Sketch_23.1.1_Get_Input_Characters.ino
    :linenos: 
    :language: c
    :lines: 18-19
    :dedent:

Send the input that get from the keyboard to the computer via the serial port in function loop().

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_23.1.1_Get_Input_Characters/Sketch_23.1.1_Get_Input_Characters.ino
    :linenos: 
    :language: c
    :lines: 29-36
    :dedent:

Verify and upload the code, open the Serial Monitor and press the keypad, and then you will see the characters you press being printed out.

.. image:: ../_static/imgs/23_Matrix_Keypad/Chapter23_06.png
    :align: center

Project Combination Lock
***************************************

Now, let us try to use keypad to make a combination lock.

Component List
======================================

+-----------------------------------------------------------------------------+
| Control board x1                                                            |
|                                                                             |
| |Chapter01_00|                                                              |
+--------------------------+--------------------------------------------------+
| Breadboard x1            | GPIO Extension Board x1                          |
|                          |                                                  |
| |Chapter02_00|           | |Chapter02_01|                                   |
+------------------+-------+--------------------------------------------------+
| USB cable x1     | Jumper M/M x15                                           |
|                  |                                                          |
| |Chapter01_02|   | |Chapter01_03|                                           |
+------------------+-------+--------------------------------------------------+
| 4x4 keypad x1            | Servo x1                                         |
|                          |                                                  |
| |Chapter23_00|           | |Chapter23_07|                                   |
+-----------------+--------+-----------------+--------------------------------+
|NPN transistor x1|Active buzzer x1          | Resistor 220Ω x8               |
|                 |                          |                                |
| |Chapter23_10|  | |Chapter23_11|           |   |Chapter23_12|               |
+-----------------+--------------------------+--------------------------------+

.. |Chapter23_07| image:: ../_static/imgs/23_Matrix_Keypad/Chapter23_07.png
.. |Chapter23_10| image:: ../_static/imgs/23_Matrix_Keypad/Chapter23_10.png
.. |Chapter23_11| image:: ../_static/imgs/23_Matrix_Keypad/Chapter23_11.png
.. |Chapter23_12| image:: ../_static/imgs/23_Matrix_Keypad/Chapter23_12.png

Circuit
============================

Use pin 11-4 on the control board to connect 4x4 keypad, pin 13 to drive buzzer and pin 12 to drive servo. Servos can be used to drive the mechanical switch and turn on the switch when the password is correct.

.. list-table:: 
   :width: 100%
   :align: center

   * -  Schematic diagram
   * -  |Chapter23_08|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter23_09|

.. |Chapter23_08| image:: ../_static/imgs/23_Matrix_Keypad/Chapter23_08.png
.. |Chapter23_09| image:: ../_static/imgs/23_Matrix_Keypad/Chapter23_09.png

Sketch
============================

Sketch Combination_Lock
-----------------------------

Now write the code to obtain the keypad characters, and compare them with the preset password. If the input is correct, the servo moves, otherwise the buzzer makes an input error alarm.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_23.2.1_Combination_Lock/Sketch_23.2.1_Combination_Lock.ino
    :linenos: 
    :language: c
    :lines: 1-47
    :dedent:

Based on the last section, this code adds a comparison function, the corresponding action will be different whenever the password is right or wrong.

First we define a correct password with four characters.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_23.2.1_Combination_Lock/Sketch_23.2.1_Combination_Lock.ino
    :linenos: 
    :language: c
    :lines: 29-29
    :dedent:

Make a prompt sound every time when a key is pressed and save the pressed characters.

.. code-block:: c

    if (keyPressed) {
        // Make a prompt tone each time press the key.
        digitalWrite(buzzerPin, HIGH);
        delay(100);
        digitalWrite(buzzerPin, LOW);
        // Save the input characters
        keyIn[keyInNum++] = keyPressed;
        ...
    }

Compare with the preset password after 4 characters are input and adopt the corresponding operation.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_23.2.1_Combination_Lock/Sketch_23.2.1_Combination_Lock.ino
    :linenos: 
    :language: c
    :lines: 50-67
    :dedent:

Verify and upload the code, and press the keypad to input password with 4 characters. If the input is correct, the servo will move to a certain degree, and then return to the original position. If the input is error, an input error alarm will be generated.