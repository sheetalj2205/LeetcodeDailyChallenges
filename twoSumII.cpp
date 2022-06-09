#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& arr, int t);
int main(){
    int n;
    cout<<"Enter size of the array"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter sorted array";
    for(int i = 0; i<n ;i++){
        cin>>arr[i];
    }
    int t;
    cout<<"Enter target"<<endl;
    cin>>t;
    vector<int> sum = twoSum(arr, t);
    for(int i  = 0; i<sum.size(); i++){
        cout<<sum[i]<<" ";
    }
}

vector<int> twoSum(vector<int>& arr, int target){
    vector<int> sum;
        for(int x = 0; x < arr.size(); x++)
        {
            int low = 0, high = arr.size()-1;
            while(low <= high)
            {
                int mid = low + (high - low)/2;
                if(arr[mid] == target - arr[x])
                {
                    if(mid == x)
						low = mid + 1;  // moves low to next value in case the original value is the difference to be added
                    else
                    {
                        sum = {x+1, mid+1}; //add index of elements in sum (index = 0 add it as index+1)
                        return sum;
                    }
                }
                else if(arr[mid] < target - arr[x])
                    low = mid + 1; //if value of arr[mid] < diff the increase low
                else
                    high = mid - 1; //if value of arr[mid] > diff then decrease high 
            }
        }
    return sum;

}
