#include<bits/stdc++.h>
using namespace std;

int mirrorReflection(int p, int q);

int main(){
    int p, q;
    cout<<"Enter p and q ";
    cin>>p>>q;
    cout<<mirrorReflection(p, q);
}

int mirrorReflection(int p, int q){
    //p and q both can't be even - make odd
    while((p%2==0) && (q%2==0)){
        p = p/2;
        q = q/2;
    }
    //when p is even and q is odd
    if(p%2 == 0 && q%2 != 0){
        return 2;
    }
    //when p is odd and q is odd
    if(p%2 != 0 && q%2!= 0){
        return 1;
    }

    return 0;

}
