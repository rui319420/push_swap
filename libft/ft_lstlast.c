/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:31:57 by rishiyam          #+#    #+#             */
/*   Updated: 2026/05/09 23:03:08 by rishiyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*res;

// 	node1 = ft_lstnew("1");
// 	node2 = ft_lstnew("2");
// 	node3 = ft_lstnew("3");
// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;
// 	res = ft_lstlast(node1);
// 	printf("%s", (char *)res->content);
// 	return (0);
// }
