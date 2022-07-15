/*Graph:
Use DFS to solve this question
*/

#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<vector<int>> &island);

int main(){
    int n, m;
    cout<<"enter no. of rows and columns ";
    cin>>n>>m;
    vector<vector<int>> vec( n , vector<int> (m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>vec[i][j];
        }
    }
    cout<<maxArea(vec);
}

bool isValid(int i, int j, int n, int m, vector<vector<int>> &island){
    //check boundary conditions i.e. value of i and j are greater than or equal to zero and less than the size of row and col
    if(i<n && j<m && i>=0 && j>=0 && island[i][j] == 1){
        return true;
    }
    return false;
}

void dfs(vector<vector<int>> &island, int i, int j, int n, int m, int &area){
    //if the value of island[i][j] is 1 increase area by 1
    area++;
    //once the particular index is visited mark it as zero
    island[i][j] = 0;
    //check if the index is valid or not
    if(isValid(i+1, j, n, m, island)){
       //if the index is valid check values in all its four directions and wherever it is 1(checked by isValid function) increase area
       dfs(island, i+1, j, n, m, area);
    }
    if(isValid(i-1, j, n, m, island)){
       dfs(island, i-1, j, n, m, area);
    }
    if(isValid(i, j-1, n, m, island)){
       dfs(island, i, j-1, n, m, area);
    }
    if(isValid(i, j+1, n, m, island)){
       dfs(island, i, j+1, n, m, area);
    }
}
int maxArea(vector<vector<int>> &island){
    int n = island.size();
    int m = island[0].size();
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(island[i][j] == 1){ //if the value is 1 check its four direction neighbours through dfs
                int area = 0; //intialize area by 0 everytime when you get 1 to find max area
                dfs(island, i, j, n, m, area);
                ans = max(area, ans); //store max area in ans
            }
        }
    }
    return ans;
}
