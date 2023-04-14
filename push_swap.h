/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:56:46 by csiqueir          #+#    #+#             */
/*   Updated: 2023/04/14 18:58:37 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include "printf/libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		length;
	int		min;
	int		max;
}			t_stack;

t_node	*new_node(int value);
void	push(t_stack *stack, t_node *new);
t_node	*pop(t_stack *stack);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

void	swap(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);

void	rotate(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	rev_rotate(t_stack *stack);
void	rra(t_stack *stack);

int		is_sorted(t_stack *stack_a);
void	handle_sort(t_stack *stack_a, t_stack *stack_b);
void	radix_sort_bit(t_stack *stack_a, t_stack *stack_b);

int		get_lshift_limit(t_stack *stack);
void	set_stack_index(t_stack *stack);
int		get_min_value(int argc, char **argv);
int		get_max_value(int argc, char **argv);

int		has_only_int(int argc, char **argv);
int		is_out_of_bounds(int argc, char **argv);
int		has_duplicate(int argc, char **argv);

#endif
