/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:07:03 by tgoossen          #+#    #+#             */
/*   Updated: 2024/04/18 14:28:06 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Swap the first 2 elements at the top of stack a or b
void	ft_s(t_list **head, char ab)
{
	t_list	*temp;

	if (*head == NULL || (*head)->link == NULL)
		return ;
	temp = (*head)->link;
	(*head)->link = temp->link;
	temp->link = *head;
	*head = temp;
	if (ab == 'a')
		ft_printf("sa\n");
	if (ab == 'b')
		ft_printf("sb\n");
}

// swap a and b at the same time
void	ft_ss(t_list **head_a, t_list **head_b)
{
	ft_s(head_a, 'x');
	ft_s(head_b, 'x');
	ft_printf("ss\n");
}

void	ft_p(t_list **head_a, t_list **head_b, char ab)
{
	t_list	*temp;

	if (ab == 'b')
	{
		if (*head_b == NULL)
			return ;
		temp = *head_b;
		*head_b = (*head_b)->link;
		temp->link = *head_a;
		*head_a = temp;
		ft_printf("pa\n");
	}
	else if (ab == 'a')
	{
		if (*head_a == NULL)
			return ;
		temp = *head_a;
		*head_a = (*head_a)->link;
		temp->link = *head_b;
		*head_b = temp;
		ft_printf("pb\n");
	}
}

// Shift up all elements of the stack by 1.
// The first element becomes the last one.
void	ft_rotate(t_list **head, char ab)
{
	t_list	*last;
	t_list	*temp;

	if (*head == NULL || (*head)->link == NULL)
		return ;
	last = *head;
	temp = *head;
	while (last->link != NULL)
		last = last->link;
	*head = (*head)->link;
	temp->link = NULL;
	last->link = temp;
	if (ab == 'a')
		ft_printf("ra\n");
	if (ab == 'b')
		ft_printf("rb\n");
}

// do the above function for both stacks
void	ft_rr(t_list **head_a, t_list **head_b)
{
	ft_rotate(head_a, 'x');
	ft_rotate(head_b, 'x');
	ft_printf("rr\n");
}
