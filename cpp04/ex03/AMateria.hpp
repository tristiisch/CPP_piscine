#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "Character.hpp"


class ICharacter;

class AMateria
{
	public:
		AMateria();
		AMateria(std::string name);
		AMateria(AMateria const &instance);
		virtual	~AMateria();
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string name;
};

#endif
