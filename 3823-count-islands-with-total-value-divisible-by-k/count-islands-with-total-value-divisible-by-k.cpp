class Solution {
    private:
    bool isvalid(int i,int j,int n,int m){
        if(i>=n || j>=m || i<0 || j<0) return false;
        return true;
    }
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& vis,int n,int m,long long &sum){
        vis[i][j]=true;
        int x[4]={0,0,-1,1};
        int y[4]={-1,1,0,0};
        for(int k = 0 ;k<4;k++){
            int row = i+x[k];
            int col = j+y[k] ;
            if(isvalid(row,col,n,m)==true && grid[row][col]>0 && vis[row][col]==false){
                sum=sum+grid[row][col];
                dfs(grid,row,col,vis,n,m,sum);
            }
        }
        return;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && vis[i][j]==false){
                    long long sum = grid[i][j];
                    dfs(grid,i,j,vis,n,m,sum);// CONNNECTED COMPONENTS
                    if(sum%k==0) ans++;
                }
            }
        }
        return ans;
    }
};