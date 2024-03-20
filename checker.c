#include "push_swap.h"

int ft_str_isnumeric(char *str)
{
    int i = 0;
	if (str[i] == '-')
		i++;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}
// checks if the argv is all numbers
int validcheck(int argc, char *argv[], var *man)
{
	int i;

	i = 1;
    while(i != argc)
    {
        if (!ft_str_isnumeric(argv[i]))
        {
            printf("Error\n");
            return (1);
        }
        i++;
    }
	return(0);
}
// set all struct to 0
void set0(var *man)
{
	man->charnum = 0;
	man->allnum = 0;
}