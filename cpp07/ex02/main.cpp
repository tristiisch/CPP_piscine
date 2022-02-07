/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:53:33 by tglory            #+#    #+#             */
/*   Updated: 2022/02/07 01:08:14 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

# define MAX_VAL 750

static int test42()
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	std::srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = std::rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}

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

	Array<std::string> stringArray(3);
	i = 0;
	while (i < stringArray.size())
		stringArray[i++] = "Foo Bar";
	i = 0;
	while (i < stringArray.size())
		std::cout << stringArray[i++] << std::endl;

	Array<int> intArrayEmpty;
	std::cout << "intArrayEmpty Size:\t" << intArrayEmpty.size() << std::endl;
	try
	{
		std::cout << intArrayEmpty[42] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "42 test:" << std::endl;
	test42();
	return 0;
}
