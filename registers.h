#ifndef REGISTERS_H
#define REGISTERS_H

#include "CPU.h"
#include <iostream>
#include <string>
#include <map>

class Registers {
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

    Registers(RegisterName);
    Registers(int, const std::string&);
    std::string getRegisterName() const;
    int getValue() const;
    void setValue(int);
    void setName(const std::string&);
    static std::string toString(RegisterName);
    void print() const;

private:
    RegisterName registerName;
    int value;
    std::string name;
    static const std::map<RegisterName, std::string> RegisterNameMap;
};


const std::map<Registers::RegisterName, std::string> Registers::RegisterNameMap = {
    {RegisterName::R0, "R0"},
    {RegisterName::R1, "R1"},
    {RegisterName::R2, "R2"},
    {RegisterName::R3, "R3"},
    {RegisterName::R4, "R4"},
    {RegisterName::R5, "R5"},
    {RegisterName::R6, "R6"},
    {RegisterName::R7, "R7"}
};

Registers::Registers(RegisterName regName) : value{0}, name(RegisterNameMap.at(regName)) {}

Registers::Registers(int v, const std::string& n) : value{v}, name{n} {}

std::string Registers::getRegisterName() const {
    return name;
}

int Registers::getValue() const {
    return value;
}

void Registers::setValue(int v) {
    value = v;
}

void Registers::setName(const std::string& n) {
    name = n;
}

std::string Registers::toString(RegisterName reg) {
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

void Registers::print() const {
    std::cout << "Register Name: " << name << ", Value: " << value << std::endl;
}

#endif // REGISTERS_H