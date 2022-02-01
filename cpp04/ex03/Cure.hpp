#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "Character.hpp"

class ICharacter;

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &instance);
		Cure &operator=(Cure const &instance);
		~Cure();

		Cure* clone() const;
		void use(ICharacter& target);
};

#endif
