/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 03:17:41 by tglory            #+#    #+#             */
/*   Updated: 2022/01/25 17:34:18 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <sstream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
		void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
