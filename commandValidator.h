#ifndef COMMANDVALIDATOR_H
#define COMMANDVALIDATOR_H


#include "command.h"
#include <map>
#include <algorithm>
#include <regex>
#include <iterator>



class CommandValidator {
public:
    CommandValidator();
    CommandValidator(const Command&);
    bool isValidCommand();
    Command getCommand() const;
    bool isValidRegister(const std::string& reg);
    bool isDigit(const std::string&);
private:
    Command command;
    std::vector<std::string> validCommands = {
        "inc",
        "dec",
        "add",
        "sub",
        "mul",
        "div",
        "logicOr",
        "logicAnd",
        "jmp",
        "print",
        "move"
    };

    std::vector<std::string> validRegisters = {
        "r0",
        "r1",
        "r2",
        "r3",
        "r4",
        "r5",
        "r6",
        "r7"
    };
};



CommandValidator::CommandValidator() = default;

CommandValidator::CommandValidator(const Command& com) : command(com) {}

Command CommandValidator::getCommand() const {
    return command;
}

bool CommandValidator::isValidCommand() {
    std::string commandName = command.getCommand();
    std::vector<std::string> args = command.getArguments();
    
    // Check if it's a label declaration
    if (commandName.size() > 0 && commandName[commandName.size() - 2] == ':') {
        return true;
    }
    bool flag = false;
    for(size_t i = 0; i < validCommands.size(); ++i) {
        if(commandName == validCommands[i]) {
            flag = true;
            break;
        }

    }
    if(!flag) return false;
    if(commandName == "jmp") return true;

    flag = false;
    
    for(size_t j = 0; j < validRegisters.size(); j++) {
        if(args[0] == validRegisters[j]) {
            flag = true;
            break;
        }
    }
    if(!flag) return false;

    flag = false;
    std::string a = args[1];
    if(isDigit(args[1]) || isValidRegister(args[1])) {
            flag = true;
    }
    //if(!flag) return false;
    
    return true;
}


bool CommandValidator::isValidRegister(const std::string& reg) {
    for (const std::string& validReg : validRegisters) {
        if (reg == validReg) {
            return true;
        }
    }
    return false;
}


bool CommandValidator::isDigit(const std::string& str) {
    for(size_t i = 0; i < str.size(); ++i) {
        if(str[i] > 57 && str[i] > 48) {
            return false;
        }
    }
    return true;
}



#endif
