/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:21:49 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/17 09:42:17 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *str, t_stack *stack, char **tab)
{
	if (stack)
		free_stack(stack);
	if (tab)
		free_tab(tab);
	ft_putendl_fd(str, 1);
	exit(1);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_atoi2(const char *str, t_stack *stack, char **tab)
{
	long long	nb;
	long		sign;
	int			i;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] == 0)
		print_error("Error", stack, tab);
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i++] - '0';
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			print_error("Error", stack, tab);
	}
	if ((int)ft_strlen(str) != i || str[i] == '-' || str[i] == '+')
		print_error("Error", stack, tab);
	return ((int)(nb * sign));
}
