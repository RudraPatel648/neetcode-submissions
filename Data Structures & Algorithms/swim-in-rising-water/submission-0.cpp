class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        set<pair<int, int>> visited;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited.insert({0, 0});
        while (!pq.empty()) {
            vector<int> current = pq.top();
            pq.pop();
            int t = current[0], r = current[1], c = current[2];

            if (r == N - 1 && c == N - 1) return t;

            int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

            for (const auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nc < 0 || nr == N || nc == N || visited.count({nr, nc})) continue;

                visited.insert({nr, nc});
                pq.push({max(t, grid[nr][nc]), nr, nc});
            }
        }

        return N * N;
    }
};
