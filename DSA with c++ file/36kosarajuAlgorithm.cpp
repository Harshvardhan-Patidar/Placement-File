// It is use to check the strongly connected component of graph

#include <bits/stdc++.h>
using namespace std;
void dfs(int src,stack<int> &s,bool visited[],vector<int> graph[]){
    visited[src]=true;
    for(auto nbr:graph[src]){
        if(visited[nbr]==false){
            dfs(nbr,s,visited,graph);
        }
    }
    s.push(src);
}
void reDFS(int src,bool visited[],vector<int> transpose[]){
    cout<<src<<" ";
    visited[src]=true;
    for(auto nbr:transpose[src]){
        if(visited[nbr]==false){
            reDFS(nbr,visited,transpose);
        }
    }
}
int main(){
    int edges,vertex;
    cin>>edges>>vertex;
    vector<int> graph[vertex];
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    stack<int> s;
    bool visited[vertex];
    fill(visited,visited+vertex,false);
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            dfs(i,s,visited,graph);
        }
    }
    vector<int> transpose[vertex];
    fill(visited,visited+vertex,false);
    for(int i=0;i<vertex;i++){
        for(auto nbr:graph[i]){
            transpose[nbr].push_back(i);
        }
    }
    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(visited[node]==false){
            cout<<"SCC: ";
            reDFS(node,visited,transpose);
            cout<<endl;
        }
    }
    return 0;
}