#include "get_next_line.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int test = open(av[1], O_RDONLY);
	int testdeux = open(av[2], O_RDONLY);
	printf("main %d %d %d\n", ac, test, testdeux);
	char *vrai;
//		//vrai = get_next_line(3);/		//free(vrai);
		//vrai = get_next_line(3);
		//free(vrai);
		while (1)
		{
			vrai = get_next_line(3);
			if (vrai == NULL)
			{
				free(vrai);
				break ;
			}
			printf("\n ligne lu : %s", vrai);
			free(vrai);
		}
		
	//char *m;

	//m = get_next_line(3);
	//printf("\n%s", m);
	return (0);
}
