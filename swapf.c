#include "push_swap.h"

void ft_s(t_list **head, char ab)
{
	t_list *temp;

	if(*head == NULL || (*head)->link == NULL)
		return ;
	temp = (*head)->link;
	(*head)->link = temp->link;
	temp->link = *head;
	*head = temp;
	if(ab == 'a')
		ft_printf("sa\n");
	if(ab == 'b')
		ft_printf("sb\n");
}

void	ft_ss(t_list **head_a, t_list **head_b)
{
	ft_s(head_a, 'x');
	ft_s(head_b, 'x');
	ft_printf("ss\n");
}

void ft_push(t_list **head_a, t_list **head_b, char ab)
{
	t_list *temp;

	if(ab == 'b')
	{
		if(*head_b == NULL)
			return ;

		temp = *head_b;
		*head_b = (*head_b)->link;
		temp->link = *head_a;
		*head_a = temp;
		ft_printf("pb\n");
	}
	else if (ab == 'a')
	{
		if(*head_a == NULL)
			return ;

		temp = *head_a;
		*head_a = (*head_a)->link;
		temp->link = *head_b;
		*head_b = temp;
		ft_printf("pa\n");
	}
}
// void ft_rotate(t_list **head, char ab)
// {
// 	t_list *last;
// 	t_list *temp;

// 	if (*head == NULL || (*head)->link == NULL)
// 		return;
// 	last = *head;
// 	temp = *head;
// 	while (last->link != NULL)
// 		last = last->link;
// 	*head = (*head)->link;
// 	temp->link = NULL;
// 	last->link = *head;
// 	if (ab == 'a')
// 		ft_printf("ra\n");
// 	if (ab == 'b')
// 		ft_printf("rb\n");
// }

void ft_rotaterev(t_list **head, char ab)
{
	t_list *temp;
	t_list *first;

	if (*head == NULL || (*head)->link == NULL)
		return;

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
void teststacks(t_list **head_a, t_list **head_b)
{
	t_list *temp_a;
	t_list *temp_b;

	// ft_push(head_a, head_b, 'a');
	// ft_ss(head_a, head_b);
	// ft_s(head_a, 'a');
	// ft_rr(head_a, 'a');
	// ft_rotate(head_a, 'a');
	temp_a = *head_a;
	temp_b = *head_b;
	while (temp_a != NULL)
	{
		printf("stack a =%d\n", temp_a->data);
		temp_a = temp_a->link;
	}
	// printf("stack a =%d\n", temp_a->data);
	while (temp_b != NULL)
	{
		printf("stack b =%d\n", temp_b->data);
		temp_b = temp_b->link;
	}
}

