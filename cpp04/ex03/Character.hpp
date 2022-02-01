#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

# define MAX_INV 4
# define DEBUG 0

class AMateria; // necessary ?

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(Character const &instance);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		Character &operator=(Character const & instance);
	protected:
		std::string name;
		AMateria *inventory[MAX_INV];
		void initInventory();
};

#endif
