#pragma once
#include <QDebug>

template <class Mt>
class VectorMt
{
public:
    typedef typename std::list<Mt>::iterator iterator;

     VectorMt();

     void push_back(Mt item);
     void deleteElement(const int &elem);

     iterator begin()
     {
         iterator it = mobject.begin();
         return it;
     }

     iterator end()
     {
         iterator it = mobject.end();
         return it;
     }

     Mt operator++();
     Mt operator[](const int &n);
     int get_size() const;

protected:
       size_t i=0;
       std::list<Mt> mobject;
};


#include <buf.hpp>

