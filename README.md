# Multi-Robot System

## Overview
This project implements a **multi-robot system** consisting of **6 robots**, each equipped with **Mecanum wheels**, enabling omnidirectional movement.  
The system is designed for coordinated motion and formation control between multiple robots.

A **computer vision system** is used to track and identify each robot in real time. A camera detects **AprilTags (tag16h5 family)** placed on top of each robot, allowing the system to recognize their positions and orientations.

---

##  Features
- Coordination of **6 robots** in a shared environment  
- Omnidirectional movement using **Mecanum wheels**  
- Real-time robot detection using **AprilTags (tag16h5)**  
- Position and orientation tracking via camera  
- Wireless communication between robots using **nRF24L01**  
- Centralized control through a computer  

---

##  System Architecture
The system consists of three main components:
- **Robots:** Each robot includes an Arduino Uno, motor driver, and nRF module  
- **Vision System:** Camera + AprilTag detection for localization  
- **Control Unit:** Computer running Python for processing and decision-making  

---

##  Software Structure
The project is divided into **three main codes**:

1. **Python Code (Central Controller)**  
   - Handles AprilTag detection using the camera  
   - Computes robot positions and orientations  
   - Generates control commands for all robots  

2. **Arduino Code (Robot Side)**  
   - Uploaded to each robot’s Arduino Uno  
   - Controls motors and executes received commands  

3. **Transmitter Code (also arduino) (nRF Module)**  
   - Acts as a **central transmitter**  
   - Sends control data wirelessly to all robots  
   - Communicates with the nRF modules on each robot  

---

## 🔩 Hardware
- 6 × Robot platforms (Mecanum wheels + DC motors)  
- Arduino Uno (one per robot)  
- nRF24L01 modules (one per robot + one central transmitter)  
- USB camera  
- AprilTags (**tag16h5 family**) mounted on each robot  

---

## 🧰 Software & Tools
- Python (OpenCV, apriltag, numpy, pyserial)  
- Arduino IDE  
- Serial communication  

---

## 📸 Demo (pics and videos of the final result)
 ![1c46176b-e96d-4f85-8c87-fb7a06fd406c](https://github.com/user-attachments/assets/9327528a-3a3d-4720-922f-87a3bea7748f)

 video links: 
 https://youtu.be/gWvH3oarOw4
 https://youtu.be/p_ECw-n_ZIg
 https://youtu.be/rD1lK1Pv0eA

---


## 👩‍💻 Author
**Raghad**  
Robotics Engineer
  

