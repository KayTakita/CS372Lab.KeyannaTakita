//
//  List.hpp
//  Lazy Deletion
//
//  Created by Keyanna Takita 
//


//----- Module03PartB -----
    // template <namename T>
    // class List {
    // private:
        // class Node {
        // public:
            // T data;
            // Node* prev;
            // Node* next;
// };
// Using the same template, adding DF

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
        bool deleted = false;
    };

    Node* head = nullptr;
    Node* tail = nullptr;

    int Count = 0;
    int deletedCount = 0;

    void cleanupDeleted()
    {
        Node* current = head;

        while (current != nullptr)
        {
            Node* nextNode = current->next;

            if (current->deleted) {
                if (current->prev != nullptr)
                {
                    current->prev->next = current->next;
                }
                else
                    {
                    head = current->next;
                    }

                if (current->next != nullptr)
                {
                    current->next->prev = current->prev;
                }
                else
                    {
                    tail = current->prev;
                    }

                delete current;
            }

            current = nextNode;
        }

        deletedCount = 0;
    }

    void clearList()
        {
        Node* current = head;

        while (current != nullptr)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        tail = nullptr;
        Count = 0;
        deletedCount = 0;
    }

public:
    List() {}

    List(T newData)
    {
        push_back(newData);
    }

    ~List()
    {
        clearList();
    }

    bool empty()
    {
        return Count == 0;
    }

    void push_front(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;

        if (head == nullptr)
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

        Count++;
    }

    void push_back(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;

        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        Count++;
    }

    T front()
    {
        Node* current = head;

        while (current != nullptr && current->deleted)
        {
            current = current->next;
        }

        return current->data;
    }

    T back()
    {
        Node* current = tail;

        while (current != nullptr && current->deleted)
        {
            current = current->prev;
        }

        return current->data;
    }

    void pop_front()
    {
        Node* current = head;

        while (current != nullptr && current->deleted)
        {
            current = current->next;
        }

        if (current != nullptr)
        {
            current->deleted = true;
            deletedCount++;
            Count--;

            if (deletedCount == Count)
            {
                cleanupDeleted();
            }
        }
    }

    void pop_back()
    {
        Node* current = tail;

        while (current != nullptr && current->deleted)
        {
            current = current->prev;
        }

        if (current != nullptr)
        {
            current->deleted = true;
            deletedCount++;
            Count--;

            if (deletedCount == Count)
            {
                cleanupDeleted();
            }
        }
    }

    void remove(T data)
    {
        Node* current = head;
        bool found = false;

        while (current != nullptr && !found)
        {
            if (!current->deleted && current->data == data)
            {
                current->deleted = true;
                deletedCount++;
                Count--;
                found = true;
            }

            current = current->next;
        }

        if (deletedCount == Count)
        {
            cleanupDeleted();
        }
    }

    void traverse(void (*doIt)(T data))
    {
        Node* current = head;

        while (current != nullptr)
        {
            if (!current->deleted)
            {
                doIt(current->data);
            }

            current = current->next;
        }
    }

    int size()
    {
        return Count;
    }
};

