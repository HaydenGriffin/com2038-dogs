#pragma once
#include <string>

class Dog {
private:
	std::string name;
	std::string colour;
	Dog* paternal_dog;
	Dog* maternal_dog;

public:
	Dog(std::string n, std::string c, Dog* f,  Dog* m);
	
	std::string getName() 	{return name;}
	std::string getColour() {return colour;}
	Dog* getPaternalDog() 	{return &paternal_dog;}
	Dog* getMaternalDog() 	{return &maternal_dog;}
};

class Husky: public Dog {
	
};

class Boxer: public Dog {
	
};

class Corgi: public Dog {
	
};