#ifndef PARSING_H
#define PARSING_H

#include <iostream> 
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>

class Parsing {
public:
	Parsing(const std::string&);
	std::vector<std::string> split(const std::string&, char);
	std::string normalization(std::string&);
	std::map<int, std::string> getData() const;
	std::unordered_map<std::string, int> getLables() const;
private:
	std::map<int, std::string> data_map;
	std::unordered_map<std::string, int> lables;
};

Parsing::Parsing(const std::string& fileName) {
	std::ifstream file(fileName);
	if(!file.is_open()) {
		std::cerr << "Error: unable to open file " << std::endl;
	}

	std::string line;
	int line_number = 1;

	while(std::getline(file, line)) {
		bool isLable = false;
		if(line[line.size() - 2] == ':') {
			isLable = true;
		}
		if(line.find(':') != std::string::npos) {
			isLable = true;
		}
		std::string norLine = normalization(line);
		data_map[line_number] = norLine;
		if(isLable) {
			lables[line] = line_number;
		}
		line_number++;
	}

	file.close();
}

std::vector<std::string> Parsing::split(const std::string& str, char ch) {
	std::vector<std::string> newV;
	std::stringstream ss(str);
	std::string part;
	while(std::getline(ss, part, ch)) {
		newV.push_back(part);
	}
	return newV;
}

std::string Parsing::normalization(std::string& text) {
	std::string processedText = text;

    std::transform(processedText.begin(), processedText.end(), processedText.begin(), ::tolower);
    const std::string charactersToRemove = ",+";

    for (char c : charactersToRemove) {
        processedText.erase(std::remove(processedText.begin(), processedText.end(), c), processedText.end());
    }

    return processedText;
}

std::map<int, std::string> Parsing::getData() const {
	return data_map;
}

std::unordered_map<std::string, int> Parsing::getLables() const {
	return lables;
}


#endif  //PARSING_H