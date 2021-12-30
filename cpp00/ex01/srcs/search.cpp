/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:12:43 by tglory            #+#    #+#             */
/*   Updated: 2021/12/30 01:42:52 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class Search : public Command
{
    std::string getName() const
    {
        return ("SEARCH");
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
