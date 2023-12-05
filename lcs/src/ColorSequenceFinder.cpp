#include "ColorSequenceFinder.h"

bool ColorSequenceFinder::canMove(size_t rows, size_t cols, int i, int j) 
{
    return i >= 0 && i < rows && j >= 0 && j < cols;
}

int ColorSequenceFinder::findLongestColorSequence(const matrix& matrix) 
{
    size_t rowsLength = matrix.size();
    size_t colsLength = matrix[0].size();
    int longestSequence = 0;

    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    for(int row = 0; row < rowsLength; row++) 
    {
        for(int col = 0; col < colsLength; col++) 
        {
            int currentColorSequence = findColorSequence(matrix, directions, row, col);
            longestSequence = std::max(longestSequence, currentColorSequence);
        }
    }
    return longestSequence;
}

int ColorSequenceFinder::findColorSequence(const matrix& matrix, const std::vector<std::pair<int, int>>& directions, int row, int col)
{
    char colorSymbol = matrix[row][col];
    size_t rowsLength = matrix.size();
    size_t colsLength = matrix[0].size();

    std::vector<std::vector<bool>> visited(rowsLength, std::vector<bool>(colsLength, false));
    std::vector<std::pair<int, int>> cells;
    cells.push_back({row, col});
    visited[row][col] = true;

    while (!cells.empty()) 
    {
        int x = cells.front().first;
        int y = cells.front().second;
        cells.erase(cells.begin());

        for(auto dir : directions) 
        {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (canMove(rowsLength, colsLength, newX, newY) && !visited[newX][newY] && matrix[newX][newY] == colorSymbol) 
            {
                cells.push_back({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }

    return colorSequenceLength(visited);
}

int ColorSequenceFinder::colorSequenceLength(const std::vector<std::vector<bool>>& visited)
{
    size_t rowsLength = visited.size();
    size_t colsLength = visited[0].size();
    int countSequenceElements = 0;

    for (int i = 0; i < rowsLength; i++) 
    {
        for (int j = 0; j < colsLength; j++) 
        {
            if (visited[i][j]) 
            {
                countSequenceElements++;
            }
        }
    }

    return countSequenceElements;
}

int ColorSequenceFinder::findLongestColorSequence(const ColorMatrix& matrix)
{
    return findLongestColorSequence(matrix.getMatrix());
}
