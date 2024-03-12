#include "push_swap.h"


t_list *makenode(char *argv[], int i)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	
	node->data = ft_atoi(argv[i]);
	node->link = NULL;

	return(node);
}
void putnode(t_list **head, t_list *node)
{
	t_list *temp;

	
	if(*head == NULL)
	{
		*head = node;
		return;
	}
	temp = *head;
	if (temp->link != NULL)
		temp = temp->link;
	if (temp->link == NULL)
		temp->link = node;
}

t_list *fillnodes(int argc, char *argv[])
{
	t_list head;

	int i = 1;

	while (i < argc)
	{
		putnode(&head, makenode(argv, i));
		i++;
	}
}
int main(int argc, char *argv[])
{
	int i = 1;

	fillnodes(argc, argv);
}

