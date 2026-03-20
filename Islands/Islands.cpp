#include <vector>
#include <iostream>
#include <queue>

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

static void breadth_first_search(std::vector<std::vector<char>>& grid, int start_i, int start_j)
{
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());

    std::queue<std::pair<int, int>> q;
    q.emplace(start_i, start_j);
    grid[start_i][start_j] = '0';

    const std::vector<int> dir_i = {1, -1, 0, 0};
    const std::vector<int> dir_j = {0, 0, 1, -1};

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int ni = i + dir_i[d];
            int nj = j + dir_j[d];

            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1')
            {
                grid[ni][nj] = '0';
                q.emplace(ni, nj);
            }
        }
    }
}

int count_islands(std::vector<std::vector<char>>& grid)
{
    if (grid.empty()) return 0;

    int islands = 0;

    for (int i = 0; i < static_cast<int>(grid.size()); ++i)
    {
        for (int j = 0; j < static_cast<int>(grid[0].size()); ++j)
        {
            if (grid[i][j] == '1')
            {
                islands++;
                breadth_first_search(grid, i, j);
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
