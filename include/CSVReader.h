#pragma once
#include <vector>
#include <string>

class CSVReader {
private:
	std::vector<std::string> lines;
	int no_of_lines;
public:
	CSVReader(std::string filename);

	std::string getLine(int index){return lines[index];};
	int getNoOfLines(){return no_of_lines;};
};