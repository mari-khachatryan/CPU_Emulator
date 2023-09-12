#ifndef ALU_H
#define ALU_H


#include "registers.h"
#include <iostream>
#include <vector>
#include <string>

class ALU {
public:
	ALU() = default;
	void move(Registers&, Registers&);
	void move(Registers&, int); 
	void increment(Registers&);
	void decrement(Registers&);
	void add(Registers&, int);
	void add(Registers&, Registers&);
	void sub(Registers&, int);
	void sub(Registers&, Registers&);
	void mul(Registers&, int);
	void mul(Registers&, Registers&);
	void div(Registers&, int);
	void div(Registers&, Registers&);
	bool logicAnd(Registers&, int);
	bool logicAnd(int, Registers&); 
	bool logicAnd(Registers&, Registers&); 
	bool logicOr(Registers&, int); 
	bool logicOr(int, Registers&); 
	bool logicOr(Registers&, Registers&); 
	void print(const Registers&);
	void execute(const std::string&, const std::vector<std::string>&, std::vector<Registers>&);
	bool isDigit(const std::string&);
private:

// std::map<std::string, std::function<void(ALU&, Registers&, int)>> operationMap;

//    std::function<bool(ALU&, Registers&, int)> logicAndFunction;
//    std::function<bool(ALU&, Registers&, int)> logicOrFunction;
};

void ALU::move(Registers& r1, Registers& r2) {
	r1.setValue(r2.getValue());
}

void ALU::move(Registers& r, int num) {
	r.setValue(num);
}

void ALU::increment(Registers& r) {
	int num = r.getValue() + 1;
	r.setValue(num);
}

void ALU::decrement(Registers& r) {
	int num = r.getValue() - 1;
	r.setValue(num);
} 

void ALU::add(Registers& r, int num) {
	int regVal = r.getValue();
	regVal += num;
	r.setValue(regVal);
}

void ALU::add(Registers& r1, Registers& r2) {
	int regVal1 = r1.getValue();
	int regVal2 = r2.getValue();
	regVal1 += regVal2;
	r1.setValue(regVal1);
}

void ALU::sub(Registers& r, int num) {
	int regVal = r.getValue();
	regVal -= num;
	r.setValue(regVal);
}

void ALU::sub(Registers& r1, Registers& r2) {
	int regVal1 = r1.getValue();
	int regVal2 = r2.getValue();
	regVal1 -= regVal2;
	r1.setValue(regVal1);
}

void ALU::mul(Registers& r, int num) {
	int regVal = r.getValue();
	regVal *= num;
	r.setValue(regVal);
} 

void ALU::mul(Registers& r1, Registers& r2) {
	int regVal1 = r1.getValue();
	int regVal2 = r2.getValue();
	regVal1 *= regVal2;
	r1.setValue(regVal1);
}

void ALU::div(Registers& r, int num) {
	 if (num != 0) {
	    int regVal = r.getValue();
		regVal = regVal / num;
		r.setValue(regVal);
    } else {
        std::cerr << "Division by zero!" << std::endl;
  		exit(0);
    }
}

void ALU::div(Registers& r1, Registers& r2) {
	int regVal1 = r1.getValue();
	int regVal2 = r2.getValue();
  	 if (regVal2 != 0) {
		regVal1 = regVal1 / regVal2;
		r1.setValue(regVal1);
    } else {
        std::cerr << "Division by zero!" << std::endl;
  		exit(0);
    }
}

bool ALU::logicAnd(Registers& r, int num) {
    return r.getValue() && num;
}

bool ALU::logicAnd(int num, Registers& r) {
    return num && r.getValue();
}

bool ALU::logicAnd(Registers& r1, Registers& r2) {
    return r1.getValue() && r2.getValue();
}

bool ALU::logicOr(Registers& r, int num) {
    return r.getValue() || num;
}

bool ALU::logicOr(int num, Registers& r2) {
    return num || r2.getValue();
}

