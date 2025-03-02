#pragma once

#include <stdexcept>

template <typename T>
class Stack{
    public:
        Stack();
        ~Stack();

        void push(const T& value);
        void pop();

        T& top();
        const T& top() const;

        bool is_empty() const;
        size_t get_size() const;
    private:
        struct Node{
            T data;
            Node* next;
            Node(const T& value, Node* nextNode = nullptr)
                : data(value), next(nextNode) {}
        };

        Node* head;
        size_t size;
};

template <typename T>
Stack<T>::Stack() :head(nullptr), size(0) {}

template <typename T>
Stack<T>::~Stack(){
    while(!is_empty()){
        pop();
    }
}

template <typename T>
void Stack<T>::push(const T &value){
    head = new Node(value, head);
    size++;
}

template <typename T>
void Stack<T>::pop(){
    if(is_empty()){
        throw std::out_of_range("Stack is empty");
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}

template <typename T>
T &Stack<T>::top(){
    if(is_empty()){
        throw std::out_of_range("Stack is empty");
    }

    return head->data;
}

template <typename T>
const T &Stack<T>::top() const{
    if(is_empty()){
        throw std::out_of_range("Stack is empty");
    }

    return head->data;
}

template <typename T>
bool Stack<T>::is_empty() const{
    return size == 0;
}

template <typename T>
size_t Stack<T>::get_size() const{
    return size;
}