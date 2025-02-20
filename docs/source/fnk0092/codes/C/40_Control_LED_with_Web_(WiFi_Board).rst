##############################################################################
Chapter Control LED with Web (WiFi Board)
##############################################################################

In this chapter, we will use control board to make a simple smart home. We will learn how to control LED lights through web pages.

Project Control the LED with Web
******************************************************

In this project, we need to build a Web Service and then use the control board to control the LED through the Web browser of the phone or PC. Through this example, you can remotely control the appliances in your home to achieve smart home.

Component List 
=====================================

.. list-table:: 
   :width: 100%
   :align: center

   * -  Control board x1
     -  USB cable x1
   * -  |Chapter40_04|
     -  |Chapter40_05|

.. |Chapter40_04| image:: ../_static/imgs/40_Control_LED_with_Web_(WiFi_Board)/Chapter40_04.png
.. |Chapter40_05| image:: ../_static/imgs/40_Control_LED_with_Web_(WiFi_Board)/Chapter40_05.png
    
Component knowledge
=================================

HTML
------------------------------

HyperText Markup Language (HTML) is a standard Markup Language for creating web pages.It includes a set of tags that unify documents on the network and connect disparate Internet resources into a logical whole.HTML text is descriptive text composed of HTML commands that describe text, graphics, animations, sounds, tables, links, etc.The extension of the HTML file is HTM or HTML.Hyper Text is a way to organize information.It uses hyperlinks to associate words and charts in Text with other information media.These related information media may be in the same Text, other files, or files located on a remote computer.This way of organizing information connects the information resources distributed in different places, which is convenient for people to search and retrieve information.

The nature of the Web is hypertext Markup Language (HTML), which can be combined with other Web technologies (e.g., scripting languages, common gateway interfaces, components, etc.) to create powerful Web pages. Thus, HYPERtext Markup Language (HTML) is the foundation of World Wide Web (Web) programming, that is, the World Wide Web is based on hypertext.   Hypertext Markup Language is called hypertext Markup language because the text contains so-called "hyperlink" points.

You can build your own WEB site using HTML, which runs on the browser and is parsed by the browser.

Example analysis is shown in the figure below:

.. image:: ../_static/imgs/40_Control_LED_with_Web_(WiFi_Board)/Chapter40_00.png
    :align: center

**<!DOCTYPE html>:** Declare it as an HTML5 document

**<html>:** Is the root element of an HTML page

**<head>:** Contains meta data for the document, such as &lt; meta charset="utf-8"&gt; Define the web page encoding format to UTF-8.

**<title>:** Notesthe title of the document

**<body>:** Contains visible page content

**<h1>:** Define a big heading

**<p>:** Define a paragraph

For more information, please visit: https://developer.mozilla.org/en-US/docs/Web/HTML

Circuit
=========================

Connect the board to the computer using the USB cable.

.. image:: ../_static/imgs/7_Timer/Chapter07_01.png
    :align: center

Sketch
===========================

Sketch_40.1.1
-----------------------

.. image:: ../_static/imgs/40_Control_LED_with_Web_(WiFi_Board)/Chapter40_01.png
    :align: center

Upload the code to the control board, open the serial monitor and set the board rate to 115200. After the board connects to WiFi successfully, the IP address will be printed out, as shown below.  

.. image:: ../_static/imgs/40_Control_LED_with_Web_(WiFi_Board)/Chapter40_02.png
    :align: center

When Control Board successfully connects to “ssid_Router”, serial monitor will print out the IP address assigned to Control Board by the router. Access http://192.168.1.26 in a computer browser on the LAN. As shown in the following figure:

.. image:: ../_static/imgs/40_Control_LED_with_Web_(WiFi_Board)/Chapter40_02.png
    :align: center

You can click the corresponding button to control the LED on and off.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_40.1.1_Control_the_LED_with_Web/Sketch_40.1.1_Control_the_LED_with_Web.ino
    :linenos: 
    :language: c
    :lines: 1-117
    :dedent:

Include the WiFi Library header file of Control Board.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_40.1.1_Control_the_LED_with_Web/Sketch_40.1.1_Control_the_LED_with_Web.ino
    :linenos: 
    :language: c
    :lines: 8-8
    :dedent:

Enter correct router name and password.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_40.1.1_Control_the_LED_with_Web/Sketch_40.1.1_Control_the_LED_with_Web.ino
    :linenos: 
    :language: c
    :lines: 10-12
    :dedent:

Set Control Board in Station mode and connect it to your router.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_40.1.1_Control_the_LED_with_Web/Sketch_40.1.1_Control_the_LED_with_Web.ino
    :linenos: 
    :language: c
    :lines: 37-37
    :dedent:

Check whether Control Board has connected to router successfully every 0.5s.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_40.1.1_Control_the_LED_with_Web/Sketch_40.1.1_Control_the_LED_with_Web.ino
    :linenos: 
    :language: c
    :lines: 38-41
    :dedent:

Serial monitor prints out the IP address assigned to Control Board.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_40.1.1_Control_the_LED_with_Web/Sketch_40.1.1_Control_the_LED_with_Web.ino
    :linenos: 
    :language: c
    :lines: 46-46
    :dedent:

Click the button on the web page to control the LED light on and off.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_40.1.1_Control_the_LED_with_Web/Sketch_40.1.1_Control_the_LED_with_Web.ino
    :linenos: 
    :language: c
    :lines: 72-81
    :dedent: