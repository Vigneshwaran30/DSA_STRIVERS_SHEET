#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    //Constructor
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    //Destructor
    ~Node() {
        int val = this -> data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

void print(Node* &head){
    Node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertathead(Node* &tail,Node* &head,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        tail=temp;        
    }
    else{
    
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}

void insertattail(Node* &tail,Node* &head,int data){

    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        tail=temp;        
    }
    else{
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
    }
}

int getlength(Node* &head){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

void insertatposition(Node* &tail,Node* &head,int position,int d){

    if(position==1){
        insertathead(tail,head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;

    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertattail(tail,head,d);
        return;
    }

    Node* newNodeTobeinserted=new Node(d);

    newNodeTobeinserted->next=temp->next;
    temp->next->prev=newNodeTobeinserted;
    temp->next=newNodeTobeinserted;
    newNodeTobeinserted->prev=temp;    
}

void deletion(Node* &tail,Node* &head,int position){

    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* before = NULL;

        int cnt = 1;
        while(cnt < position) {
            before = curr;
            curr = curr -> next;
            cnt++;
        }

        if(curr->next==NULL){   
            curr -> prev = NULL;
            before -> next = curr -> next;
            curr -> next = NULL;
            tail=before;
            delete curr;
        }

        else{
            curr -> prev = NULL;
            before -> next = curr -> next;
            curr->next->prev=before;
            curr -> next = NULL;
            delete curr;
            
            while(before->next!=NULL){
                before=before->next;
            }
            tail=before;
        }

    }
}

int main(){
    Node* node1=new Node(30);
    Node* head=node1;
    Node* tail=node1;
    insertathead(tail,head,20);
    insertathead(tail,head,10);
    insertattail(tail,head,40);
    insertatposition(tail,head,3,25);
    insertatposition(tail,head,6,50);
    deletion(tail,head,6);
    deletion(tail,head,3);
    print(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    
    int len=getlength(head);
    cout<<endl<<len<<endl;
    return 0;
}