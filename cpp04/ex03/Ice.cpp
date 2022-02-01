#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &instance) : AMateria("ice")
{
	*this = instance;
}

Ice &Ice::operator=(Ice const &instance)
{
	(void)instance;
	return (*this);
}

Ice::~Ice() {}

Ice* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
}
