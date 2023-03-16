#include "push_swap.h"

void	put_index(t_stack *stack)
{
	t_stack	*next;
	t_stack	*current;

	current = stack;
	while (current)
	{
		current->index = 0;
		next = stack;
		while (next)
		{
			if (current->i > next->i)
				current->index++;
			next = next->next;
		}
		current = current->next;
	}
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->i);
		stack = stack->next;
	}
}

t_stack	*add_stack(t_stack *stack, char *c)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (tmp)
	{
		tmp->i = ft_atoi(c);
		tmp->next = stack;
	}
	return (tmp);
}

t_stack	*create_stack(t_stack *stack, int j, char **av)
{
	int	i;

	i = tab_len(av);
	while (--i >= j)
		stack = add_stack(stack, av[i]);
	return (stack);
}
