/*
You have a sorted array - find first and last index of the target element. 
Brute force approach - using two for loops - O(n) time
Optimised approach - binary search - O(nlogn) time
*/
#include<bits/stdc++.h>
using namespace std;

void findIndices(vector<int> &arr, int target);

int main(){
    int target, n;
    cout<<"Enter target element and size of array ";
    cin>>target>>n;
    vector<int> arr(n);
    cout<<"Enter sorted array ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    findIndices(arr, target);
}

void findIndices(vector<int> &arr, int target){
    //binary search approach
    vector<int> ans(2,-1); //initialize vector to store first and last occurence of element
    int low = 0, high = arr.size()-1;

    //first occurence
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] < target){
            low = mid+1;
        }
        else if(arr[mid] > target){
            high = mid -1;
        }
        else{
            //when arr[mid-1] is not equals to arr[mid] then mid is the first occurence of that element or if mid is at low index(starting index) which means arr[low] or arr[mid] == target then also this condition satisfies
            if(mid == low || arr[mid-1] != arr[mid]){ 
                ans[0] = mid;
                break;
            }
            else{
                //when arr[mid] == target but arr[mid-1] == arr[mid] OR mid!=low then shift high
                high = mid-1;
                ans[0] = mid-1;
            }
        }
    }
    //last occurence
    low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] < target){
            low = mid+1;
        }
        else if(arr[mid] > target){
            high = mid -1;
        }
        else{
            //when arr[mid+1] is not equals to arr[mid] then mid is the last occurence of that element or if mid is at high index(last index) which means arr[high] or arr[mid] == target then also this condition satisfies
            if(mid == high || arr[mid+1] != arr[mid]){ 
                ans[1] = mid;
                break;
            }
            else{
                //when arr[mid] == target but arr[mid+1] == arr[mid] OR mid!=high then shift low
                low = mid+1;
                ans[1] = mid+1;
            }
        }
    }
    for(int i = 0; i<2; i++){
        cout<<ans[i]<<" ";
    }
}

