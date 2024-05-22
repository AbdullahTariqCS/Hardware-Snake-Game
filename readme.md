# Hardware Snake Game

Welcome to the Hardware Snake Game project! This repository showcases a unique approach to recreating the classic Snake game using only fixed logic and fundamental non-programmable integrated circuits (ICs). By exploring the potential of sequential circuits, this project emphasizes the foundational principles of digital electronics and innovative solutions within constraints.

## Project Overview

This project was undertaken by:
- Abdullah Tariq, Faculty of Computer Science
- Hasan Abbas, Faculty of Computer Science
- Muhammad Murtaza, Faculty of Computer Science

### Abstract

The primary goal of this project is to demonstrate the capability of sequential circuits to execute complex tasks like the Snake game. Detailed herein are the designs and implementations of each sub-circuit, both simulated in Proteus and realized in hardware. Key components include shift registers, multiplexers, demultiplexers, adders, and counters.

## Introduction

Traditional implementations of the Snake game often use a microcontroller interfaced with a display. In contrast, this project aimed to recreate the game logic using fundamental non-programmable ICs. This not only highlights resourcefulness but also reinforces the basic principles of digital electronics, making it an intriguing study in minimalist hardware design.

## Methodology

The project followed a ground-up approach, developing every aspect from scratch while referencing the operations of integrated circuits. The process involved conceptualization, component selection, circuit design, simulation, and physical implementation on breadboards.

## Project Structure

The project is divided into four main sub-circuits:

1. **Input Direction**
2. **Movement Processing**
3. **Length Calculation**
4. **Output Display (4x4 LED matrix)**

### Input Direction

#### Fixed Logic Design in Simulation

- **Components**:
  - Toggle switches (Up, Down, Left, Right)
  - D-latches (7474)
  - 4-input OR Gate (4072)

- **Working**:
  Toggle switches allow users to direct the snake. D-latches store the state of each direction, interfacing with the movement calculation circuit to determine the snake's next position.

- **Simulation Results**:
  The design was successfully simulated in Proteus, accurately capturing user inputs.

#### Hardware Implementation (with Arduino)

- **Components**:
  - Arduino Uno
  - Joystick Module
  - De-multiplexer (SN74LS139)

- **Working**:
  The joystick updates a direction variable, which is converted to binary and processed by a de-multiplexer to control the snake's direction.

### Movement Processing

#### Fixed Logic Design in Simulation

- **Components**:
  - 4-bit Universal Shift Registers (SN74LS95)
  - Multiplexers, Adders, Counters, De-Multiplexers

- **Working**:
  Coordinates of the snake are stored in shift registers. Movement is processed using counters and multiplexers to update the snake's position.

#### Hardware Implementation

- **Components**:
  - Shift Registers
  - Arduino Uno

- **Working**:
  Movement processing was partly implemented with Arduino to avoid synchronization issues.

### Length Calculation

#### Fixed Logic Design in Simulation

- **Components**:
  - D-Latches, De-Multiplexers, Counters, Comparators, AND, OR, NOT Gates

- **Working**:
  The length of the snake is controlled using D-latches and counters. The length increases when a fruit is detected.

### Output Display

#### Fixed Logic Design in Simulation

- **Components**:
  - De-Multiplexers, NOR Gates, OR Gates

- **Working**:
  The display module converts snake coordinates into a 4x4 matrix for real-time game visualization.

#### Hardware Implementation (with Arduino)

- **Components**:
  - Shift Registers
  - Arduino Uno
  - 4x4 LED Matrix

- **Working**:
  The coordinates are processed and displayed using a 4x4 LED matrix controlled by Arduino.

## Components Used

- **Shift Registers**: Store coordinates and expand output pins.
- **Multiplexer/Demultiplexer**: Select and route signals.
- **Adders**: Perform arithmetic operations.
- **Arduino Uno**: Main controller for processing and control.
- **Breadboard**: Platform for circuit integration.
- **Joystick Module**: Captures user input.
- **4x4 LED Matrix**: Visual display for the game.
- **Wiring and Connectors**: Establish connections between components.

## Implementation

Detailed schematics and images of the Proteus simulations and hardware implementations are provided in the project documentation.

## Conclusion

This project demonstrates the potential and versatility of non-programmable ICs in achieving complex tasks. It serves as both an educational tool and a testament to the ingenuity of minimalist hardware design.

For more detailed information, schematics, and code, please refer to the complete project documentation.

---

**Project Link**: [GitHub Repository](https://github.com/AbdullahTariqCS/Hardware-Snake-Game)

---

Feel free to explore, contribute, and provide feedback. Enjoy the journey through the fundamentals of digital design!