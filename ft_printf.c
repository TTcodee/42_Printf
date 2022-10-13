/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:39:42 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/12 21:40:27 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	is_error(t_list **words)
{
	t_list *walker;

	walker = *words;
	while (walker)
	{
		if (walker->content == NULL)
			return (1);
		walker = walker->next;
	}
	return (0);
}

int	is_equal(char *s1, char *s2)
{
	if (!ft_strncmp(s1, s2, 20))
		return (1);
	return (0);
}
void	del_lists(t_list **lists)
{
	t_list	*walker;

	walker = *lists;
	while (walker)
	{
		t_list	*tmp;

		tmp = walker->next;
		if (!(is_equal(walker->type, "ptr") || is_equal(walker->type, "%")))
			free(walker->content);
		free(walker);
		walker = tmp;
	}
	lists = NULL;
	return ;
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	t_list	**words;
	int	ret;

	ret = 0;
	va_start(arg, str);
	words = pf_get_data(ft_strdup(str), arg);
	if (is_error(words))
	{
		del_lists(words);
		return (-1);
	}
	ret = pf_print_data(words);
	va_end(arg);
	del_lists(words);
	free(words);
	return (ret);
}