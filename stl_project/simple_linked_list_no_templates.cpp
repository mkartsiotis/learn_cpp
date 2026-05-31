#include <iostream>
using namespace std;

class Node
{
  private:
    int k;
    Node *next_node;

  public:
    Node(int l, Node *next_node)
    {
        k = l;
        this->next_node = next_node;
    }
    void set_next_node(Node *pointer_to_next_node)
    {
        next_node = pointer_to_next_node;
    }
    int getValue()
    {
        return k;
    }
};
class LIST
{
  private:
    Node *first_node = nullptr;
    Node *last_node = nullptr;

  public:
    LIST()
    {
    }
    void add_item(int value);
    Node *getLastNode()
    {
        return last_node;
    }
};

void LIST::add_item(int value)
{
    Node *ptr = new Node(value, nullptr);
    if (first_node == nullptr)
        first_node = ptr;
    else
        last_node->set_next_node(ptr);
    last_node = ptr;
}
int main()
{
    cout << "List Tets program" << endl;
    LIST mylist;
    mylist.add_item(10);
    cout << mylist.getLastNode()->getValue() << endl;
    mylist.add_item(12);
    cout << mylist.getLastNode()->getValue() << endl;
    mylist.add_item(15);
    cout << mylist.getLastNode()->getValue() << endl;
}