bool ALU::logicOr(Registers& r1, Registers& r2) {
    return r1.getValue() || r2.getValue();
}


void ALU::print(const Registers& r) {
	std::cout << r.getRegisterName() << r.getValue() << std::endl;
}

void ALU::execute(const std::string& command, const std::vector<std::string>& arguments, std::vector<Registers>& reg) {
	if (command == "inc") {
		std::string str = arguments[0];
    	int regIndex = str[1] - '0';
        increment(reg[regIndex]);

    } else if (command == "dec") {
        if (arguments.size() == 1) {
            std::string str = arguments[0];
            int regIndex = str[1] - '0';
            decrement(reg[regIndex]);
        } else {
            std::cerr << "Invalid number of arguments for 'dec' command." << std::endl;
            exit(0);
        } 
    } else if (command == "add") {
    	std::string arg1 = arguments[0];
    	std::string arg2 = arguments[1];
    	int regIndex1 = arg1[1] - '0';
    	if(isDigit(arg2)) {
    		int num = stoi(arg2);
    		add(reg[regIndex1], num);
    	} else {
    		int regIndex2 = arg2[1] - '0';
    		add(reg[regIndex1], reg[regIndex1]);
    	}
    } else if (command == "sub") {
        std::string arg1 = arguments[0];
    	std::string arg2 = arguments[1];
    	int regIndex1 = arg1[1] - '0';
    	if(isDigit(arg2)) {
    		int num = stoi(arg2);
    		sub(reg[regIndex1], num);
    	} else {
    		int regIndex2 = arg2[1] - '0';
    		sub(reg[regIndex1], reg[regIndex1]);
    	}
    } else if (command == "mul") {
        std::string arg1 = arguments[0];
    	std::string arg2 = arguments[1];
    	int regIndex1 = arg1[1] - '0';
    	if(isDigit(arg2)) {
    		int num = stoi(arg2);
    		mul(reg[regIndex1], num);
    	} else {
    		int regIndex2 = arg2[1] - '0';
    		mul(reg[regIndex1], reg[regIndex1]);
    	}
    } else if (command == "div") {
        std::string arg1 = arguments[0];
    	std::string arg2 = arguments[1];
    	int regIndex1 = arg1[1] - '0';
    	if(isDigit(arg2)) {
    		int num = stoi(arg2);
    		div(reg[regIndex1], num);
    	} else {
    		int regIndex2 = arg2[1] - '0';
    		div(reg[regIndex1], reg[regIndex1]);
    	}
    } else if (command == "logicAnd") {
        std::string arg1 = arguments[0];
    	std::string arg2 = arguments[1];
    	int regIndex1 = arg1[1] - '0';
    	if(isDigit(arg2)) {
    		int num = stoi(arg2);
    		logicAnd(reg[regIndex1], num);
    	} else {
    		int regIndex2 = arg2[1] - '0';
    		logicAnd(reg[regIndex1], reg[regIndex1]);
    	}

    } else if (command == "logicOr") {
        std::string arg1 = arguments[0];
    	std::string arg2 = arguments[1];
    	int regIndex1 = arg1[1] - '0';
    	if(isDigit(arg2)) {
    		int num = stoi(arg2);
    		logicOr(reg[regIndex1], num);
    	} else {
    		int regIndex2 = arg2[1] - '0';
    		logicOr(reg[regIndex1], reg[regIndex1]);
    	}
    } else if (command == "move") {
    	if(isDigit(arguments[1])) {
    		std::string arg1 = arguments[0];
        	int regIndex = arg1[1] - '0';
        	int arg2 = stoi(arguments[1]);
    		move(reg[regIndex], arg2);
    	} else {
    		std::string arg1 = arguments[0];
    		int regIndex1 = arg1[1] - '0';
    		std::string arg2 = arguments[1];
    		int regIndex2 = arg2[1] - '0';
    		move(reg[regIndex1], reg[regIndex2]);
    	}
    } else if (command == "print") {
        std::string arg = arguments[0];
        int regIndex = arg[1] - '0';
        print(reg[regIndex]);
    } else {
        std::cerr << "Its a label: " << command << std::endl;
    }
    
}

