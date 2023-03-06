#ifndef MYMySet_H
#define MYMySet_H

#include <iostream> // deklaracje strumieni cout, cin, cerr
#include <cassert>  // assert()

template <typename T>
struct Node
{
    // the default access mode and default inheritance mode are public
    T value;
    Node *next;
    Node() : value(T()), next(nullptr) {} // konstruktor domyslny
    Node(const T &item, Node *ptr = nullptr) : value(item), next(ptr) {}
    ~Node() {} // destruktor
};

template <typename T>
class MySet
{
    Node<T> *head, *tail;

public:
    MySet() : head(nullptr), tail(nullptr) {}
    ~MySet();
    MySet(const MySet &other);
    bool empty() const { return head == nullptr; }
    T front() { return head->value; };
    T back() { return tail->value; };
    bool exists(const T &item);
    int insert(const T &item);
    int remove(const T &item);
    MySet<T> my_union(MySet<T> temp_list);
    MySet<T> my_difference(MySet<T> temp_list);
    MySet<T> my_intersection(MySet<T> temp_list);
    void display();
};

template <typename T>
MySet<T>::~MySet()
{
    for (Node<T> *node; !empty();)
    {
        node = head->next; // zapamietujemy
        delete head;
        head = node; // kopiowanie wskaznika
    }
}

template <typename T>
MySet<T>::MySet(const MySet &other)
{
    if (other.head == nullptr)
    {
        head = tail = nullptr;
    }
    else
    {
        head = new Node<T>(other.head->value);

        Node<T> *next = other.head->next;
        Node<T> *temp = head;
        while (next != nullptr)
        {
            temp->next = new Node<T>(next->value);
            temp = temp->next; // move to newly added node
            next = next->next; // move one node further
        }
        tail = temp;
    }
} // copy constructor
// usage:   MySet<int> list2(list1);

template <typename T>
bool MySet<T>::exists(const T &item)
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        if (temp->value == item)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename T>
int MySet<T>::insert(const T &item)
{
    if (empty())
    {
        head = tail = new Node<T>(item);
        return 1;
    }
    else if (!exists(item))
    {
        tail->next = new Node<T>(item);
        tail = tail->next;
        return 1;
    }
    else
    {
        return -1;
    }
}

template <typename T>
int MySet<T>::remove(const T &item)
{
    Node<T> *temp = head;
    Node<T> *prev = head;

    // szukanie elementu
    while (temp != nullptr || temp->value == item)
    {
        prev = temp;
        temp = temp->next;
    }

    // nie znaleziono
    if (temp == nullptr)
    {
        return -1;
    }

    // znaleziono
    if (temp == head)
    {
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    else if (temp == tail)
    {
        delete temp;
        prev->next = nullptr;
        tail = prev;
    }
    else
    {
        prev->next = temp->next;
        temp->next = nullptr;
        delete temp;
    }
    
    return 1;
}

template <typename T>
MySet<T> MySet<T>::my_union(MySet<T> temp_list)
{
    MySet<T> list(*this);

    Node<T> *temp = temp_list.head;
    while (temp != nullptr)
    {
        list.insert(temp->value);
        temp = temp->next;
    }
    return list;
}

template <typename T>
MySet<T> MySet<T>::my_difference(MySet<T> temp_list)
{
    MySet<T> list;

    Node<T> *temp = head;

    while (temp != nullptr)
    {
        if (!temp_list.exists(temp->value))
        {
            list.insert(temp->value);
        }
        temp = temp->next;
    }

    return list;
}

template <typename T>
MySet<T> MySet<T>::my_intersection(MySet<T> temp_list)
{
    MySet<T> list;

    Node<T> *temp = head;

    while (temp != nullptr)
    {
        if (temp_list.exists(temp->value))
        {
            list.insert(temp->value);
        }
        temp = temp->next;
    }

    return list;
}

template <typename T>
void MySet<T>::display()
{
    Node<T> *node = head;
    while (node != nullptr)
    {
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}
#endif