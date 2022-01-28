/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:32:46 by tglory            #+#    #+#             */
/*   Updated: 2022/01/28 16:26:48 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <cstdlib>

class Brain
{
	public:
		Brain();
		Brain(Brain const &instance);
		void operator=(Brain const &instance);
		~Brain(void);
	private:
		std::string ideas[100];
};

#endif