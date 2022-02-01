/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:17:36 by tglory            #+#    #+#             */
/*   Updated: 2022/02/01 20:17:25 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "Materia.hpp"
# include <iostream>

# define DELETE_SAFE_BUFFER 1
# define MAX_INV 4
# define DEBUG 1

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

		virtual void unEquipSafe(int idx) = 0;
};

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(Character const &instance);
		Character &operator=(Character const & instance);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		void unEquipSafe(int idx);
	protected:
		std::string name;
		AMateria *inventory[MAX_INV];
		AMateria *toDelete[DELETE_SAFE_BUFFER];
		void initInventory();
};

#endif
