#include "../solutions/solution.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(const vector<vector<int>>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "[" << vec[i][0] << ", " << vec[i][1] << "]";
        if (i < vec.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

bool areEqual(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    return a == b;
}

bool runTest(vector<int> input, vector<vector<int>> expected, int testNum) {
    Solution sol;
    auto result = sol.minimumAbsDifference(input);

    cout << "==== Test Case " << testNum << " ====" << endl;
    cout << "Input: [";
    for (size_t i = 0; i < input.size(); i++) {
        cout << input[i];
        if (i < input.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: ";
    printVector(expected);
    cout << endl;

    cout << "Result:   ";
    printVector(result);
    cout << endl;

    if (areEqual(result, expected)) {
        cout << "PASSED ✅" << endl;
        cout << "=============================" << endl;
        return true;
    } else {
        cout << "FAILED ❌" << endl;
        cout << "=============================" << endl;
        return false;
    }
}

int main() {
    vector<pair<vector<int>, vector<vector<int>>>> testCases = {
        {{4, 2, 1, 3}, {{1, 2}, {2, 3}, {3, 4}}},
        {{1, 3, 6, 10, 15}, {{1, 3}}},
        {{3, 8, -10, 23, 19, -4, -14, 27}, {{-14, -10}, {19, 23}, {23, 27}}},
        {{1, 2, 3, 4}, {{1, 2}, {2, 3}, {3, 4}}},
        {{1000000, 999999, 999998}, {{999998, 999999}, {999999, 1000000}}},
        {{1, 1, 1, 1}, {{1, 1}, {1, 1}, {1, 1}}},
        {{5, 2}, {{2, 5}}},
        {{-10, -5, 0, 5, 10}, {{-10, -5}, {-5, 0}, {0, 5}, {5, 10}}}
    };

    bool allPassed = true;
    for (size_t i = 0; i < testCases.size(); ++i) {
        bool passed = runTest(testCases[i].first, testCases[i].second, i + 1);
        if (!passed) {
            allPassed = false;
        }
    }

    if (!allPassed) {
        cerr << "❌ Some test cases failed!" << endl;
        return 1;  // 🔴 Exit with non-zero code
    } else {
        cout << "✅ All test cases passed successfully!" << endl;
        return 0;
    }
}
