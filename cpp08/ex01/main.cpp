/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 08:53:11 by tglory            #+#    #+#             */
/*   Updated: 2022/02/07 00:45:45 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span *sp = new Span(5);

	sp->addNumber(6);
	sp->addNumber(3);
	sp->addNumber(17);
	sp->addNumber(9);
	sp->addNumber(11);
	std::cout << *sp << std::endl;
	std::cout << "shortest span\t" << sp->shortestSpan() << std::endl << "longest span\t" << sp->longestSpan() << std::endl;
	std::cout << std::endl;

	delete sp;
	sp = new Span(6);
	sp->addNumber(6);
	sp->addNumber(3);
	sp->addNumber(17);
	sp->addNumber(9);
	sp->addNumber(9);
	sp->addNumber(11);
	std::cout << *sp << std::endl;
	std::cout << "shortest span\t" << sp->shortestSpan() << std::endl << "longest span\t" << sp->longestSpan() << std::endl;
	std::cout << std::endl;

	delete sp;
	sp = new Span(1);

	sp->addNumber(6);
	try {
		sp->addNumber(3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *sp << std::endl;
	try {
		sp->shortestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp->longestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	delete sp;
	sp = new Span(2);

	sp->addNumber(std::numeric_limits<int>::max());
	sp->addNumber(std::numeric_limits<int>::min());
	std::cout << *sp << std::endl;
	std::cout << "shortest span\t" << sp->shortestSpan() << std::endl << "longest span\t" << sp->longestSpan() << std::endl;
	std::cout << std::endl;

	delete sp;

	std::vector<int> intVector;
	intVector.push_back(6);
	intVector.push_back(3);
	intVector.push_back(17);
	intVector.push_back(9);
	intVector.push_back(11);
	sp = new Span(intVector.size());
	sp->addNumber(intVector.begin(), intVector.end());

	std::cout << *sp << std::endl;
	std::cout << "shortest span\t" << sp->shortestSpan() << std::endl << "longest span\t" << sp->longestSpan() << std::endl;
	std::cout << std::endl;

	intVector.clear();
	delete sp;
	int size = 10000;
	sp = new Span(size);

	std::srand(time(NULL));
	for (int i = 0; i < size; ++i)
		sp->addNumber(std::rand());
	std::cout << "shortest span\t" << sp->shortestSpan() << std::endl << "longest span\t" << sp->longestSpan() << std::endl;
	
	delete sp;
	return 0;
}
