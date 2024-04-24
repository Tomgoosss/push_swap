/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:28:55 by tgoossen          #+#    #+#             */
/*   Updated: 2024/04/24 10:23:01 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_correct_place(t_list *node_a, t_list *node_b,
		t_list *prev_b, t_num *man)
{
	if (node_a->data > node_b->data && node_a->data < prev_b->data)
		return (1);
	if (node_a->data > man->high_b && node_b->data == man->high_b)
		return (1);
	if (node_a->data < man->low_b && node_b->data == man->high_b)
		return (1);
	return (0);
}

void	sort_rotate(t_num *man)
{
	man->temp_rrot_b = 0;
	man->temp_rrot_a = 0;
	man->temp_rot_a = 0;
	man->temp_rot_b = 0;
	man->temp_rrot_b = man->nodes_b - man->rotate_b;
	man->temp_rrot_a = man->nodes_a - man->rotate_a;
	man->temp_rot_a = man->rotate_a;
	man->temp_rot_b = man->rotate_b;
}

void	safe_moves(t_num *man)
{
	man->rot_a = 0;
	man->rot_b = 0;
	man->rev_b = 0;
	man->rev_a = 0;
	if (man->temp_rot_a < man->temp_rrot_a)
		man->rot_a = man->temp_rot_a;
	else
		man->rev_a = man->temp_rrot_a;
	if (man->temp_rot_b < man->temp_rrot_b)
		man->rot_b = man->temp_rot_b;
	else
		man->rev_b = man->temp_rrot_b;
}

void	check_if_fit(t_list *node_a, t_list *node_b, t_list *prev_b, t_num *man)
{
	int	count;

	sort_rotate(man);
	count = 0;
	if (check_correct_place(node_a, node_b, prev_b, man))
	{
		if (man->temp_rot_a < man->temp_rrot_a)
			count += man->temp_rot_a;
		else
			count += man->temp_rrot_a;
		if (man->temp_rot_b < man->temp_rrot_b)
			count += man->temp_rot_b;
		else
			count += man->temp_rrot_b;
	}
	else
		return ;
	if (count < man->temp)
	{
		man->temp = count;
		safe_moves(man);
	}
}
