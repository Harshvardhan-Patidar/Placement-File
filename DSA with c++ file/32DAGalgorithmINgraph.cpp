#include <bits/stdc++.h>
using namespace std;
void topologicalSort(int src,stack<int> &topo,bool visited[],vector<pair<int,int>> graph[]){
    visited[src]=true;
    for(auto nbr:graph[src]){
        if(!visited[nbr.first]){
            topologicalSort(nbr.first,topo,visited,graph);
        }
    }
    topo.push(src);
}
void shortestPath(int src,int vertex,vector<pair<int,int>> graph[]){
    bool visited[vertex];
    stack<int> topo;
    fill(visited,visited+vertex,false);
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            topologicalSort(i,topo,visited,graph);
        }
    }
    int dist[vertex];
    for(int i=0;i<vertex;i++){
        dist[i]=1e9;
    }
    dist[src]=0;
    while(topo.empty()==false){
        int node=topo.top();
        topo.pop();
        for(auto nbr:graph[node]){
            if(dist[node]!=1e9){
                if(dist[node]+nbr.second<dist[nbr.first]){
                    dist[nbr.first]=dist[node]+nbr.second;
                }
            }
        }
    }
    cout<<"Sortest distance from source to every vertex:"<<endl;
    cout<<0<<" -> ";
    for(int i=0;i<vertex;i++){
        if(dist[i]!=1e9){
            cout<<dist[i]<<" ";
        }
        else{
            cout<<"INF"<<" ";
        }
    }
}
int main(){
    int edges,vertex;
    cin>>edges>>vertex;
    vector<pair<int,int>> graph[vertex];
    for(int i=0;i<edges;i++){
        int m,n,wt;
        cin>>m>>n>>wt;
        graph[m].push_back({n,wt});
    }
    for(int i=0;i<vertex;i++){
        cout<<i<<" -> ";
        for(auto x:graph[i]){
            cout<<"("<<x.first<<","<<x.second<<") ";
        }
        cout<<endl;
    }
    shortestPath(0,vertex,graph);
    return 0;
}