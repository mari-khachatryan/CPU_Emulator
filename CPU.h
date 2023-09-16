#ifndef CPU_H
#define CPU_H

#include "ALU.h"
#include "commandValidator.h"
#include "command.h"
#include "parsing.h"
#include "registers.h"
#include <iostream>
#include <map>
#include <unordered_map>

class CPU {
public:
    // Enum for register names
    enum class RegisterName {
        R0,
        R1,
        R2,
        R3,
        R4,
        R5,
        R6,
        R7,
    };

    // Constructor that takes a file path
    CPU(const std::string&);

    // Function to convert RegisterName enum to string
    std::string toString(RegisterName);

    // Function to start executing the program
    void run();

private:
    std::string path;              // File path to program code
    ALU alu;                       // Arithmetic Logic Unit
    std::map<int, std::string> data;            // Program code storage
    std::unordered_map<std::string, int> lables; // Labels storage
    std::vector<Registers> registers;           // Registers
};

CPU::CPU(const std::string& p) : path{ p } {
    // Parse the program code and initialize data and labels
    Parsing pars(path);
    data = pars.getData();
    lables = pars.getLables();

    // Initialize registers
    for(const auto& pair: lables) {
        std::cout << "Label: " << pair.first << " Line: " << pair.second << std::endl;
    }
    for (int i = 0; i < 8; ++i) {
        registers.push_back(Registers(static_cast<Registers::RegisterName>(i)));
    }
}

std::string CPU::toString(RegisterName reg) {
    // Convert RegisterName enum to string
    switch (reg) {
    case RegisterName::R0: return "R0";
    case RegisterName::R1: return "R1";
    case RegisterName::R2: return "R2";
    case RegisterName::R3: return "R3";
    case RegisterName::R4: return "R4";
    case RegisterName::R5: return "R5";
    case RegisterName::R6: return "R6";
    case RegisterName::R7: return "R7";
    }
    return "";
}

void CPU::run() { 
    std::cout << "\nYou have 8 registers: R0, R1, R2, R3, R4, R5, R6, R7," << std::endl;
    std::cout << "The program is in progress..." << std::endl;

    // Loop through each line of the program code
    for (int i = 1; i <= data.size(); ++i) {

        std::string lineStr = data[i];
        if(lineStr == "") continue;

        // Parse the current line into a Command object
        Command command(lineStr);
        CommandValidator validCom(command);
        std::string com = command.getCommand();
        std::vector<std::string> args = command.getArguments();
        int lineNum = i;

        // Check if the command is valid
        if (!validCom.isValidCommand()) {
            exit(0); // Exit the program if the command is not valid
        }

        // Execute the command based on its type
        if (com == "jmp") {
            // Handle jump (jmp) command
            args[0].pop_back(); // Remove the colon from the label
            int index = lables[args[0]]; // Get the line number of the label
            i = index; // Jump to the specified line
            data.erase(index); // Remove the label line from execution
            data.erase(lineNum); // Remove the current line
        } else {
            // Execute other arithmetic or logic commands using the ALU
            alu.execute(com, args, registers);
            
            // Print the values of specific registers (for debugging)
            std::cout << "Value of " << toString(RegisterName::R0) << ": " << registers[0].getValue() << std::endl;
            std::cout << "Value of " << toString(RegisterName::R1) << ": " << registers[1].getValue() << std::endl;
            // ... Repeat for other registers if needed
        }
    }
}


#endif // CPU_H
