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
}				t_cell;

int main()
{
	int number_of_cells;
	scanf("%d", &number_of_cells);
	t_cell	cells[number_of_cells + 1];
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
	}

	int number_of_bases;
	scanf("%d", &number_of_bases);
	fprintf(stderr, "nbbases :%d\n", number_of_bases);

	int my_base_index;
	scanf("%d", &my_base_index);

	int opp_base_index;
	scanf("%d", &opp_base_index);

	// Micode jajajaj
	int i = 0;
	int j = 0;
	int	k[20];
	while (i < number_of_cells)
	{
		if (cells[i].initial_resources > 5)
			k[j++] = i;
		i++;
	}
	fprintf(stderr, "Debug messages...\n");


	// game loop
	while (1) {
		for (int i = 0; i < number_of_cells; i++) {
			int resources;
			int my_ants;
			int opp_ants;
			scanf("%d%d%d", &resources, &my_ants, &opp_ants);
		}

		printf("LINE %d %d 100\n", my_base_index, k[j]);

		printf("WAIT\n");
	}

	return 0;
}