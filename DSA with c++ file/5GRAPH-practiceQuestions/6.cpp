// Our task is to find the articulation point in graph: A point which divide the graph into two part

// Our task is to find the bridges present in the graph: beridges means the edge which connct two graph directly, if the bridge edge is
// removed then the graph will be disconnected.

#include <bits/stdc++.h>
using namespace std;
void dfs(int src,int parent,int timer,int cur[],int low[],bool visited[],vector<int> graph[]){
    visited[src]=true;
    cur[src]=low[src]=timer;
    timer++;
    for(auto nbr:graph[src]){
        if(visited[nbr]==false){
            dfs(nbr,src,timer,cur,low,visited,graph);
            low[src]=min(low[src],low[nbr]);
            if(low[nbr]>=cur[src] && parent!=-1){
                cout<<src<<" ";
            }
        }
        else{
            low[src]=min(low[src],cur[nbr]);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> graph[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int time[n];
    int low[n];
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
        low[i]=-1;
        time[i]=-1;
    }
    cout<<"Articulation points: "<<endl;
    int timer=0;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            dfs(i,-1,timer,time,low,visited,graph);
        }
    }
    return 0;
}