#include <iostream>
#include <list>
#include <algorithm>
#include <cassert>
using namespace std;

template<typename T, typename RetT = T>
struct range_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
    range_iterator(T cur, T step)
        : m_current(cur), m_step(step)
    {
    }

    RetT& operator*()
    {
        return m_current;
    }

    range_iterator& operator++()
    {

        m_current = m_current + m_step;
        return *this;
    }

    range_iterator operator++(int)
    {
        range_iterator tmp(m_current, m_step);
        ++(*this);
        return tmp;
    }

    bool operator==(const range_iterator& rhs)
    {
        return m_current == rhs.m_current;
    }

    bool operator!=(const range_iterator& rhs)
    {
        return (this->m_current < rhs.m_current); //SOME DIRTY MOVE, SORRY FOR THAT :)
    }

private:
    T m_current;
    T m_step;
};



template<int B, int E, int S=1>
class Range
{
public:
    Range() {}
    typedef range_iterator<int> iterator;
    typedef range_iterator<int, const int> const_iterator;
    iterator begin(){
        return iterator(B, S);
    }

    iterator end(){
        if(E >= (B + S)) return iterator(E , S);

        else return ++begin();
    }

    const_iterator begin() const
    {
        return const_iterator(B, S);
    }

    const_iterator end() const
    {
        return const_iterator(E, S);
    }

    const_iterator cbegin() const
    {
        return const_iterator(B, S);
    }

    const_iterator cend() const
    {
        return const_iterator(E, S);
    }
};

int main(){
    for (auto& elem : Range<1, 5>())
    {
        cout << elem << " "; // 1 2 3 4
    }
    cout << endl;
    for (auto& elem : Range<0, 10, 2>())
    {
        cout << elem << " "; // 2 4 6 8
    }
    cout << endl;
    for (auto& elem : Range<20, 50, 1000>())
    {
        cout << elem << " "; // 20
    }
    cout << endl;

    auto r = Range<1,30>();
    cout << count_if(r.begin(), r.end(), [](int e){return e>20;}) << endl; // 9
    assert(count_if(r.begin(), r.end(), [](int e){return e>20;}) == 9);
    auto r2 =  Range<0, 20, 2>();
    for (auto& elem : r2)
    {
        cout << elem << " ";
    }
    cout << endl;
    assert(count_if(r2.begin(), r2.end(), [](int e){return e%2;}) == 0);
    cout << "PASSED" << endl;
    return 0;
}


