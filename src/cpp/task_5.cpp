#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Problem5 {
public:
    bool hasTripletSumZero(const vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            int targetSum = -sortedNums[i];

            while (left < right) {
                int currentSum = sortedNums[left] + sortedNums[right];

                if (currentSum == targetSum) {
                    return true;
                } else if (currentSum < targetSum) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return false;
    }
};

int main() {
    vector<int> nums = {1, -2, 3, 0, -1, 2};
    Problem5 problem;
    bool result = problem.hasTripletSumZero(nums);

    if (result) {
        cout << "The given set of numbers contains a distinct triplet with sum zero." << endl;
    } else {
        cout << "The given set of numbers does not contain a distinct triplet with sum zero." << endl;
    }

    return 0;
}
