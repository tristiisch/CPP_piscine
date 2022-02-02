#ifndef ICE_HPP
# define ICE_HPP

# include "Character.hpp"

class ICharacter;
 
class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &instance);
		Ice &operator=(Ice const &instance);
		~Ice();

		Ice* clone() const;
		void use(ICharacter& target);
};

#endif
