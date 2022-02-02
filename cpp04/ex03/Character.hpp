/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:19:38 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 16:20:07 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

# define MAX_INV 4
# define DELETE_SAFE_BUFFER 1

class AMateria;

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
		void unEquipSafe(int idx);
	protected:
		std::string name;
		AMateria *inventory[MAX_INV];
		AMateria *toDelete[DELETE_SAFE_BUFFER];
		void initInventory();
};

#endif
