/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:05:30 by tgoossen          #+#    #+#             */
/*   Updated: 2024/04/25 10:14:29 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_last_three(t_list **head)
{
	if ((*head)->data > (*head)->link->data
		&& (*head)->data > (*head)->link->link->data)
		ft_rotate(head, 'a');
	else if ((*head)->link->data > (*head)->data
		&& (*head)->link->data > (*head)->link->link->data)
		ft_rotaterev(head, 'a');
	if ((*head)->data > (*head)->link->data)
		ft_s(head, 'a');
}

void	fix_two_node(t_list **head_a)
{
	if ((*head_a)->data > (*head_a)->link->data)
		ft_rotate(head_a, 'a');
}

void	sort_four(t_list **head_a, t_list **head_b)
{
	ft_p(head_a, head_b, 'a');
	sort_last_three(head_a);
	if ((*head_b)->data < (*head_a)->data)
		ft_p(head_a, head_b, 'b');
	else if ((*head_b)->data < (*head_a)->link->data)
	{
		ft_p(head_a, head_b, 'b');
		ft_s(head_a, 'a');
	}
	else if ((*head_b)->data < (*head_a)->link->link->data)
	{
		ft_p(head_a, head_b, 'b');
		ft_rotaterev(head_a, 'a');
		ft_s(head_a, 'a');
		ft_rotate(head_a, 'a');
		ft_rotate(head_a, 'a');
	}
	else if ((*head_b)->data > (*head_a)->link->link->data)
	{
		ft_p(head_a, head_b, 'b');
		ft_rotate(head_a, 'a');
	}
}

int	count_nodes(t_list **head)
{
	t_list	*temp;
	int		i;

	i = 0;
	if (!head)
		return (0);
	temp = *head;
	while (temp != NULL)
	{
		temp = temp->link;
		i++;
	}
	return (i);
}

void	sortmain(t_list **head_a, t_list **head_b, int numstacks, t_num *man)
{
	if (numstacks == 1)
		return ;
	if (numstacks == 2)
		fix_two_node(head_a);
	if (numstacks == 3)
		sort_last_three(head_a);
	if (numstacks == 4)
		sort_four(head_a, head_b);
	if (numstacks >= 5)
		five_or_more(head_a, head_b, man);
}
