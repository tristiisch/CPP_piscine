/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:00:16 by tglory            #+#    #+#             */
/*   Updated: 2022/01/25 17:30:45 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
	private:
		std::string	name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
