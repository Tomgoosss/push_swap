/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:55:26 by tgoossen          #+#    #+#             */
/*   Updated: 2024/04/24 12:13:38 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_to_correct_spot(t_num *man, t_list **head_a, t_list **head_b)
{
	if (man->numrot == 2)
		ft_rotate(head_a, 'a');
	if (man->numrot == 3)
		ft_rotaterev(head_a, 'a');
	while (man->rot_b > 0)
	{
		ft_rotate(head_b, 'b');
		man->rot_b--;
	}
	while (man->rev_b > 0)
	{
		ft_rotaterev(head_b, 'b');
		man->rev_b--;
	}
}

int	check_if_push(t_list *head_a, t_list *head_b, t_list *last_a, t_num *man)
{
	if (!head_b)
		return (0);
	if (head_b->data < head_a->data && head_b->data > last_a->data)
		return (1);
	if (head_b->data > man->high_a && head_b->data == man->high_b
		&& head_a->data == man->low_a)
		return (1);
	if (head_b->data < man->low_a && head_a->data == man->low_a)
		return (1);
	if (last_a->data == man->high_a && head_b->data < head_a->data)
		return (1);
	return (0);
}

void	push_correct(t_list **head_a, t_list **head_b, t_num *man)
{
	t_list	*last_a;

	take_3_numbers_a(*head_a, man);
	while (*head_b)
	{
		last_a = *head_a;
		while (last_a->link)
			last_a = last_a->link;
		make_high_and_low_a(*head_a, man);
		make_high_and_low_b(*head_b, man);
		while (check_if_push(*head_a, *head_b, last_a, man))
		{
			ft_p(head_a, head_b, 'b');
			make_high_and_low_a(*head_a, man);
			make_high_and_low_b(*head_b, man);
		}
		ft_rotaterev(head_a, 'a');
	}
}

void	rot_a(t_list **head_a, t_num *man)
{
	if (man->temp_rot_a < man->temp_rrot_a)
	{
		while (man->temp_rot_a != 0)
		{
			ft_rotate(head_a, 'a');
			man->temp_rot_a--;
		}
	}
	else
	{
		while (man->temp_rrot_a != 0)
		{
			ft_rotaterev(head_a, 'a');
			man->temp_rrot_a--;
		}
	}
}

void	high_low(t_list **head_a, t_num *man)
{
	int		temp;
	int		temp_i;
	t_list	*temp_a;

	temp = INT_MAX;
	temp_i = 0;
	temp_a = *head_a;
	man->count_a = 0;
	while (temp_a)
	{
		if (temp_a->data < temp)
		{
			temp = temp_a->data;
			man->count_a = temp_i;
		}
		temp_a = temp_a->link;
		temp_i++;
	}
	man->nodes_a = count_nodes(head_a);
	sort_rotate_a(man);
	rot_a(head_a, man);
}
