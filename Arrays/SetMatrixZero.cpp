//Better Solution

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowsize=matrix.size();
        int colsize=matrix[0].size();
        vector<int>row(rowsize,0);
        vector<int>col(colsize,0);
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row[i]=-1;
                    col[j]=-1;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(col[j]==-1||row[i]==-1){
                    matrix[i][j]=0;
                }
            }
        }
}
};

TC:O(2*N*M)
SC:O(1)


//Optimal solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0)
                    matrix[0][j]=0;
                    else
                    col0=0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]!=0){
                    if(matrix[i][0]==0||matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<matrix[0].size();j++){
                matrix[0][j]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
    }
};
TC:O(2*N*M)
SC:O(1)
