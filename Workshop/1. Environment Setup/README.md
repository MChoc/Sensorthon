# Environment Setup

## What you need

### Personal computer

This is required as the Suncorp laptops are very locked down and you will need to be able to connect your EduKit to your computer to upload code, monitor output etc.

### Visual Studio Code

Go here https://code.visualstudio.com/download and download the appropriate version of Visual Studio Code for your device

### PlatformIO extension

1. Open Visual Studio Code and click on the extensions icon
2. Search for "PlatformIO"
3. Click "Install"
4. VSCode may need to restart after you install this

![VSCode_Extensions](/Workshop/1.%20Environment%20Setup/VSCode_Extensions.png)

### Github

We have stored all our sample code on Github at https://github.com/MChoc/Sensorthon.

Experience with Git and Github will be helpful for you when navigating and using our sample code. After cloning the repository, you will need to open each folder separately in VSCode to allow the PlatformIO extensions to detect the project.

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

## Determining your device

1. Click on the PlatformIO icon in the side bar
2. Click "Open" on the PlatformIO menu
3. Click "Devices" on the PlatformIO homepage
4. To determine which port your device is located at, you can disconnect your device, click refresh and then reconnect your device to see what the differences are. In the below example, mine is /dev/cu.SLAB_USBtoUART. This will be important when uploading your program to the device.
![PlatformIO_Devices](/Workshop/1.%20Environment%20Setup/PlatformIO_Devices.png)

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