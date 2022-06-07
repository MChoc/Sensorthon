# Device Registration

1. Log in to your AWS account and make sure you are in the Sydney (ap-southeast-2) region
2. Search for IoT Core in the search bar
3. Click the "IoT Core" option under "Services'
![IoT_Core](/Workshop/2.%20Device%20Registration/IoT_Core.png)
4. Click on the "Manage" link
5. Click "Create thing"
![IoT_Core_Manage](/Workshop/2.%20Device%20Registration/IoT_Core_Manage.png)
6. Give your thing the name in the format "EduKit_TEAMNAME", replaceing TEAMNAME with your teams name you used to register. Leave all other options as default
7. Click next
![Register_Thing_Name](/Workshop/2.%20Device%20Registration/Register_Thing_Name.png)
8. Choose "Auto-generate a new certificate"
9. Click next
![Register_Thing_Certificate](/Workshop/2.%20Device%20Registration/Register_Thing_Certificate.png)
10. Check the provided Sensorthon_EduKit_Policy
11. Click "Create thing"
![Register_Thing_Policy](/Workshop/2.%20Device%20Registration/Register_Thing_Policy.png)
12. Download all 5 certificates and save them in the MQTT folder at the root of this project (these will be needed later to communicate securely with AWS IoT Core). When downloading, rename the certificates according to the naming scheme below. We will be referring to them by these names in further workshops.
![Certificates](/Workshop/2.%20Device%20Registration/Certificates.png)
13. Open the MQTT folder in Sensorthon via PlatformIO using the same method you learned before. Open the include folder and you should see a file called secrets_template.h. Rename this or make a copy then rename to secrets.h and fill in the file (https://github.com/MChoc/Sensorthon/blob/main/MQTT/include/secrets_template.h). **Follow the comments to determine which certificate to copy to each line of code**
14. Build and upload this program to your EduKit using the same method you've learned before.

# AWS MQTT Test Client

## Subscribe

1. Click the "MQTT test client"
2. Click on the "Subscribe to a topic" tab
3. The topic filter field will define what topics/urls to subscribe and listen to
    1. \# - this is called the "wildcard" and will listen to ALL topics
    2. In the given MQTT example the topic that the AWS device will publish to is "EduKit_TEAMNAME/pub"
4. Click subscribe to start listening to that topic
5. The topic you defined above will appear as a an option that you can click
6. The messages sent from the device will then show up here
![AWS_Subscribe](/Workshop/2.%20Device%20Registration/AWS_Subscribe.png)

## Publish

1. Click on "Publish to a topic"
2. Enter the topic name - in the MQTT example the topic that the device will listen to is "EduKit_TEAMNAME"
3. Define a payload/message that will be sent to the device. This should be in the format of a JSON
4. Click publish to push the message to the device
![AWS_Publish](/Workshop/2.%20Device%20Registration/AWS_Publish_1.png)
5. The message should print to the console is you are monitoring the device. In the MQTT example we send true or false on the "LED" field to toggle the green LED on the device
![AWS_Publish](/Workshop/2.%20Device%20Registration/AWS_Publish_2.png)
