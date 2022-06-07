# Environment Setup

## What you need

### Personal computer

This is required as the Suncorp laptops are very locked down and you will need to be able to connect your EduKit to your computer to upload code, monitor output etc.

**Please remember that if your device does not have a standard USB-A port, you are required to bring a USB-C to USB-C Male to Male cable to connect the device to your computer**

### Drivers

Some windows users may face issues around correctly connecting and uploading their device for the workshop. Pre-requeisite drivers may be required for the device to function.

Go to https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers and download the driver most appropriate for your system you are running.

### Visual Studio Code (REQUIRED)

Go here https://code.visualstudio.com/download and download the appropriate version of Visual Studio Code for your device

### PlatformIO extension (REQUIRED)

1. Open Visual Studio Code and click on the extensions icon
2. Search for "PlatformIO"
3. Click "Install"
4. VSCode may need to restart after you install this

![VSCode_Extensions](/Workshop/1.%20Environment%20Setup/VSCode_Extensions.png)

### Github

We have stored all our sample code on Github at https://github.com/MChoc/Sensorthon.

Experience with Git and Github will be helpful for you when navigating and using our sample code. After cloning the repository, you will need to open each folder separately via the PlatformIO homepage in VSCode to allow the PlatformIO extensions to detect the project.

If you know how to use Git, clone the repo to your local. Else, go to the above github link and download the file as a zip and unzip it.
![Github](/Workshop/1.%20Environment%20Setup/Github.png)

## Determining your device

1. Click on the PlatformIO icon in the side bar
2. Click "Open" on the PlatformIO menu
3. Click "Devices" on the PlatformIO homepage
4. To determine which port your device is located at, you can disconnect your device, click refresh and then reconnect your device to see what the differences are. In the below example, the device is shown as ***/dev/cu.SLAB_USBtoUART***. This will vary according to your device. The name of this port will be important when uploading your program to the device.
![PlatformIO_Devices](/Workshop/1.%20Environment%20Setup/PlatformIO_Devices.png)

## Opening a project

1. Click on the PlatformIO extension icon
2. Open the PlatformIO homepage
3. Click on "Home"
4. Click on "Open Project" and navigate to where you created/saved your project and open one of the examples
![PlatformIO_Open_Project_1](/Workshop/1.%20Environment%20Setup/PlatformIO_Open_Project_1.png)
![PlatformIO_Open_Project_2](/Workshop/1.%20Environment%20Setup/PlatformIO_Open_Project_2.png)
5. After opening the project, ensure that PlatformIO has been able to detect your project by checking that the name in brackets after "Default" is the name of your project
6. Ensure that before running tasks the name of the tasks is the same as defined in your "platformio.ini" file
![PlatformIO_Open_Project_3](/Workshop/1.%20Environment%20Setup/PlatformIO_Open_Project_3.png)

## Building and running

PlatformIO will define a list of tasks that you can simply and run
1. Open the PlatformIO menu in the side bar
2. Look for "PROJECT TASKS"
3. Expand the m5stack-core2 tab
![PlatformIO_Tasks](/Workshop/1.%20Environment%20Setup/PlatformIO_Tasks.png)

Useful tasks
* Build - builds and compiles the project, used mostly to validate your program is valid
* Upload - upload and builds the project to your device
* Monitor - connect to your device and monitor the Serial output
* Upload and Monitor - a combined of the Upload and Monitor tasks
* Clean - deletes your build
* Clean All - deletes your build and all builds in dependency builds
* Erase Flash - deletes the current program from your device

When building/uploading you may encounter the below error. This safe to ignore and close.
![Error](/Workshop/1.%20Environment%20Setup/Error.png)

## Creating a new project

1. Select the PlatformIO icon on the side bar of VSCode
2. Click open on the PlatformIO menu
3. Click "New Project"
![PlatformIO_Project_1](/Workshop/1.%20Environment%20Setup/PlatformIO_Project_1.png)
4. Give your project a name
5. Choose M5Stack Core2 for the Board (if there are multiple just choose any one)
6. Choose the Arduino Framework
7. Choose a location to save the project
![PlatformIO_Project_2](/Workshop/1.%20Environment%20Setup/PlatformIO_Project_2.png)

## Downloading other libraries

### Via PlatformIO

1. Click the PlatformIO icon
2. Click open to bring up the PlatformIO interface
3. Click on "Libraries"
4. Search for the library you need
![PlatformIO_Libraries](/Workshop/1.%20Environment%20Setup/PlatformIO_Libraries.png)

### Manually

1. Unzip the library you have downloaded
2. Move the folder into the lib folder
3. VSCode may not immediately recognise your library but after you run build once, it should be able to provide all the features of IntelliSense
```
project
|   include
└───lib
|   └───MyDownloadedLibrary
|       |   examples
|       |   README.md
|       └───src
|           |   MyDownloadedLibrary.h
|           |   MyDownloadedLibrary.c
|   src
|   test
```
