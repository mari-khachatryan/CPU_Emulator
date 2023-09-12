# CPU_Emulator
# Simple CPU Simulator

The Simple CPU Simulator is a minimalistic CPU simulation project with components for simulating a CPU, Arithmetic Logic Unit (ALU), parsing, and command validation. It supports assembly-like operations including move, add, subtract, multiply, divide, logical AND, logical OR, jump (jmp), and more. This project allows users to write code in a text file, which can then be compiled and executed using the provided `main.cpp` program.

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Writing Code](#writing-code)
- [Contributing](#contributing)

## Getting Started
### Prerequisites

Before you can use the Simple CPU Simulator, ensure you have the following dependencies installed on your system:

- C++ compiler (e.g., g++)
- Any necessary development libraries or tools

### Installation

1. Clone this repository to your local machine:

   ```bash
   git clone git@github.com:mari-khachatryan/CPU_Emulator.git
  
Compile the project:
g++ main.cpp -o cpu_simulator (or g++ main.cpp)

## Usage
To run the Simple CPU Simulator, execute the compiled program (cpu_simulator) from the command line:
./cpu_simulator               (or ./a.out)

## Writing Code
To write code for the simulator, you can create a text file (e.g., code.txt) or use test.txt which already exists in the code and follow the assembly-like syntax for the supported operations. Here's an example of a code file:
; Sample code file (code.txt)

; Initialize registers
R0 = 10
R1 = 5

; Perform arithmetic operations

add R0, 20 ; Add 20 to R0
sub R1, 3  ; Subtract 3 from R1
mul R0, R1 ; Multiply R0 by R1
div R0, 2  ; Divide R0 by 2

; Perform logical operations
and R1, 1  ; Perform logical AND with 1
or R0, 7   ; Perform logical OR with 7

; Jump to a label
jmp label1

label1:
; Code continues here

## Contributing
Contributions are welcome! If you'd like to contribute to this project, please follow the contribution guidelines.
