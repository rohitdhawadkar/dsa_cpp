#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> errorScore, int p, int q) {
    int ans = 0;
    int score = 0;

    for (int i = 0; i < errorScore.size(); i++) {
        score += errorScore[i];
    }

    int zcount = 0;
    for (int i = 0; i < errorScore.size(); i++) {
        if (errorScore[i] > 0) {
            zcount++;
        }
    }

    score -= zcount;

    if (p != 0) {
        ans = score / p;
    } else {
        // Handle division by zero case
        cout << "Error: Division by zero." << endl;
        return -1;
    }

    return ans;
}

int main() {
    int n, p, q;

    cout << "Enter n, p, q: ";
    cin >> n >> p >> q;

    vector<int> nums = {9, 8, 2, 5};

    int ans = find(nums, p, q);

    cout << "The answer is: " << ans << endl;

    return 0;
}
