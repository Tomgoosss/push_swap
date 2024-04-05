#include "../push_swap.h"

void sort_rotate_a(t_num *man)
{
	man->temp_rrot_b = 0;
	man->temp_rot_b = 0;
	man->temp_rot_b = man->count_b;
	man->temp_rrot_b= man->nodes_b - man->count_b;
}

void save_moves_a(t_num *man)
{
	sort_rotate_a(man);
	int count;
	int temp;

	count = 0;
	temp = INT_MAX;
	if(man->temp_rot_b > man->temp_rrot_b)
		count = man->temp_rot_b;
	else 
		count = man->temp_rrot_b;
	if(count < temp)
	{
		count = temp;
		man->rot_b = 0;
		man->rev_b = 0;
		if(man->temp_rot_b > man->temp_rrot_b)
			man->rot_b = man->temp_rot_b;
		else 
			man->rev_b = man->temp_rrot_b;
	}

}

void find_correct_spot(t_list **head_a, t_list **head_b, t_num *man)
{
	t_list *temp_a;
	t_list *temp_b;
	t_list *temp_b_prev;

	temp_a = *head_a;
	temp_b = *head_b;
	temp_b_prev = *head_b;
	while(temp_b_prev)
		temp_b_prev = temp_b_prev->link;
	while(temp_b)
	{
		if(temp_b->data < man->num1_a && temp_b_prev->data > man->num1_a)
			save_moves_a(man);
		if(temp_b->data < man->num2_a && temp_b_prev->data > man->num2_a)
			save_moves_a(man);
		if(temp_b->data < man->num3_a && temp_b_prev->data > man->num3_a)
			save_moves_a(man);
		temp_b_prev = temp_b;
		temp_b = temp_b->link;
		man->count_b++;
	}
}

void take_3_numbers_a(t_list *head_a, t_num *man)
{
	man->num1_a = head_a->data;
	man->num2_a = head_a->link->data;
	man->num3_a = head_a->link->link->data;
}
void rotate_to_correct_spot(t_num *man, t_list **head_b)
{
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
}

void push_correct(t_list **head_a, t_list **head_b, t_num *man)
{
	while ((*head_b)->data < man->num1_a)
		ft_p(head_a, head_b, 'b');
	// ft_rotaterev(head_a, 'a');
	// while ((*head_b)->data > man->num2_a)
	// 	ft_p(head_a, head_b, 'b');
	// while ((*head_b)->data > man->num3_a)
	// 	ft_p(head_a, head_b, 'b');
}
void push_to_a(t_list **head_a, t_list **head_b, t_num *man)
{
	man->nodes_b = count_nodes(head_b);
	take_3_numbers_a(*head_a, man);
	find_correct_spot(head_a, head_b, man);
	rotate_to_correct_spot(man, head_b);
	push_correct(head_a, head_b, man);
}