/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:01:11 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (new_node == NULL)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void	*f_map(void *content)
// {
// 	char	*s;

// 	s = ft_strdup((char *)content);
// 	if (s)
// 		s[0] = 'A';
// 	return (s);
// }

// void	del_map(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*orig;
// 	t_list	*mapped;

// 	orig = ft_lstnew(ft_strdup("abc"));
// 	ft_lstadd_back(&orig, ft_lstnew(ft_strdup("def")));
// 	ft_lstadd_back(&orig, ft_lstnew(ft_strdup("ghi")));
// 	printf("Original first node: %s\n", (char *)orig->content);
// 	mapped = ft_lstmap(orig, f_map, del_map);
// 	if (mapped)
// 	{
// 		printf("Mapされた node1: %s\n", (char *)mapped->content);
// 		printf("Mapされた node2: %s\n", (char *)mapped->next->content);
// 	}
// 	ft_lstclear(&orig, del_map);
// 	ft_lstclear(&mapped, del_map);
// 	return (0);
// }
