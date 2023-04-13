
#include "push_swap.h"

static void	sort_three(t_stack *stack)
{
	t_node	*top;
	t_node	*mid;
	t_node	*bot;

	top = stack->head;
	mid = stack->head->prev;
	bot = stack->tail;
	if ((top->value < mid->value) && (mid->value <= bot->value))
		return ;
	else if ((top->value > mid->value) && (top->value > bot->value))
		ra(stack);
	else if ((mid->value > top->value) && (mid->value > bot->value))
		rra(stack);
	else if (top->value > mid->value)
		sa(stack);
	sort_three(stack);
}

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node->prev)
	{
		if (node->value > node->prev->value)
			return (0);
		node = node->prev;
	}
	return (1);
}

static void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	while (stack_a->length > 3)
	{
		if (stack_a->head->value == stack_a->min)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	while (stack_a->length > 3)
	{
		if (stack_a->head->value == stack_a->min
			|| stack_a->head->value == stack_a->max)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	if (stack_b->head->value == stack_a->max)
		sb(stack_b);
	while (stack_b->length > 0)
		pa(stack_a, stack_b);
	ra(stack_a);
}

void	handle_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->length == 1)
		return ;
	else if (stack_a->length <= 3)
		sort_three(stack_a);
	else if (stack_a->length == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->length == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort_bit(stack_a, stack_b);
}
