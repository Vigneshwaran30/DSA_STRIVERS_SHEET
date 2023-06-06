#include<bits/stdc++.h>
using namespace std;

int main(){
// All operations happen in big oh of 1 time complexity...constant time complexity
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    while(st.size()!=0){
        cout<<st.top()<<"\t";
        st.pop();
    }
    cout<<endl;
    return 0;
}
