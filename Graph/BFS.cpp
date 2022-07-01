#include<iostream>
#include<vector>
using namespace std;
class Graph{
private:

bool** adj;
int numVertices;
vector<vector<int> > adjList;

public:
Graph(int numVertices){
    this->numVertices = numVertices;
    adj = new bool*[numVertices];
for(int i = 0;i < numVertices;i++){
adj[i] = new bool[numVertices];
for(int j = 0;j < numVertices;j++){
    adj[i][j] = false;
}
}
}

void addEdgeList(int u, int v){
  
  adjList[u].push_back(v);
  adjList[v].push_back(u);

}
void addEdge(int u, int v){
    adj[u][v] = true;
    adj[v][u] = true;
}
//function to add edges
void addEdgeDirected(int u, int v){
    adj[u][v] = true;
   
}

 // Remove edges
  void removeEdge(int i, int j) {
    adj[i][j] = false;
    adj[j][i] = false;
  }
//Function to print matrix
 void toString() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 0; j < adjList[i].size(); j++)
        cout << adj[i][j] << " ";
      cout << "\n";
    }
  }

   void toStringList() {
   for(int i = 0; i< numVertices;i++){
    cout<< i <<": ";
    for(int j = 0;j<adjList[i].size();j++){
        cout<<adjList[i][j]<<" ";
    }
    cout<<endl;
   }
  }
 
//Destructor
~Graph(){
    for(int i = 0;i < numVertices;i++){
        delete[] adj[i];
      
    }
      delete[] adj;
}

};

int main(){
Graph g(4);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);

  g.toString();
  g.toStringList();
}