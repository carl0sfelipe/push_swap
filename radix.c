
#include "push_swap.h"

static void	ra_log(int ra_count)
{
	while (ra_count)
	{
		ft_printf("ra\n");
		ra_count--;
	}
}

static void	rb_log(int rb_count)
{
	while (rb_count)
	{
		ft_printf("rb\n");
		rb_count--;
	}
}

static void	radix_sort_pb(t_stack *stack_a, t_stack *stack_b, int lshift)
{
	int	i;
	int	ra_count;

	ra_count = 0;
	i = stack_a->length;
	if (is_sorted(stack_a))
		return ;
	while (i && stack_a->length > 0)
	{
		if ((stack_a->head->index & 1 << lshift) == 0)
		{
			ra_log(ra_count);
			pb(stack_a, stack_b);
			ra_count = 0;
		}
		else
		{
			rotate(stack_a);
			ra_count++;
		}
		i--;
	}
	if (ra_count == stack_a->length)
		return ;
	ra_log(ra_count);
}

static void	radix_sort_pa(t_stack *stack_a, t_stack *stack_b, int lshift)
{
	int	i;
	int	rb_count;

	rb_count = 0;
	i = stack_b->length;
	while (i && stack_b->length > 0)
	{
		if ((stack_b->head->index & 1 << (lshift + 1)) != 0)
		{
			rb_log(rb_count);
			pa(stack_a, stack_b);
			rb_count = 0;
		}
		else
		{
			rotate(stack_b);
			rb_count++;
		}
		i--;
	}
	if (rb_count == stack_b->length)
		return ;
	rb_log(rb_count);
}

void	radix_sort_bit(t_stack *stack_a, t_stack *stack_b)
{
	int	lshift;
	int	lshift_limit;

	lshift = 0;
	lshift_limit = get_lshift_limit(stack_a);
	while (lshift <= lshift_limit + 1)
	{
		radix_sort_pb(stack_a, stack_b, lshift);
		radix_sort_pa(stack_a, stack_b, lshift);
		lshift++;
	}
	while (stack_b->length > 0)
		pa(stack_a, stack_b);
}
