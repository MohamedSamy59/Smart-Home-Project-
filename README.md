# Smart Home Embedded System Project

Welcome to the **Smart Home Embedded System** project! This project demonstrates how embedded systems can be used to create a smart home environment by controlling and monitoring various aspects such as lighting, security, temperature, and fire detection. The project is designed using Proteus 8 Professional, showcasing the integration of sensors, actuators, and microcontrollers into a functional smart home system.

## Project Overview

The Smart Home project aims to simulate a modern, automated home where different subsystems are managed through a central control unit. The system includes:

- Room-specific lighting controls
- A fire detection and alarm system
- Temperature monitoring
- Secure garage door operation

This project exemplifies how embedded systems can be applied to improve home automation, safety, and energy efficiency.

### Features

- **Room Lighting Control:** Each room has an independent lighting system, which can be controlled and monitored through a central interface.
- **Fire Alarm System:** Equipped with a flame sensor, the system automatically triggers an alarm in case of fire detection.
- **Temperature Monitoring:** The system includes temperature sensors to monitor the ambient conditions of various rooms.
- **Garage Door Control:** The garage door can be securely operated through the embedded system, offering both convenience and security.

## System Components

### Hardware Components

- **Microcontroller (PIC18F46K20):** Acts as the brain of the system, handling all operations, inputs, and outputs.
- **Sensors:**
  - **Flame Sensor:** Detects fire or extreme heat and triggers the fire alarm system.
  - **Temperature Sensor (LM35):** Continuously monitors the temperature within each room and provides data to the control unit.
- **Actuators:**
  - **Buzzer:** Sounds an alarm when the flame sensor detects fire, providing an auditory alert.
  - **Motor Driver (L293D):** Controls the garage door motor, allowing it to open and close based on commands from the system.
- **Bluetooth Module (HC-05):** Facilitates wireless communication, allowing remote control and monitoring of the system.
- **LCD Display:** Displays real-time data such as temperature readings and system status messages.

### Software

- **Proteus 8 Professional:** Used for designing, simulating, and testing the entire smart home system before physical implementation.

## How It Works

1. **Room Lighting Control:**
   - Each room is equipped with lighting that can be controlled by the central microcontroller.
   - The control unit sends signals to the lights in response to user commands, enabling on/off control.

2. **Fire Detection:**
   - The flame sensor constantly monitors for any signs of fire.
   - Upon detecting a fire, the system immediately triggers the buzzer and can be configured to take additional safety measures, such as cutting off power to certain parts of the home.

3. **Temperature Monitoring:**
   - Temperature sensors in each room provide real-time data to the microcontroller.
   - The data is displayed on the LCD screen, allowing the user to monitor the ambient temperature and set alerts if temperatures go beyond a predefined range.

4. **Garage Door Control:**
   - The garage door is operated using a motor controlled by the L293D motor driver.
   - The user can open or close the garage door remotely via the Bluetooth module, enhancing convenience and security.

## Schematic

![Smart Home Schematic](path/to/your/image.png)

This schematic provides a detailed view of the entire Smart Home system, showing the connections between the microcontroller, sensors, actuators, and other components.


## Future Enhancements

- **IoT Integration:** Incorporate Internet of Things (IoT) capabilities to allow remote monitoring and control via a mobile app or web interface.
- **Voice Control:** Add voice command functionality for hands-free control of the smart home environment.
- **Energy Management:** Implement smart energy management features, optimizing power usage based on real-time data.

## Contributing

Contributions are welcome! If you have suggestions or improvements, feel free to submit a pull request or open an issue.

---

Feel free to adjust the details further based on the exact features and functionality of your project!
