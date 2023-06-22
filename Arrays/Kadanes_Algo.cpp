#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int arraystart,arrayend;//To get the index of subarray 
    int maxcount = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int start;
        if(sum==0){
            start=i;
        }
        sum += nums[i];
        if (sum < 0)
        {
            sum = 0;
        }
        if(sum>maxcount){
            maxcount=sum;
            arraystart=start;
            arrayend=i;
        }
    }
    // Prints the start index of max subarray and end index of max subarray
    cout<<arraystart<<" "<<arrayend<<endl;
    return maxcount;
}

//TC:O(N)
//SC:O(1)

int main(){
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
    int ans=maxSubArray(nums);
    cout<<ans<<endl;
    return 0;
}
