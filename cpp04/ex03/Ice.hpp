/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:20:24 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 16:20:25 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
