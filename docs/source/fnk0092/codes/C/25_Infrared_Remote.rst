##############################################################################
Chapter Infrared Remote
##############################################################################

In this chapter, we'll learn how to use an infrared remote control, and control a LED.

Project Infrared Remote Control
**********************************************

First, we need to understand how infrared remote control works, and then get the command sent from infrared remote control.

Component List
=================================

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
| Infrared remote x1                                   |
|                                                      |
| (May need CR2025 battery x1, please check the holder)|
|                                                      |
| |Chapter25_00|                                       |
+---------------------+--------------------------------+
| Infrared receiver x1| Resistor 10kΩ x1               |
|                     |                                |
| |Chapter25_01|      | |Chapter25_02|                 |
+---------------------+--------------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter01_03| image:: ../_static/imgs/1_LED_Blink/Chapter01_03.png
.. |Chapter02_00| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_00.png
.. |Chapter02_01| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_01.png
.. |Chapter25_00| image:: ../_static/imgs/25_Infrared_Remote/Chapter25_00.png   
.. |Chapter25_01| image:: ../_static/imgs/25_Infrared_Remote/Chapter25_01.png
.. |Chapter25_02| image:: ../_static/imgs/25_Infrared_Remote/Chapter25_02.png

Component Knowledge
=============================

Infrared remote
------------------------------

An Infrared(IR) remote control is a device with a certain number of buttons. Pressing down different buttons will make the infrared emission tube, which is located in the front of the remote control, send infrared with different encoding. Infrared remote control technology is widely used in household appliances, such as TV, air conditioning, etc. Thus, it makes it possible for you to switch TV programs and adjust the temperature of the air conditioning away from them. The remote control we use is shown below:

.. image:: ../_static/imgs/25_Infrared_Remote/Chapter25_03.png
    :align: center

Infrared receiver
-----------------------------

Infrared(IR) receiver is a component which can receive the infrared light, so we can use it to detect the signal emitted by the infrared remote control. DATA pin here outputs the received infrared signal.

.. image:: ../_static/imgs/25_Infrared_Remote/Chapter25_04.png
    :align: center

Circuit
=========================

Use pin 12 on the control board to connect IR receiver.

.. list-table:: 
   :width: 100%
   :align: center

   * -  Schematic diagram
   * -  |Chapter25_05|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter25_06|

.. |Chapter25_05| image:: ../_static/imgs/25_Infrared_Remote/Chapter25_05.png
.. |Chapter25_06| image:: ../_static/imgs/25_Infrared_Remote/Chapter25_06.png

Sketch
=========================

Sketch Infrared_Remote_Control
-------------------------

Before writing code, we need to import the library needed.

Click "Add .ZIP Library..." and then find IRremote.zip in libraries folder (this folder is in the folder unzipped from the ZIP file we provided). This library makes it easy to control IR receiver. 

You can also type "IRremote" into the library search bar to install the library.

.. image:: ../_static/imgs/25_Infrared_Remote/Chapter25_07.png
    :align: center

Now, write code to get the command sent from IR remote control, and send it to the serial port.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_25.1.1_Infrared_Remote_Control/Sketch_25.1.1_Infrared_Remote_Control.ino
    :linenos: 
    :language: c
    :lines: 1-77
    :dedent:

First, include header file. Each time you use the infrared sensor, you need to include the header file at the beginning of the program.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_25.1.1_Infrared_Remote_Control/Sketch_25.1.1_Infrared_Remote_Control.ino
    :linenos: 
    :language: c
    :lines: 9-9
    :dedent:

Second, define an infrared receive pin and the infrared sensor is initialized.

.. code-block:: c

    // Define the pin numbers for the IR receiver
    const int IR_RECEIVE_PIN = 12;
    ...
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver

The function decodeKeyValue() is used to map the received IR signal to the corresponding key.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_25.1.1_Infrared_Remote_Control/Sketch_25.1.1_Infrared_Remote_Control.ino
    :linenos: 
    :language: c
    :lines: 30-77
    :dedent:

Finally, **IrReceiver.decode()** is used to determine whether an infrared signal has been received, returning true/1 if an infrared signal has been received, or false/0 if no infrared signal has been received;  If an infrared signal is received, the received infrared coded value is printed through the serial port. 

