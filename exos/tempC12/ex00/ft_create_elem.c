#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (|NULL);
	res->data = data;
	res->next = NULL;
	return (res);
}
