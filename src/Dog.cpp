#include "Dog.h"

Dog::Dog(std::string n, std::string c, Dog* p_d, Dog* m_d) {
	name = n;
	colour = c;
	paternal_dog = p_d;
	maternal_dog = m_d;
}

Dog::~Dog() {
}