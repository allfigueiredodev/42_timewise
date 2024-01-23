#include "timewise.h"

void	ft_lstadd_back(t_project **alst, t_project *new)
{
	t_project	*tmp;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = ft_lstlast(*(alst));
			tmp->next = new;
		}
	}
}
