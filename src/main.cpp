#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Dog.h"
#include "CSVReader.h"

//Set macros just to make life easy
#define MATERNAL false
#define PATERNAL true

using namespace std;

//Forward declarations
string traverse_paternal_tree(Dog child);
string traverse_maternal_tree(Dog child);
void add_dogs(CSVReader reader, vector<Dog> * dogs);

int main() {
	//Setup reader, feed in data file
	CSVReader reader("testfile.csv");

	//Declare and feed dogs into the vector
	vector<Dog> dogs;
	add_dogs(reader, &dogs);

	//Main output
	cout << "There are " << dogs.size() << " dog(s) in the inventory, which are:\n\n";
	cout << "Name 	Colour 	Dad 	Mom\n";
	cout << "-------------------------------\n";

	//Build the rows
	for (size_t i = 0; i < dogs.size(); ++i) {
		string row = dogs[i].getName() + "	" + dogs[i].getColour() + "	";
		//If paternal_dog is null, simply print NULL
		if (dogs[i].getPaternalDog() == NULL) {
			row += "NULL";
		} else {
			row += dogs[i].getPaternalDog()->getName();
		}

		row += "	";

		//if maternal_dog is null, simply print NULL
		if (dogs[i].getMaternalDog() == NULL) {
			row += "NULL";
		} else {
			row += dogs[i].getMaternalDog()->getName();
		}	

		cout << row << endl;
	}

	string input = ""; //User input string
	bool type; //Type of tree requsted

	//---------------------
	//MAIN LOOP STARTS HERE
	//---------------------
	//Loop will continue until "quit" is typed in
	//---------------------
	while (input != "quit") {
		cout << "\nWould you like to find maternal or paternal trees? (m/p): ";

		//Get input
		getline(cin, input);

		//Check if input is valid
		if (input == "m" || input == "p") {
			//Check which tree was requested and set "type"
			type = (input == "m") ? MATERNAL : PATERNAL;

			cout << "Enter the name of the dog: ";
			getline(cin, input);
			bool found = false;
			for (size_t i = 0; i < dogs.size(); ++i) {
				//If the input matches the dog name
				if (input == dogs[i].getName()) {
					//Traverse and print the tree
					if (type == MATERNAL) {
						cout << traverse_maternal_tree(dogs[i]) << endl;
					} else {
						cout << traverse_paternal_tree(dogs[i]) << endl;
					}
					found = true;
					break;
				}
			}

			//If the dog was not found in the database
			if (!found) {
				cout << input << " was not found in the inventory!" << endl;
			}
		} else {
			cout << "Invalid input, please input m or p\n";
		}
	}

	return 0;
}	

string traverse_paternal_tree(Dog child) {
	string final_string = child.getName() + " <-- ";
	//Base case
	if (!child.getPaternalDog()) {
		return final_string + "[END]";
	} else {
		return final_string + traverse_paternal_tree(*child.getPaternalDog());
	}
}

string traverse_maternal_tree(Dog child) {
	string final_string = child.getName() + " <-- ";
	//Base case
	if (!child.getMaternalDog()) {
		return final_string + "[END]";
	} else {
		return final_string + traverse_maternal_tree(*child.getMaternalDog());
	}
}

void add_dogs(CSVReader reader, vector<Dog> *dogs) {
	//Iterate through all the lines
	for (int i = 0; i < reader.getNoOfLines(); ++i) {
		//Create string stream
		stringstream ss(reader.getLine(i));

		string data[4]; //Array for each field
		
		for (int j = 0; j < 4; ++j) {
			getline(ss, data[j], ',');
		}

		//Create the dog object
		Dog dog(data[0], data[1], NULL, NULL);

		//Check for father
		if (!data[2].empty()) {
			for (size_t j = 0; j < dogs->size(); ++j) {
				if (data[2] == dogs->at(j).getName()) {
					dog.setPaternalDog(&dogs->at(j));
				}
			}
		}

		//Check for mother
		if (!data[3].empty()) {
			for (size_t j = 0; j < dogs->size(); ++j) {
				if (data[3] == dogs->at(j).getName()) {
					dog.setMaternalDog(&dogs->at(j));
				}
			}
		}

		//Add finalized dog object to database
		dogs->push_back(dog);
	}
}