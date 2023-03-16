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

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
}

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
