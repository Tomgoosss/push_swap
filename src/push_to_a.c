#include "../push_swap.h"

void sort_rotate_b(t_num *man)
{
	man->temp_rrot_b = 0;
	man->temp_rot_b = 0;
	man->temp_rot_b = man->count_b;
	man->temp_rrot_b= man->nodes_b - man->count_b;
}

void sort_rotate_a(t_num *man)
{
	man->temp_rrot_a = 0;
	man->temp_rot_a = 0;
	man->temp_rot_a = man->count_a;
	man->temp_rrot_a = man->nodes_a - man->count_a;
}

void save_moves_a(t_num *man, int num)
{
	sort_rotate_b(man);
	int count;
	int temp;

	count = 0;
	temp = INT_MAX;
	if(man->temp_rot_b < man->temp_rrot_b)
		count = man->temp_rot_b;
	else 
		count = man->temp_rrot_b;
	if(count < temp)
	{
		count = temp;
		man->rot_b = 0;
		man->rev_b = 0;
		if(man->temp_rot_b < man->temp_rrot_b)
			man->rot_b = man->temp_rot_b;
		else 
			man->rev_b = man->temp_rrot_b;
		man->numrot = num;
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
	while(temp_b_prev->link)
		temp_b_prev = temp_b_prev->link;
	while(temp_b)
	{
		if(temp_b->data < man->num1_a && temp_b_prev->data > man->num1_a)
			save_moves_a(man, 1);
		if(temp_b->data < man->num2_a && temp_b_prev->data > man->num2_a)
			save_moves_a(man, 2);
		if(temp_b->data < man->num3_a && temp_b_prev->data > man->num3_a)
			save_moves_a(man, 3);
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
void rotate_to_correct_spot(t_num *man, t_list **head_a ,t_list **head_b)
{
	if(man->numrot == 2)
		ft_rotate(head_a, 'a');
	if(man->numrot == 3)
		ft_rotaterev(head_a, 'a');
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

int check_if_push(t_list *head_a, t_list *head_b, t_list *last_b, t_num *man)
{
	if(!head_b)
		return(0);
	if (head_b->data < head_a->data && head_b->data > last_b->data)
		return(1);
	if(head_b->data > man->high_a && head_b->data == man->high_b)
		return(1);
	if(head_b->data < man->low_a && head_a->data == man->low_a)
		return(1);

	return (0);
}

void push_correct(t_list **head_a, t_list **head_b, t_num *man)
{
	take_3_numbers_a(*head_a, man);
	t_list *last_a;

	while(*head_b)
	{
		make_high_and_low_a(*head_a, man);
		make_high_and_low_b(*head_b, man);
		last_a = *head_a;
		while (last_a->link)
			last_a = last_a->link;
		while(check_if_push(*head_a, *head_b, last_a, man))
			ft_p(head_a, head_b, 'b');
		// teststacks(head_a, head_b);
		ft_rotaterev(head_a, 'a');
	}
}
void rot_a(t_list **head_a, t_num *man)
{
	if(man->temp_rot_a < man->temp_rrot_a)
	{
		while(man->temp_rot_a != 0)
		{
			ft_rotate(head_a, 'a');
			man->temp_rot_a--;
		}
	}
	else
	{
		while(man->temp_rrot_a != 0)
		{
			ft_rotaterev(head_a, 'a');
			man->temp_rrot_a--;
		}
	}
}

void high_low(t_list **head_a, t_num *man)
{
	int temp;
	int temp_i;
	t_list *temp_a;

	temp = INT_MAX;
	temp_i = 0;
	temp_a = *head_a;
	man->count_a = 0;
	while(temp_a)
	{
		if (temp_a->data < temp)
		{
			temp = temp_a->data;
			man->count_a = temp_i;
			// printf("low = %d\n", temp);
		}
		temp_a = temp_a->link;
		temp_i++;
	}
	man->nodes_a = count_nodes(head_a);
	sort_rotate_a(man);
	rot_a(head_a, man);
}

void push_to_a(t_list **head_a, t_list **head_b, t_num *man)
{
	man->nodes_b = count_nodes(head_b);
	take_3_numbers_a(*head_a, man);
	find_correct_spot(head_a, head_b, man);
	rotate_to_correct_spot(man, head_a, head_b);
	push_correct(head_a, head_b, man);
	high_low(head_a, man);
}