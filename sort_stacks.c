#include "push_swap.h"

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
void fix_two_node(t_list **head_a)
{
	if((*head_a)->data < (*head_a)->link->data)
		ft_rotate(head_a, 'a');
}
// void sort_stackb(t_list **head_a, t_list **head_b)
// {
// 	push_first_three(head_a, head_b);
// }
void sort_four(t_list **head_a, t_list **head_b)
{
	ft_p(head_a, head_b, 'a');
	sort_last_three(head_a);
}
void	sortmain(t_list **head_a, t_list **head_b, int numstacks)
{
	if(numstacks == 1)
		return;
	if(numstacks == 2)
		fix_two_node(head_a);
	if(numstacks == 3)
		sort_last_three(head_a);
	if(numstacks == 4)
		sort_four(head_a, head_b);
	// sort_stackb(head_a, head_b);
}