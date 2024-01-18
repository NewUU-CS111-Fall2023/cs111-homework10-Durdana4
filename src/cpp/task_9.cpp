#include <iostream>
#include <vector>

using namespace std;

class Problem9 {
public:
    bool isSatisfied(vector<vector<int>>& formula, vector<int>& assignment) {
        for (const auto& clause : formula) {
            bool clauseSatisfied = false;

            for (int literal : clause) {
                if (literal > 0 && assignment[literal - 1] == 1) {
                    clauseSatisfied = true;
                    break;
                } else if (literal < 0 && assignment[-literal - 1] == 0) {
                    clauseSatisfied = true;
                    break;
                }
            }

            if (!clauseSatisfied) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    vector<vector<int>> formula = {{1, 2}, {-1, 3}, {-2, -3}};
    vector<int> assignment = {1, 0, 1};

    Problem9 problem;
    bool result = problem.isSatisfied(formula, assignment);

    if (result) {
        cout << "The formula is satisfied by the assignment." << endl;
    } else {
        cout << "The formula is not satisfied by the assignment." << endl;
    }

    return 0;
}
