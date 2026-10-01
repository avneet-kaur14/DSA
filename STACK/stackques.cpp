#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//PUSH AT THE BOTTOM OF STACK-RECURSION O(n)

// void pb(stack<int> &s,int val){
//     if(s.empty()){
//         s.push(val);
//         return;
//     }

//     int temp=s.top();
//     s.pop();

//     pb(s,val);
//     s.push(temp);
// }

// int main(){
//     stack<int> s;
//     s.push(3);
//     s.push(2);
//     s.push(1);

//     pb(s,4);
//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
// }


//STOCK SPAN PROBLEM-refer notes
// void stockSpan(vector<int> price , vector<int> &span){

//     stack<int> s;
//     s.push(0);
//     span[0]=1;
//     for(int i=0;i<price.size();i++){
//         while(!s.empty() && price[i]>=price[s.top()]){
//             s.pop();
//         }
//         if(s.empty()){
//             span[i]=i+1;
//         }else{
//             span[i]=i-s.top();
//         }

//         s.push(i);
//         cout<<span[i]<<" ";
//     }

// }

// int main(){
//     vector<int> stock={100,80,60,70,60,85,100};
//     vector<int> span={0,0,0,0,0,0,0};
//     stockSpan(stock,span);
// }


//DUPLICATE PARENTHESIS-Refer notes for ques
bool duplicateP(string str){
    stack<char> s;

    for(int i=0;i<str.length();i++){
        char ch=str[i];

        if(ch!=')'){ //non-closing
            s.push(ch);
        }else{ //closing
             if(s.top()=='('){   //if closing bracket is char and opening is encountered directly in stack then it is duplicate-return true
                return true;
            }

            while(s.top()!='('){
                s.pop();
            }
            s.pop();
        } 
    }
    return false;
}

int main(){
    string str="(((a+b))+c)";
    bool ans=duplicateP(str);
    cout<<ans;
}
