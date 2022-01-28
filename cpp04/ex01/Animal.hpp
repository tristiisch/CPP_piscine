/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:49:01 by tglory            #+#    #+#             */
/*   Updated: 2022/01/28 01:16:40 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(std::string name);
		Animal(Animal const& instance);
		Animal &operator=(Animal const &instance);
		virtual ~Animal();

		void virtual makeSound() const;
		std::string getType() const;
	protected:
		std::string name;
};

#endif