/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:21:04 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/16 12:40:21 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int len, t_stack **stack_a, t_stack **stack_b)
{
	if (is_stack_sorted(*stack_a))
		return ;
	put_index(*stack_a);
	if (len == 2)
		sort_two(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_four(stack_a, stack_b);
	else if (len == 5)
		sort_five(stack_a, stack_b);
	else
		sort_all(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*stackb;
	char	**tab;

	stack = NULL;
	stackb = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (not_number(tab, 0))
		{
			free_tab(tab);
			print_error("Error", NULL);
		}
		stack = create_stack(stack, 0, tab);
		free_tab(tab);
	}
	else
	{
		if (not_number(av, 1))
			print_error("Error", NULL);
		stack = create_stack(stack, 1, av);
	}
	sort(get_stack_len(stack), &stack, &stackb);
	free(stack);
	exit(0);
}
