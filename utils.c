
#include "push_swap.h"

int	get_lshift_limit(t_stack *stack)
{
	int	lshift_limit;
	int	tmp;

	lshift_limit = 0;
	tmp = stack->length;
	while (tmp)
	{
		tmp /= 2;
		lshift_limit++;
	}
	return (lshift_limit);
}

void	set_stack_index(t_stack *stack)
{
	t_node	*tmp;
	int		curr_value;
	int		i;

	i = stack->length;
	while (i)
	{
		tmp = stack->head;
		stack->head->index = 0;
		curr_value = stack->head->value;
		while (tmp)
		{
			if (tmp->value < curr_value)
				stack->head->index++;
			tmp = tmp->prev;
		}
		rotate(stack);
		i--;
	}
}

int	get_min_value(int argc, char **argv)
{
	int	min;

	min = ft_atoi(argv[argc - 1]);
	while ((argc - 1) > 0)
	{
		if (ft_atoi(argv[argc - 1]) < min)
			min = ft_atoi(argv[argc - 1]);
		argc--;
	}
	return (min);
}

int	get_max_value(int argc, char **argv)
{
	int	max;

	max = ft_atoi(argv[argc - 1]);
	while ((argc - 1) > 0)
	{
		if (ft_atoi(argv[argc - 1]) > max)
			max = ft_atoi(argv[argc - 1]);
		argc--;
	}
	return (max);
}
