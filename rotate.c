/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:57:21 by csiqueir          #+#    #+#             */
/*   Updated: 2023/04/14 18:57:24 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	rotate(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;

	if (stack->length < 2)
		return ;
	head = stack->head;
	tail = stack->tail;
	stack->head = stack->head->prev;
	head->prev = NULL;
	stack->tail->prev = head;
	stack->tail = head;
	stack->head->next = NULL;
	head->next = tail;
}
