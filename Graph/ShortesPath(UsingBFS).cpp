#include<bits/stdc++.h>
using namespace std;

void ShortestPath(int src, vector<int> adj[], int V){
int distance[V];
for(int i = 0;i<V;i++){
    distance[i] = INT_MAX;
}
queue<int> q;
distance[src] = 0;
q.push(src);
while(!q.empty()){
int node = q.front();
q.pop();

for(auto it : adj[node]){
    if(distance[node]+1 < distance[it]){
        distance[it] = distance[node]+1;
        q.push(it);
    }

}

}
for(int i = 0 ;i < V;i ++){
cout<<distance[i]<<" ";
}
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
             adj[v].push_back(u);
        }
        int src;

        cin>>src;
       
         ShortestPath(src, adj, N);

        
    }
    
    return 0;
} 

