#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader(std::string filename) {
	no_of_lines = 0;
	std::string line;

	//Load in and open file
	std::ifstream file(filename.c_str());
	if (file.is_open()) {
		//While there are still lines available
		while (getline(file, line)) {
			//Add lines to vector
			lines.push_back(line);

			//Increment line count
			no_of_lines++;
		}

		file.close();
	} else {
		std::cout << "File not found\n";
	}
}