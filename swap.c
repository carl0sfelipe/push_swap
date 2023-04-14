/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:57:53 by csiqueir          #+#    #+#             */
/*   Updated: 2023/04/14 18:57:57 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	swap(t_stack *stack)
{
	t_node	*head;

	if (stack->length < 2)
		return ;
	head = stack->head;
	stack->head = stack->head->prev;
	head->prev = stack->head->prev;
	stack->head->prev = head;
	if (stack->length > 2)
		head->prev->next = head;
	head->next = stack->head;
	stack->head->next = NULL;
}
