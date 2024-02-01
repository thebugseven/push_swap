/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:40:51 by jhue              #+#    #+#             */
/*   Updated: 2023/12/06 17:40:51 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	fill_list(char **argv)
{
	t_list	*new;
	t_list	*node;

	new = NULL;
	while (*++argv)
	{
		node = ft_lstnew(ft_atoi(*argv));
		if (!node)
			return (error_end(new));
		ft_lstadd_back(new, node);
	}

}