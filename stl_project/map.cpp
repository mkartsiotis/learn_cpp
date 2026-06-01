#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T1, typename T2> class node
{
  private:
    T1 key;
    T2 element;
    node<T1, T2> *left_child = nullptr;
    node<T1, T2> *right_child = nullptr;

  public:
    node(T1 _key, T2 _element) : key(_key), element(_element)
    {
    }
    T1 getKey() const
    {
        return key;
    }
    T2 getElement() const
    {
        return element;
    }
    node<T1, T2> *&getLeftChild()
    {
        return left_child;
    }
    node<T1, T2> *&getRightChild()
    {
        return right_child;
    }
};
template <typename T1, typename T2> class map
{
  private:
    node<T1, T2> *TopNode = nullptr;

  public:
    map()
    {
    }
    class iterator
    {
      private:
      public:
    };
    void insert(T1 key1, T2 element1);
    void insert_at(node<T1, T2> *new_node, node<T1, T2> *&base_node);
    T2 at(T1 key);
    T2 at_from_basepoint(T1 key, node<T1, T2> *basepoint);
    iterator erase(T1 key);
};

template <typename t1, typename t2> void map<t1, t2>::insert_at(node<t1, t2> *new_node, node<t1, t2> *&base_node)
{
    if (base_node == nullptr)
    {
        base_node = new_node;
        return;
    }
    else if (new_node->getKey() < base_node->getKey())
        insert_at(new_node, base_node->getLeftChild());
    else if (new_node->getKey() > base_node->getKey())
        insert_at(new_node, base_node->getRightChild());
}

template <typename T1, typename T2> void map<T1, T2>::insert(T1 key1, T2 element1)
{
    node<T1, T2> *newNode = new node<T1, T2>(key1, element1);
    insert_at(newNode, TopNode);
}
template <typename T1, typename T2> T2 map<T1, T2>::at_from_basepoint(T1 key, node<T1, T2> *basepoint)
{
    if (basepoint == nullptr)
        std::out_of_range("KEY NOT FOUND");
    if (key < basepoint->getKey())
        return at_from_basepoint(key, basepoint->getLeftChild());
    else if (key > basepoint->getKey())
        return at_from_basepoint(key, basepoint->getRightChild());
    return basepoint->getKey();
}
template <typename T1, typename T2> T2 map<T1, T2>::at(T1 key)
{
    return at_from_basepoint(key, TopNode);
}
int main()
{
    map<int, int> MAP1;
    MAP1.insert(1, 2);
    cout << MAP1.at(1) << endl;
}
