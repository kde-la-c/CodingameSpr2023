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
		for (int i = 0; i < number_of_ressource_cells; i++)
		{
			if (crystals[i][1] > tmp)
			{
				tmp = crystals[i][1];
				targ = i;
			}
		}
		/* fprintf(stderr, "%d %d %d %d %d %d %d %d %d %d %d \n", 
			cells[0].type, 
			cells[0].initial_resources, 
			cells[0].neigh_0, 
			cells[0].neigh_1, 
			cells[0].neigh_2, 
			cells[0].neigh_3, 
			cells[0].neigh_4, 
			cells[0].neigh_5, 
			cells[0].resources, 
			cells[0].my_ants, 
			cells[0].opp_ants
		); */

		printf("LINE %d %d 100\n", my_base_index, targ);

		// printf("WAIT\n");

		tick++;
	}

	return 0;
}