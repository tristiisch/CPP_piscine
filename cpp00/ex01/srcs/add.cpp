/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:44:03 by tglory            #+#    #+#             */
/*   Updated: 2021/12/30 01:44:59 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class Add : public Command
{
    std::string getName() const
    {
        return ("ADD");
    }

	bool execute(void)
	{
		return (true);
	}

	bool print(void)
	{

		std::cout << "Nones values" << std::endl;
		return (true);
	}
};
