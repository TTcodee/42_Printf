/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:21:52 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/14 11:45:58 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

unsigned int	looploop(t_list *message, unsigned int total)
{
	while (message)
	{
		if (ft_strncmp(message->type, "char", 5) == 0)
			total += pf_putchar(message->content);
		else if (ft_strncmp(message->type, "%", 2) == 0)
			total += pf_putchar("%");
		else if (ft_strncmp(message->type, "hex", 4) == 0)
			total += pf_putuint(message->content, 2);
		else if (ft_strncmp(message->type, "HEX", 4) == 0)
			total += pf_putuint(message->content, 1);
		else if (ft_strncmp(message->type, "str", 4) == 0)
			total += pf_putstr(message->content);
		else if (ft_strncmp(message->type, "ptr", 4) == 0)
			total += pf_printptr(message->content);
		else if (ft_strncmp(message->type, "unsigned int", 15) == 0)
			total += pf_putuint(message->content, 0);
		else if (ft_strncmp(message->type, "int", 4) == 0)
			total += pf_putnbr(message->content);
		message = message->next;
	}
	return (total);
}

int	pf_print_data(t_list **data)
{
	t_list			*message;
	unsigned int	total;

	total = 0;
	message = *data;
	return (looploop(message, total));
}
