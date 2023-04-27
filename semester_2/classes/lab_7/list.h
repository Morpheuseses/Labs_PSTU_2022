#include<iostream>
using namespace std;

template <class T>
class List
{
private:
    int size;
    T* data;
public:
    List(int s,T k);
    List(const List<T>&a);
    ~List();
    List& operator=(const List<T>&a);
    T& operator[](int index);
    int& operator()();
    template <class T2>
    friend ostream& operator<< (ostream& out, const List<T2>&a);
    template <class T2>
    friend istream& operator>> (istream& in , List<T2>&a);
};