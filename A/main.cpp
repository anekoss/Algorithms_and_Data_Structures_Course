#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a,b;
    int k=1;
    int min=1, min1=1, max1=1;
    int max=1;
    cin>>a;
    for(int i=2;i<=n;i++){
        cin>>b;
    if(a==b){
        k++;
        if(k==3){
            max1=i-1;}
        else
        if(k<3){
            max1=i;
        }
    }
    else{
    if(k>=3){
        min1=i-2;
        max1=i;
    }
    else
    if(k<3){
        max1=i;
    }
    k=1;}
    if(max-min<max1-min1){
        max=max1;
        min=min1;
    }
    a=b;
    }
    cout<<min<<" "<<max;
    return 0;
}

