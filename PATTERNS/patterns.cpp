#include <iostream>
using namespace std;

//star pattern
// int main(){
//     int n=5;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

//inverted star pattern
// int main(){
//     int n=5;
//     for(int i=0;i<n;i++){
//         for(int j=1;j<=n-i;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

//half pyramid
// int main(){
//     int n=5;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }

//character pyramid
// char ch='A';
// int main(){
//     int n=7;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout<<ch;
//             ch++;
//         }
//         cout<<endl;
//     }
// }

//HOLLOW RECTANGLE PATTERN
// int main(){
//     int n=6;
//     for(int i=1;i<=n;i++){
//         cout<<"* ";
//         for(int j=1;j<n;j++){
//             if(i==1||i==n){
//                 cout<<"* ";
//             }else{
//                 cout<<"  ";
//             }
//         }
//         cout<<"* "<<endl;
//     }
// }

//inverted and rotated half pyramid
// int main(){
//     int n=5;

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n-i;j++){
//             cout<<"  ";
//         }
//         for(int j=1;j<=i;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

//Floyd's triangle
// int n=5;
// int num=1;
// int main(){
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout<<num++<<" ";
//         }
//         cout<<endl;
//     }
// }

//DIAMOND PATTERN
// int  main(){
//     int n=5;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n-i;j++){
//             cout<<"  ";
//         }
//         for(int j=1;j<=2*i-1;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }

//     for(int i=n;i>=1;i--){
//         for(int j=1;j<=n-i;j++){
//             cout<<"  ";
//         }
//         for(int j=1;j<=2*i-1;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

//butterfly pattern
int main(){
    int n=4;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }

        for(int j=1;j<=2*(n-i);j++){
            cout<<"  ";
        }

        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }

        for(int j=1;j<=2*(n-i);j++){
            cout<<"  ";
        }

        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}