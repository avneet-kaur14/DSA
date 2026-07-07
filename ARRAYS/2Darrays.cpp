#include <iostream>
using namespace std;
//SPRIRAL MATRIX🌀

void spiralMatrix(int arr[][4],int n,int m){
    int srow=0,scol=0,erow=n-1,ecol=m-1;

    while(srow<=erow && scol<=ecol){
        //top
        for(int i=scol;i<=ecol;i++){
            cout<<arr[srow][i]<<" ";
        }

        //right
        for(int i=srow+1;i<=erow;i++){
            cout<<arr[i][ecol]<<" ";
        }

        //bottom
        for(int i=ecol-1;i>=scol;i--){
            if(srow==erow){  //corner case for odd mattrix //middle-already printed in top boundary
                break;
            }
            cout<<arr[erow][i]<<" ";
        }

        //right
        for(int i=erow-1;i>srow;i--){
            if(scol==ecol){  //corner case for odd mattrix //middle-already printed in top boundary
                break;
            }
            cout<<arr[i][scol]<<" ";
        }

        srow++;
        erow--;
        scol++;
        ecol--;
    }
}

// int main(){
//     int arr[4][4]={{1,2,3,4},
//                    {5,6,7,8},
//                    {9,10,11,12},
//                    {13,14,15,16}};
//     int arr2[3][4]={{1,2,3,4},
//                    {5,6,7,8},
//                    {9,10,11,12}};
//     spiralMatrix(arr,4,4);
//     cout<<endl;
//     spiralMatrix(arr2,3,4);

// }


//DIAGNOL SUM-O(n)

int diagnolSum(int arr[][3],int n){
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i][i];
        if(i!=n-i-1){
            sum+=arr[i][n-i-1];
        }
    }
    return sum;
}

// int main(){
//     int arr[4][4]={{1,2,3,4},
//                    {5,6,7,8},
//                    {9,10,11,12},
//                    {13,14,15,16}};
//     int arr2[3][3]={{1,2,3},
//                    {4,5,6},
//                    {7,8,9}};
//     // cout<<diagnolSum(arr,4);
//     // cout<<endl;
//     cout<<diagnolSum(arr2,3);

// }


//SEARCH IN A SORTED MATRIX-🗿STAIRCASE APPROACH(👌BEST FOR BOTH ROW-WISE AND COLUMN-WISE SORTED MATRIX)
                            //other two are brute force and binary search either column wise or row-wise!
//O(n+m)
bool search(int arr[][4],int n,int m,int key){
    int r,c;
    int i=n-1,j=0;

    while(i>=0 && j<m){
        if(arr[i][j]==key){
            cout<<key<<" found at cell ("<<i<<","<<j<<")";
            return true;
        }else if(arr[i][j]<key){
            j++;
        }else{
            i--;
        }
    }

    cout<<"key not found";
    return false;
}

int main(){
    int arr[4][4]={{1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12},
                   {13,14,15,16}};
    int arr2[3][3]={{1,2,3},
                   {4,5,6},
                   {7,8,9}};
    search(arr,4,4,7);

}