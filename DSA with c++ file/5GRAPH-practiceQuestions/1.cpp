// Our task is to find the components of the graph:- total no. of subgraphs
// find using both techiques

#include <bits/stdc++.h>
using namespace std;
void adjList(int edge,int vertex,vector<int> graph[]){
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
void dfs(int src,bool visited[],vector<int> graph[]){
    visited[src]=true;
    for(auto nbr:graph[src]){
        if(!visited[nbr]){
            dfs(nbr,visited,graph);
        }
    }
}
void bfs(int src,bool visited[],vector<int> graph[]){
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int data=q.front();
        q.pop();
        if(!visited[data]){
            visited[data]=true;
            for(auto nbr:graph[data]){
                q.push(nbr);
            }
        }
    }
}
int dfsANDfsComp(int src,bool visited[],vector<int> graph[],int vertex){
    int count=0;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            count++;
            // dfs(i,visited,graph);
            bfs(i,visited,graph);
        }
    }
    return count;
}
int main(){
    int edge,vertex;
    cin>>edge>>vertex;
    vector<int> graph[vertex];
    adjList(edge,vertex,graph);
    bool visited[vertex];
    for(int i=0;i<5;i++){
        visited[i]=false;
    }
    cout<<"Total components in graph: "<<dfsANDfsComp(0,visited,graph,vertex);
return 0;
}