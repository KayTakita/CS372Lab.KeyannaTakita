
//list.hpp

#pragma once
#include <iostream>
using namespace std;

template <typename T>
class List
{
private:
    class Node
    {
    public:
        T data;
        Node* prev = nullptr;
        Node* next = nullptr;
    };

    Node* head = nullptr;
    Node* tail = nullptr;

public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool empty() const
    {
        return head == nullptr;
    }

    void push_front(T value)
    {
        Node* newNode = new Node();
        newNode->data = value;

        if (empty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(T value)
    {
        Node* newNode = new Node();
        newNode->data = value;

        if (empty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    T front() const
    {
        return head->data;
    }

    T back() const
    {
        return tail->data;
    }
    
    void pop_front()
    {
        if (empty())
        {
            return;
        }

        Node* temp = head;

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
    }

    void pop_back()
    {
        if (empty())
        {
            return;
        }

        Node* temp = tail;

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
    }
    
    ~List()
    {
        while (!empty())
        {
            pop_front();
        }
    }
    
    List(const List<T>& other)
    {
        head = nullptr;
        tail = nullptr;

        Node* current = other.head;

        while (current != nullptr)
        {
            push_back(current->data);
            current = current->next;
        }
    }
    
    // ----- Copy Constructor -----
    List<T>& operator=(const List<T>& other)
    {
        if (this != &other)
        {
            while (!empty())
            {
                pop_front();
            }

            Node* current = other.head;

            while (current != nullptr)
            {
                push_back(current->data);
                current = current->next;
            }
        }

        return *this;
    }
    
    // ----- Copy Assignemnt -----
    List(List<T>&& other)
    {
        head = other.head;
        tail = other.tail;

        other.head = nullptr;
        other.tail = nullptr;
    }
    
    // ----- Move Assignment -----
    List<T>& operator=(List<T>&& other)
    {
        if (this != &other)
        {
            while (!empty())
            {
                pop_front();
            }

            head = other.head;
            tail = other.tail;

            other.head = nullptr;
            other.tail = nullptr;
        }

        return *this;
    }
    
    // ----- Add Traverse -----
    void traverse(void (*doIt)(T data)) const
    {
        Node* current = head;

        while (current != nullptr)
        {
            doIt(current->data);
            current = current->next;
        }
    }
};

