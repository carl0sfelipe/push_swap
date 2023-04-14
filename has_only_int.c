/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_only_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:55:31 by csiqueir          #+#    #+#             */
/*   Updated: 2023/04/14 18:55:36 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_only_int(int argc, char **argv)
{
	int	i;

	while ((argc - 1) > 0)
	{
		i = 0;
		while (argv[argc - 1][i])
		{
			if (argv[argc - 1][i] == '-' && i == 0)
				i++;
			if ((!ft_isdigit(argv[argc - 1][i])))
				return (0);
			i++;
		}
		argc--;
	}
	return (1);
}
