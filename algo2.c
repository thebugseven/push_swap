/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:53:01 by jhue              #+#    #+#             */
/*   Updated: 2024/01/08 15:53:01 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_r(t_list *list_a, int pivot, int middle)
{
	int		count;
	t_list	*buffer;

	count = 0;
	while (list_a->value != pivot && list_a->value != middle)
		list_a = list_a->next;
	if (list_a->value != middle)
		return (1);
	buffer = list_a;
	while (!list_a->pivot)
		list_a = list_a->next;
	if (list_a->value != pivot)
		return (0);
	while (!buffer->pivot)
	{
		if (buffer->value > pivot)
			count++;
		buffer = buffer->previous;
	}
	return (count);
}

int	cost_rr(t_list *list_a, int pivot, int middle)
{
	int	count;
	int	pass_middle;

	count = 0;
	pass_middle = 0;
	while (list_a->next && list_a->value != pivot)
	{
		list_a = list_a->next;
		if (list_a->value == middle)
			pass_middle = 1;
	}
	if (!pass_middle)
		return (0);
	list_a = list_a->previous;
	while (!list_a->pivot && list_a->value != middle)
	{
		if (list_a->value > pivot)
			count++;
		list_a = list_a->previous;
	}
	return (count);
}

void	ft_rotate(t_list *list_a, t_list *list_b, int pivot, int init_val)
{
	while (list_a->value != init_val)
		list_a = rotate_a(list_a);
	while (list_a->value != pivot)
	{
		if (list_a->value > pivot)
			list_a = push_b(list_a, list_b);
		else
			list_a = rotate_a(list_a);
	}
	list_a = rotate_a(list_a);
	while (list_b)
		list_a = push_a(list_a, list_b);
	list_a = rrotate_a(list_a, list_b)
	while (list_a->value ?)

}