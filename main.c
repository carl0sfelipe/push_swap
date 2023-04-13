
#include "push_swap.h"

//void	print_stack(t_stack *stack)
//{ch
//	t_node	*node;
//
//	node = stack->head;
//	while (node)
//	{
//		ft_printf("%d: %d\n", node->index, node->value);
//		node = node->prev;
//	}
//}

static void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->length = 0;
}

int	validate_args(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if (!has_only_int(argc, argv))
		return (2);
	else if (is_out_of_bounds(argc, argv))
		return (3);
	else if (has_duplicate(argc, argv))
		return (4);
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->head;
	while (node)
	{
		tmp = node->prev;
		free(node);
		node = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;

	if (validate_args(argc, argv))
	{
		if (argc > 1)
			ft_printf("Error\n");
		return (1);
	}
	init_stack(&stack_a);
	init_stack(&stack_b);
	i = argc - 1;
	stack_a.min = get_min_value(argc, argv);
	stack_a.max = get_max_value(argc, argv);
	while (i > 0)
	{
		push(&stack_a, new_node(ft_atoi(argv[i])));
		i--;
	}
	set_stack_index(&stack_a);
	handle_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
