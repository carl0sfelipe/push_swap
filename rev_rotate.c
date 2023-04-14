/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:57:11 by csiqueir          #+#    #+#             */
/*   Updated: 2023/04/14 18:57:14 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	rev_rotate(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;

	if (stack->length < 2)
		return ;
	head = stack->head;
	tail = stack->tail;
	stack->head = stack->tail;
	stack->tail = tail->next;
	stack->head->prev = head;
	stack->tail->prev = NULL;
	stack->head->next = NULL;
	head->next = tail;
}
