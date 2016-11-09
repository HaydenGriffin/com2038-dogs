#include <iostream>
#include <string>
#include <vector>
#include "Dog.h"
#include "CSVReader.h"

using namespace std;

string traverse_paternal_tree(Dog child) {
	string final_string = child.getName() + " <-- ";
	if (!child.getPaternalDog()) {
		return final_string + "[END]";
	} else {
		return final_string + traverse_paternal_tree(*child.getPaternalDog());
	}
}

string traverse_maternal_tree(Dog child) {
	string final_string = child.getName() + " <-- ";
	if (!	child.getMaternalDog()) {
		return final_string + "[END]";
	} else {
		return final_string + traverse_maternal_tree(*child.getMaternalDog());
	}
}

void add_dog(Dog* dog_loc, string name) {

}

int main() {
	CSVReader reader("testfile.csv");
	vector<Dog> dogs;

	for (int i = 0; i < reader.getNoOfLines(); ++i) {
		cout << reader.getLine(i) << endl;
	}

	Dog dog1("Max", "brown", NULL, NULL);
	Dog dog2("Dave", "brown", &dog1, NULL);

	//cout << traverse_paternal_tree(dog2) << endl;

	return 0;
}	