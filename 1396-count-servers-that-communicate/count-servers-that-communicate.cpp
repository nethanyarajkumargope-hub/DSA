#include <vector>

class Solution {
public:
    int countServers(std::vector<std::vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<int> rowCount(m, 0);
        std::vector<int> colCount(n, 0);
        int total_servers = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                    total_servers++;
                }
            }
        }

        int isolated_servers = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                    isolated_servers++;
                }
            }
        }

        return total_servers - isolated_servers;
    }
};
