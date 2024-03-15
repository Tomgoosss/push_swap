#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct node {
	int data;
	struct node *link;
} t_list;

typedef struct var{
	char *charnum;
	int allnum;
} var;

int		ft_str_isnumeric(char *str);
int		validcheck(int argc, char *argv[], var *man);
void	set0(var *man);
void	teststacks(t_list **head_a, t_list **head_b);
void	ft_s(t_list **head, char ab);
void	ft_ss(t_list **head_a, t_list **head_b);
void	ft_p(t_list **head_a, t_list **head_b, char ab);
void	ft_rotate(t_list **head, char ab);
void	ft_rr(t_list **head_a, t_list **head_b);
void	ft_rotaterev(t_list **head, char ab);
void	rrr(t_list **head_a, t_list **head_b);
void	sortmain(t_list **head_a, t_list **head_b);
int		stack_len(t_list **head);
#endif