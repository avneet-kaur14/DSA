#include <iostream>
#include <vector>
#include <stack>  // stack<int> s; STL
using namespace std;

//STACK IMPLEMENTATION USING VECTOR

// template <class T>
// class Stack{
//     public:
//     vector<T> vec;

//     void push(T val){
//         vec.push_back(val);
//     }

//     void pop(){
//         if(isempty()){
//             cout<<"Stack is empty"<<endl;
//             return;
//         }
//         vec.pop_back();
//     }
//     T top(){
//         if(isempty()){
//             cout<<"Stack is empty"<<endl;
//             return -1;
//         }
//         int lastIdx=vec.size()-1;
//         return vec[lastIdx];
//     }

//     bool isempty(){
//         return vec.size()==0;
//     }
// };

//STACK IMPLEMENTATION USING LINKED LIST

template <class T>
class Node{
public:
    T data;
    Node* next;

    Node(T val){
        data=val;
        next=nullptr;
    }
};

template <class T>
class Stack{
public:
    Node<T>* head;

    Stack(){
        head=nullptr;
    }

    void push(T val){
        Node<T>* newNode=new Node<T>(val);

        if(head==nullptr){
            head=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }

    void pop(){
        if(head==nullptr){
            cout<<"Stack underflow"<<endl;
            return;
        }
        Node<T>* temp=head;
        head=head->next;
        temp->next=nullptr;
        delete temp;
    }

    Node<T>* top(){
        return head;
    }

    bool isempty(){
       return head==nullptr;
    }

};

int main(){
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isempty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
    return 0;
}

