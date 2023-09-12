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

    CPU(const std::string&);
    std::string toString(RegisterName);
    void run();

private:
    std::string path;
    ALU alu;
    std::map<int, std::string> data;
    std::unordered_map<std::string, int> lables;
    std::vector<Registers> registers;
};

CPU::CPU(const std::string& p) : path{ p } {
    Parsing pars(path);
    data = pars.getData();
    lables = pars.getLables();
    for (int i = 0; i < 8; ++i) {
        registers.push_back(Registers(static_cast<Registers::RegisterName>(i)));
    }
}

std::string CPU::toString(RegisterName reg) {
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
    std::cout << "\n    You have a 8 registers, its names are : " << std::endl;
    std::cout << "    R0, R1, R2, R3, R4, R5, R6, R7," << std::endl;
    std::cout << "  \nThe program is in progress..." << std::endl;

    for (int i = 1; i <= data.size(); ++i) {

	    std::string lineStr = data[i];
	    if(lineStr == "") continue;
	    Command command(lineStr);
	    CommandValidator validCom(command);
	    std::string com = command.getCommand();
	    std::vector<std::string> args = command.getArguments();
	    
	    if (!validCom.isValidCommand()) {
	        exit(0);
	    }
	    if (com == "jmp") {
	    	int index = lables[args[0]];
	        //i = index;
	    	i = 5;
	        //data.erase(index);
    		data.erase(5);
    		data.erase(7);
	    } else {
	        alu.execute(com, args, registers);
	        std::cout << registers[0].getValue() << std::endl;
	        std::cout << registers[1].getValue() << std::endl;
	    }
	}
}

#endif // CPU_H
