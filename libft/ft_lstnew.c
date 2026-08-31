/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:01:47 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// int	main(void)
// {
// 	t_list	*node;
// 	char	*str;

// 	str = "hello world";
// 	node = ft_lstnew(str);
// 	if (!node)
// 	{
// 		printf("malloc失敗\n");
// 		return (1);
// 	}
// 	printf("Content: %s\n", (char *)node->content);
// 	if (node->next == NULL)
// 		printf("Next: NULL (OK)\n");
// 	else
// 		printf("Next: Not NULL (Error)\n");
// 	free(node);
// 	return (0);
// }
