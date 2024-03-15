#include "push_swap.h"

void sort_b(t_list **head_a, t_list **head_b)
{
	t_list *temp;

	temp = *head_b;
	ft_p(head_a, head_b, 'a');
	ft_p(head_a, head_b, 'a');
	if((*head_b)->data < (*head_b)->link->data)
	{
		ft_s(head_b, 'b');
	}
}
void sortmain(t_list **head_a, t_list **head_b)
{
	sort_b(head_a, head_b);
}
