##############################################################################
Chapter Acceleration sensor
##############################################################################

In the previous chapter, we have learned sensors that are used to detect light or temperature. Now we will learn a sensor that can detect acceleration.

Project Acceleration Detection
*********************************************

We will use serial port to get the data of MPU6050 module.

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
| USB cable x1     | Jumper M/M x4                     |
|                  |                                   |
| |Chapter01_02|   | |Chapter01_03|                    |
+------------------+-----------------------------------+
| Joystick x1                                          |
|                                                      |
| |Chapter17_00|                                       |
+------------------------------------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png
.. |Chapter01_03| image:: ../_static/imgs/1_LED_Blink/Chapter01_03.png
.. |Chapter02_00| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_00.png
.. |Chapter02_01| image:: ../_static/imgs/2_Two_LEDs_Blink/Chapter02_01.png
.. |Chapter17_00| image:: ../_static/imgs/17_Acceleration_sensor/Chapter17_00.png 

Component Knowledge
==================================

I2C communication
-----------------------------

I2C (Inter-Integrated Circuit) is a two-wire serial communication mode, which can be used to the connection of micro controller and its peripheral equipment. Devices using I2C communication must be connected to the serial data (SDA) line, and serial clock (SCL) line (called I2C bus). Each device has a unique address and can be used as a transmitter or receiver to communicate with devices connected to the bus.

MPU6050
-----------------------------

MPU6050 Sensor Module is a complete 6-axis Motion Tracking Device. It combines a 3-axis Gyroscope, a 3-axis Accelerometer and a DMP (Digital Motion Processor) all in a small package. The settings of the Accelerometer and Gyroscope of MPU6050 can be changed. A precision wide range digital temperature sensor is also integrated to compensate data readings for changes in temperature, and temperature values can also be read. The MPU6050 Module follows the I2C communication protocol and the default address is 0x68.

.. image:: ../_static/imgs/17_Acceleration_sensor/Chapter17_01.png
    :align: center

The port description of the MPU6050 module is as follows:

.. table::
    :align: center
    :class: freenove-ow

    +----------+------------+-------------------------------------------------------------+
    | Pin name | Pin number | Description                                                 |
    +==========+============+=============================================================+
    | VCC      | 1          | Positive pole of power supply with voltage 5V               |
    +----------+------------+-------------------------------------------------------------+
    | GND      | 2          | Negative pole of power supply                               |
    +----------+------------+-------------------------------------------------------------+
    | SCL      | 3          | I2C communication clock pin                                 |
    +----------+------------+-------------------------------------------------------------+
    | SDA      | 4          | I2C communication data pin                                  |
    +----------+------------+-------------------------------------------------------------+
    | XDA      | 5          | I2C host data pin which can be connected to other devices.  |
    +----------+------------+-------------------------------------------------------------+
    | XCL      | 6          | I2C host clock pin which can be connected to other devices. |
    +----------+------------+-------------------------------------------------------------+
    |          |            | I2C address bit control pin.                                |
    |          |            |                                                             |
    | AD0      | 7          | Low level: the device address is 0x68                       |
    |          |            |                                                             |
    |          |            | High level: the device address is 0x69                      |
    +----------+------------+-------------------------------------------------------------+
    | INT      | 8          | Output interrupt pin                                        |
    +----------+------------+-------------------------------------------------------------+

For more detail, please refer to datasheet.

MPU6050 is widely used to assist with balancing vehicles, robots and aircraft, mobile phones and other products which require stability to control stability and attitude or which need to sense same.

Circuit
============================

Use pin A4/SDA, pin A5/SCL port on the control board to communicate with MPU6050 module.

.. list-table:: 
   :align: center

   * -  Schematic diagram
   * -  |Chapter17_02|
   * -  Hardware connection 
     
        If you need any support, please feel free to contact us via: support@freenove.com

   * -  |Chapter17_03|

.. |Chapter17_02| image:: ../_static/imgs/17_Acceleration_sensor/Chapter17_02.png
.. |Chapter17_03| image:: ../_static/imgs/17_Acceleration_sensor/Chapter17_03.png

Sketch
==========================

Sketch Acceleration_Detection
------------------------------------------------------

As we use the I2C interface to read the gyrpscope's data, we need to install the related library before use.

Open Arduino IDE, click **"Sketch"** -> **"Include Library"** -> **"Add.ZIP Library..."**

.. image:: ../_static/imgs/17_Acceleration_sensor/Chapter17_04.png
    :align: center

Click **"Libraries"**, then select **"IMU_Fusion_SYC_v1.2.1.zip"**.

.. image:: ../_static/imgs/17_Acceleration_sensor/Chapter17_05.png
    :align: center

Or, you can search Adafruit_MPU6050 on library manager to install.

Now write sketch to communicate with the MPU6050 module and send the collected data to Serial Monitor window

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_17.1.1_Acceleration_Detection/Sketch_17.1.1_Acceleration_Detection.ino
    :linenos: 
    :language: c
    :dedent:

Include the necessary libraries.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_17.1.1_Acceleration_Detection/Sketch_17.1.1_Acceleration_Detection.ino
    :linenos: 
    :language: c
    :lines: 8-8
    :dedent:

Initialize the sensor object. The IMU_Fusion_SYC library provides the IMU class to operate the MPU6050.

Before using it, you need to instantiate an object of the class.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_17.1.1_Acceleration_Detection/Sketch_17.1.1_Acceleration_Detection.ino
    :linenos: 
    :language: c
    :lines: 10-10
    :dedent:

MPU6050 initialization.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_17.1.1_Acceleration_Detection/Sketch_17.1.1_Acceleration_Detection.ino
    :linenos: 
    :language: c
    :lines: 16-16
    :dedent:

MPU6050 self-calibration.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_17.1.1_Acceleration_Detection/Sketch_17.1.1_Acceleration_Detection.ino
    :linenos: 
    :language: c
    :lines: 17-17
    :dedent:

Read acceleration, gyroscope from the MPU6050 and print them to the serial monitor

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_17.1.1_Acceleration_Detection/Sketch_17.1.1_Acceleration_Detection.ino
    :linenos: 
    :language: c
    :lines: 22-43
    :dedent:

Verify and upload the code, open the Serial Monitor, then you can see the value of MPU6050 in original state and converted state, which is sent from control board. Rotate and move the MPU6050 module, and then you can see the change of values.

.. image:: ../_static/imgs/17_Acceleration_sensor/Chapter17_07.png
    :align: center

If you are unfamiliar with accelerometer and gyroscope data, the readings may not be immediately intuitive.

For better visualization, you can upload Sketch 17.1.2, which provides real-time angle outputs for all three axes.

:red:`Troubleshooting Tip: If the MPU6050 module fails to initialize (as shown in the image below), try the following steps:`

:red:`1. Reconnect the USB cable - Unplug and replug it securely.`

:red:`2. Check jumper wire connections - Ensure all jumper wires are firmly seated and well contacted.`

.. image:: ../_static/imgs/17_Acceleration_sensor/Chapter17_08.png
    :align: center