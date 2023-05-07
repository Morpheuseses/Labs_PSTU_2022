#pragma once 
#include<iostream>
using namespace std;

class Pair
{
private:
    int first = 0;
    double second = 0;
public:
    Pair()
    {
        first = 0;
        second = 0;
    }
    Pair(int f, double s)
    {
        first = f;
        second = s;
    }
    int getFirst()
    {
        return first;
    }
    double getSecond()
    {
        return second;
    }
    void setFirst(int f)
    {
        first = f;
    }
    void setSecond(double s)
    {
        second = s;
    }
    Pair operator= (int n)
    {
        first = n;
        second = n;
        return *this;
    } 
    Pair operator * (Pair& p)
    {
        first = this->first * p.first;
        second = this->second * p.second;
        return *this;
    }
    friend ostream& operator<< (ostream& out, const Pair& p) {
        out << p.first << " : " << p.second << endl;
        return out;
    }
    friend istream& operator>> (istream& in, Pair& p) {
        cout << "first? "; in >> p.first;
        cout << "second? "; in >> p.second;
        return in;
    }
};