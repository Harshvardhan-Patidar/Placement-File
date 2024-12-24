// Task is to find the cycle through dfs in directed graph

#include <bits/stdc++.h>
using namespace std;
void adjList(int edge,int vertex,vector<int> graph[]){
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
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
bool cycleDFS(int src,vector<int> graph[],bool visited[],bool visited_dfs[]){
    visited[src]=true;
    visited_dfs[src]=true;
    for(auto nbr:graph[src]){
        if(!visited[nbr]){ 
            if(cycleDFS(nbr,graph,visited,visited_dfs)){
                return true;
            }
        }
        else if(visited_dfs[nbr]){
            return true;
        }
    }
    visited_dfs[src]=false;
    return false;
}
int main(){
    int edge,vertex;
    cin>>edge>>vertex;
    vector<int> graph[vertex];
    adjList(edge,vertex,graph);
    bool visited[vertex];
    bool visited_dfs[vertex];
    for(int i=0;i<vertex;i++){
        visited[i]=false;
        visited_dfs[i]=false;
    }
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            if(cycleDFS(i,graph,visited,visited_dfs)){
                cout<<"Cycle present";
                break;
            }
        }
        cout<<"Cycle not present";
    }
return 0;
}