bool ALU::isDigit(const std::string& str) {
	for(size_t i = 0; i < str.size(); ++i) {
		if(str[i] > 57 && str[i] > 48) {
			return false;
		}
	}
	return true;
}

#endif  //ALU_H



// #ifndef ALU_H
// #define ALU_H


// #include "registers.h"
// #include <iostream>
// #include <vector>
// #include <string>
// #include <functional>

// class ALU {
// public:
// 	ALU();
//     void execute(const std::string&, const std::vector<std::string>&, std::vector<Registers>&);
//     bool isDigit(const std::string&);

// private:

// 	std::map<std::string, std::function<void(ALU&, Registers&, int)>> operationMap;

//     // Define function pointers for logical operations
//     std::function<bool(ALU&, Registers&, int)> logicAndFunction;
//     std::function<bool(ALU&, Registers&, int)> logicOrFunction;


// 	void move(Registers&, Registers&);
// 	void move(Registers&, int); 
// 	void increment(Registers&);
// 	void decrement(Registers&);
// 	void add(Registers&, int);
// 	void add(Registers&, Registers&);
// 	void sub(Registers&, int);
// 	void sub(Registers&, Registers&);
// 	void mul(Registers&, int);
// 	void mul(Registers&, Registers&);
// 	void div(Registers&, int);
// 	void div(Registers&, Registers&);
// 	bool logicAnd(Registers&, int);
// 	bool logicAnd(int, Registers&); 
// 	bool logicAnd(Registers&, Registers&); 
// 	bool logicOr(Registers&, int); 
// 	bool logicOr(int, Registers&); 
// 	bool logicOr(Registers&, Registers&); 
// 	void print(const Registers&);
// };

// ALU::ALU() {
//     // Initialize the operationMap with function pointers for various operations
//     operationMap["move"] = [this](Registers& r1, Registers& r2, int num) { this->move(r1, r2); };
//     operationMap["increment"] = [this](Registers& r) { this->increment(r); };
//     operationMap["decrement"] = [this](Registers& r) { this->decrement(r); };
//     operationMap["add"] = [this](Registers& r1, int num) { this->add(r1, num); };
//     operationMap["sub"] = [this](Registers& r1, int num) { this->sub(r1, num); };
//     operationMap["mul"] = [this](Registers& r1, int num) { this->mul(r1, num); };
//     operationMap["div"] = [this](Registers& r1, int num) { this->div(r1, num); };
//     // ... add more operations as needed
// }

// void ALU::move(Registers& r1, Registers& r2) {
// 	r1.setValue(r2.getValue());
// }

// void ALU::move(Registers& r, int num) {
// 	r.setValue(num);
// }

// void ALU::increment(Registers& r) {
// 	int num = r.getValue() + 1;
// 	r.setValue(num);
// }

// void ALU::decrement(Registers& r) {
// 	int num = r.getValue() - 1;
// 	r.setValue(num);
// } 

// void ALU::add(Registers& r, int num) {
// 	int regVal = r.getValue();
// 	regVal += num;
// 	r.setValue(regVal);
// }

// void ALU::add(Registers& r1, Registers& r2) {
// 	int regVal1 = r1.getValue();
// 	int regVal2 = r2.getValue();
// 	regVal1 += regVal2;
// 	r1.setValue(regVal1);
// }

// void ALU::sub(Registers& r, int num) {
// 	int regVal = r.getValue();
// 	regVal -= num;
// 	r.setValue(regVal);
// }

// void ALU::sub(Registers& r1, Registers& r2) {
// 	int regVal1 = r1.getValue();
// 	int regVal2 = r2.getValue();
// 	regVal1 -= regVal2;
// 	r1.setValue(regVal1);
// }

