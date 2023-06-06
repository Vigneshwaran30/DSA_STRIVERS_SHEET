#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //pair
    pair<int,int>pair1;
    pair1={1,2};
    cout<<pair1.first<<endl<<pair1.second<<endl;
    
    //pair of pair
    pair<int,pair<int,int>>pair2;
    pair2={1,{2,3}};
    cout<<pair2.first<<endl<<pair2.second.first<<"\t"<<pair2.second.second;
    
    //array of pair
    pair<int,int>arr[3]={{1,2},{3,4},{5,6}};
    cout<<endl<<arr[0].first<<"\t"<<arr[0].second;
    
    return 0;
}