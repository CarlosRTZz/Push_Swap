/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:21:39 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/16 09:21:41 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	if (!is_stack_sorted(*stack))
		sa(stack);
}

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->i;
	second = (*stack_a)->next->i;
	third = (*stack_a)->next->next->i;
	if (second < first && second < third && third > first)
		sa(stack_a);
	if (second < first && second < third && third < first)
		ra(stack_a);
	if (third < first && third < second && first < second)
		rra(stack_a);
	if (third < first && third < second && first > second)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (first < second && first < third && second > third)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int		smallest;

	smallest = get_smallest(*stack_a);
	while ((*stack_a)->i > smallest)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;

	smallest = get_smallest(*stack_a);
	while ((*stack_a)->i > smallest)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	biggest;
	int	i;
	int	j;
	int	k;

	k = 0;
	i = -1;
	biggest = get_biggest(*stack_a);
	size = get_stack_len(*stack_a);
	while (((biggest) >> k) != 0)
		k++;
	while (++i < k)
	{
		j = -1;
		while (++j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}
