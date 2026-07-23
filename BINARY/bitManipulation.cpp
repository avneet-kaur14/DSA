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

bool isPowerof2(int n){
    if(!(n & n-1)){
        return true;
    }else{
        return false;
    };
}
int main(){
    oddEven(8);
    oddEven(15);
    cout<<getIthBit(6,3)<<endl;
    cout<<setIthBit(6,3)<<endl;
    cout<<clearIthBit(6,1)<<endl;
    cout<<isPowerof2(6)<<endl;
    cout<<isPowerof2(16)<<endl;
    cout<<isPowerof2(61)<<endl;

}