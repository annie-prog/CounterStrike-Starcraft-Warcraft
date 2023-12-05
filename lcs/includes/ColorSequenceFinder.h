#ifndef COLOR_SEQUENCE_FINDER
#define COLOR_SEQUENCE_FINDER
#include <vector>
#include <utility>
#include <cmath>
#include <iostream>
#include "ColorMatrix.h"

class ColorSequenceFinder
{
public:
    ColorSequenceFinder() = default;

    int findLongestColorSequence(const ColorMatrix& matrix);

    int findColorSequence(const matrix& matrix, const std::vector<std::pair<int, int>>& directions, int row, int col);
    int colorSequenceLength(const std::vector<std::vector<bool>>& visited);

    void generateBigMatrix();
private:
    using matrix = std::vector<std::vector<char>>;

    bool canMove(size_t rows, size_t cols, int i, int j);

    int findLongestColorSequence(const matrix& matrix);
};


#endif