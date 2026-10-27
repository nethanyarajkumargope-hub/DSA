#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> createGrid(int m, int n) {
        std::vector<std::string> grid(m, std::string(n, '#'));
        for (int i = 0; i < m; ++i) {
            grid[i][0] = '.';
        }
        for (int j = 0; j < n; ++j) {
            grid[m - 1][j] = '.';
        }
        
        return grid;
    }
};
