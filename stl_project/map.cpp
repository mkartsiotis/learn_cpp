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
    void setKey(T1 key)
    {
        this->key = key;
    }
    void setElement(T2 element)
    {
        this->element = element;
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
    int number_of_nodes = 0;
    void insert_at(node<T1, T2> *new_node, node<T1, T2> *&base_node);
    node<T1, T2> *&get_from_basepoint(T1 key, node<T1, T2> *&basepoint);

  public:
    map()
    {
    }
    class iterator
    {
      private:
        node<T1, T2> *current_node = nullptr;
        node<T1, T2> *TopNodeOfHeap = nullptr;

      public:
        iterator(node<T1, T2> *node1, node<T1, T2> *top) : current_node(node1), TopNodeOfHeap(top)
        {
        }
        std::pair<const T1, T2> operator*() const
        {
            return std::make_pair(current_node->getKey(), current_node->getElement());
        }
        iterator &operator++()
        {
            if (current_node->getRightChild() != nullptr)
            {
                if (current_node == nullptr)
                    return *this;
                else
                {
                    current_node = current_node->getRightChild();
                    while (current_node->getLeftChild() != nullptr)
                        current_node = current_node->getLeftChild();
                    return *this;
                }
            }
            else
            {
                // Find the father
                node<T1, T2> *ancestor = TopNodeOfHeap;
                node<T1, T2> *nearest_ancestor_to_our_right = nullptr;
                while (ancestor->getKey() != current_node->getKey())
                {
                    if (ancestor->getKey() > current_node->getKey())
                    {
                        nearest_ancestor_to_our_right = ancestor;
                        ancestor = ancestor->getLeftChild();
                    }
                    else
                        ancestor = ancestor->getRightChild();
                }
                current_node = nearest_ancestor_to_our_right;
                return *this;
            }
        }
        bool operator==(const iterator &other) const
        {
            return this->current_node == other.current_node;
        }
        bool operator!=(const iterator &other) const
        {
            return this->current_node != other.current_node;
        }
    };
    void insert(T1 key1, T2 element1);
    T2 at(T1 key);
    int size() const
    {
        return number_of_nodes;
    }
    iterator begin()
    {
        if (TopNode == nullptr)
            return iterator(nullptr, nullptr);
        node<T1, T2> *smallest = TopNode;
        while (smallest->getLeftChild() != nullptr)
            smallest = smallest->getLeftChild();
        return iterator(smallest, TopNode);
    }
    iterator end()
    {
        return iterator(nullptr, TopNode);
    }
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
    number_of_nodes++;
}
template <typename T1, typename T2> node<T1, T2> *&map<T1, T2>::get_from_basepoint(T1 key, node<T1, T2> *&basepoint)
{
    if (basepoint == nullptr)
        throw std::out_of_range("KEY NOT FOUND");
    if (key < basepoint->getKey())
        return get_from_basepoint(key, basepoint->getLeftChild());
    else if (key > basepoint->getKey())
        return get_from_basepoint(key, basepoint->getRightChild());
    return basepoint;
}
template <typename T1, typename T2> T2 map<T1, T2>::at(T1 key)
{
    return get_from_basepoint(key, TopNode)->getElement();
}
template <typename T1, typename T2> typename map<T1, T2>::iterator map<T1, T2>::erase(T1 key)
{
    node<T1, T2> *N = get_from_basepoint(key, TopNode);
    iterator myiterator(N, TopNode);
    ++myiterator;
    if (N->getLeftChild() == nullptr && N->getRightChild() == nullptr)
    {
        delete N;
        N = nullptr;
    }
    else if (N->getLeftChild() == nullptr && N->getRightChild() != nullptr)
    {
        node<T1, T2> *newN = N->getRightChild();
        delete N;
        N = newN;
    }
    else if (N->getRightChild() == nullptr && N->getLeftChild() != nullptr)
    {
        node<T1, T2> *newN = N->getLeftChild();
        delete N;
        N = newN;
    }
    else
    {
        node<T1, T2> *searchnode = N->getRightChild();
        while (searchnode->getLeftChild() != nullptr)
            searchnode = searchnode->getLeftChild();
        T1 tempKey = searchnode->getKey();
        T2 tempElement = searchnode->getElement();
        erase(searchnode->getKey());
        N->setKey(tempKey);
        N->setElement(tempElement);
    }
    number_of_nodes--;
    return myiterator;
}

