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
