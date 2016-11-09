#include <iostream>
#include <string>
#include "Dog.h"

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

int main() {
	Dog dog1("Max", "brown", NULL, NULL);
	Dog dog2("Dave", "brown", &dog1, NULL);

	cout << "lol" << endl;

	return 0;
}	