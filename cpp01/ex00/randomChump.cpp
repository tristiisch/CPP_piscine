/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 01:35:43 by tglory            #+#    #+#             */
/*   Updated: 2022/01/25 17:28:26 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
