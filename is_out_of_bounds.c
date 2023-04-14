/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_out_of_bounds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:55:53 by csiqueir          #+#    #+#             */
/*   Updated: 2023/04/14 18:55:59 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_min_limit(char *number)
{
	const char	*min;
	int			i;

	min = "-2147483648";
	i = 1;
	while (number[i])
	{
		if (number[0] != '-')
			return (1);
		if ((number[i]) - '0' > min[i] - '0')
			return (1);
		if ((number[i]) - '0' < min[i] - '0')
			return (0);
		i++;
	}
	return (0);
}

static int	check_max_limit(char *number)
{
	const char	*max;
	int			i;

	max = "2147483647";
	i = 0;
	while (number[i])
	{
		if ((number[i]) - '0' > max[i] - '0')
			return (1);
		if ((number[i]) - '0' < max[i] - '0')
			return (0);
		i++;
	}
	return (0);
}

int	is_out_of_bounds(int argc, char **argv)
{
	while ((argc - 1) > 0)
	{
		if (ft_strlen(argv[argc - 1]) > 11)
			return (1);
		else if (ft_strlen(argv[argc - 1]) == 11)
			return (check_min_limit(argv[argc - 1]));
		else if (ft_strlen(argv[argc - 1]) == 10)
			return (check_max_limit(argv[argc - 1]));
		argc--;
	}
	return (0);
}
