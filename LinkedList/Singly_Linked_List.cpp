// Linked-List:It is a Linear Data Structure 
// It is a collection nodes
// each node conatins data and next node address


//   |----|   |------|-------|   |------|-------|   |----|
//   |Head|-->| Data |Address|-->| Data |Address|-->|Null|
//   |----|   |------|-------|   |------|-------|   |----|


#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //Using constructor assihn data
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};


//Insert At Head of LinedList
void insertathead(Node* &head,int d){//Taking refernce so that there is no copy of it
    //Create new node and insert at head
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}


//Insert At Tail
void insertattail(Node* &tail,int d){
    //Create a new node that needed to be insertyed
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}


//Insert At Specify Position
void insertatposition(Node* &head,Node* &tail,int position,int d){

    //Insert At start
    if(position==1){
        insertathead(head,d);
        return;
    }

    //Point temp to head and increment until it reaches position-1
    Node* temp=head;
    int cnt=1;

    ////Insert At start beacsue tail also should be incremeneted
    if(temp->next==NULL){
        insertattail(tail,d);
    }
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    //create a new node that need to be inserted
    Node* newNodeTobeinserted=new Node(d);

    newNodeTobeinserted->next=temp->next;
    temp->next=newNodeTobeinserted;
    
}

//Traversal Through linkedlist
void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;
    
    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


//Deletion Of Node
void deleteNode(int position, Node* & head,Node* &tail) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        //For tail to point at end
        if(curr->next==NULL){
            prev -> next = curr -> next;
            tail=prev;
            delete curr;
        }
        //When deleted in middle tail to point at end we are using while loop
        else{
            prev -> next = curr -> next;
            curr -> next  = NULL;
            delete curr;
            while(prev->next!=NULL){
                prev=prev->next;
            }
            tail=prev;
        }
    }
}

int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;

    insertathead(head,20);
    insertathead(head,30);

    insertattail(tail,40);
    insertattail(tail,50);

    insertatposition(head,tail,4,60);
    insertatposition(head,tail,1,70);
    insertatposition(head,tail,8,80);
    
    deleteNode(8,head,tail);
    deleteNode(7,head,tail);
    deleteNode(6,head,tail);
    print(head);
    cout<<tail->data<<endl;
    return 0;
}