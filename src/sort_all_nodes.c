#include "../push_swap.h"

void push2(t_list **head_a, t_list **head_b)
{
	ft_p(head_a, head_b, 'a');
	ft_p(head_a, head_b, 'a');
}

void five_or_more(t_list **head_a, t_list **head_b)
{
	push2(head_a, head_b);
	push_rest(head_a, head_b);
}