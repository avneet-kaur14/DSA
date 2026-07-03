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

//KADANE'S ALGORITHM O(N)
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

int main(){
    int arr[6]={2,-3,6,-5,4,2};
    int arr2[]={-1,-2,-3,-4,-5};
    int n=6;
    subArraySum3(arr,n);
    cout<<endl;
    subArraySum3(arr2,5);
}