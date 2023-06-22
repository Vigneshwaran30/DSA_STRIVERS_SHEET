// 3 types of problems in pascals triangle

//                 1
//             1       1
//         1       2       1
//     1       3       3       1
// 1       4       6       4       1

// 1st type
// Given row and column give that elelemnt from pascals triangle
#include<bits/stdc++.h>
using namespace std;
long long returnelement(int row,int col){
    long long res=1;
    for(auto i=0;i<col;i++){
        res=res*(row-i);
        res=res/(i+1);
    }
    return res;
}

// Time Complexity:O(col)
// Space Complexity:O(1)


// Type 2
// print the ith row fully
vector<long long> printrow(long long row){
    long long ans=1;
    vector<long long>res;
    res.push_back(ans);
    for(auto i=1;i<row;i++){
        ans=ans*(row-i);
        ans=ans/i;
        res.push_back(ans);
    }
    return res;
}

//TC:O(row)
//SC:O(1)


//Type 3
//Print the entire Pascal Triangle
vector<vector<long long>> printtriangle(long long rows){
    vector<vector<long long>>ans;

    for(auto col=1;col<=rows;col++){
        ans.push_back(printrow(col));
    }
    return ans;
}

//TC:O(N^2)
//SC:O(1)

int main(){

    //Type1
    long long row1;
    cout<<"Enter row and column:";
    cin>>row1;
    long long col1;
    cin>>col1;
    cout<<endl;

    long long elem=returnelement(row1-1,col1-1);
    cout<<elem<<endl;

    //Type2
    vector<long long> ans=printrow(6);
    for(auto i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    // Type 3
    cout<<"Enter number of rows:";
    long long numberofrows;
    cin>>numberofrows;
    vector<vector<long long>>ans1;
    ans1=printtriangle(numberofrows);
    for(auto i=0;i<ans.size();i++){
        for(auto j=0;j<ans1[i].size();j++){
            cout<<ans1[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
