#include <assert.h>
#define NUMBER_OF_COLORS 5

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

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0, pairNumber, acceptedMajorColor, acceptedMinorColor;
    
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            pairNumber = i * 5 + j;
            acceptedMajorColor = fetchMajorColorFromPairNumber(pairNumber);
            acceptedMinorColor = fetchMinorColorFromPairNumber(pairNumber);

            assert(majorColor[acceptedMajorColor] == majorColor[i]);
            assert(minorColor[acceptedMinorColor] == minorColor[j]);
            
            std::cout << pairNumber << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
