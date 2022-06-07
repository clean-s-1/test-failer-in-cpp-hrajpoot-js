#include <iostream>
#include <assert.h>

#define SIZE_NUMBER_MIN 38
#define SIZE_NUMBER_MAX 42

#define TSHIRT_SIZE_SMALL 'S'
#define TSHIRT_SIZE_MEDIUM 'M'
#define TSHIRT_SIZE_LARGE 'L'

char fetchSize(int tshirt_size_cms) {
    char sizeName = '\0';
    if(tshirt_size_cms <= SIZE_NUMBER_MIN) {
        sizeName = TSHIRT_SIZE_SMALL;
    } else if(tshirt_size_cms > SIZE_NUMBER_MIN && tshirt_size_cms <= SIZE_NUMBER_MAX) {
        sizeName = TSHIRT_SIZE_MEDIUM;
    } else if(tshirt_size_cms > SIZE_NUMBER_MAX) {
        sizeName = TSHIRT_SIZE_LARGE;
    }
    return sizeName;
}

int main() {
    assert(fetchSize(37) == 'S');
    assert(fetchSize(40) == 'M');
    assert(fetchSize(43) == 'L');

    assert(fetchSize(38) == 'S');
    assert(fetchSize(42) == 'M');


    std::cout << "All is well.\n";
    return 0;
}
