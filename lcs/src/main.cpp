#include <utility>
#include <cmath>
#include "ColorSequenceFinder.h"

int main(int argc, char* argv[]) 
{
    if (argc < 2) 
    {
        std::cerr << "Usage: " << argv[0] << " test_1 [test_2 ...]" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++) 
    {
        const std::string testFileName = "../../../lcs/tests/" + std::string(argv[i]);

        std::ifstream inputFile(testFileName);
        if (!inputFile.is_open()) 
        {
            std::cerr << "Error opening file: " << testFileName << std::endl;
            continue;
        }

        int rowsLength, colsLength;
        inputFile >> rowsLength >> colsLength;

        ColorMatrix rgbMatrix(rowsLength, colsLength);
        rgbMatrix.readMatrix(inputFile);

        ColorSequenceFinder sequenceFinder;
        int longestColorSequence = sequenceFinder.findLongestColorSequence(rgbMatrix);

        std::cout << longestColorSequence << std::endl;

        inputFile.close();
    }

    return 0;
}