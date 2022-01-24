/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:07:16 by tglory            #+#    #+#             */
/*   Updated: 2022/01/24 22:45:50 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Karen.hpp"

int main(void)
{
    Karen karen;

	std::cout << "--------------------------------------" << std::endl;
	karen.complain("DEBUG");

	std::cout << "--------------------------------------" << std::endl;
	karen.complain("INFO");

	std::cout << "--------------------------------------" << std::endl;
	karen.complain("WARNING");

	std::cout << "--------------------------------------" << std::endl;
	karen.complain("ERROR");

	return (0);
}
