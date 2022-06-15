# AWS IoT Core Rules Engine

1. Open the IoT Core service and expand the message routing option
2. Click on "Rules"
3. Click "Create rule"
![Rules_1](/Workshop/4.%20Rules/Rules_1.png)
4. Prefix your rule with your team name along with an underscore and give the rule a meaningful name
5. Click "Next"
![Rules_2](/Workshop/4.%20Rules/Rules_2.png)
6. Construct an SQL statement where the table you are selecting from is the name of the topic being published to. The message format will be the exact JSON payload you send from the EduKit with no extra fields. The name of the topic is one that you have defined within your MQTT code. E.g. you could have "EduKit_TEAMNAME/motion/intruder/detected" etc.
7. Click "Next"
![Rules_3](/Workshop/4.%20Rules/Rules_3.png)
8. Choose an AWS service to forward the EduKit message to. In this case I have chosen Lambda where the message can be further processed and forwarded to other services
9. Choose the instance of the service you wish to target
10. Click "Next"
![Rules_4](/Workshop/4.%20Rules/Rules_4.png)
11. Review your rule configuration and when you happy click "Create"
![Rules_5](/Workshop/4.%20Rules/Rules_5.png)
