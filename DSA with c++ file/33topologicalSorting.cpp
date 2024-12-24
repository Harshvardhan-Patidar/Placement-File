// acyclic graph is called topological graph: if (u,v) are the vertex of graph then it sorting u come before v

#include <bits/stdc++.h>
using namespace std;
void dfs(int src,bool visited[],vector<int> graph[],stack<int> &s){
    visited[src]=true;
    for(auto nbr:graph[src]){
        if(visited[nbr]==false){
            dfs(nbr,visited,graph,s);
        }
    }
    s.push(src);
}
void topologicalSortDFS(int vertex,bool visited[],vector<int> graph[]){
    stack<int> s;
    for(int i=0;i<vertex;i++){
        if(visited[i]==false){
            dfs(i,visited,graph,s);
        }
    }
    cout<<"Topological sort order: ";
    while(s.empty()==false){
        cout<<s.top()<<" ";
        s.pop();
    }
}
void topologicalSortBFS(int vertex,bool visited[],vector<int> graph[]){
    int indegree[vertex];
    fill(indegree,indegree+vertex,0);
    for(int i=0;i<vertex;i++){
        for(auto nbr:graph[i]){
            indegree[nbr]++;
        }
    }
    queue<int> q;
    for(int i=0;i<vertex;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    cout<<"Topoplocial sorting: ";
    while(q.empty()==false){
        int node=q.front();
        cout<<node<<" ";
        q.pop();
        for(auto nbr:graph[node]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
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
    for(int i=0;i<vertex;i++){
        cout<<i<<" -> ";
        for(auto x:graph[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    bool visited[vertex];
    fill(visited,visited+vertex,false);
    topologicalSortDFS(vertex,visited,graph);
    topologicalSortBFS(vertex,visited,graph);
    return 0;
}