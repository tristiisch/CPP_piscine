/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:47:57 by tglory            #+#    #+#             */
/*   Updated: 2022/02/07 01:02:02 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		MutantStack() {}
		MutantStack(MutantStack const *instance) : std::stack<T>(instance) {}
		MutantStack &operator=(MutantStack const &instance)
		{
			(void)instance;
			return *this;
		}
		~MutantStack() {}

		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}
		reverse_iterator rbegin() {
			return this->c.rbegin();
		}
		reverse_iterator rend() {
			return this->c.rend();
		}
};

#endif
