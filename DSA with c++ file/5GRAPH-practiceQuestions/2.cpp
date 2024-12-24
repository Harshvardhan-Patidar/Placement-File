#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &grid,int i,int j,vector<vector<bool>> &visited){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j]==true || grid[i][j]=='0'){
        return;
    }
    visited[i][j]=true;
    dfs(grid,i-1,j,visited);  //upper
    dfs(grid,i,j+1,visited);  //right
    dfs(grid,i+1,j,visited);  //bottom
    dfs(grid,i,j-1,visited);  //left
}
int numIslands(vector<vector<char>> &grid){
    int count=0;
    int row=grid.size();
    int col=grid[0].size();
    vector<vector<bool>> visited(row,vector<bool>(col,false));  //visited vector
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]=='1' && visited[i][j]==false){
                dfs(grid,i,j,visited);
                count++;
            }
        }
    }
    return count;
}
int main(){
    int rows, cols;
    cin>>rows>>cols;
    vector<vector<char>> grid(rows, vector<char>(cols));
    cout << "Enter the grid values (0 or 1):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }
    cout<<"Number of islands: "<<numIslands(grid);
    return 0;
}