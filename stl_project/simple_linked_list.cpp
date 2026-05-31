#include <iostream>
using namespace std;

template <typename T> class Node
{
  private:
    T k;
    Node *next_node;

  public:
    Node(T l, Node *next_node)
    {
        k = l;
        this->next_node = next_node;
    }
    void set_next_node(Node *pointer_to_next_node)
    {
        next_node = pointer_to_next_node;
    }
    Node<T> *get_next_node() const
    {
        return next_node;
    }
    T &getValue()
    {
        return k;
    }
};
template <typename T> class LIST
{
  private:
    Node<T> *first_node = nullptr;
    Node<T> *last_node = nullptr;
    unsigned int number_of_elements = 0;

  public:
    class Iterator
    {
      private:
        Node<T> *current;

      public:
        Iterator() : current(nullptr)
        {
        }
        Iterator(Node<T> *it)
        {
            current = it;
        }
        Node<T> *get_current()
        {
            return current;
        }
        T &operator*()
        {
            return current->getValue();
        }
        Iterator &operator++()
        {
            current = current->get_next_node();
            return *this;
        }
        bool operator!=(Iterator b)
        {
            return (this->get_current() != b.get_current());
        }
    };
    LIST()
    {
    }
    void push_back(T value);
    void push_front(T value);
    void pop_front();
    void pop_back();
    void clear();
    T front()
    {
        if (!this->empty())
            return first_node->getValue();
        else
            throw std::runtime_error("LIST::front() called on an empty list!");
    }
    T back()
    {
        if (!this->empty())
            return last_node->getValue();
        else
            throw std::runtime_error("LIST::front() called on an empty list!");
    }
    bool empty()
    {
        return (number_of_elements == 0);
    }
    unsigned int size()
    {
        return number_of_elements;
    }
    Iterator begin()
    {
        Iterator return_iterator(this->first_node);
        return return_iterator;
    }
    Iterator end()
    {
        return Iterator(nullptr);
    }
    ~LIST()
    {
        this->clear();
    }
};
template <typename T> void LIST<T>::push_back(T value)
{
    Node<T> *ptr = new Node<T>(value, nullptr);
    if (first_node == nullptr)
        first_node = ptr;
    else
        last_node->set_next_node(ptr);
    last_node = ptr;
    number_of_elements++;
}
template <typename T> void LIST<T>::push_front(T value)
{
    Node<T> *ptr = new Node<T>(value, nullptr);
    if (this->empty())
        last_node = ptr;
    else
        ptr->set_next_node(first_node);
    first_node = ptr;
    number_of_elements++;
}
template <typename T> void LIST<T>::pop_front()
{
    if (this->empty())
        return;
    if (this->size() == 1)
        last_node = nullptr;
    Node<T> *second_node = first_node->get_next_node();
    delete first_node;
    first_node = second_node;
    number_of_elements--;
}
template <typename T> void LIST<T>::pop_back()
{
    if (this->empty())
        return;
    else if (this->size() == 1)
    {
        delete last_node;
        last_node = nullptr;
        first_node = nullptr;
        number_of_elements = 0;
        return;
    }
    Node<T> *second_to_last_node = first_node;
    for (int i = 0; i < ((int)this->size() - 2); i++)
    {
        second_to_last_node = second_to_last_node->get_next_node();
    }
    delete last_node;
    last_node = second_to_last_node;
    last_node->set_next_node(nullptr);
    number_of_elements--;
}
template <typename T> void LIST<T>::clear()
{
    while (!this->empty())
    {
        this->pop_front();
    }
}
int main()
{
    cout << "Singly Linked List Test" << endl;
    LIST<std::string> mylist;
    mylist.push_back("HELLO");
    mylist.push_back("WORLD");
    mylist.push_back("OF");
    mylist.push_back("TEMPLATES");
    for (auto &str : mylist)
    {
        cout << str << " ";
    }
    cout << endl;

    cout << "Size before clear: " << mylist.size() << endl;
    mylist.clear();
    cout << "Size after clear: " << mylist.size() << endl;
}
