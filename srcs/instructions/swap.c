/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:21:17 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/16 19:28:18 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*first;

	first = *stack_a;
	tmp = (*stack_a)->next;
	first->next = tmp->next;
	tmp->next = first;
	*stack_a = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*first;

	first = *stack_b;
	tmp = (*stack_b)->next;
	first->next = tmp->next;
	tmp->next = first;
	*stack_b = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
