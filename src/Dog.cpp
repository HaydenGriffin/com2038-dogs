#include "Dog.h"

Dog::Dog(std::string n, std::string c, Dog* f,  Dog* m) {
	name = n;
	colour = c;
	paternal_dog = f;
	maternal_dog = m;
}