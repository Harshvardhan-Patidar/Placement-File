// It is a graph in which the node is coloured and coloring of node is alternative if 1node with yellow then next with green and alternative
// and our task is to check that graph is bipartite or not

#include <bits/stdc++.h>
using namespace std;
bool dfs(int src,vector<int> graph[],int color[]){
    if(color[src]==-1){
        color[src]=1;
    }
    for(auto nbr:graph[src]){
        if(color[nbr]==-1){
            color[nbr]=1-color[src];
            if(dfs(nbr,graph,color)==false){
                return false;
            }
        }
        else if(color[src]==color[nbr]){
            return false;
        }
    }
    return true;
}
bool bfs(int src,vector<int> graph[],int color[]){
    queue<int> q;
    q.push(src);
    color[src]=1;
    while(q.empty()==false){
        int node=q.front();
        q.pop();
        for(auto nbr:graph[node]){
            if(color[nbr]==-1){
                color[nbr]=1-color[src];
            }
            else if(color[nbr]==color[src]){
                return false;
            }
        }
    }
    return true;
}
bool bipartiteUsingDFS(vector<int> graph[],int vertex){
    int color[vertex];
    fill(color,color+vertex,-1);
    for(int i=0;i<vertex;i++){
        if(color[i]==-1){
            if(!dfs(i,graph,color)){
                return false;
            }
        }
    }
    return true;
}
bool bipartiteUsingBFS(vector<int> graph[],int vertex){
    int color[vertex];
    fill(color,color+vertex,-1);
    for(int i=0;i<vertex;i++){
        if(color[i]==-1){
            if(!bfs(i,graph,color)){
                return false;
            }
        }
    }
    return false;
}
int main(){
    int edges,vertex;
    cin>>edges>>vertex;
    vector<int> graph[vertex];
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0;i<vertex;i++){
        cout<<i<<" -> ";
        for(auto x:graph[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    if(bipartite(graph,vertex)){
        cout<<"Graph is bipartite";
    }
    else{
        cout<<"Graph is not bipartite";
    }
    return 0;
}