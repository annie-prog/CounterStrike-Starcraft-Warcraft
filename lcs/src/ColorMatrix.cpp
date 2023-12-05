#include "ColorMatrix.h"

ColorMatrix::ColorMatrix(int rows, int cols) : rgbMatrix(rows, std::vector<char>(cols)) {}

void ColorMatrix::readMatrix(std::ifstream& inputFile)
{
    for(int row = 0; row < rgbMatrix.size(); row++) 
    {
        for(int col = 0; col < rgbMatrix[0].size(); col++) 
        {
            inputFile >> rgbMatrix[row][col];
        }
    }
}

const matrix& ColorMatrix::getMatrix() const
{
    return this->rgbMatrix;
}