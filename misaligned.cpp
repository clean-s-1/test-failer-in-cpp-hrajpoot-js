#include <iostream>
#include <assert.h>
#include <string.h>
#define NUMBER_OF_COLORS 5

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int fetchMajorColorFromPairNumber(const int pairNumber) {
    const int zeroBasedPairNumber = pairNumber - 1;
    const int majorColorNumber = zeroBasedPairNumber / NUMBER_OF_COLORS;
    return majorColorNumber;  
}

int fetchMinorColorFromPairNumber(const int pairNumber) {
    const int zeroBasedPairNumber = pairNumber - 1;
    const int minorColorNumber = zeroBasedPairNumber % NUMBER_OF_COLORS;
    return minorColorNumber;
}

std::string getFormatedColorPairString(int majorColorIndex, int minorColorIndex)
{
    const int pairNumber = majorColorIndex * 5 + minorColorIndex + 1;
    std::string formatedColorPairString = std::to_string(pairNumber) + " | " + majorColor[majorColorIndex] + " | " + minorColor[minorColorIndex];
    return formatedColorPairString;
}

void printFormatedColorPair(std::string colorPairString)
{
    std::cout << colorPairString << std::endl;
}

void validateColorPairString(int majorColorIndex, int minorColorIndex, const std::string colorPairString)
{
    const int colorPairNumber = majorColorIndex * NUMBER_OF_COLORS + minorColorIndex + 1;
    int acceptedMajorColor = fetchMajorColorFromPairNumber(colorPairNumber);
    int acceptedMinorColor = fetchMinorColorFromPairNumber(colorPairNumber);

    std::string acceptedColorPairString = std::to_string(colorPairNumber) + " | " + majorColor[acceptedMajorColor] + " | " + minorColor[acceptedMinorColor];
    assert(colorPairString == acceptedColorPairString);
}

int printColorMap() {
    int i = 0, j = 0;

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::string formatedColorPairString = getFormatedColorPairString(i, j);
            validateColorPairString(i, j, formatedColorPairString);
            printFormatedColorPair(formatedColorPairString);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well \n";
    return 0;
}
