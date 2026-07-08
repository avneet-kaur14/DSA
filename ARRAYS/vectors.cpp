#include <iostream>
#include <vector>
using namespace std;

//pairSum(given vector is sorted in asc order) - (somewhat binary search logic)

vector<int> pairSum(vector<int> v,int target){
    int st=0,end=v.size()-1;
    int currSum=0;
    vector<int> ans;
    while(st<end){
        currSum=v[st]+v[end];
        if(currSum==target){
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }else if(currSum<target){
            st++;
        }else{
            end--;
        }
    }
    return ans;
}

int main(){
    vector<int> nums={2,7,11,15};
    vector <int> ans=pairSum(nums,22);
    cout<<ans[0]<<","<<ans[1];
}