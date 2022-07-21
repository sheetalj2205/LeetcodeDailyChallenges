#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
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
    void reverseList(int left, int right);
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

void LinkedList:: reverseList(int left, int right){
        Node *tmp = first,*age;
        int count = 1;
        while(tmp && count<left)
        {
            age = tmp;
            tmp = tmp->next;
            count++;
        }
        Node *prev=NULL,*later=NULL,*curr=tmp;
        //doubt
        while(curr && count<=right)
        {
            later = curr->next;
            curr->next = prev;
            prev = curr;
            curr = later;
            count++;
        }
        if(left==1)
        {
            first = prev;
        }
        else
        {
            age->next = prev;
        }
        tmp->next = curr;
}
int main(){
    int arr[] = {1,2,3,4,5};
    LinkedList l(arr, 5);
    l.display();
    int left, right;
    cout<<"Enter left and right ";
    cin>>left>>right;
    l.reverseList(left, right);
    l.display();
}
