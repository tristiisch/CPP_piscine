#include "AMateria.hpp"

AMateria::AMateria() : name("empty") {}

AMateria::AMateria(AMateria const &instance)
{
	*this = instance;
}

AMateria::AMateria(std::string name) : name(name) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return (this->name);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "An error occurred with AMateria::use()." << std::endl;
}