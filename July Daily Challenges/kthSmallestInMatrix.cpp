/*Approach: Take a max heap and simply add elements to it till size becomes k
*/
#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>> matrix, int n, int m, int k);

int main(){
    int n, m, k;
    cout<<"Enter number of rows and columns and k  ";
    cin>>n>>m>>k;
    vector<vector<int>> matrix(n, vector<int>(m,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>matrix[i][j];
        }
    }
   cout<<kthSmallest(matrix, n, m, k);
}
int kthSmallest(vector<vector<int>> matrix, int n, int m, int k){
    int ans = 0;
    priority_queue<int> max;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            max.push(matrix[i][j]);
            if(max.size() > k){
                max.pop();
            }
        }
    }
    return max.top();
}
