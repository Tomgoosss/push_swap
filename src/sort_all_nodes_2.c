/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all_nodes_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:37:18 by tgoossen          #+#    #+#             */
/*   Updated: 2024/04/18 14:26:28 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	count_moves(t_list **head_a, t_list **head_b, t_num *man)
{
	t_list	*check_a;
	t_list	*check_b;
	t_list	*prev_b;

	man->temp = INT_MAX;
	prev_b = *head_b;
	check_a = *head_a;
	check_b = *head_b;
	while (prev_b->link != NULL)
		prev_b = prev_b->link;
	man->rotate_a = 0;
	while (man->rotate_a < man->nodes_a)
	{
		while (man->rotate_b < man->nodes_b)
		{
			check_if_fit(check_a, check_b, prev_b, man);
			prev_b = check_b;
			check_b = check_b->link;
			man->rotate_b++;
		}
		check_b = *head_b;
		man->rotate_b = 0;
		check_a = check_a->link;
		man->rotate_a++;
	}
}

void	push2(t_list **head_a, t_list **head_b)
{
	ft_p(head_a, head_b, 'a');
	ft_p(head_a, head_b, 'a');
}

void	make_high_and_low_a(t_list *head_a, t_num *man)
{
	man->high_a = 0;
	man->low_a = INT_MAX;
	while (head_a != NULL)
	{
		if (head_a->data > man->high_a)
			man->high_a = head_a->data;
		if (head_a->data < man->low_a)
			man->low_a = head_a->data;
		head_a = head_a->link;
	}
}

void	make_high_and_low_b(t_list *head_b, t_num *man)
{
	man->high_b = 0;
	man->low_b = INT_MAX;
	while (head_b != NULL)
	{
		if (head_b->data > man->high_b)
			man->high_b = head_b->data;
		if (head_b->data < man->low_b)
			man->low_b = head_b->data;
		head_b = head_b->link;
	}
}

void	setzero(t_num *man)
{
	man->temp_rot_a = 0;
	man->temp_rot_b = 0;
	man->temp_rrot_a = 0;
	man->temp_rrot_b = 0;
}
