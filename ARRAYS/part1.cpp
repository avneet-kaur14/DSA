#include <iostream>
using namespace std;


//finding largest and smallest in array
// int main(){
//     int arr[]={18,45,66,12,30};
//     int n=sizeof(arr)/sizeof(int);
//     int max=-999;
//     int min=999;
//     int max_idx,min_idx;

//     for(int i=0;i<n;i++){
//         if(arr[i]>max){
//             max=arr[i];
//             max_idx=i;
//         }
//         if(arr[i]<min){
//             min=arr[i];
//             min_idx=i;
//         }
//     }
//     cout<<"maximum value:"<<max<<",found at idx "<<max_idx<<endl;
//     cout<<"minimum value:"<<min<<",found at idx "<<min_idx<<endl;

// }

//linear search TC:O(n)
// int main(){
//     int arr[5]={40,33,66,78,92};
//     int n=sizeof(arr)/sizeof(int);
//     int target=78;
//     int idx=-1;
//     for(int i=0;i<n;i++){
//         if(arr[i]==target){
//             idx=i;
//             break;
//         }
//     }

//     if(idx==-1){
//         cout<<"not found"<<endl;
//     }else{
//         cout<<target<<" found at idx "<<idx<<endl;
//     }
// }

//BINARY SEARCH TC:O(log n)
// int main(){
//     int arr[5]={33,56,63,78,99};
//     int n=sizeof(arr)/sizeof(int);
//     int target=99;
//     int idx=-1;
//     int st=0,end=n-1;
//     while(st<=end){
//         int mid=(st+end)/2;

//         if(target==arr[mid]){
//             idx=mid;
//             break;
//         }else if(target<arr[mid]){
//             end=mid-1;
//         }else{
//             st=mid+1;
//         }
//     }

//     if(idx==-1){
//         cout<<"not found"<<endl;
//     }else{
//         cout<<target<<" found at idx "<<idx<<endl;
//     }
// }

//REVERSE AN ARRAY
int main(){
    int arr[6]={33,56,63,78,99,55};
    int n=sizeof(arr)/sizeof(int);
    int st=0,end=n-1;
    while(st<end){
        swap(arr[st],arr[end]);
        st++;
        end--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}