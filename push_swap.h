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

int ft_str_isnumeric(char *str);
int validcheck(int argc, char *argv[], var *man);
void set0(var *man);

#endif