#ifndef Sorted_List_H
#define Sorted_list_H
#include <string>



class Sorted_List {

    public:

Sorted_List();
Sorted_List(const Sorted_List &origList); // deep copy constructor
~Sorted_List(); // destructor
Sorted_List(Sorted_List&& origList); //move constructor
    
    void insert(int const value);
    void remove(int const value);

    Sorted_List& operator=(Sorted_List&& origList); // move operator
    Sorted_List& operator=(const Sorted_List &origList); // deep copy operator
    int size() const;
    bool is_empty() const;
    std::string print() const;

    private:
        struct Node {
        int data;
        Node* next;
        };
        
        int listSize;
        Node* head;
        void traverse(Node *&inNode,int const value);
};

#endif
