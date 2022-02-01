#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(Cure const &instance) : AMateria("cure")
{
	*this = instance;
}

Cure &Cure::operator=(Cure const &instance)
{
	(void)instance;
	return (*this);
}

Cure::~Cure() {}

Cure* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl; 
}
