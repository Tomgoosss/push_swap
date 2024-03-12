#include "push_swap.h"

// t_list *makenode(int i, char *argv[])
// {
// 	t_list *link;
// 	link = malloc(sizeof(t_list));

// 	link->data = ft_atoi(argv[i]);
// 	link->link = NULL;
// 	return(link);
// }
// void add_node_back(t_list **head, t_list *node)
// {
// 	t_list *temp;
// 	printf("check nodes = %d\n", node->data);
// 	if (*head == NULL)
// 	{
// 		*head = node;
// 		return ;
// 	}
// 	temp = *head;
// 	while(temp->link != NULL)
// 	{
// 		temp = temp->link;
// 	}
// 	if (temp->link == NULL)
// 		temp->link = node;
// }

// void stackfiller(int argc, char *argv[], var *man)
// {
// 	t_list *head_a;
// 	int i = 1;

// 	head_a = NULL;

// 	while (i != argc)
// 	{
// 		add_node_back(&head_a, makenode(i, argv));
// 		i++;
// 	}
// }

int main(int argc, char *argv[])
{
	var *man;
	man = malloc(sizeof(var));
	set0(man);
	if (validcheck(argc, argv, man) == 1)
	{
		exit(EXIT_FAILURE);
	}
	stackfiller(argc, argv, man);
	free(man);
}
