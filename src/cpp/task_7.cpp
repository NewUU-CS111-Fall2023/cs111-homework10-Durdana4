#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Problem7 {
public:
    int minimumRabbits(vector<int>& answers) {
        unordered_map<int, int> count;

        for (int answer : answers) {
            count[answer]++;
        }

        int minRabbits = 0;
        for (auto it = count.begin(); it != count.end(); it++) {
            int groupSize = it->first + 1;
            int rabbitsInGroup = it->second;
            int groupCount = (rabbitsInGroup + groupSize - 1) / groupSize;
            minRabbits += groupCount * groupSize;
        }

        return minRabbits;
    }
};

int main() {
    vector<int> answers = {1, 1, 2, 2, 3};

    Problem7 problem;
    int result = problem.minimumRabbits(answers);

    cout << "Minimum number of rabbits: " << result << endl;

    return 0;
}
