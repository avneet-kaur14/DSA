#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n){  //large els come to end by swapping adjacents
//O(n^2)
    for(int i=0;i<n;i++){
        bool isSwap=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
        }
        if(!isSwap){
            return;
        }
    }
}


void selectionSort(int arr[],int n){
//O(n^2) //pick the min el from unsorted part of array and put it in beginning by swapping 
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

//useful for nearly sorted arrays and online sorting-******** best case TC:O(n)
void insertionSort(int arr[],int n){ //pick el from unsorted part and place it correctly in sorted part
//O(n^2)
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev] < curr){  // < is for descending order
            // swap(arr[prev],arr[prev+1]);
            arr[prev+1]=arr[prev]; //shifting is better than swapping
            prev--;
        }
        arr[prev+1]=curr;
    }
}


//⭐non-comparing algorithm
//preferred when The range of values is small compared to the number of elements  
void countingSort(int arr[],int n){ //it counts how many times each value appears, then reconstructs the sorted array using those counts.
//O(n+k)   
    int minVal=INT_MAX,maxVal=INT_MIN;
    int freq[1000]={0};

    for(int i=0;i<n;i++){  //O(n)
        freq[arr[i]]++;
        minVal=min(arr[i],minVal);
        maxVal=max(arr[i],maxVal);
    }

    for(int i=minVal,j=0;i<=maxVal;i++){  //O(range) range=max-min
        while(freq[i]>0){
            arr[j++]=i;
            freq[i]--;
        }
    }
    
}

//INBUILT
//sort(arr,arr+n);
//sort(arr,arr+n,greater<int>())


int main(){
    int arr[5]={11,67,45,23,89};
    insertionSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}