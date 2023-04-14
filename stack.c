/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:57:43 by csiqueir          #+#    #+#             */
/*   Updated: 2023/04/14 18:57:46 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push(t_stack *stack, t_node *new)
{
	if (!stack->head)
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		new->prev = stack->head;
		stack->head->next = new;
		stack->head = new;
	}
	stack->length++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*head;

	head = stack->head;
	if (stack->length > 1)
	{
		stack->head = head->prev;
		head->prev = NULL;
		stack->head->next = NULL;
	}
	else
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	stack->length--;
	return (head);
}
