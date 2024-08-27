#include <iostream>
using namespace std;
class Solution {
public:
    int minFlips(int a, int b, int c) {
        // XOR of (a | b) and c to get the bits that need to be flipped
        int ans = (a | b) ^ c;
        // Count the number of set bits in the result
        int y = countSetBits(ans);
        return y;
    }

    int countSetBits(int x) {
        int count = 0;
        // Count the number of 1s in the binary representation of x
        while (x > 0) {
            if (x & 1) {
                count++;
            }
            x = x >> 1;
        }
        return count;
    }
};


int main() {
    Solution sol;
    int a = 2; // Binary: 010
    int b = 6; // Binary: 110
    int c = 5; // Binary: 101
    int result = sol.minFlips(a, b, c);
    cout << "Minimum bit flips required: " << result << endl; // Output should be 2
    return 0;
}
