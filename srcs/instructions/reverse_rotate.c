/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:28:23 by carlosortiz       #+#    #+#             */
/*   Updated: 2023/03/16 19:28:35 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*tail;
	t_stack	*btail;

	tail = get_bottom_stack(*stack_a);
	btail = get_before_bottom_stack(*stack_a);
	tail->next = *stack_a;
	btail->next = NULL;
	*stack_a = tail;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*tail;
	t_stack	*btail;

	tail = get_bottom_stack(*stack_b);
	btail = get_before_bottom_stack(*stack_b);
	tail->next = *stack_b;
	btail->next = NULL;
	*stack_b = tail;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
