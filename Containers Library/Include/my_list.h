#pragma once

#include <stdexcept>
#include <initializer_list>

template<typename T>
class List{
    private:
        struct Node{
            T data;
            Node* next;
            Node* prev;

            Node(const T& value, Node* p = nullptr, Node* n = nullptr)
                : data(value), prev(p), next(n) {}
        };

        Node* head;
        Node* tail;
        size_t size;

    public:
        List();
        List(std::initializer_list<T> initList);
        ~List();

        void push_back(const T& value);
        void push_front(const T& value);
        void pop_back();
        void pop_front();

        T& front();
        T& back();

        bool is_empty() const;
        size_t get_size() const;

        bool contains(const T& value) const;
        T* find(const T& value);

        class Iterator{
            public:
                Iterator(Node* node) : current(node) {}
                T& operator*() { return current->data; }
                Iterator& operator++() {current = current->next; return *this; }
                Iterator& operator--() {current = current->prev; return *this; }
                bool operator!=(const Iterator& other) const { return current != other.current; }
            private:
                Node* current;
        };

        Iterator begin() {return Iterator(head); }
        Iterator end() {return Iterator(nullptr); }
};

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
List<T>::List(std::initializer_list<T> initList) : head(nullptr), tail(nullptr), size(0) {
    for(const auto& value : initList){
        push_back(value);
    }
}

template <typename T>
List<T>::~List(){
    while(!is_empty()){
        pop_front();
    }
}

template <typename T>
void List<T>::push_back(const T &value){
    Node* newNode = new Node(value, tail, nullptr);
    if(tail){
        tail->next = newNode;
    }else{
        head = newNode;
    }
    tail = newNode;
    size++;
}

template <typename T>
void List<T>::push_front(const T &value){
    Node* newNode = new Node(value, nullptr, head);
    if(head){
        head->prev = newNode;
    }else{
        tail = newNode;
    }
    head = newNode;
    size++;
}

template <typename T>
void List<T>::pop_back(){
    if(is_empty()) throw std::out_of_range("List is empty");
    Node* temp = tail;
    tail = tail->prev;
    if(tail){
        tail->next = nullptr;
    }else{
        head = nullptr;
    }
    delete temp;
    size--;
}

template <typename T>
void List<T>::pop_front(){
    if(is_empty()) throw std::out_of_range("List is empty");
    Node* temp = head;
    head = head->next;
    if(head){
        head->prev = nullptr;
    }else{
        tail = nullptr;
    }
    delete temp;
    size--;
}

template <typename T>
T& List<T>::front(){
    if(is_empty()) throw std::out_of_range("List is empty");
    return head->data;
}

template <typename T>
T& List<T>::back(){
    if(is_empty()) throw std::out_of_range("List is empty");
    return tail->data;
}

template <typename T>
bool List<T>::is_empty() const{
    return size == 0; 
}

template <typename T>
size_t List<T>::get_size() const{
    return size;
}

//Find if value exists (return true or false)
template <typename T>
bool List<T>::contains(const T &value) const{
    Node* current = head;
    while(current){
        if(current->data == value){
            return true;
        }
        current = current->next;
    }
    return false;
}

//return pointer to the value or nullptr
template <typename T>
T* List<T>::find(const T& value){
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}
