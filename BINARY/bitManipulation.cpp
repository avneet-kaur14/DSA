#include <iostream>
using namespace std;

void oddEven(int num){
    if(!(num&1)){
        cout<<"even\n";
    }else{
        cout<<"odd\n";
    }
}

int getIthBit(int n,int i){
    int bitMask=1<<i;
    if ((n & bitMask)==0){  // == has higher precendence than bitwise operators.
        return 0;
    }else{
        return 1;
    }
}

int setIthBit(int num,int i){  //0=>1,1=>1
    int bitMask=1<<i;
    return (num|bitMask);
}

int clearIthBit(int num,int i){   //0=>0,1=>0
    int bitMask=~(1<<i);
    return (num&bitMask);
}

bool isnerof2(int n){
    if(!(n & n-1)){
        return true;
    }else{
        return false;
    };
}

void updateIthBit(int num,int i,int val){
    num=num& ~(1<<i); //clear ith bit first
    num=num|(val<<i);
    cout<<num<<endl;
}

void cleariBits(int num,int i){
    int bitMask=(~0)<<i;  
    num=num & bitMask;
    cout<<num<<endl;
}

int countSetBits(int num){
    int count=0;
    while(num>0){
        int lastDigit=num & 1;
        count+=lastDigit;

        num=num>>1;
    }
    return count;
}

int fastExpo(int x,int n){
    int ans=1;
    while(n>0){
        int lastBit=(n&1);
        if(lastBit){
            ans=ans*x;
        }
        x=x*x;
        n=n>>1;
    }
    return ans;
}
int main(){
    // oddEven(8);
    // oddEven(15);
    // cout<<getIthBit(6,3)<<endl;
    // cout<<setIthBit(6,3)<<endl;
    // cout<<clearIthBit(6,1)<<endl;
    // cout<<isnerof2(6)<<endl;
    // cout<<isnerof2(16)<<endl;
    // cout<<isnerof2(61)<<endl;
    // updateIthBit(7,2,0);
    // updateIthBit(7,3,1);
    // cleariBits(15,2);
    // cout<<countSetBits(10)<<endl;
    cout<<fastExpo(10,3)<<endl;
}