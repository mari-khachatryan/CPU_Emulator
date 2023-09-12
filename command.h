#include <iostream> 

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>


class Command {
public:
	Command();
	Command(const std::string&);
	std::string getAllCommand() const;
	std::string getCommand() const;
	std::vector<std::string> getArguments() const;

	void setAllCommand(const std::string& c);
	std::vector<std::string> split(const std::string&, char);
private:
	std::string allCommond;
	std::string commond;
	std::vector<std::string> arguments;
};

Command::Command() = default;

Command::Command(const std::string& a) : allCommond{a} {
	std::vector<std::string> newV = split(a, ' ');
	if(!newV.empty()) {
		commond = newV[0];
		std::cout << "command : "<< commond << std::endl;
		for(size_t i = 1; i < newV.size(); ++i) {
			arguments.push_back(newV[i]);
			std::cout << "argument " << i << " : " << arguments[i - 1] << std::endl;
		}
	}
}

std::string Command::getAllCommand() const {
	return allCommond;
}

std::string Command::getCommand() const {
	return commond;
}

std::vector<std::string> Command::getArguments() const {
	return arguments;
}

void Command::setAllCommand(const std::string& c) {
	allCommond = c;
}

std::vector<std::string> Command::split(const std::string& str, char ch) {
	std::vector<std::string> newV;
	std::stringstream ss(str);
	std::string part;
	while(std::getline(ss, part, ch)) {
		newV.push_back(part);
	}
	return newV;
}


#endif    //COMMAND_H