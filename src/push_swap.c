#include "../push_swap.h"

t_list *makenode(char *num)
{
	t_list *link;
	link = malloc(sizeof(t_list));

	link->data = ft_atoi(num);
	link->link = NULL;
	return(link);
}
void add_node_back(t_list **head, t_list *node)
{
	t_list *temp;
	// printf("check nodes = %d\n", node->data);
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	temp = *head;
	while(temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = node;
}

void stackfiller(int argc, char *argv[], t_num *man, t_list **head_a)
{
	int i = 1;

	*head_a = NULL;
	while (i < argc)
	{
		add_node_back(head_a, makenode(argv[i]));
		i++;
	}
}

void free_nodes(t_list **head_a, t_list **head_b)
{
	t_list *temp;

	while(*head_a != NULL)
	{
		temp = (*head_a)->link;
		free(*head_a);
		*head_a = temp;
	}
	while(*head_b != NULL)
	{
		temp = (*head_b)->link;
		free(*head_b);
		*head_b = temp;
	}
}

int main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list *head_b;
	t_num *man;

	head_b = NULL;
	man = ft_calloc(1, sizeof(t_num));
	if (validcheck(argc, argv) == 1)
	{
		write(2, "Error\n", 6);
		free(man);
		exit(EXIT_FAILURE);
	}
	stackfiller(argc, argv, man, &head_a);
	if(check_dupe_num(&head_a) == 1)
	{
		write(2, "Error\n", 6);
		free_nodes(&head_a, &head_b);
		free(man);
		exit(EXIT_FAILURE);
	}
	sortmain(&head_a, &head_b, argc - 1, man);
	// printf("amount of nodes = %d\n", count_nodes(&head_a));
	// teststacks(&head_a, &head_b);
	free_nodes(&head_a, &head_b);
	free(man);
}
