#include <iostream>
#include <vector>

using namespace std;

class Problem8 {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        if (totalSum % 2 != 0) {
            return false;
        }

        int targetSum = totalSum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= targetSum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][targetSum];
    }
};

int main() {
    vector<int> nums = {1, 5, 11, 5};

    Problem8 problem;
    bool result = problem.canPartition(nums);

    if (result) {
        cout << "It is possible to partition the array into two subsets with equal sums." << endl;
    } else {
        cout << "It is not possible to partition the array into two subsets with equal sums." << endl;
    }

    return 0;
}
