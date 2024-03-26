#include "../push_swap.h"

int most_efficent_node(t_list **node_a, t_list **node_b, t_num *man)
{
	int i;
	int y;
	int count;

	i = 0;
	y = 0;
	

	if((*node_a)->data < (*node_b)->data)
	{

	}

}

void count_moves(t_list **head_a, t_list **head_b, t_num *man)
{
	t_list *check_a;
	t_list *check_b;
	int		temp;

	temp = INT_MAX;
	check_a = *head_a;
	check_b = *head_b;
	while(check_a != NULL);
	{
		while(check_b != NULL)
		{
			if(most_efficent_node(check_a, check_b, man) < temp)
				temp = most_efficent_node(check_a, check_b, man);
			man->rotate_b++;
			if(man->rotate_b > man->nodes_b / 2)
				man->revrotate_b++;
			check_b = check_b->link;
		}
		check_b = head_b;
		if(most_efficent_node(check_a, check_b, man) < temp)
			temp = most_efficent_node(check_a, check_b, man);
		man->rotate_a++;
		if(man->rotate_a > man->nodes_a / 2)
			man->revrotate_a++;
		check_a = check_a->link;
	}
}

void push2(t_list **head_a, t_list **head_b)
{
	ft_p(head_a, head_b, 'a');
	ft_p(head_a, head_b, 'a');
}

void five_or_more(t_list **head_a, t_list **head_b, t_num *man)
{
	push2(head_a, head_b);
	while(count_nodes(head_a) > 3)
	{
		man->nodes_a = count_nodes(head_a);
		man->nodes_b = count_nodes(head_b);
		count_moves(head_a, head_b, man);
	}
}