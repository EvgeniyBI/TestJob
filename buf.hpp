#include "buf.h"
#include <list>
using namespace std;

template <class Mt>
VectorMt<Mt>::VectorMt()
{

}

template <class Mt>
void  VectorMt<Mt>::push_back(Mt item)
{
mobject.push_back(item);
}

template <class Mt>
Mt  VectorMt<Mt>::operator[](const int &n)
{
    list<Mt>::iterator it = mobject.begin();
    std::advance(it, n);
    Mt  result=*it;
    return result;
}

template <class Mt>
Mt VectorMt<Mt>::operator++()
{
    if(i>=mobject.size()-1) {
        i = 0;
    } else {
        ++i;
    }
    list<Mt>::iterator it = mobject.begin();
    std::advance(it, i);
    Mt  result=*it;
    return result;
}

template <class Mt>
void  VectorMt<Mt>::deleteElement(const int &elem)
{
    mobject.remove(elem);
}

template <class Mt>
int VectorMt<Mt>::get_size() const
{
    return mobject.get_allocator();
}







