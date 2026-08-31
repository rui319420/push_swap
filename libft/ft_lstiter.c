/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:59:59 by rishiyam          #+#    #+#             */
/*   Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	ft_change_to_A(void *content)
// {
// 	char	*s;

// 	s = (char *)content;
// 	s[0] = 'A';
// 	s[1] = '\0';
// }

// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;

// 	node1 = ft_lstnew(ft_strdup("1"));
// 	node2 = ft_lstnew(ft_strdup("2"));
// 	node3 = ft_lstnew(ft_strdup("3"));
// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;
// 	printf("%s\n", (char *)node1->content);
// 	printf("%s\n", (char *)node2->content);
// 	printf("%s\n", (char *)node3->content);
// 	ft_lstiter(node1, ft_change_to_A);
// 	printf("\n");
// 	printf("%s\n", (char *)node1->content);
// 	printf("%s\n", (char *)node2->content);
// 	printf("%s\n", (char *)node3->content);
// 	ft_lstclear(&node1, free);
// 	return (0);
// }
