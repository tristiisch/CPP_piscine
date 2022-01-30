/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:17:36 by tglory            #+#    #+#             */
/*   Updated: 2022/01/30 20:07:37 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "Materia.hpp"
# include <iostream>

# define MAX_INV 4

class AMateria;

class ICharacter
{
	public:
		ICharacter();
		ICharacter(std::string name);
		ICharacter(ICharacter const &instance);
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
	protected:
		std::string name;
		AMateria *inventory[MAX_INV];
};

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(Character const &instance);
		~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
	protected:
		virtual void initInventory();
};

#endif
