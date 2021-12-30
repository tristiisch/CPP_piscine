/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:13:07 by tglory            #+#    #+#             */
/*   Updated: 2021/12/30 01:42:33 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class Exit : public Command
{
    std::string getName() const
    {
        return ("EXIT");
    }
    
	bool execute(void)
	{
		return (true);
	}

	bool print(void)
	{
		return (true);
	}
};
