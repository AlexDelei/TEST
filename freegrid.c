#include "main.h"
/**
 * free_grid - Free the allocated memory used in the last exercise
 * @grid: pointer to grid
 * @height: Height of the grid
 */
void free_grid(char **grid, int height)
{
    if (grid == NULL || height <= 0)
        return;

    for (int i = 0; i < height; i++)
    {
        if (grid[i] != NULL)
            free(grid[i]);
    }

    free(grid);
}