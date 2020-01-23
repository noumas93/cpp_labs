#include "Sorted_List.h"
#include <iostream>

using namespace std;

Sorted_List::Sorted_List():head{}, listSize{} {}


Sorted_List::Sorted_List(Sorted_List && origList) : head {origList.head} {
origList.head = nullptr;
}

// deep copy constructor
Sorted_List::Sorted_List(const Sorted_List &origList): Sorted_List{}{
    if(origList.head == nullptr)
    return;
    Node* temp = origList.head;
    head = new Node();
    head->data = temp->data;
    head->next = nullptr;
    Node* current = head;
    temp = temp->next;
    while (temp !=nullptr) {
        current->next = new Node();
        current = current->next;
        current->data = temp->data;
        temp = temp->next;
    }
}

//move operator
Sorted_List& Sorted_List::operator=(Sorted_List &&origList) {
    head = origList.head;
    origList.head = nullptr;
    return *this;
    
}

Sorted_List& Sorted_List::operator = (const Sorted_List &origList){
  //TODO Should not use placment new here. The constructor will be called twice here but the deconstructor will only be called once.
  // fixed
   return *this;
}

//destructor
Sorted_List::~Sorted_List() {
    Node* curr{head};
    while (curr!=nullptr){
        Node* temp{curr->next};
        delete curr;
        curr = temp;
    }

    }

int Sorted_List::size() const {
        return listSize;
    }


bool Sorted_List::is_empty() const {
    if (listSize == 0) {
            return true;
    }
    return false;
}

void Sorted_List::traverse(Node *&inNode,int const value) {
        Node* newNode = new Node();
        if (inNode->next != nullptr) {
            if (value > inNode->next->data) {
                delete newNode;
                traverse(inNode->next, value);
            }
            else 
            {
                //newNode = new Node();
                newNode->data = value;
                newNode->next = inNode->next;
                listSize++;
                inNode->next = newNode;
                
            }

        }
         else 
            {
           // newNode = new Node();
            inNode->next = newNode;
            newNode->data = value;
            listSize++;
            }
}

void Sorted_List::insert(int const value) {
        Node *node = new Node();
        node->data = value;
        if (head != nullptr) {
            if (value < head->data) {
            node->next = head;
            head = node;  
            listSize++;
            } 
            else 
                {
                delete node;
                traverse(head,value);
                }
       }

        if (is_empty()) {
           head = node;
            listSize++;
            }

    
    }

void Sorted_List::remove(int const value) {
    if (listSize > 0) {
        listSize--;
    }

    Node* curr{};
    Node* nextptr{};
    curr = head;
        if (curr->data == value) {
        nextptr = curr->next;
        delete curr;
        head = nextptr;
        return;
            
        }
        else 
        {
            while(curr!= nullptr){
            if(curr->data == value){
                nextptr->next = curr->next;
                delete curr;
                return;
            }
            else
            {
                nextptr=curr;
                curr=curr->next;
            }
            }

        }
        
    }

string Sorted_List::print() const {
    string str{};
    Node* current;
    current = head;
while (current != nullptr) {
    str.append(to_string(current->data));
    current = current->next;
}
    return str;
}
