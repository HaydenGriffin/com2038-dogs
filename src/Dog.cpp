#include "Dog.h"

Dog::Dog(std::string n, std::string c, Dog* f,  Dog* m) {
	name = n;
	colour = c;
	paternal_dog = f;
	maternal_dog = m;
}

Dog::~Dog() {
	delete[] paternal_dog;
	delete[] maternal_dog;
}