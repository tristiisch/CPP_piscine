/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 04:24:13 by tglory            #+#    #+#             */
/*   Updated: 2021/12/28 04:38:21 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	int		i;
	char	*c;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		c = argv[i];
		while (*c)
		{
			*c = toupper(*c);
			c++;
		}
		std::cout << argv[i];
		if (argv[i + 1])
			std::cout << " ";
		else
			std::cout << std::endl;
		i++;
	}
	return (0);
}
