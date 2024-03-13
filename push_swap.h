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
void 	ft_s(t_list **head, char ab);
void	ft_ss(t_list **head_a, t_list **head_b);
void	teststacks(t_list **head_a, t_list **head_b);

#endif