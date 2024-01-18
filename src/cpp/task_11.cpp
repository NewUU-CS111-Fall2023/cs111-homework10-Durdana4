#include <iostream>
#include <vector>

using namespace std;

class Problem11 {
public:
    bool isSatisfiable(vector<vector<int>>& cnf_formula) {
        int numVariables = getMaxVariable(cnf_formula);
        vector<int> assignment(numVariables + 1, 0);

        return backtrack(cnf_formula, assignment, 1);
    }

private:
    int getMaxVariable(vector<vector<int>>& cnf_formula) {
        int maxVariable = 0;

        for (const auto& clause : cnf_formula) {
            for (int literal : clause) {
                int variable = abs(literal);
                maxVariable = max(maxVariable, variable);
            }
        }

        return maxVariable;
    }

    bool evaluateClause(const vector<int>& clause, const vector<int>& assignment) {
        for (int literal : clause) {
            int variable = abs(literal);
            int value = assignment[variable];

            if ((literal < 0 && value == 0) || (literal > 0 && value == 1)) {
                return true;
            }
        }

        return false;
    }

    bool backtrack(vector<vector<int>>& cnf_formula, vector<int>& assignment, int variable) {
        if (variable >= assignment.size()) {
            return isFormulaSatisfied(cnf_formula, assignment);
        }

        for (int value = 0; value <= 1; value++) {
            assignment[variable] = value;
            if (backtrack(cnf_formula, assignment, variable + 1)) {
                return true;
            }
        }

        return false;
    }

    bool isFormulaSatisfied(vector<vector<int>>& cnf_formula, vector<int>& assignment) {
        for (const auto& clause : cnf_formula) {
            if (!evaluateClause(clause, assignment)) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    vector<vector<int>> cnf_formula = {{1, 2, -3}, {-1, -2, 3}, {2, -3}};

    Problem11 problem;
    bool result = problem.isSatisfiable(cnf_formula);

    if (result) {
        cout << "The formula is satisfiable." << endl;
    } else {
        cout << "The formula is not satisfiable." << endl;
    }

    return 0;
}
