#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Problem10 {
public:
    vector<vector<int>> generate3SAT(int numVariables, int numClauses) {
        vector<vector<int>> formula;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(1, numVariables);

        for (int i = 0; i < numClauses; i++) {
            vector<int> clause;

            for (int j = 0; j < 3; j++) {
                int variable = dis(gen);
                if (dis(gen) % 2 == 0) {
                    variable *= -1;
                }
                clause.push_back(variable);
            }

            formula.push_back(clause);
        }

        return formula;
    }
};

int main() {
    int numVariables = 4;
    int numClauses = 3;

    Problem10 problem;
    vector<vector<int>> formula = problem.generate3SAT(numVariables, numClauses);

    cout << "Generated 3-SAT formula:" << endl;
    for (const auto& clause : formula) {
        for (int literal : clause) {
            cout << literal << " ";
        }
        cout << endl;
    }

    return 0;
}
