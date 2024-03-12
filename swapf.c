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
}

void	ft_ss(t_list **head_a, t_list **head_b)
{
	ft_s(head_a, 2);
	ft_s(head_b, 2);
	// return ("ss"); // replace with how you keep track of past instructions
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
	}
	else
	{
		if(*head_a == NULL)
			return ;

		temp = *head_a;
		*head_a = (*head_a)->link;
		temp->link = *head_b;
		*head_b = temp;
	}
}


void teststacks(t_list **head_a, t_list **head_b)
{
	t_list *temp_a;
	t_list *temp_b;

	temp_a = *head_a;
	temp_b = *head_b;
	while (temp_a != NULL)
	{
		printf("stack a =%d\n", temp_a->data);
		temp_a = temp_a->link;
	}
	while (temp_a != NULL)
	{
		printf("stack b =%d\n", temp_b->data);
		temp_b = temp_b->link;
	}
}

