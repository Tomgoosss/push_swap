/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:39:40 by tgoossen          #+#    #+#             */
/*   Updated: 2024/04/18 13:18:45 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	take_3_numbers_a(t_list *head_a, t_num *man)
{
	man->num1_a = head_a->data;
	man->num2_a = head_a->link->data;
	man->num3_a = head_a->link->link->data;
}

int	check_dupe_num(t_list **head_a)
{
	t_list	*temp;
	t_list	*iterator;

	if (*head_a == NULL)
		return (1);
	temp = *head_a;
	iterator = *head_a;
	while (temp != NULL)
	{
		while (iterator != NULL)
		{
			if (iterator->data == temp->data && iterator->link != temp->link)
				return (1);
			iterator = iterator->link;
		}
		iterator = *head_a;
		temp = temp->link;
	}
	return (0);
}

int	ft_str_isnumeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_max_min(char *str)
{
	long long	num;
	int			len;

	len = ft_strlen(str);
	if (len > 19 || (len == 19 && str[0] == '9'))
		return (1);
	num = ft_atoll(str);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

// checks if the argv is all numbers
int	validcheck(int nodeamount, char *argv[])
{
	int	i;

	i = 1;
	while (i != nodeamount)
	{
		if (ft_str_isnumeric(argv[i]) == 1)
			return (1);
		if (check_max_min(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
