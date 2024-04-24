/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:24:11 by tgoossen          #+#    #+#             */
/*   Updated: 2024/04/24 12:12:07 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	five_or_more(t_list **head_a, t_list **head_b, t_num *man)
{
	int	i;

	i = 0;
	push2(head_a, head_b);
	if ((*head_b)->data < (*head_b)->link->data)
		ft_s(head_b, 'b');
	man->nodes_a = count_nodes(head_a);
	while (man->nodes_a > 3)
	{
		man->nodes_a = count_nodes(head_a);
		man->nodes_b = count_nodes(head_b);
		make_high_and_low_b(*head_b, man);
		count_moves(head_a, head_b, man);
		rotate(man, head_a, head_b);
		rotate2(man, head_a, head_b);
		ft_p(head_a, head_b, 'a');
		man->nodes_a = count_nodes(head_a);
	}
	sort_last_three(head_a);
	push_to_a(head_a, head_b, man);
}

// Shift down all elements of the stack by 1.
// The last element becomes the first one.
void	ft_rotaterev(t_list **head, char ab)
{
	t_list	*temp;
	t_list	*first;

	if (*head == NULL || (*head)->link == NULL)
		return ;
	temp = *head;
	first = *head;
	while ((*head)->link != NULL)
		*head = (*head)->link;
	while (temp->link->link != NULL)
		temp = temp->link;
	temp->link = NULL;
	(*head)->link = first;
	if (ab == 'a')
		ft_printf("rra\n");
	if (ab == 'b')
		ft_printf("rrb\n");
}

void	rrr(t_list **head_a, t_list **head_b)
{
	ft_rotaterev(head_a, 'x');
	ft_rotaterev(head_b, 'x');
	ft_printf("rrr\n");
}

int	stack_len(t_list **head)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *head;
	while (temp != NULL)
	{
		temp = temp->link;
		i++;
	}
	printf("test len = %d\n", i);
	return (i);
}

void	teststacks(t_list **head_a, t_list **head_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *head_a;
	temp_b = *head_b;
	while (temp_a != NULL)
	{
		printf("stack a =%d\n", temp_a->data);
		temp_a = temp_a->link;
	}
	printf("\n");
	while (temp_b != NULL)
	{
		printf("stack b =%d\n", temp_b->data);
		temp_b = temp_b->link;
	}
	printf("\n");
}
