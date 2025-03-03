// Approach

//     Initialization:
//         Traverse the grid to:
//             Enqueue all cells with rotten oranges (value 2) into a queue.
//             Count the total number of fresh oranges (value 1).

//     Breadth-First Search (BFS):
//         Use BFS to simulate the process minute by minute.
//         At each level (representing one minute), process all currently rotten oranges.
//         For each rotten orange, check its four adjacent cells (up, down, left, right).
//             If an adjacent cell contains a fresh orange, turn it rotten (set value to 2), decrement the fresh orange count, and add it to the queue.
//         Increase the time counter only if at least one fresh orange was converted in the current minute.

//     Termination:
//         If all fresh oranges are rotted, return the total minutes taken.
//         If the BFS completes and there are still fresh oranges, return -1.

// Time Complexity

//     O(m * n):
//         Every cell in the grid is processed at most once.
//         The BFS visits each cell and its neighbors (constant time operation for 4 directions).

// Space Complexity

//     O(m * n):
//         In the worst case (e.g., when most oranges are rotten), the queue could contain a large portion of the grid.
//         The grid itself uses O(m * n) space.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int cnt=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        vector<int> dirs={0,1,0,-1,1,0,-1,0};
        if(cnt==0) return 0;
        int ans=0;
        while(!q.empty()){
            bool check=false;
            int n2=q.size();
            for(int k=0;k<n2;k++){
               auto node=q.front();
               q.pop();
               int i=node.first;
               int j=node.second;
               for(int d=0;d<4;d++){
                int newi=i+dirs[2*d];
                int newj=j+dirs[2*d+1];
                if(newi<0 || newj<0 || newi>=m || newj>=n || grid[newi][newj]!=1){
                    continue;
                }
                grid[newi][newj]=2;
                q.push({newi,newj});
                cnt--;
                check=true;
                
               }

            }
            if(check){
                ans++;
            }
        }
        if(cnt==0){
            return ans;
        }
        return -1;
    }
};
