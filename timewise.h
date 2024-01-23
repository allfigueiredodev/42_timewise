#ifndef TIMEWISE_H
# define TIMEWISE_H 

# define RED     		"\033[1;31m"
# define GREEN   		"\033[1;32m"
# define YELLOW 		"\033[1;33m"
# define BLUE   	 	"\033[1;34m"
# define MAGENTA    	"\033[1;35m"
# define CYAN    		"\033[1;36m"
# define WHITE    		"\033[1;37m"
# define DFT   			"\033[0m"

# define TRUE 1
# define FALSE 0

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_project
{
	int				id;
	int				duration;
	struct s_project *next;
}				t_project;

int			check_viability(int current, int etd);
void		add_node(t_project **proj, int id, int duration);
t_project	*ft_lstlast(t_project *lst);

#endif