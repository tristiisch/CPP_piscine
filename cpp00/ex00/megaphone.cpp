/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 04:24:13 by tglory            #+#    #+#             */
/*   Updated: 2021/12/28 05:00:20 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		j = 0;

		while (argv[i][j])
		{
			argv[i][j] = std::toupper(argv[i][j]);
			j++;
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
