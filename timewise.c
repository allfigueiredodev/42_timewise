#include "timewise.h"

int main(void)
{
	int current_project;
	int etd;

	// printf("%sHow many weeks ago did you start your formation?\n%sTip: Input only the number.%s\n", YELLOW, MAGENTA, DFT);
	// scanf("%d", &start_date);
	printf("%sWhat project are you currently on?\n%sTip: Consider the project intra index, e.g: libft == 00, gnl == 01 and so on.%s\n", YELLOW, MAGENTA, DFT);
	scanf("%d", &current_project);
	printf("%sIn how many weeks from now do you wish to finish your formation?\n%sTip: Input only the number.%s\n", YELLOW, MAGENTA, DFT);
	scanf("%d", &etd);

	if (check_viability(current_project, etd))
		printf("%sYou have enough time. :D%s\n", GREEN, DFT);
	else
		printf("%sYou need to speed up your pace!! ò_ó%s\n", RED, DFT);

	// printf("%sStart date: %s%d%s\n", BLUE, GREEN, start_date, DFT);
	// printf("%scurrent project: %s%d%s\n", BLUE, GREEN, current_project, DFT);
	// printf("%sEstimated time to delivery: %s%d%s\n", BLUE, GREEN, etd, DFT);
}

int	check_viability(int current, int etd)
{
	int	i = -1;
	int	result = 0;
	int	duration[15] = {4, 2, 2, 2, 4, 2, 4, 6, 2, 2, 6, 6, 4, 6, 8};
	t_project *proj;

	while (++i < 15)
		add_node(&proj, i, duration[i]);
	i = -1;
	while (++i < current)
		proj = proj->next;
	while (i++ < 15)
		result += proj->duration;
	free(proj);
	if (etd >= result)
		return (TRUE);
	else
		return (FALSE);
}

void	add_node(t_project **proj, int id, int duration)
{
	t_project	*node;

	node = (t_project *)malloc(sizeof(t_project));
	if (!node)
		return ;
	node->id = id;
	node->duration = duration;
	node->next = NULL;
	if (!*proj)
		*proj = node;
	else
		ft_lstlast(*proj)->next = node;
}

t_project	*ft_lstlast(t_project *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}