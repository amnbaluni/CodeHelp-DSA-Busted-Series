//Creating and Printing Graph
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<int> ans[n];
    //ans array will store adjacent nodes
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        ans[u].push_back(v);

        //since graph is undirected
        ans[v].push_back(u);
    }

    vector < vector < int >> adj(n);
    for(int i=0; i<n; i++){
        adj[i].push_back(i);
        //entering neighbours
        for(int j=0; j<ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
    }
   return adj;
}

For AdjList:-
Add Edge T.C: O(m) and S.C: O(n+m)
Print Edge T.C: O(n*m) and S.C: O(1)
