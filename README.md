# Technical Assignment # 1
This project demonstrates how to use an ESP8266 microcontroller to read data from an ultrasonic sensor (HC-SR04) and send it to a local server using the HTTP REST API (POST method). 
The local server is implemented using Python's Flask framework, which receives the sensor data and responds accordingly.
![Gambar WhatsApp 2024-06-15 pukul 00 10 19_bfb9ff64](https://github.com/sahikjaman/nodemcu/assets/79184185/b4f3ce89-d767-4fa9-a2c4-6e0477da5841)

# Physical Setup
1. Assemble the Components by placing the ESP8266 on the breadboard then connect the HC-SR04 sensor to the ESP8266 using jumper wires.
2. Ensure all connections are secure.

# Running the Project
1. Upload the Arduino code to your ESP8266:
- Open the Arduino IDE.
- Configure the correct board and port.
- Upload the code to the ESP8266.
2. Start the Local Server:
- Save the Python code to a file (e.g., server.py).
- Run the server using the command: python server.py.
3. Monitor the ESP8266 Serial Output:
- Open the Serial Monitor in the Arduino IDE to see the distance readings and HTTP response from the server.

# Notes :
Ensure the ESP8266 is connected to a stable WiFi network.
Adjust the server address in the Arduino code to match your local server's IP address and port.
The delay in the loop() function can be adjusted based on how frequently you want to read and send the sensor data.
