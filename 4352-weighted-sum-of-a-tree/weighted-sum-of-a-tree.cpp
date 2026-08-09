class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
vector<vector<int>> adj(n); 
for (int i = 0; i < n; i++) {
    if (parent[i] != -1) {
        adj[parent[i]].push_back(i);
    }
}
        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0]=1;
        int count=1;
        vector<int> depth(n,0);
       int max_depth = 1;
        depth[0]=1;
        while(!q.empty()){
            int a = q.front();
            q.pop();
            count++;
            for(int i=0;i<adj[a].size();i++){
                if(vis[adj[a][i]]==0){
                    q.push(adj[a][i]);
                    vis[adj[a][i]]=1;
                   depth[adj[a][i]] = depth[a] + 1;
                   max_depth = max(max_depth, depth[adj[a][i]]);
                }
            }
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            sum += (long long)nums[i] * (max_depth - depth[i] + 1);
        }
        return sum;
    }
};