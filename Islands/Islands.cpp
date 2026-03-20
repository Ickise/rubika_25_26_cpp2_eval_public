#include <vector>
#include <iostream>

/*
 * To analyze satellite images, a geospatial company studies maps of remote ocean regions.
 * Each map is represented as a grid where land and water are identified.
 *
 * Your task is to determine how many separate islands are present on a given map.
 * The map is represented as a 2D grid of characters :
 *    - '1' represents land
 *    - '0' represents water
 *
 * An island is defined as a group of connected land cells.
 * Cells are considered connected if they are adjacent horizontally or vertically(not diagonally).
 * The grid is surrounded by water.
 * 
 * Implement the function count_islands which returns the total number of islands present in the map.
 */

static void depth_first_search(std::vector<std::vector<char>>& grid, size_t i, size_t j)
{
    const size_t m = grid.size();
    const size_t n = grid[0].size();

    if (i >= m || j >= n || grid[i][j] != '1')
        return;

    grid[i][j] = '0';

    if (i + 1 < m) depth_first_search(grid, i + 1, j);
    if (i > 0) depth_first_search(grid, i - 1, j);
    if (j + 1 < n) depth_first_search(grid, i, j + 1);
    if (j > 0) depth_first_search(grid, i, j - 1);
}

int count_islands(std::vector<std::vector<char>>& grid)
{
    if (grid.empty()) return 0;

    const size_t m = grid.size();
    const size_t n = grid[0].size();
    int islands = 0;

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                islands++;
                depth_first_search(grid, i, j);
            }
        }
    }

    return islands;
}

int main()
{
    {
        std::vector<std::vector<char>> firstGrid = {
            {'1', '1', '0', '0'},
            {'1', '1', '0', '0'},
            {'0', '0', '1', '0'},
            {'0', '0', '0', '1'}
        };
        const int firstResult = count_islands(firstGrid);
        std::cout << "Number of islands in firstGrid: " << firstResult << '\n';
    }

    {
        std::vector<std::vector<char>> secondGrid = {
            {'1', '1', '1'},
            {'0', '1', '0'},
            {'1', '1', '1'}
        };
        const int secondResult = count_islands(secondGrid);
        std::cout << "Number of islands in secondGrid: " << secondResult << '\n';
    }

    return 0;
}
