//using set
#include<set>
#include <unordered_map>
#include <list>
#include <vector>
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //create adjacency list
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        //since it is undirected graph
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //distance array
    vector<int> dist(vertices);
    for(int i=0; i<vertices; i++){
        dist[i] = INT_MAX;
    }

    //make set
    set<pair<int,int>> st;
    dist[source] = 0;
    st.insert(make_pair(0, source));

    while(!st.empty()){
        //fetch top recor
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        //now erase top record
        st.erase(st.begin());
        
        //travserse neighour nodes
        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                //if record found then erase it
                if(record!=st.end()){
                    st.erase(record);
                }

                //update the distance
                dist[neighbour.first] = neighbour.second + nodeDistance;
                //push record in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

TC = O(ElogV)
SC = O(N+E)
