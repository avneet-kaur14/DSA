#include <iostream>
#include <vector>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

void print(int n){
    if (n==0){
        return;
    }
    cout<<n<<" ";
    return print(n-1);
} 

int nthFibo(int n){
    if(n==0 || n==1){
        return n;
    }

    return nthFibo(n-1)+nthFibo(n-2);
}

bool isSorted(int arr[],int n,int i){
    if(i==n-1){
        return true;
    }

    if(arr[i]>arr[i+1]){
        return false;
    }
    return isSorted(arr,n,i+1);
    }


int firstOcc(vector<int> nums,int i,int target){
    if(i==nums.size()-1){
        return -1;
    }

    if(nums[i]==target){
        return i;
    }
    return firstOcc(nums,i+1,target);
}

int lastOcc(vector<int> nums,int i,int target){
    if(i<0){
        return -1;
    }

    if(nums[i]==target){
        return i;
    }
    return lastOcc(nums,i-1,target);
}

int pow(int x,int n){
    if (n==0){
        return 1;
    }

    int halfpow=pow(x,n/2);
    int doublehalfPow=halfpow*halfpow;

    if (n%2==0){
        return doublehalfPow;
    }else{
        return x*doublehalfPow;
    }
}
int main(){
    cout<<factorial(5)<<endl;
    print(10);
    cout<<endl;
    cout<<nthFibo(10)<<endl;
    int arr[]={2,6,8,9,10};
    int arr2[]={8,42,6,2,10};
    cout<<isSorted(arr,5,0)<<endl;
    cout<<isSorted(arr2,5,0)<<endl;

    vector<int> nums={1,2,3,3,3,6,7};
    cout<<firstOcc(nums,0,10)<<endl;
    cout<<lastOcc(nums,nums.size()-1,3)<<endl;

    cout<<pow(2,5);
    

}