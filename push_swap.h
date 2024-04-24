/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:10:02 by tgoossen          #+#    #+#             */
/*   Updated: 2024/04/24 10:24:52 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct node
{
	int			data;
	struct node	*link;
}	t_list;

typedef struct num
{
	int	rotate_a;
	int	rotate_b;
	int	temp_rot_a;
	int	temp_rot_b;
	int	temp_rrot_a;
	int	temp_rrot_b;
	int	rev_b;
	int	rev_a;
	int	rot_a;
	int	rot_b;
	int	nodes_a;
	int	nodes_b;
	int	high_b;
	int	low_b;
	int	high_a;
	int	low_a;
	int	num1_a;
	int	num2_a;
	int	num3_a;
	int	count_b;
	int	count_a;
	int	temp;
	int	numrot;
}	t_num;

int		ft_str_isnumeric(char *str);
int		validcheck(int argc, char *argv[]);
void	set0(t_num *man);
void	teststacks(t_list **head_a, t_list **head_b);
void	ft_s(t_list **head, char ab);
void	ft_ss(t_list **head_a, t_list **head_b);
void	ft_p(t_list **head_a, t_list **head_b, char ab);
void	ft_rotate(t_list **head, char ab);
void	ft_rr(t_list **head_a, t_list **head_b);
void	ft_rotaterev(t_list **head, char ab);
void	rrr(t_list **head_a, t_list **head_b);
void	sortmain(t_list **head_a, t_list **head_b, int numstacks, t_num *man);
int		stack_len(t_list **head);
void	five_or_more(t_list **head_a, t_list **head_b, t_num *man);
void	sort_last_three(t_list **head);
int		count_nodes(t_list **head);
int		check_dupe_num(t_list **head_a);
void	fix_two_node(t_list **head_a);
void	rotate(t_num *man, t_list **head_a, t_list **head_b);
void	rotate2(t_num *man, t_list **head_a, t_list **head_b);
void	push_to_a(t_list **head_a, t_list **head_b, t_num *man);
void	high_low(t_list **head_b, t_num *man);
void	make_high_and_low_a(t_list *head_a, t_num *man);
void	make_high_and_low_b(t_list *head_b, t_num *man);
void	take_3_numbers_a(t_list *head_a, t_num *man);
void	rotate_to_correct_spot(t_num *man, t_list **head_a, t_list **head_b);
int		check_if_push(t_list *head_a, t_list *head_b,
			t_list *last_a, t_num *man);
void	push_correct(t_list **head_a, t_list **head_b, t_num *man);
void	rot_a(t_list **head_a, t_num *man);
void	high_low(t_list **head_a, t_num *man);
void	sort_rotate_b(t_num *man);
void	sort_rotate_a(t_num *man);
void	count_moves(t_list **head_a, t_list **head_b, t_num *man);
void	push2(t_list **head_a, t_list **head_b);
void	make_high_and_low_a(t_list *head_a, t_num *man);
void	make_high_and_low_b(t_list *head_b, t_num *man);
void	setzero(t_num *man);
void	five_or_more(t_list **head_a, t_list **head_b, t_num *man);
void	check_if_fit(t_list *node_a, t_list *node_b,
			t_list *prev_b, t_num *man);

#endif