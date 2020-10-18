#include <vector>
#include <queue>
#include <iostream>

// question source:
// https://leetcode.com/discuss/interview-question/411357/
int minHours (int rows, int columns, std::vector<std::vector<int>>& grid) {
    if (grid.empty()) return 0;
    std::queue<std::pair<int, int>> q;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            if (grid[i][j]==1) q.push({i, j});
        }
    }
    
    int hours = -1;
    while (!q.empty()) {
        int size = q.size();
        for (int i=0; i<size; i++) {
            auto cur = q.front();
            q.pop();
            for (auto dir: dirs) {
                int nr = cur.first+dir[0];
                int nc = cur.second+dir[1];
                if (nr>=0 && nr<rows && nc>=0 && nc<columns && grid[nr][nc]==0) {
                    q.push({nr, nc});
                    grid[nr][nc] = 1;
                }
            }   
        }
        hours++;
    }
    
    return hours;
}
int main() {
    std::vector<std::vector<int>> grid = {
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
    };
    int row = grid.size(), col = grid[0].size();
    std::cout << minHours(row, col, grid) << std::endl;
    
    return 0;
}