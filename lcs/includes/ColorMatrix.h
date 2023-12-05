#ifndef COLOR_MATRIX
#define COLOR_MATRIX

#include <iostream>
#include <vector>
#include <fstream>

using matrix = std::vector<std::vector<char>>;
class ColorMatrix
{
public:
    ColorMatrix(int rows, int cols);
    void readMatrix(std::ifstream& inputFile);

    const matrix& getMatrix() const;
private:
    matrix rgbMatrix;
};

#endif