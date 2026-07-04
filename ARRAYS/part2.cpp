#include <iostream>
#include <climits> //for INT_MAX INT_MIN
#include <algorithm> //for SORT()
using namespace std;

//SUBARRAYS-O(n^3)
// int main(){
//     int arr[]={1,2,3,4,5};
//     int n=sizeof(arr)/sizeof(int);

//     for(int i=0;i<n;i++){ //n
//         for(int j=i;j<n;j++){ //n
//             for(int k=i;k<=j;k++){ //n
//                 cout<<arr[k];
//             }
//             cout<<", ";
//         }
//         cout<<endl;
//     }
// }


//MAX SUBARRAYS SUM
//BRUTE FORCE APPROACH O(n^3)
void subArraySum1(int arr[],int n){
    int maxSum=INT_MIN;

    for(int st=0;st<n;st++){
        for(int e=st;e<n;e++){
            int currSum=0;
            for(int k=st;k<=e;k++){
                currSum+=arr[k];
            }
            // cout<<currSum<<", ";
            maxSum=max(currSum,maxSum);
        }
        // cout<<endl;
    }
    cout<<maxSum<<" is the maximum sum";
}

//Slightly optimized O(n^2)
void subArraySum2(int arr[],int n){
    int maxSum=INT_MIN;

    for(int st=0;st<n;st++){
        int currSum=0;
        for(int e=st;e<n;e++){
            currSum+=arr[e];
            maxSum=max(currSum,maxSum);
        }
        // cout<<endl;
    }
    cout<<maxSum<<" is the maximum sum";
}

//KADANE'S ALGORITHM O(N)****IMPORTANT FOR INTERVIEWS    
void subArraySum3(int arr[],int n){
    int maxSum=INT_MIN;
    int currSum=0;

    for(int st=0;st<n;st++){
        currSum+=arr[st];
        maxSum=max(maxSum,currSum);
        if(currSum<0){
            currSum=0;
        }
    }
    cout<<maxSum<<" is the maximum sum";
}

// int main(){
//     int arr[6]={2,-3,6,-5,4,2};
//     int arr2[]={-1,-2,-3,-4,-5};
//     int n=6;
//     subArraySum3(arr,n);
//     cout<<endl;
//     subArraySum3(arr2,5);
// }


//BUY AND SELL STOCKS

void buyAndSell(int arr[],int n){
    int bestBuy[100000];
    bestBuy[0]=INT_MAX;

    for(int i=1;i<n;i++){
        bestBuy[i]=min(arr[i-1],bestBuy[i-1]);
    }

    int maxProfit=0;
    for(int i=0;i<n;i++){
       int currProfit=arr[i]-bestBuy[i];
       maxProfit=max(maxProfit,currProfit);
    }

    cout<<"maxProfit:"<<maxProfit<<endl;
}

// int main(){
//     int prices[]={7,1,5,3,6,4};
//     int prices2[]={6,5,4,3,2,1}; //0
//     int n=sizeof(prices)/sizeof(int);

//     buyAndSell(prices,n);
// }

//TRAPPING RAINWATER

int trap(int heights[],int n){
    int leftMax[100],rightMax[100];
    leftMax[0]=heights[0];
    rightMax[n-1]=heights[n-1];

    for(int i=1;i<n;i++){
        leftMax[i]=max(leftMax[i-1],heights[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        rightMax[i]=max(rightMax[i+1],heights[i+1]);
    }
    int waterTrapped=0;
    for(int i=0;i<n;i++){
        int currWater=min(rightMax[i],leftMax[i])-heights[i];
        if(currWater>0){
            waterTrapped+=currWater;
        }
    }
    return waterTrapped;
}

// int main(){
//     int heights[7]={4,2,0,6,3,2,5};
//     int heights2[7]={7,6,5,4,3,2,1}; //0
//     int n=sizeof(heights)/sizeof(int);
//     cout<<trap(heights,n);
// }

//ASSIGNMENT QUESTIONS 
//Question1:Given an integer array nums,return true if any value appears at least twice in the array,and return false if every element is distinct.
bool duplicate(int arr[],int n){  //O(n^2)
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]==arr[i]){
                return true;
            }
        }
    }
    return false;
}
//MORE OPTIMIZED O(n log n)-SORTING THEN COMPARING ADJACENT
bool duplicate2(int arr[],int n){  
    sort(arr,arr+n);
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            return true;
        }
    }
    
    return false;
}
// int main(){
//     int arr[]={1,1,1,3,3,4,3,2,4,2};
//     int arr2[]={1,2,3,4,5};
//     int n=sizeof(arr)/sizeof(int);
//     cout<<duplicate(arr,n)<<endl;
//     cout<<duplicate(arr2,5)<<endl;

//     cout<<duplicate2(arr,n)<<endl;
//     cout<<duplicate2(arr2,5);
// }

//SEARCH IN ROTATED SORTED ARRAY-(1 ROTATION-(WHICH MEANS ONE HALF IS ALWAYS SORTED) AND NO DUPLICATES)

int search(int arr[],int n,int target){
    int st=0,end=n-1;
    int idx=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(target==arr[mid]){
            idx=mid;
        }

        if(arr[st]<=arr[mid]){ //if left half is sorted
            if(target>=arr[st] && target<arr[mid]){ //if target is in left half
                end=mid-1;
            }else{
                st=mid+1;
            }
        }else{ //right half is sorted
            if(target<=arr[end] && target>arr[mid]){ //if target is in right half
                st=mid+1;
            }else{
                end=mid-1;
            }
        } 
    }
    return idx;
}
// int main(){
//     int nums[] = {4,5,6,7,0,1,2};
//     int n = sizeof(nums) / sizeof(nums[0]);

//     cout << search(nums, n, 0);

//     return 0;
// }

//largest product subarray

int pr(int arr[],int n){
    int maxPr=INT_MIN;
    int currPr=1;
    for(int i=0;i<n;i++){
        currPr*=arr[i];
        maxPr=max(maxPr,currPr);
        if(currPr<=0){
            currPr=1;
        }
    }
    return maxPr;
}

int main(){
    int arr[]={2,3,-2,4};
    int arr2[]={-2,0,-1};
    int n=4;
    cout<<pr(arr,n)<<endl;
    cout<<pr(arr2,3);
}