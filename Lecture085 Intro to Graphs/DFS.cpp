void dfs(int node, unordered_map<int, bool> &isVisited, unordered_map<int, list<int>> &adj, vector<int> &component){
    component.push_back(node);
    isVisited[node] = true;

    //recursion
    for(auto i: adj[node]){
        if(!isVisited[i]){
            dfs(i, isVisited, adj, component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // prepare adjacency list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    vector<int> component;
    unordered_map<int, bool> isVisited;
    for(int i=0; i<V; i++){
        if(!isVisited[i]){
            dfs(i, isVisited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}
