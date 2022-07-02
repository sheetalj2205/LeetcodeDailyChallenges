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
   //passing 42/56 cases this approach:  
   /*
   1) Sort both the arrays
   2) Check the size of arrays
   3) If both are of size 1 then max area would be their product
   4) If one of them is of size 1 then check the diff bw that element and width or hight and get their max.
   5) If one of them is not of size 1 then simply find consecutive max diff and find their product.
   */
  /*
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        int hdiff=0, vdiff = 0;
         if(vc.size() == 1 && hc.size() == 1 ){
           return vc[0]*hc[0];
        }
        else if(vc.size() == 1 || hc.size() == 1 ){
            if(vc.size() == 1){
                vdiff = max(w-vc[0], vc[0]);
            }
            else{
                hdiff = max(h-hc[0], hc[0]);
            }
            
        }
        if(vc.size() > 1 || hc.size() > 1){
          for(int i = 1; i<hc.size(); i++){
            hdiff = max(hdiff, hc[i]-hc[i-1]);
          }
          for(int i = 1; i<vc.size(); i++){
            vdiff = max(vdiff, vc[i]-vc[i-1]);
          }
        }
        return hdiff*vdiff;
        */

        /* To optimze this approach simply push 0 and height, width to both the arrays then sort them and return the ans by modulo 10^9+7 and long long int doesn't support max and min functions so manually find greatest diff
        */
        hc.push_back(0);
        hc.push_back(h);
        vc.push_back(0);
        vc.push_back(w);
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        long long int hdiff=0, vdiff = 0;
        int mod = 1e9+7;
        for(int i = 1; i<hc.size(); i++){
            if(hc[i] - hc[i-1] > hdiff){
                hdiff = hc[i] - hc[i-1];
            }
          }
        for(int i = 1; i<vc.size(); i++){
            if(vc[i] - vc[i-1] > vdiff){
                vdiff = vc[i] - vc[i-1];
            }
          }
        return (hdiff*vdiff) % mod;
    }


