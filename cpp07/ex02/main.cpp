/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:53:33 by tglory            #+#    #+#             */
/*   Updated: 2022/02/05 08:02:37 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

int main()
{
	Array<int> intArray1(10);
	Array<int> intArray2(1);
	int i = 0;

	while (i < intArray1.size())
	{
		intArray1[i] = i;
		++i;
	}
	intArray2 = intArray1;
	i = 0;
	while (i < intArray1.size())
	{
		std::cout << "intArray1:\t"<< intArray1[i] << "\t\tintArray2:\t" << intArray2[i] << std::endl;
		i++;
	}

	Array<int> intArrayEmpty;
	std::cout << "intArrayEmpty Size:\t" << intArrayEmpty.size() << std::endl;

	Array<std::string> stringArray(3);
	i = 0;
	while (i < stringArray.size())
		stringArray[i++] = "Foo Bar";
	i = 0;
	while (i < stringArray.size())
		std::cout << stringArray[i++] << std::endl;

	try
	{
		std::cout << intArrayEmpty[42] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}