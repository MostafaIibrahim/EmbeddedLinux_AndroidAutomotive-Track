# Task Description
Create two services: the first service should print a string to the standard output, and the second service should ping Google. The second service must be dependent on the first service, meaning it should only start after the first service is running. Let's determine how to implement this dependency.
### Step 1: Define the first service
- Create service under etc/systemd/system directory
![CREATE_service](CRF1.png)
- Write your service named print_S.service
![alt text](2266.png)
- Write the runnable script
![alt text](2288.png)

### Step2: Define the second service
![alt text](22445.png)
-Write runnable script
![alt text](2277.png)

- Make both scripts executable

------------------------------------------------------------------------------------------------

- Reload daemon services 
```
sysetmctl daemon_reload
```
- Run systemctl status for both tasks
![alt text](SYS1.png)
![alt text](2331.png)

- Start both services by systemctl start 
![alt text](123231.png)
![alt text](223.png)