// Note that due to the lack of time tets were vibe coded...I am not proud for this but ok...
int main()
{
    try
    {
        map<int, string> student_map; // Χρησιμοποιούμε int και string για να είναι πιο "ανθρώπινο"

        cout << "--- ΣΤΑΔΙΟ 1: Εισαγωγή Στοιχείων ---" << endl;
        student_map.insert(50, "Giannis (Root)");
        student_map.insert(30, "Maria (Leaf)");
        student_map.insert(70, "Kosta (Two Children)");
        student_map.insert(60, "Eleni (One Child)");
        student_map.insert(65, "Petros (Leaf)");

        cout << "Το μέγεθος του map είναι: " << student_map.size() << " (Αναμένεται: 5)" << endl;
        cout << "Αναζήτηση με το .at(60): " << student_map.at(60) << endl;
        cout << endl;

        cout << "--- ΣΤΑΔΙΟ 2: Έλεγχος Iterator (In-Order Διάσχιση) ---" << endl;
        cout << "Τα στοιχεία ταξινομημένα:" << endl;
        for (map<int, string>::iterator it = student_map.begin(); it != student_map.end(); ++it)
        {
            // Χρησιμοποιούμε το ζεύγος που επιστρέφει ο operator*
            pair<const int, string> p = *it;
            cout << "  Κλειδί: " << p.first << " -> Τιμή: " << p.second << endl;
        }
        cout << endl;

        cout << "--- ΣΤΑΔΙΟ 3: Δοκιμή Erase - Case 1 (Διαγραφή Φύλλου: 30) ---" << endl;
        // Η erase επιστρέφει iterator στο επόμενο στοιχείο (το επόμενο του 30 είναι το 50)
        map<int, string>::iterator next_it = student_map.erase(30);
        cout << "Το επόμενο στοιχείο μετά το 30 που διαγράφηκε είναι το: " << (*next_it).first << " (Αναμένεται: 50)"
             << endl;
        cout << "Μέγεθος μετά τη διαγραφή: " << student_map.size() << " (Αναμένεται: 4)" << endl;
        cout << endl;

        cout << "--- ΣΤΑΔΙΟ 4: Δοκιμή Erase - Case 2 (Διαγραφή Κόμβου με 1 παιδί: 60) ---" << endl;
        // Το 60 έχει μόνο το 65. Ο πατέρας (το 70) πρέπει να συνδεθεί απευθείας με το 65.
        student_map.erase(60);
        cout << "Έλεγχος αν το παιδί (65) επιβίωσε: " << student_map.at(65) << endl;
        cout << endl;

        cout << "--- ΣΤΑΔΙΟ 5: Δοκιμή Erase - Case 3 (Διαγραφή Κόμβου με 2 παιδιά: 70) ---" << endl;
        // Το 70 έχει παιδιά. Θα γίνει ανταλλαγή με τον διάδοχό του.
        student_map.erase(70);

        cout << "--- ΤΕΛΙΚΟ ΤΕΣΤ: Εκτύπωση όσων απέμειναν στο map ---" << endl;
        for (map<int, string>::iterator it = student_map.begin(); it != student_map.end(); ++it)
        {
            cout << "  Κλειδί: " << (*it).first << " -> " << (*it).second << endl;
        }
    }
    catch (const exception &e)
    {
        cout << "Ωχ! Κάτι πήγε λάθος: " << e.what() << endl;
    }

    return 0;
}
/*
int main()
{
   map<int, int> MAP1;
   MAP1.insert(1, 2);
   cout << MAP1.at(1) << endl;
}
*/
