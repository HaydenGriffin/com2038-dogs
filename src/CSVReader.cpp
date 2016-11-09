#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader(std::string filename) {
	std::string line;
	std::ifstream file(filename.c_str());
	if (file.is_open()) {
		while (getline(file, line)) {
			lines.push_back(line);
			no_of_lines++;
		}

		file.close();
	} else {
		std::cout << "File not found\n";
	}
}