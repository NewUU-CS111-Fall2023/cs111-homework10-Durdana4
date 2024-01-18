#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Problem6 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            graph[u].push_back({v, w});
        }

        vector<int> distances(n + 1, numeric_limits<int>::max());
        distances[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            int u = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (dist > distances[u]) {
                continue;
            }

            for (const auto& edge : graph[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist + w < distances[v]) {
                    distances[v] = dist + w;
                    pq.push({dist + w, v});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (distances[i] == numeric_limits<int>::max()) {
                return -1;
            }
            maxTime = max(maxTime, distances[i]);
        }

        return maxTime;
    }
};

int main() {
    vector<vector<int>> times = {{1, 2, 1}, {2, 3, 2}, {1, 3, 4}};
    int n = 3;
    int k = 1;

    Problem6 problem;
    int result = problem.networkDelayTime(times, n, k);

    cout << "Minimum time for all nodes to receive the signal: " << result << endl;

    return 0;
}
