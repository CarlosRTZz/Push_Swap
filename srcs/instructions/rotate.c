/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:27:48 by carlosortiz       #+#    #+#             */
/*   Updated: 2023/03/16 19:27:59 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*tail;
	t_stack	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tail = get_bottom_stack(*stack_a);
	tmp->next = NULL;
	tail->next = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*tail;
	t_stack	*tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tail = get_bottom_stack(*stack_b);
	tmp->next = NULL;
	tail->next = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
