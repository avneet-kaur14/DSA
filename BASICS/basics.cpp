#include <iostream>
#include <cmath>
using namespace std;

// int main(){
//     cout<<"Hello world!\n";

//     //check for prime number
//     int num=15;
//     bool isPrime=true;
//     for(int i=2;i<num-1;i++){
//         if(num%i==0){
//             isPrime=false;
//             break;
//         }
//     }
//     cout<<isPrime<<endl;
//     return 0;
// }


//optimized logic for prime num
// int main(){
//     int num;
//     cout<<"Enter number:"<<endl;
//     cin>>num;
//     bool isPrime=true;
//     for(int i=2;i<=sqrt(num);i++){  //only need to test divisors up to sqrt(num) because factors come in pairs.
//         if(num%i==0){
//             isPrime=false;
//             break;
//         }
//     }
//     cout<<isPrime<<endl;
//     return 0;
// }


//factorial
// int main(){
//     int n=5;
//     int fact=1;
//     for(int i=1;i<=n;i++){
//         fact*=i;
//     }
//     cout<<fact<<endl;
// }


//armstrong number
// int digitsCount(int n){
//     int d=0;
//     while(n>0){
//         d++;
//         n/=10;
//     }
//     return d;
// }
// int main(){
//     int n=153;
//     int temp=n;
//     int digits=digitsCount(n);
    
//     int sum=0;

//     while(n>0){
//         int ld=n%10;
//         int p = 1;
//         for (int i = 0; i < digits; i++) {
//             p *= ld;
//         }
//         sum += p;
//         n/=10;
//     }
//     if(temp==sum){
//         cout<<sum<<","<<temp<<",armstrong number"<<endl;
//     }else{
//         cout<<sum<<","<<temp<<" ,not armstrong number"<<endl;
//     }
// }

//fibonacci series
int main(){
    int n=10;
    int f=0,s=1;
    cout<<f<<" "<<s<<" ";
    int sum=0;
    for(int i=1;i<n;i++){
        sum=f+s;
        cout<<sum<<" ";
        f=s;
        s=sum;
    }
}