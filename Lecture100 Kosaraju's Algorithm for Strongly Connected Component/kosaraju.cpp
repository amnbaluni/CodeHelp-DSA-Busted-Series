https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

#include <unordered_map>
#include <list>
#include <stack>
#include <vector>

void dfs(int node,unordered_map<int,bool> &vis, stack<int> &st,unordered_map<int,list<int>> &adj){
	vis[node] = true;
	for(auto neighbour : adj[node]){
		if(!vis[neighbour]){
			dfs(neighbour, vis, st, adj);
		}
	}
	st.push(node);
}

void revDFS(int node,unordered_map<int,bool> &vis, unordered_map<int,list<int>> &adj){
	vis[node] = true;
	for(auto neighbour : adj[node]){
		if(!vis[neighbour]){
			revDFS(neighbour, vis, adj);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{   //create adjacency list
	unordered_map<int,list<int>> adj;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].push_back(v);
	}
    
	//topological sort
	unordered_map<int,bool> vis;
	stack<int> st;

	for(int i=0; i<v; i++){
		if(!vis[i]){
			dfs(i, vis, st, adj);
		}
	}
     
    //create transpose graph
	unordered_map<int,list<int>> transpose;
	for(int i=0; i<v; i++){
		vis[i] = 0;
		for(auto neighbour : adj[i]){
			transpose[neighbour].push_back(i);
		}
	}

    //call dfs for transpose graph
	int count = 0;
	while(!st.empty()){
		int top = st.top();
		st.pop();
		if(!vis[top]){
			count++;
			revDFS(top, vis, transpose);
		}
	}
	return count;
}

TC = O(N+E)
------------------------------------------------------------------------------------------------------
//Kosaraju's Algorithm :     Time  : O(V+E), V = # vertices, E = # edges , Space : O(V)
class Solution
{
	public:
	void dfsFill(int u, vector<vector<int>>& adj, vector<bool> &visited, stack<int>& st) {
	    visited[u] = true;
	    
	    for(int &v : adj[u]) {
	        
	        if(!visited[v]) {
	            dfsFill(v, adj, visited, st);
	        }
	        
	    }
	    
	    st.push(u);
	}
	void dfsTraverse(int u, vector<vector<int>>& adjReversed, vector<bool> &visited) {
	    visited[u] = true;
	    
	    for(int &v : adjReversed[u]) {
	        
	        if(!visited[v]) {
	            dfsTraverse(v, adjReversed, visited);
	        }
	        
	    }

	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<bool> visited(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i]) {
                dfsFill(i, adj, visited, st);
            }
        }
        
        
        vector<vector<int>> adjReversed(V);
        for(int u = 0; u<V; u++) {
            for(int &v : adj[u]) {
                
                //u->v
                //v->u
                adjReversed[v].push_back(u);
                
            }   
        }
        
        int count = 0;
        
        visited = vector<bool>(V, false);
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!visited[node]) {
                dfsTraverse(node, adjReversed, visited);
                count++;
            }
        }
        return count;
    }
};
SC = linear  
