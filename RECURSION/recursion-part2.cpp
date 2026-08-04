#include <iostream>
#include <string>
using namespace std;

int tilingWays(int n){
    if(n==0||n==1){
        return 1;
    }

    return tilingWays(n-1)+tilingWays(n-2);
}

void removeDuplicates(string str,string ans,int i,int map[]){
    if(i==str.size()){
        cout<<ans<<endl;
        return;
    }

    char ch=str[i];
    int mapIdx=(int)ch-'a';

    if(map[mapIdx]){
        removeDuplicates(str,ans,i+1,map);
    }else{
        map[mapIdx]=true;
        removeDuplicates(str,ans+str[i],i+1,map);
    }
}

int friendsPairing(int n){
    if(n==1 || n==2){
        return n;
    }

    return friendsPairing(n-1)+ ((n-1) * friendsPairing(n-2));
}

void binaryString(int n,string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }

    if(ans[ans.size()-1]!='1'){
        binaryString(n-1,ans+'0');
        binaryString(n-1,ans+'1');
    }else{
        binaryString(n-1,ans+'0');
    }
}

//ASSIGNMENT QUESTIONS
int binarySearch(int arr[],int st,int end,int target){

    if(st>end){
        return -1;
    }
    int mid=st+(end-st)/2;

    if(arr[mid]==target){
        return mid;
    }

    if(arr[mid]<target){
        return binarySearch(arr,mid+1,end,target);
    }
    return binarySearch(arr,st,mid-1,target);
}

int occ(int arr[],int key,int i){
    if(i<0){
        return 0;
    }
    return (arr[i]==key) + occ(arr,key,i-1);
  
}
int main(){
    // cout<<tilingWays(4)<<endl;

    // int map[26]={false};
    // removeDuplicates("appnna college","",0,map);

    // cout<<friendsPairing(4)<<endl;

    // binaryString(3,"");

    // int arr[] = {12, 23, 34, 56, 67, 85, 90};
    // cout << binarySearch(arr, 0, 6, 34); 

    int arr[]={3,2,4,5,6,2,7,2,3,2};
    int n=sizeof(arr)/sizeof(int);
    cout<<occ(arr,3,n-1);
}