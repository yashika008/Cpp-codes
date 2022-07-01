
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool bcolor(int node, int color[], vector<int>adj[]){
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while(!q.empty()){
            int nodee = q.front();
            q.pop();
            for(auto it : adj[nodee]){
                if(color[it]==-1){
                    color[it] = 1-color[nodee];
                    q.push(it);
                }
                else if(color[it]==color[nodee]) return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	  int color[V];
	  memset(color, -1, sizeof color);
	  for(int i = 0; i < V; i++){
	      if(color[i] == -1){
	          if(!bcolor(i, color, adj)) return false;
	      }
	  }
	  return true;
	}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}