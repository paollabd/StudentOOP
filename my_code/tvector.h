#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

template <typename T>
class MyVec {
    public:


        class Iterator { 
            friend bool operator!=(Iterator& rhs, Iterator& lhs) {
                return rhs.ptr != lhs.ptr;
            }

         public:
            Iterator(T* p) : ptr(p) {}

            Iterator& operator++() {
            	ptr++;
                return *this;
            }

            T operator*() { return *ptr; }

         private:
            T* ptr;
        };




        // Default Constructor:
        MyVec() {
            sz = 0;
            capacity = DEF_CAPACITY;
            data = new T[DEF_CAPACITY];
        }


        // New Constructor:
        MyVec(int sz, T val) : sz{sz} {
            capacity = sz*2;
            data = new T[capacity];
            for (int i = 0; i < sz; i++)
            {
                data[i] = val;
            }
        }


        // Copy Control:
        MyVec(const MyVec<T>& v2) {
            capacity = v2.capacity;
            sz = v2.size();
            data = new T[capacity];
            for (int i = 0; i < size(); i++)
            {
                data[i] = v2.data[i];
            }
        }

        ~MyVec() {
            if (data != nullptr) delete[] data;
        }

        MyVec<T>& operator=(const MyVec<T>& v2) {
            if (&v2 != this)
            { 
                delete[] data;
                capacity = v2.capacity;
                sz = v2.size();
                data = new T[capacity];
                for (int i = 0; i < size(); i++)
                {
                    data[i] = v2.data[i];
                }
            }
            return *this;
        }


        void push_back(T val) {
            if (sz == capacity)
            {
                capacity *= 2;
                T* new_data = new T[capacity];
                for (int i = 0; i < size(); i++)
                {
                    new_data[i] = data[i];
                }
                delete[] data;
                data = new_data;
            }
            data[sz++] = val;
        }


        int size() const { return sz; }


        T operator[](int i) const {
            return data[i];
        }


        T& operator[](int i) {
            return data[i];
        }


        Iterator begin() const {
            return Iterator(data);
        }


        Iterator end() const {
            return Iterator(data + size());
        }

    private:
        T* data;
        int sz;
        int capacity;
        void copy_fields(const MyVec<T>& v2);
};


template <typename T>
void print_vector(const MyVec<T>& v) {
    for (T i : v) std::cout << i << " ";
    std::cout << std::endl;
}


template <typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
    if (v1.size() != v2.size())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[i])
            {
                return false;
            }
        }
    }
    return true;
}

#endif