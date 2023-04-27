#include "list.h"
#include<iostream>
using namespace std;

template <class T>
List<T>::List(int s, T k) {
    
    size = s;
    data = new T[size];
    for (int i=0; i<size; i++)
        data[i] = k;
}

template <class T>
List<T>& List<T>:: operator=(const List<T>&a) {

    if(this==&a) return *this;
    size=a.size;
    if(data!=0) delete[]data;
    data=new T[size];
    for (int i=0; i<size; i++)
        data[i]=a.data[i];
    return *this;
}
template <class T>
T& List<T>::operator[](int index) {
    if (index<size) return data[index];
    else cout << "\nError! Index>size";
}
template <class T>
int& List<T>::operator()()
{
    return size;
}
template <class T>
ostream& operator<< (ostream& out, const List<T>&a) {

    for (int i=0; i<a.size; ++i)
        out << a.data[i] << " ";
    return out;
}
template <class T>
istream& operator>> (istream& in, List<T>&a) {

    for (int i=0; i<a.data; ++i)
        in >> a.data[i];
    return in;
}