Vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
  //create dist vector
  vector<int> dist(n+1, 1e9);
  dist[src] = 0;

  //do relaxation for n-1 times on every node
  for(int i=0; i<=n; i++){
      //traverse on each edge
      for(int j=0; j<m; j++){
         int u = edges[j][0];
         int v = edges[j][1];
         int wt = edges[j][2];

         //check for relaxation condition
         if(dist[u]!=1e9 && (dist[u] + wt) < dist[v]){
            dist[v] = dist[u] + wt;
         }
      }
  }

  //check for negative cycle
  bool flag = 0;
  for(int j=0; j<m; j++){
         int u = edges[j][0];
         int v = edges[j][1];
         int wt = edges[j][2];

         //check for relaxation condition
         if(dist[u]!=1e9 && (dist[u] + wt) < dist[v]){
           flag = 1;
        }
    }

    if(flag == 0){
       return dist;
    }
return vector<int>();
}

TC = O(n*m) = O(number of vertices * number of edges)
