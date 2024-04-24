/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:55:09 by tgoossen          #+#    #+#             */
/*   Updated: 2024/04/24 13:28:25 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_rotate_b(t_num *man)
{
	man->temp_rrot_b = 0;
	man->temp_rot_b = 0;
	man->temp_rot_b = man->count_b;
	man->temp_rrot_b = man->nodes_b - man->count_b;
}

void	sort_rotate_a(t_num *man)
{
	man->temp_rrot_a = 0;
	man->temp_rot_a = 0;
	man->temp_rot_a = man->count_a;
	man->temp_rrot_a = man->nodes_a - man->count_a;
}

void	save_moves_a(t_num *man, int num, int temp)
{
	int	count;

	sort_rotate_b(man);
	count = 0;
	if (man->temp_rot_b < man->temp_rrot_b)
		count = man->temp_rot_b;
	else
		count = man->temp_rrot_b;
	if (count + num < temp)
	{
		temp = count + num;
		man->rot_b = 0;
		man->rev_b = 0;
		if (man->temp_rot_b < man->temp_rrot_b)
			man->rot_b = man->temp_rot_b;
		else
			man->rev_b = man->temp_rrot_b;
		man->numrot = num;
	}
}

void	find_correct_spot(t_list **head_a, t_list **head_b, t_num *man)
{
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*temp_b_prev;
	int		temp;

	temp = INT_MAX;
	temp_a = *head_a;
	temp_b = *head_b;
	temp_b_prev = *head_b;
	while (temp_b_prev->link)
		temp_b_prev = temp_b_prev->link;
	while (temp_b)
	{
		if (temp_b->data < man->num1_a && temp_b_prev->data > man->num1_a)
			save_moves_a(man, 1, temp);
		if (temp_b->data < man->num2_a && temp_b_prev->data > man->num2_a)
			save_moves_a(man, 2, temp);
		if (temp_b->data < man->num3_a && temp_b_prev->data > man->num3_a)
			save_moves_a(man, 3, temp);
		temp_b_prev = temp_b;
		temp_b = temp_b->link;
		man->count_b++;
	}
}

void	push_to_a(t_list **head_a, t_list **head_b, t_num *man)
{
	man->nodes_b = count_nodes(head_b);
	take_3_numbers_a(*head_a, man);
	if (count_nodes(head_b) > 2)
	{
		find_correct_spot(head_a, head_b, man);
		rotate_to_correct_spot(man, head_a, head_b);
	}
	push_correct(head_a, head_b, man);
	high_low(head_a, man);
}
