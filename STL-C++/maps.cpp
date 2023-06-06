#include<bits/stdc++.h>
using namespace std;
void explainmap(){
    map<int,int> mpp;
    mpp[1]=1;
    mpp.insert({3,3});
    for(auto it:mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    auto it=mpp.find(1);
}