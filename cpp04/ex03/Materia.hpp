/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:58:40 by tglory            #+#    #+#             */
/*   Updated: 2022/01/30 20:10:52 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_HPP
# define MATERIA_HPP

# include <iostream>
# include "Character.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria(std::string name);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string name;
};
 
class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &instance);
		~Ice();

		virtual Ice* clone() const;
		virtual void use(ICharacter& target);
};

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &instance);
		~Cure();

		virtual Cure* clone() const;
		virtual void use(ICharacter& target);
};

#endif
