/*Approach: simple create a vector of pairs to add start and end time then check if the interval overlaps with other or not, if not then return true or false
*/
#include<bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    vector<pair<int, int>> m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for(auto it: m){
            if(start < it.second && it.first < end){
                return false;
            }
        }
            m.push_back({start, end});
        return true;
    }
};

int main(){
    MyCalendar* obj = new MyCalendar();
    bool param_1 = obj->book(10,20);
    bool param_2 = obj->book(15,25);
}
