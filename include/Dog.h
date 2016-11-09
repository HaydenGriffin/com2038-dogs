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
	~Dog();

	std::string getName() 	{return name;}
	std::string getColour() {return colour;}
	Dog* getPaternalDog() 	{return paternal_dog;}
	Dog* getMaternalDog() 	{return maternal_dog;}

	void setName(std::string new_name) {name = new_name;}
	void setPaternalDog(Dog* p_d) {paternal_dog = p_d;}
	void setMaternalDog(Dog* m_d) {maternal_dog = m_d;}
};

class Husky: public Dog {
	
};

class Boxer: public Dog {
	
};

class Corgi: public Dog {
	
};