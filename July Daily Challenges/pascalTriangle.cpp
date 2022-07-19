#include<bits/stdc++.h>
using namespace std;

/*          1
          /   \
          1    1
        /  \  / \
        1   2   1
       / \ / \ / \
       1  3   3   1
      / \ /\ / \ / \
      1  4  6   4  1

*/

void triangle(int rows);

int main(){
    cout<<"Enter no. of rows ";
    int n;
    cin>>n;
    triangle(n);
}

void triangle(int rows){
    //ans
    vector<vector<int>> ans;
    //loop for rows
    for(int i = 0; i<rows; i++){
      //intialize vector for each row
      vector<int> r(i+1,1); // size of the vector will be 1 plus of the row number
      //loop for column
      for(int j = 1; j<i; j++){
        r[j] = ans[i-1][j] + ans[i-1][j-1]; //find value of inside elements, j<i because we don't want to update last value
      }
      ans.push_back(r);
    }
for(int i = 0; i<rows; i++){
    for(int j = 0; j<ans[i].size(); j++){
        cout<<ans[i][j];
    }
    cout<<endl;
}
}
