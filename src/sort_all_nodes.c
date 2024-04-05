#include "../push_swap.h"


int check_correct_place(t_list *node_a, t_list *node_b,t_list *prev_b, t_num *man)
{
	if(node_a->data > node_b->data && node_a->data < prev_b->data)
		return(1);
	if(node_a->data > man->high_b && node_b->data == man->high_b)
		return(1);
	if(node_a->data < man->low_b && node_b->data == man->high_b)
		return(1);

	return(0);
}

// this makes the reverse rotate and it makes the normale rotate in 2 differend ints
// with the / 2 it halfs it to make sure that normal rotate isnt bigger then half of the nodes
// and with rev rotate i do / 2 - 1 cus half int (1.5) rounds up to 1 so that why i add 0.5 so it rounds it up to 2
void sort_rotate(t_num *man)
{
	man->temp_rrot_b = 0;
	man->temp_rrot_a = 0;
	man->temp_rot_a = 0;
	man->temp_rot_b = 0;
	man->temp_rrot_b = man->nodes_b - man->rotate_b;
	man->temp_rrot_a = man->nodes_a - man->rotate_a;
	man->temp_rot_a = man->rotate_a;
	man->temp_rot_b = man->rotate_b;
}

void rotate(t_num *man, t_list **head_a, t_list **head_b)
{
	printf("this is rorate \n rot_a %d\n rev_a %d\n rot_b %d\n rev_b %d\n",man->rot_a, man->rev_a, man->rot_b, man->rev_b);
	// 	teststacks(head_a, head_b);
	while(man->rot_a > 0)
	{
		ft_rotate(head_a, 'a');
		man->rot_a--;
	}
	while(man->rev_a > 0)
	{
		ft_rotaterev(head_a, 'a');
		man->rev_a--;
	}
	while(man->rot_b > 0)
	{
		ft_rotate(head_b, 'b');
		man->rot_b--;
	}
	while(man->rev_b > 0)
	{
		ft_rotaterev(head_b, 'b');
		man->rev_b--;
	}
	// teststacks(head_a, head_b);
}

void safe_moves(t_num *man)
{
	man->rot_a = 0;
	man->rot_b = 0;
	man->rev_b = 0;
	man->rev_a = 0;
	if(man->temp_rot_a < man->temp_rrot_a)
		man->rot_a = man->temp_rot_a;
	else
		man->rev_a = man->temp_rrot_a;
	if (man->temp_rot_b < man->temp_rrot_b)
		man->rot_b = man->temp_rot_b;
	else
		man->rev_b = man->temp_rrot_b;
	// printf("this is safe moves \n rot a %d\n rev a %d\n rot b %d\n rev b %d\n", man->rot_a, man->rev_a, man->rot_b, man->rev_b);
}

void check_if_fit(t_list *node_a, t_list *node_b,t_list *prev_b, t_num *man)
{
	sort_rotate(man);

	int count;
	int temp;

	count = 0;
	if(check_correct_place(node_a, node_b, prev_b, man))
	{
		if (man->temp_rot_a < man->temp_rrot_a)
			count += man->temp_rot_a;
		else
			count += man->temp_rrot_a;
		if (man->temp_rot_b < man->temp_rrot_b)
			count += man->temp_rot_b;
		else
			count += man->temp_rrot_b;
	}
	else
		return;
	if (count < temp)
	{
		temp = count;
		safe_moves(man);
		// printf("count = %d\n", temp);
	}
}

void count_moves(t_list **head_a, t_list **head_b, t_num *man)
{
	t_list *check_a;
	t_list *check_b;
	t_list *prev_b;
	int		temp;

	temp = INT_MAX;
	prev_b = *head_b;
	check_a = *head_a;
	check_b = *head_b;
	while(prev_b->link != NULL)
		prev_b = prev_b->link;
	// printf("test last %d", prev_b->data);
	man->rotate_a = 0;
	while(man->rotate_a < man->nodes_a)
	{
		while(man->rotate_b < man->nodes_b)
		{
			check_if_fit(check_a, check_b, prev_b, man);
			prev_b = check_b;
			check_b = check_b->link;
			man->rotate_b++;
		}
		check_b = *head_b;
		man->rotate_b = 0;
		check_a = check_a->link;
		man->rotate_a++;
	}
	// printf("rot a %d,\n ver rot a %d,\n rot b %d,\n rev rot b %d,\n", man->temp_rot_a, man->temp_rrot_a, man->temp_rot_b, man->temp_rrot_b);
}

void push2(t_list **head_a, t_list **head_b)
{
	ft_p(head_a, head_b, 'a');
	ft_p(head_a, head_b, 'a');
}

void make_high_and_low(t_list *head_b, t_num * man)
{
	man->high_b = 0;
	man->low_b = INT_MAX;

	while(head_b != NULL)
	{
		if(head_b->data > man->high_b)
			man->high_b = head_b->data;
		if(head_b->data < man->low_b)
			man->low_b = head_b->data;
		head_b = head_b->link;
	}
}
void setzero(t_num *man)
{
	man->temp_rot_a = 0;
	man->temp_rot_b = 0;
	man->temp_rrot_a = 0;
	man->temp_rrot_b = 0;
	// man->rot_a = 0;
	// man->rot_b = 0;
	// man->rev_a = 0;
	// man->rev_b = 0;
}

void five_or_more(t_list **head_a, t_list **head_b, t_num *man)
{
	int i = 0;
	push2(head_a, head_b);

	if((*head_b)->data < (*head_b)->link->data)
		ft_s(head_b, 'b');
	man->nodes_a = count_nodes(head_a);
	while(man->nodes_a > 3)
	{
		man->nodes_a = count_nodes(head_a);
		man->nodes_b = count_nodes(head_b);
		make_high_and_low(*head_b, man);
		count_moves(head_a, head_b, man);
		rotate(man, head_a, head_b);
		ft_p(head_a, head_b, 'a');
		man->nodes_a = count_nodes(head_a);
		// teststacks(head_a, head_b);
	}
		// teststacks(head_a, head_b);
		// sort_last_three(head_a);
		// push_to_a(head_a, head_b, man);

}