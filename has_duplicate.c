/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:54:52 by csiqueir          #+#    #+#             */
/*   Updated: 2023/04/14 18:55:01 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(int argc, char **argv)
{
	int	tmp;
	int	i;

	while ((argc - 1) > 0)
	{
		tmp = ft_atoi(argv[argc - 1]);
		i = argc - 1;
		while (i > 1)
		{
			if (ft_atoi(argv[i - 1]) == tmp)
				return (1);
			i--;
		}
		argc--;
	}
	return (0);
}
