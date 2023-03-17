/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:21:46 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/17 10:10:24 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_bottom_stack(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_before_bottom_stack(t_stack *stack)
{
	while (stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

int	get_smallest(t_stack *stack, int *i)
{
	t_stack	*tmp;

	tmp = stack;
	stack = stack->next;
	while (stack)
	{
		if (tmp->i > stack->i)
		{
			*i += 1;
			tmp = stack;
		}
		stack = stack->next;
	}
	return (tmp->i);
}

int	get_biggest(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	stack = stack->next;
	while (stack)
	{
		if (tmp->index < stack->index)
			tmp = stack;
		stack = stack->next;
	}
	return (tmp->index);
}

int	get_stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
