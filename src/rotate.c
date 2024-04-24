/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:24:30 by tgoossen          #+#    #+#             */
/*   Updated: 2024/04/24 10:40:42 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_num *man, t_list **head_a, t_list **head_b)
{
	while (man->rev_b > 0 && man->rev_a > 0)
	{
		rrr(head_a, head_b);
		man->rev_b--;
		man->rev_a--;
	}
	while (man->rot_a > 0 && man->rot_b > 0)
	{
		ft_rr(head_a, head_b);
		man->rot_a--;
		man->rot_b--;
	}
	while (man->rot_a > 0)
	{
		ft_rotate(head_a, 'a');
		man->rot_a--;
	}
}

void	rotate2(t_num *man, t_list **head_a, t_list **head_b)
{
	while (man->rev_a > 0)
	{
		ft_rotaterev(head_a, 'a');
		man->rev_a--;
	}
	while (man->rot_b > 0)
	{
		ft_rotate(head_b, 'b');
		man->rot_b--;
	}
	while (man->rev_b > 0)
	{
		ft_rotaterev(head_b, 'b');
		man->rev_b--;
	}
}
