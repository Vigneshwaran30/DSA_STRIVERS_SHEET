#include<bits/stdc++.h>
using namespace std;

int main(){

    // Implemented using Singly LL in Backend 
    vector<int> v;
    v.push_back(5);
    v.emplace_back(10);//Genreally emplace_back is faster than push_back
    v.push_back(15);
    v.push_back(20);
    
    // for(vector<int>:: iterator it=v.begin();it!=v.end();it++){
    //     cout<<*(it)<<endl;
    // }
    
    // for(auto it=v.begin();it!=v.end();it++){
    //     cout<<*(it)<<endl;
    // }
    
    
    // for Each loop
    // for(auto it:v){
    //     cout<<it<<endl;
    // }

    v.erase(v.begin()+2,v.end());
    for(auto it:v){
        cout<<it<<endl;
    }
    
    v.insert(v.end(),100);
    for(auto it:v){
        cout<<it<<endl;
    }
    cout<<v.size()<<endl;
    
    for(auto it:v){
        cout<<it<<endl;
    }
    
    // POP BACK REMOVES THE LAST ELEMENT THAT IS INSERTED
    v.pop_back();
    cout<<"AFTER POP BACK"<<endl;
    for(auto it:v){
        cout<<it<<endl;
    }

    v.clear();//Clears the vector
    // v.empty() - returns true if vector is empty else false

    return 0;
}

void explainlist(){
    // Implemented using Doubly LL in Backend 
    // similar to vector but there is push front and emplace front available 
    list<int> ls;
    ls.push_back(1);
    ls.emplace_back(2);
    for(auto it:ls){
        cout<<it<<"\t";
    }    
    cout<<endl;
    ls.push_front(3);
    ls.emplace_front(4);
    for(auto it:ls){
        cout<<it<<"\t";
    }   
}