Please note that **IrReceiver.resume()** must be applied to release the infrared receiver function each time  data are received. Otherwise, the infrared receiver function can only be used once and data cannot be received next time.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_25.1.1_Infrared_Remote_Control/Sketch_25.1.1_Infrared_Remote_Control.ino
    :linenos: 
    :language: c
    :lines: 21-27
    :dedent:

.. image:: ../_static/imgs/25_Infrared_Remote/Chapter25_08.png
    :align: center

Project Control LED through Infrared Remote
*********************************************************

Now, let us try to control a LED through infrared remote.

Component List
===================================

+------------------------------------------------------+
| Control board x1                                     |
|                                                      |
| |Chapter01_00|                                       |
+--------------------------+---------------------------+
| Breadboard x1            | GPIO Extension Board x1   |
|                          |                           |
| |Chapter02_00|           | |Chapter02_01|            |
+------------------+-------+---------------------------+
| USB cable x1     | Jumper M/M x11                    |
|                  |                                   |
| |Chapter01_02|   | |Chapter01_03|                    |
+------------------+-----------------------------------+
| Infrared remote x1                                   |
|                                                      |
| (May need CR2025 battery x1, please check the holder)|
|                                                      |
| |Chapter25_00|                                       |
+---------------------+--------------------------------+
| Infrared receiver x1| LED x1                         |
|                     |                                |
| |Chapter25_01|      | |Chapter25_11|                 |
+---------------------+--------------------------------+
| NPN transistor x1   | Active buzzer x1               |
|                     |                                |
| |Chapter25_09|      | |Chapter25_10|                 |
+-----------------+---+--------------+-----------------+
| Resistor 220Ω x1| Resistor 1kΩ x1  | Resistor 10kΩ x1|
|                 |                  |                 |
| |Chapter25_12|  | |Chapter25_13|   | |Chapter25_02|  |
+-----------------+------------------+-----------------+

.. |Chapter25_09| image:: ../_static/imgs/25_Infrared_Remote/Chapter25_09.png   
.. |Chapter25_10| image:: ../_static/imgs/25_Infrared_Remote/Chapter25_10.png
.. |Chapter25_11| image:: ../_static/imgs/25_Infrared_Remote/Chapter25_11.png
.. |Chapter25_12| image:: ../_static/imgs/25_Infrared_Remote/Chapter25_12.png   
.. |Chapter25_13| image:: ../_static/imgs/25_Infrared_Remote/Chapter25_13.png

Circuit
=============================

Connect pin 12 on the control board to IR receiver to simulate a desk lamp. And drive buzzer through pin 13, drive LED through pin 5. 

.. list-table:: 
   :width: 100%
   :align: center

   * -  Schematic diagram
   * -  |Chapter25_14|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter25_15|

.. |Chapter25_14| image:: ../_static/imgs/25_Infrared_Remote/Chapter25_14.png
.. |Chapter25_15| image:: ../_static/imgs/25_Infrared_Remote/Chapter25_15.png

Sketch
=============================

Sketch Control_LED_through_Infrared_Remote
----------------------------

Now, write code to get the commands sent from IR remote, and control the LED light on/off or emit light with different brightness, and control the buzzer to generate a confirmation sound when it receives the command.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_25.2.1_Control_LED_through_Infrared_Remote/Sketch_25.2.1_Control_LED_through_Infrared_Remote.ino
    :linenos: 
    :language: c
    :lines: 1-55
    :dedent:

Based on the last section, we add some new functions: control LED and buzzer.

We define a function that is used to handle the received commands. When this function is executed, make the buzzer beep first, then output PWM signals with different duty cycle to the pin connected to LED according to the receiving commands 

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_25.2.1_Control_LED_through_Infrared_Remote/Sketch_25.2.1_Control_LED_through_Infrared_Remote.ino
    :linenos: 
    :language: c
    :lines: 35-55
    :dedent:

Each time when the command is received, the function above will be called in the loop() function.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_25.2.1_Control_LED_through_Infrared_Remote/Sketch_25.2.1_Control_LED_through_Infrared_Remote.ino
    :linenos: 
    :language: c
    :lines: 27-33
    :dedent:

Verify and upload the code, press the button '0', '1', '2', '3' on IR remote, and then you can see LED emit light with different brightness, and the buzzer will start beeping when it receives the signal.