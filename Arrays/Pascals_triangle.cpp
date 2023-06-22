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
int returnelement(int row,int col){
    int res=1;
    for(int i=0;i<col;i++){
        res=res*(row-i);
        res=res/(i+1);
    }
    return res;
}

// Time Complexity:O(col)
// Space Complexity:O(1)

int main(){
    int row1;
    cout<<"Enter row and column:";
    cin>>row1;
    int col1;
    cin>>col1;
    cout<<endl;

    int elem=returnelement(row1-1,col1-1);
    cout<<elem<<endl;
    return 0;
}

// Type 2
// print the ith row fully
