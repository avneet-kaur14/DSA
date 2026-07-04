#include <iostream>
#include <climits>
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