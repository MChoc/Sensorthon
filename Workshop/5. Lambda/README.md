# Creating a Lambda

1. Search for "Lambda" in the AWS search bar
2. Click on the "Lambda" service
![Lambda_1](/Workshop/5.%20Lambda/Lambda_1.png)
3. Click "Create function"
![Lambda_2](/Workshop/5.%20Lambda/Lambda_2.png)
4. Prefix your lambda function according to your team name as shown in the top right corner of your AWS console along with a dash and a meaningful name
5. You may also choose a different runtime/language. It is recommended to keep it to Node or Python as these environments allow you to edit your code directly from the AWS console. We will be able to provide more extensive support for the Node runtime
6. Click the "Change default execution role" dropdown
7. Click on "Use an existing role"
8. In the search bar search for "participant_lambda_role" and choose that role
9. Click on "Create function"
![Lambda_3](/Workshop/5.%20Lambda/Lambda_3.png)