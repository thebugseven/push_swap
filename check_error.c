/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:45:04 by jhue              #+#    #+#             */
/*   Updated: 2023/12/06 11:45:04 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	have_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while(argv[j] && j < i)
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	only_zero(char *argv)
{
	if ((*argv == '+' || *argv == '-') && argv[1])
		argv++;
	while(*argv && *argv == '0')
		argv++;
	if (!*argv)
		return (1);
	return (0);

}

int	is_num(char *argv)
{
	int	i;

	i = 0;
	if ((*argv == '+' || *argv == '-') && argv[1])
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i++]))
			return (0);
	}
	return (1);
}

int	check_error(char **argv)
{
	int	i;
	int	nb_zero;

	nb_zero = 0;
	i = 0;
	while (argv[++i])
	{
		if (!is_num(argv[i]))
			return (0);
		if (only_zero(argv[i]))
			nb_zero++;
	}
	if (nb_zero > 1 || have_duplicate(argv))
		return (0);
	return (1);
}