#include <iostream>
#include <string>
#include <ifstream>
#include "Dog.h"

using namespace std;

string traverse_paternal_tree(Dog child) {
	string final_string = child.getName() + " <-- "
	if (!child.getPaternalDog) {
		return final_string + "[END]";
	} else {
		return final_string + traverse_paternal_tree(child.getPaternalDog()));
	}
}

string traverse_maternal_tree(Dog child) {
	string final_string = child.getName() + " <-- "
	if (!child.getMaternalDog) {
		return final_string + "[END]";
	} else {
		return final_string + traverse_maternal_tree(child.getMaternalDog()));
	}
}

int main() {


	return 0;
}	