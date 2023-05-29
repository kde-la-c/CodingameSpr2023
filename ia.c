#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

typedef struct	s_cell
{
	int	type;
	int initial_resources;
	int neigh_0;
	int neigh_1;
	int neigh_2;
	int neigh_3;
	int neigh_4;
	int neigh_5;
	int distance;
	int resources; 
	int my_ants;
	int opp_ants;
}				t_cell;

int isempty(int **crystals, int arr[], int size)
{
	int i = 0;
	while (i < size)
		if (crystals[arr[i++]][1])
			return 0;
	return 1;
}

int main()
{
	int tick = 0;
	int number_of_cells;
	int number_of_ressource_cells = 0;
	scanf("%d", &number_of_cells);
	t_cell	cells[number_of_cells];
	int		crystals[10][2];
	for (int i = 0; i < number_of_cells; i++) {
		scanf("%d%d%d%d%d%d%d%d", 
			&cells[i].type, 
			&cells[i].initial_resources, 
			&cells[i].neigh_0, 
			&cells[i].neigh_1, 
			&cells[i].neigh_2, 
			&cells[i].neigh_3, 
			&cells[i].neigh_4, 
			&cells[i].neigh_5
		);
		if (cells[i].type == 2)
		{
			crystals[number_of_ressource_cells][0] = i;
			crystals[number_of_ressource_cells++][1] = cells[i].initial_resources;
		}
	}

	int number_of_bases;
	scanf("%d", &number_of_bases);

	int my_base_index;
	scanf("%d", &my_base_index);

	int opp_base_index;
	scanf("%d", &opp_base_index);

	fprintf(stderr, "nbress :%d\n", number_of_ressource_cells);

	int current[10];
	// game loop
	while (1) {
		for (int i = 0; i < number_of_cells; i++) {
			scanf("%d%d%d", 
				&cells[i].resources, 
				&cells[i].my_ants, 
				&cells[i].opp_ants
			);
		}

		int targ;
		int	tmp = 1;
		if (isempty(crystals, current, 10))
		{
			for (int i = 0; i < number_of_ressource_cells; i++)
			{
				if (crystals[i][1] > tmp)
				{
					tmp = crystals[i][1];
					targ = i;
				}
			}
			tmp = 0;
			for (int i = 0; i < number_of_ressource_cells; i++)
			{
				if (crystals[i][1] == targ)
					current[tmp++] = crystals[i][0];
			}
		}
		for (int i = 0; i < tmp; i++)
		{
			printf("LINE %d %d %d\n", my_base_index, current[i], 100 / (tmp - 1));
		}
		

		// printf("WAIT\n");

		tick++;
	}

	return 0;
}