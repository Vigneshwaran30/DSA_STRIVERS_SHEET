#include<bits/stdc++.h>
using namespace std;

int explainSet(){
    //operations happen in logarithmic time complexity 
    set<int> st;
    //unique and sorted;
    st.insert(1);
    st.insert(1);
    st.insert(2);
    st.insert(3);
    for(auto it1:st){
        cout<<it1<<"\t";
    }
    cout<<endl;
    set<int>::iterator it=st.find(2);
    cout<<*it<<" Hello";
    cout<<endl;
    st.erase(it);//Erasing with help of iterator
    st.erase(1);//erasing with the help of value
    for(auto it2:st){
        cout<<it2<<"\t";
    }
    return 0;
}