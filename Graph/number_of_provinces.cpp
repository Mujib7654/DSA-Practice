// https://leetcode.com/problems/number-of-provinces/description/

DFS Approach

void dfs(int node, vector<bool>&vis, vector<int>graph[]){
    vis[node] = true;
    for(auto it: graph[node]){
        if(!vis[it]){
            dfs(it,vis,graph);
        }
    }
}
int findCircleNum(vector<vector<int>>&cities) {
    int n = cities.size();
    vector<int>graph[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cities[i][j] && i!=j)graph[i].push_back(j);
        }
    }

    vector<bool>vis(n,false);
    int count = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
            dfs(i,vis,graph);
        }
    }
    return count;
}

BFS Approach

int findCircleNum(vector<vector<int>>&cities) {
    int n = cities.size();
    vector<int>graph[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cities[i][j] && i!=j)graph[i].push_back(j);
        }
    }

    vector<bool>vis(n,false);
    int count = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
            vis[i] =true;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int it:graph[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=true;
                    }
                }
            }
        }
    }
    return count;
}