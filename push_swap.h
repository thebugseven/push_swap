/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:45:13 by jhue              #+#    #+#             */
/*   Updated: 2023/12/06 11:45:13 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
// # include "libft.h"
// #include <stdio.h>

typedef struct	s_list
{
	int				value;
	int				pivot;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

int		check_error(char **argv);
void	error_end(void);
void	ft_sort(t_list **list_a, t_list **list_b, int pos);
int		cost_rr(t_list *list_a, int pivot, int middle);
int		cost_r(t_list *list_a, int pivot, int middle);

#endif