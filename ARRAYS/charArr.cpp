#include <iostream>
#include <cstring>
#include <string>
using namespace std;
//UPPERCASE
// int main(){
//     char str[]="aPplE";
//     int n=strlen(str);
//     for(int i=0;i<n;i++){
//         char ch=str[i];
//         if(ch>='A' && ch<='Z'){
//             continue;
//         }else{
//             str[i]=ch-'a'+'A';  //ch-'a' gives the position of the small letter which will be similar if its capital letter 
//         }
//     }
//     cout<<str;
// }

//LOWERCASE
// int main(){
//     char str[]="AVNEET";
//     int n=strlen(str);

//     for(int i=0;i<n;i++){
//         char ch=str[i];
//         if(ch>='a' && ch<='z'){
//             continue;
//         }else{
//             str[i]=ch-'A'+'a';   //ch-'A' gives the position of the letter 
//         }
//     }
//     cout<<str;
// }

//REVERSE
// int main(){
//     char str[]="AVNEET";
//     int n=strlen(str);
//     int st=0,end=n-1;
//     while(st<end){
//         swap(str[st++],str[end--]);
//     }
//     cout<<str;
// }

//PALINDROME
// int main(){
//     char str[]="maam";
//     int n=strlen(str);
//     int st=0,end=n-1;
//     bool isPalindrome=true;
//     while(st<end){
//         if(str[st++]!=str[end--]){
//             isPalindrome=false;
//             break;
//         }
//     }
//     if(isPalindrome){
//         cout<<"Palindrome";
//     }else{
//         cout<<"Not palindrome";
//     }
    
// }

//ANAGRAM-SIMILAR APPROACH OF COUNTING SORT

bool isAnagram(string str1,string str2){
    if(str1.length()!=str2.length()){return false;}

    int count[26]={0};
    for(int i=0;i<str1.length();i++){
        count[str1[i]-'a']++;
    }
    for(int i=0;i<str2.length();i++){
        if(count[str2[i]-'a']==0){
            return false;
        }
        count[str2[i]-'a']--;
    }

    return true;

}

int main(){
    string str1="cta";
    string str2="dog";
    if(isAnagram(str1,str2)){
        cout<<"Anagram";
    }else{
        cout<<"Not anagram";
    }
}