/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:05:06 by tglory            #+#    #+#             */
/*   Updated: 2022/02/03 21:24:47 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>

class Convert
{
	public:
		Convert();
		Convert(std::string name);
		Convert(Convert const &instance);
		Convert &operator=(Convert const &instance);
		~Convert();
		std::string getRaw() const; 
		void print() const;
	private:
		std::string raw;
};

#endif
