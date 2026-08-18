#ifndef CELL_H
#define CELL_H

#include <stdbool.h>

typedef struct {
	float food_pheromone;
	float home_pheromone;
	bool  obstacle;
} Cell;

#endif