#include<bits/stdc++.h>
using namespace std;

int maxArea(int h, int w, vector<int>& hc, vector<int>& vc);

int main(){
    int h, w;
    cout<<"Enter hight and width ";
    cin>>h>>w;
    int n, m;
    cout<<"Enter size of horizontal and vertical vectors size: ";
    cin>>n>>m;
    vector<int>hv(n);
    vector<int>vv(m);
    cout<<"Enter horizontal cuts vector"<<endl;
    for(int i = 0; i<n; i++){
        cin>>hv[i];
    }
    cout<<"Enter vertical cuts vector"<<endl;
    for(int i = 0; i<m; i++){
        cin>>vv[i];
    }
    cout<<maxArea(h, w, hv, vv);
}
int maxArea(int h, int w, vector<int>& hc, vector<int>& vc){
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        int hdiff=0, vdiff = 0;
        for(int i = 1; i<hc.size(); i++){
            hdiff = max(hdiff, hc[i]-hc[i-1]);
        }
        for(int i = 1; i<vc.size(); i++){
            vdiff = max(vdiff, vc[i]-vc[i-1]);
        }
        return hdiff*vdiff;
}
