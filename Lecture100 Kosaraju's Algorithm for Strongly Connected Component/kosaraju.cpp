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
SC = linear  
