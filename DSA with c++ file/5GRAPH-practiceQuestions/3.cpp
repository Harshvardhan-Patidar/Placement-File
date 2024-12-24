// Our task is to find the cycle in undirected graph through dfs & bfs

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
bool cycleDFS(int src,int parent,vector<int> graph[],bool visited[]){
    visited[src]=true;
    for(auto nbr:graph[src]){
        if(!visited[nbr]){
            if(cycleDFS(nbr,src,graph,visited)) return true;
        }
        else if(nbr!=parent){
            return true;
        }
    }
    return false;
}
bool cycleBFS(int src,vector<int> graph[],bool visited[]){
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int data=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto nbr:graph[data]){
            if(!visited[nbr]){
                visited[nbr]=true;
                q.push({nbr,data});
            }
            else if(nbr!=parent){
                return true;
            }
        }
    }
    return false;
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
    cout<<"Check through DFS"<<endl;
    // if(cycleDFS(0,0,graph,visited)){
    //     cout<<"Cycle present";
    // }
    // else{
    //     cout<<"No cycle present";
    // }
    cout<<endl<<"Check through BFS"<<endl;
    if(cycleBFS(0,graph,visited)){
        cout<<"Cycle present";
    }
    else{
        cout<<"No cycle present";
    }
return 0;
}