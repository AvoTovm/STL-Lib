#pragma once

//Simple Vector implementation (template)

#include <stdexcept>
#include <initializer_list>

template <typename T>
class Vector{
    public:
        Vector();

        Vector(std::initializer_list<T> init);                  //new Constructor
        Vector(const Vector<T>& other);                         //copy Constructor
        Vector(Vector<T>&& other) noexcept;                     //move Constructor
        Vector<T>& operator=(const Vector<T>& other);           //copy Assignment
        Vector<T>& operator=(Vector<T>&& other) noexcept;       //move Assignment

        ~Vector();

        void push_back(const T& value);
        void pop_back();

        T& operator[](size_t index);
        const T& operator[](size_t index) const;

        size_t get_size() const;
        size_t get_capacity() const; 
    
    private:
        T* data;
        size_t capacity;
        size_t size;

        void resize();
};

template <typename T>
Vector<T>::Vector() : data(nullptr), capacity(0), size(0) {}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init)
    : data(new T[init.size()]), capacity(init.size()), size(init.size()) {
    size_t i = 0;
    for(const T& elem : init){
        data[i++] = elem;
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T> &other){
    copy_from(other);
}

template <typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept
    : data(other.data), capacity(other.capacity), size(other.size) {
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other){
    if(this != &other){
        delete[] data;
        copy_from(other);
    }
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&other) noexcept{
    if(this != &other){
        delete[] data;
        data = other.data;
        capacity = other.capacity;
        size = other.size;
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;   
}

template <typename T>
Vector<T>::~Vector(){
    delete[] data;
}

template <typename T>
void Vector<T>::resize(){
    capacity = (capacity == 0) ? 1 : capacity * 2;
    T* newData = new T[capacity];
    for(size_t i = 0; i < size; i++){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

template <typename T>
void Vector<T>::push_back(const T &value){
    if(size == capacity){
        resize();
    }
    data[size++] = value;
}

template <typename T>
void Vector<T>::pop_back(){
    if(size > 0){
        size--;
    }
}

template <typename T>
T &Vector<T>::operator[](size_t index){
    if(index >= size){
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
const T &Vector<T>::operator[](size_t index) const{
    if(index >= size){
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
size_t Vector<T>::get_size() const{
    return size;
}

template <typename T>
size_t Vector<T>::get_capacity() const{
    return capacity;
}
