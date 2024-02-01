/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:15:03 by jhue              #+#    #+#             */
/*   Updated: 2024/01/08 09:15:03 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sort(t_list *list_a)
{
	int	previous;

	previous = list_a->value;
	list_a = list_a->next;
	while (list_a && !list_a->pivot)
	{
		if (previous > list_a->value)
			return (0);
		previous = list_a->value;
		list_a = list_a->next;
	}
	return (1);
}

t_list	*take_position(t_list *list_a, int pos, int pivot)
{
	if (pos == 0)
		return (list_a);
	while (list_a->value != pivot && list_a)
		list_a = list_a->next;
	if (pos == -1)
	{
		while (!list_a->previous && !list_a->pivot)
			list_a = list_a->previous;
	}
	else
		list_a = list_a->next;
	return (list_a);
}

int	define_pivot(t_list *list_a)
{
	while (list_a->next && !list_a->pivot)
		list_a = list_a->next;
	list_a->pivot = 1;
	return (list_a->value);	
}

void	ft_sort(t_list **list_a, t_list **list_b, int pos, int pivot)
{
	int		middle;
	t_list	*head_list;

	middle = find_middle(*list_a);
	head_list = list_a;
	list_a = take_position(*list_a, pos, pivot);
	if (already_sort(list_a))
		return ;
	pivot = define_pivot(list_a);
	if (cost_r(head_list, pivot, middle) <= cost_rr(head_list, pivot, middle))
		list_a = ft_rotate(*head_list, *list_b, pivot, (*list_a)->value);
	else
		list_a = ft_reverse_rotate(*list_a, *list_b);
	ft_sort(*list_a, *list_b, -1, pivot);
	ft_sort(*list_a, *list_b, 1, pivot);
}
