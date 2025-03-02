#pragma once

#include <stdexcept>

template <typename T>
class Queue{
    public:
        Queue();
        ~Queue();

        void enqueue(const T& value);
        void dequeue();

        T& front();
        const T& front() const;

        bool is_empty() const;
        size_t get_size() const;

    private:
        struct Node{
            T data;
            Node* next;
            Node(const T& value) : data(value), next(nullptr){};
        };

        Node* head;
        Node* tail;
        size_t size;
};

template <typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
Queue<T>::~Queue(){
    while(!is_empty()){
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(const T &value){
    Node* newNode = new Node(value);
    if(tail){
        tail->next = newNode;
    }else{
        head = newNode;
    }
    tail = newNode;
    size++;
}

template <typename T>
void Queue<T>::dequeue(){
    if(is_empty()){
        throw std::out_of_range("Queue is empty");
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
    if(size == 0){
        tail = nullptr;
    }
}

template <typename T>
T& Queue<T>::front(){
    if(is_empty()){
        throw std::out_of_range("Queue is empty");
    }

    return head->data;
}

template <typename T>
const T& Queue<T>::front() const{
    if(is_empty()){
        throw std::out_of_range("Queue is empty");
    }

    return head->data;
}

template <typename T>
bool Queue<T>::is_empty() const{
    return size == 0;
}

template <typename T>
size_t Queue<T>::get_size() const{
    return size;
}
