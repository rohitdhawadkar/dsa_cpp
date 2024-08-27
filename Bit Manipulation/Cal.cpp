#include <iostream>
#include <cstdint>

uint64_t convertToBinary(int x) {
    uint64_t bin = 0;
    uint64_t place = 1;

    while (x != 0) {
        if (x % 2 != 0) {
            bin += place;
        }
        x /= 2;
        place *= 10;
    }

    return bin;
}

int main() {
    int num = 13;
    uint64_t binary = convertToBinary(num);
    std::cout << "Binary of " << num << " is: " << binary << std::endl;
    return 0;
}
