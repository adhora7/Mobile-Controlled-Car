# Mobile Controlled Rover

**Project Overview**:
This project demonstrates a **Mobile Controlled Rover** using **Arduino** and a **Bluetooth module (HC-05)**. The car is controlled remotely using a **mobile app** that I developed using **MIT App Inventor** specifically for this project. The Bluetooth module communicates with the Arduino to control the movement of the car through the **L293D motor shield**. The car can move forward, backward, and turn left or right based on the commands sent via Bluetooth.

## Components Required:
### <h4>Components required in this module:</h4>
<ol>
  <li><p>Arduino (e.g., Arduino Uno)</p></li>
  <li><p>Motor Shield L293D</p></li>
  <li><p>Chassis Set</p></li>
  <li><p>Jumper Wires</p></li>
  <li><p>Bluetooth Module (HC-05)</p></li>
  <li><p>PC</p></li>
  <li><p>Arduino Cable</p></li>
</ol>

### System Diagram:
![Mobile Controlled Rover](./Project_Photo_and_Video/Car.jpg)

**Figure 1**: The system setup with the Arduino, motor shield, Bluetooth module, and chassis.

## Working Principle:
The rover operates through Bluetooth communication between the **Arduino** and the **mobile device**. The mobile app, which I developed using **MIT App Inventor**, sends control signals to the **HC-05 Bluetooth module**, which then communicates with the Arduino. The Arduino processes these signals and drives the motors accordingly using the **L293D motor shield**.

### Features:
- **Mobile Control**: I developed a custom mobile app using **MIT App Inventor** to control the rover’s movement.
- **Bluetooth Communication**: The mobile app communicates wirelessly with the rover using the **HC-05 Bluetooth module**.
- **Arduino-based Motor Control**: The **L293D motor shield** is used to control the car’s motors, which allows it to move forward, backward, and turn.

## MIT App Inventor:
The mobile app used to control the rover was created using **MIT App Inventor**, a visual programming platform. I built the app specifically for this project to send Bluetooth commands to the Arduino for controlling the rover's movement. The app includes buttons for controlling the car’s direction (forward, backward, left, right).

### How I Built the Mobile App:
1. **MIT App Inventor**: Go to [MIT App Inventor](https://appinventor.mit.edu/) and create a new project.
2. **App Design**: I added buttons for controlling the rover's movement (e.g., "Forward", "Backward", "Left", "Right").
3. **Bluetooth Setup**: I set up the Bluetooth communication in the app to pair with the **HC-05 Bluetooth module**.
4. **Block Editor**: I used the block editor to program the logic for each button, which sends the appropriate Bluetooth command (e.g., "f" for forward, "b" for backward).

## Code Explanation:
The Arduino code listens for Bluetooth commands and drives the motors based on the received signals. The mobile app processes the commands and sends the corresponding Bluetooth signal.

```cpp
// Arduino code for controlling the mobile-controlled rover
// Code for controlling the rover with Bluetooth commands (forward, backward, left, right, stop)













































