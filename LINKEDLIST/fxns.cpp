#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int vaL){
        data=vaL;
        next=NULL;
    }
    //~Node called when a node is deleted
    ~Node() {  //propagates the deletion ()
        // cout << "--Node " << data << endl;

        if (next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

class LList{
    Node* head;
    Node* tail;
public:
    LList(){
        head=NULL;
        tail=NULL;
    }

    //A destructor is automatically called when an object is about to be destroyed.
    //So ~List() is called when ll goes out of scope.(on return 0 from main)

    ~LList() {   //starts the deletion (deletes the head)
    // cout << "destructor of List";

    if (head != NULL) {
        delete head;
        head = NULL;
    }
}

    void push_front(int vaL){
        Node* newNode=new Node(vaL); //dynamic
        // Node newNode(vaL); //static-The problem is that newNode exists only until the function ends.

        if (head==NULL){
            head=tail=newNode;
        }else{
            newNode->next = head;
            head=newNode;
        }   
    }
    void push_back(int val) {

        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    };
    void pop_front() {

        if (head == NULL) {
            return;
        }

        Node* temp = head;

        head = head->next;

        delete temp;

        if (head == NULL) {
            tail = NULL;
        }
    }

    void pop_back() {

    if (head == NULL) {
        return;
    }

    // Only one node
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    Node* current = head;

    while (current->next != tail) {
        current = current->next;
    }

    Node* temp = tail;

    tail = current;
    tail->next = NULL;

    delete temp;
}

    void print(){
        Node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        
    }

    void insert(int val,int pos){
        Node* newNode=new Node(val);
        Node* temp=head;

        for(int i=0;i<pos-1;i++){
            if (temp==NULL)
            {
                cout<<"INVALID POSITION\n";
                return;
            }
            temp=temp->next;
        }//after the loop,temp will be at pos-1

        newNode->next=temp->next;  //right connection from pos
        temp->next=newNode; //left connection from pos
    }

    int itrSearch(int key){
        Node* temp=head;
        int idx=0;
        while (temp!=NULL){
            if(temp->data==key){
                return idx;
            }
            temp=temp->next;
            idx++;
        }
        return -1;
    }

    int helper(Node* h,int key){
        if(h==NULL){
            return -1;
        }

        if(h->data==key){
            return 0;
        }
        int idx=helper(h->next,key);
        if(idx==-1){
            return -1;
        }
        return idx+1;
    }
    void recSearch(int key){
        cout<<helper(head,key)<<endl;
    }

    void reverse(){
        Node* curr=head;
        Node* prev=NULL;

        while(curr!=NULL){
            Node* next=curr->next;
            curr->next=prev;

            //updations
            prev=curr;
            curr=next;
        }
        //at end of loop-prev=head
        head=prev;
    }
};

int main(){
    LList l;

    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_back(5);
    l.print();
    l.reverse();
    // l.recSearch(3);
    // l.insert(4,3);
    l.print();
    // cout<<l.itrSearch(5)<<endl;
    return 0;
    //Technically, local objects are destroyed when their scope ends; return 0 causes the end of main and then ll is destroyed.(call of destructor)
}