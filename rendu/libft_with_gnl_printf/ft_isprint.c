/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:20:00 by amairia           #+#    #+#             */
/*   Updated: 2024/10/08 14:29:03 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	if (c == 127 || (c >= 0 && c <= 31) || c <= 0 || c >= 127)
		return (0);
	else
		return (16384);
}
