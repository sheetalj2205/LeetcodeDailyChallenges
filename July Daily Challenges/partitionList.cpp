#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {};
    Node(int x) : data(x), next(nullptr) {};
};
class LinkedList{
    private:
    Node* first;

    public:
    LinkedList(){
        first = NULL;
    };
    LinkedList(int arr[], int n);
    void display();
    void partitionList(int x);
};
LinkedList:: LinkedList(int arr[], int n){
    Node* last, *temp;
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i<n; i++){
         temp = new Node;
         temp->data = arr[i];
         temp->next = NULL;
         last->next = temp;
         last = temp;

    }

}
void LinkedList::display(){
    Node* t = first;
    cout<<"Linked List is"<<endl;
    while(t){
        cout<<t->data<< " ";
        t = t->next;
    }
}

void LinkedList:: partitionList(int x){
    //create two dummy nodes for partition to maintain separate lists
    Node* temp1 = new Node(); 
    Node* temp2 = new Node();
    Node* left = temp1;
    Node* right = temp2;

    while(first){
        int v = first->data;
        //create two separate lists for nodes having value less than x and greater than x
        if(v < x){
           temp1->next = first;
           temp1 = temp1->next;
        }
        else{
            temp2->next = first;
            temp2 = temp2->next;
        }
        first = first->next;

    }
    //in the end right side node list should point to zero
    temp2->next = NULL;
    temp1->next = right->next; //left side list should point to the starting of right list(right->next contains 4 as the first node of right list, right is null node)
    Node* t = left->next; //this will give the complete list
    cout<<"Linked List is"<<endl;
    while(t){
        cout<<t->data<< " ";
        t = t->next;
    }     
}
int main(){
    int arr[] = {1,4,3,2,5,2};
    LinkedList l(arr, 6);
    l.display();
    int x;
    cout<<"Enter x ";
    cin>>x;
    l.partitionList(x);
}
