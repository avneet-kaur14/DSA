#include <iostream>
using namespace std;


//Bin to Decimal
void binToDec(int n){
    int binNum=n;
    int decNum=0;
    int pow=1; //2^0 2^1 2^2 2^3...
    while(binNum>0){
        int lstDig=binNum%10;
        decNum+=lstDig*pow;
        pow*=2;
        binNum/=10;
    }
    cout<<decNum<<endl;
}

void decToBin(int n){
    int decNum=n;
    int binNum=0;
    int pow=1;  //10^0 10^1 10^2 10^3...

    while(decNum>0){
        int rem=decNum%2;
        binNum+=rem*pow;
        pow*=10;
        decNum/=2;
    }
    cout<<"Binary form of "<<decNum<<"is:"<<binNum;
}

int main(){
    binToDec(1011);
    decToBin(11);
}