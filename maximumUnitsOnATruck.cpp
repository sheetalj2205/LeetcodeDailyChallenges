#include<bits/stdc++.h>
using namespace std;

int maxUnits(vector<vector<int>> &vec, int size);

int main(){
    int n, size;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    vector<vector<int>> vec( n , vector<int> (2, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<2; j++){
            cin>>vec[i][j];
        }
    }
    cout<<"Enter truck size";
    cin>>size;
    int ans = maxUnits(vec, size);
    cout<<ans;

}
bool sortcol( const vector<int>& v1,
               const vector<int>& v2 ) {
    return v1[1] > v2[1]; // sort the second column
}
   
int maxUnits(vector<vector<int>> &vect, int size){
    sort(vect.begin(), vect.end(),sortcol);
        int ans = 0;
        for(int i = 0; i<vect.size(); i++){
            if(size>0){ //size should always be greater than 0
            if(vect[i][0] <= size){
                ans += (vect[i][0]*vect[i][1]);
            }
            else{
                ans += size*vect[i][1]; //if numberOfBox is greater than the size of the truck then simply multiply size with numberOfUnits
            }
            }
            size = size - vect[i][0]; // decrease the size of the truck
        }
        return ans;
}
