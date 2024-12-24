// Implementation of graph using the adjacency matrix & adjacency list

#include <bits/stdc++.h>
using namespace std;
void adjmatrix(){
    int m,n;
    cin>>m>>n;   //take input of edges & vertex
    int graph[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=0;
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    cout<<endl<<"Graph after linking: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
void adjList(){
    int edge,vertex;
    cin>>edge>>vertex;
    vector<int> graph[vertex];
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<<endl;
    cout<<endl<<"Adjacency list:"<<endl;
    for(int i=0;i<vertex;i++){
        cout<<i<<" -> ";
        for(auto x:graph[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int main(){
    adjmatrix();
    cout<<endl;
    adjList();
return 0;
}