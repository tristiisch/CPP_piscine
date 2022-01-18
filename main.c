/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:44:26 by tglory            #+#    #+#             */
/*   Updated: 2021/12/29 03:09:34 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	main2(int argc, char const **argv)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) \ 
* 10);
	if (!str)
	{
		exit(1);
		return ;
	}
	i = 0;
	while (i < 9)
		str[i++] = 'T';
	str[i] = 0;
	if (!str)
		return (1);
	else
		return 0;
}
