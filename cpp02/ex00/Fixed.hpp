/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:07:05 by tglory            #+#    #+#             */
/*   Updated: 2022/01/31 16:50:56 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &instance);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		Fixed &operator=(Fixed const &instance);

	private:
		static int const _fractional_bits;
		int _rawBits;

};

#endif
