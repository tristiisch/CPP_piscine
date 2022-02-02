/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:20:17 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 16:20:17 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

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