// void ALU::mul(Registers& r, int num) {
// 	int regVal = r.getValue();
// 	regVal *= num;
// 	r.setValue(regVal);
// } 

// void ALU::mul(Registers& r1, Registers& r2) {
// 	int regVal1 = r1.getValue();
// 	int regVal2 = r2.getValue();
// 	regVal1 *= regVal2;
// 	r1.setValue(regVal1);
// }

// void ALU::div(Registers& r, int num) {
// 	 if (num != 0) {
// 	    int regVal = r.getValue();
// 		regVal = regVal / num;
// 		r.setValue(regVal);
//     } else {
//         std::cerr << "Division by zero!" << std::endl;
//   		exit(0);
//     }
// }

// void ALU::div(Registers& r1, Registers& r2) {
// 	int regVal1 = r1.getValue();
// 	int regVal2 = r2.getValue();
//   	 if (regVal2 != 0) {
// 		regVal1 = regVal1 / regVal2;
// 		r1.setValue(regVal1);
//     } else {
//         std::cerr << "Division by zero!" << std::endl;
//   		exit(0);
//     }
// }

// bool ALU::logicAnd(Registers& r, int num) {
//     return r.getValue() && num;
// }

// bool ALU::logicAnd(int num, Registers& r) {
//     return num && r.getValue();
// }

// bool ALU::logicAnd(Registers& r1, Registers& r2) {
//     return r1.getValue() && r2.getValue();
// }

// bool ALU::logicOr(Registers& r, int num) {
//     return r.getValue() || num;
// }

// bool ALU::logicOr(int num, Registers& r2) {
//     return num || r2.getValue();
// }

// bool ALU::logicOr(Registers& r1, Registers& r2) {
//     return r1.getValue() || r2.getValue();
// }


// void ALU::print(const Registers& r) {
// 	std::cout << r.getRegisterName() << r.getValue() << std::endl;
// }


// void ALU::execute(const std::string& command, const std::vector<std::string>& arguments, std::vector<Registers>& reg) {
//     // Check if the command exists in the operationMap
//     auto operationIterator = operationMap.find(command);

//     if (operationIterator != operationMap.end()) {
//         // Operation found, execute it based on the function pointer
//         if (arguments.size() == 0) {
//             // No arguments provided, call the operation without arguments
//             operationIterator->second(*this, reg[0], 0);
//         } else if (arguments.size() == 1) {
//             // Single argument provided, parse it as an integer
//             if (isDigit(arguments[0])) {
//                 int num = std::stoi(arguments[0]);
//                 operationIterator->second(*this, reg[0], num);
//             } else {
//                 std::cerr << "Invalid argument for '" << command << "' operation." << std::endl;
//             }
//         } else if (arguments.size() == 2) {
//             // Two arguments provided, parse them and call the operation accordingly
//             if (isDigit(arguments[1])) {
//                 int num = std::stoi(arguments[1]);
//                 operationIterator->second(*this, reg[0], num);
//             } else {
//                 // Second argument is not numeric, check if it's a register
//                 auto secondRegisterIterator = operationMap.find(arguments[1]);
//                 if (secondRegisterIterator != operationMap.end()) {
//                     // Second argument is a valid register, call the operation with two registers
//                     secondRegisterIterator->second(*this, reg[0], reg[1]);
//                 } else {
//                     std::cerr << "Invalid second argument for '" << command << "' operation." << std::endl;
//                 }
//             }
//         } else {
//             std::cerr << "Invalid number of arguments for '" << command << "' operation." << std::endl;
//         }
//     } else {
//         std::cerr << "Unknown operation: " << command << std::endl;
//     }
// }

      
// bool ALU::isDigit(const std::string& str) {
// 	for(size_t i = 0; i < str.size(); ++i) {
// 		if(str[i] > 57 && str[i] > 48) {
// 			return false;
// 		}
// 	}
// 	return true;
// }

// #endif  //ALU_H

