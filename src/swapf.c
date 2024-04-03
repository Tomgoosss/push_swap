#include "../push_swap.h"

//Swap the first 2 elements at the top of stack a or b
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
// swap a and b at the same time
void	ft_ss(t_list **head_a, t_list **head_b)
{
	ft_s(head_a, 'x');
	ft_s(head_b, 'x');
	ft_printf("ss\n");
}
// Take the first element at the top of the stack and put it at the top of the stack.
void ft_p(t_list **head_a, t_list **head_b, char ab)
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
		ft_printf("pa\n");
	}
	else if (ab == 'a')
	{
		if(*head_a == NULL)
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
void ft_rotate(t_list **head, char ab)
{
	t_list *last;
	t_list *temp;

	if (*head == NULL || (*head)->link == NULL)
		return;
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
void ft_rr(t_list **head_a, t_list **head_b)
{
	ft_rotate(head_a, 'x');
	ft_rotate(head_b, 'x');
	ft_printf("rr\n");
}
// Shift down all elements of the stack by 1.
// The last element becomes the first one.
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

void rrr(t_list **head_a, t_list **head_b)
{
	ft_rotaterev(head_a, 'x');
	ft_rotaterev(head_b, 'x');
	ft_printf("rrr\n");
}

int stack_len(t_list **head)
{
	int i;
	t_list *temp;

	i = 0;
	temp = *head;

	while(temp != NULL)
	{
		temp = temp->link;
		i++;
	}
	printf("test len = %d\n", i);
	return(i);
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
	printf("\n");
	while (temp_b != NULL)
	{
		printf("stack b =%d\n", temp_b->data);
		temp_b = temp_b->link;
	}
	printf("\n");
}

