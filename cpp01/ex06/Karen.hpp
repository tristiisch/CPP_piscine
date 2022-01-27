/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:07:51 by tglory            #+#    #+#             */
/*   Updated: 2022/01/25 01:15:27 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>

# define C_CYAN "\e[36m"
# define C_GREEN "\e[32m"
# define C_YELLOW "\e[33m"
# define C_RED "\e[31m"
# define C_RESET "\e[0m"

class Karen
{
	// This is pointer on fonction has asked on the subject
	typedef void (Karen::*f)(void);

	public:
		void complain(std::string level);

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif