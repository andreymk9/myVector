#ifndef VECTOR
#define VECTOR
#include "mVector.h"
#include<iostream>

template<class T>
mVector<T>& mVector<T>::operator= ( const mVector<T>& mv1){
    if(this == &mv1)
        return *this;
    vSize = mv1.size();
    arrSize = mv1.capacity();
    ptr = new T[arrSize];
    for(int i = 0; i < vSize; ++i)
        ptr[i] = mv1[i];
    return *this;
}

template<class T>
mVector<T>& mVector<T>::operator= (mVector<T>&& mv1){
    if(this == &mv1)
        return *this;
    vSize = mv1.size();
    arrSize = mv1.capacity();
    ptr = new T[arrSize];
    for(int i = 0; i < vSize; ++i)
        ptr[i] = mv1[i];
    
    mv1.arrSize = 0;
    mv1.vSize = 0;
    delete [] mv1.ptr;
    mv1.ptr = nullptr;
    return *this;
}

template<class T>
T& mVector<T>::operator[] (const int& address){
    try{
        if(address > arrSize || address < 0 || arrSize == 0){
            throw std::out_of_range("Error:wrong address");
        }
        return ptr[address];
    }
    catch (std::out_of_range ex){
        std::cerr<<ex.what();
    }
}

template<class T>
const T& mVector<T>::operator[] (const int& address) const{
    try{
        if(address > arrSize || address < 0 || arrSize == 0){
            throw std::out_of_range();
        }
        return ptr[address];
    }
    catch (std::out_of_range ex){
        std::cerr<<ex.what();
    }
}

template<class T>
mVector<T>::mVector(mVector&& mv){
    vSize = mv.size();
    arrSize = mv.capacity();
    ptr = new T[arrSize];
    for(int i = 0; i < vSize; ++i){
        ptr[i] = mv[i];
    }
    mv.arrSize = 0;
    mv.vSize = 0;
    delete [] mv.ptr;
    mv.ptr = nullptr;
}

template<class T>
mVector<T>::mVector(const mVector& mv){
    vSize = mv.size();
    arrSize = mv.capacity();
    ptr = new T[arrSize];
    for(int i = 0; i < vSize; ++i){
        ptr[i] = mv[i];
    }
} 
 
template<class T>
mVector<T>::mVector(int val): arrSize(val), vSize(val){
    ptr = new T[vSize];
    for(int i = 0; i < val; ++i){
        ptr[i] = 0;
    }
}

template<class T>
mVector<T>::mVector(int val1, int val2): arrSize(val1), vSize(val1){
    ptr = new T[vSize];
    for(int i = 0; i < val1; ++i){
        ptr[i] = val2;
    }
}

template<class T>
void mVector<T>::insert(iterator it, const T& value){
    int position = it - ptr;
    try{
        if(position > arrSize){
            throw std::out_of_range("Error: out of range");
        }
        if(arrSize == vSize){
            arrSize = 2 * arrSize;    
            T* p = new T[arrSize];
            for(int i = 0; i < arrSize; ++i)
                p[i] = 0;
            for(int i = 0; i <= position; ++i)
                p[i] = ptr[i];
            p[position + 1] = value;
            if(position < vSize){
                for(int i = position + 1, j = position + 2; i < vSize; ++i, ++j)
                    p[j] = ptr[i];
            }
            ++vSize;
            delete [] ptr;
            ptr = p;
        }
        else{
            T* p = new T[arrSize];
            for(int i = 0; i < position; ++i)
                p[i] = ptr[i];
            p[position] = value;
            if(position < vSize){
                for(int i = position, j = position + 1; i < vSize; ++i, ++j)
                    p[j] = ptr[i];
            }
            ++vSize;
            delete [] ptr;
            ptr = p;
        }
    }
    catch (std::out_of_range ex){
        std::cerr<<ex.what();
    }
}
 
template<class T>
void mVector<T>::erase(iterator it){
    try{
        if(it > ptr + vSize - 1){
            throw std::out_of_range("Error: out of range");
        }
        int position = it - ptr;
        --vSize;
        T* p = new T[vSize];
        for(int i = 0; i < position; ++i)
            p[i] = ptr[i];
        for(int i = position; i < vSize; ++i)
            p[i] = ptr[i + 1];
        delete [] ptr;
        ptr = p;
    }
    catch (std::out_of_range ex){
        std::cerr<<ex.what();
    }
}
 
template<class T>
void mVector<T>::clear(){
    vSize = 0;
    delete [] ptr;
}

template<class T>
bool mVector<T>::Empty(){
    if(vSize > 0)
        return 0;
    else return 1;    
}
 
template<class T>
T mVector<T>::at(int position){
    try{
        if(position > arrSize || position < 0 || arrSize == 0){
            throw std::out_of_range("Error: out of range");
        }
        return ptr[position];
    }
    catch (std::out_of_range ex){
        std::cerr<<ex.what();
    }
}

template<class T>
T* mVector<T>::begin(){
    return ptr;
}

template<class T>
T* mVector<T>::end(){
    return ptr + vSize;
}

template<class T>
void mVector<T>::push_back(const T& val){
    if(arrSize == vSize){
        if(arrSize < 1){
           ++arrSize;
           ++vSize; 
        }
        else arrSize = 2 * arrSize;
        T* p = new T[arrSize];
        for(int i = 0; i < arrSize; ++i)
            p[i] = 0;
        if(arrSize != 0){
            for(int i = 0; i < vSize; ++i){
                p[i] = ptr[i];
            }
            delete [] ptr;
        }
        ptr = p;
        ptr[vSize] = val;
        ++vSize;
    }
    else{
        ptr[vSize] = val;
         ++vSize;
    }
}

template<class T>
void mVector<T>::pop_back(){
    ptr[vSize] = 0;
    --vSize;
}
#endif