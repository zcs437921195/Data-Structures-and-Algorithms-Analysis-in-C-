//
//  Chapter3.h
//  Data_Structures_Algorithms
//
//  Created by 周传赛 on 2023/3/25.
//

#ifndef Chapter3_h
#define Chapter3_h

#include <list>
using namespace std;

template<typename Object>
void printLots(list<Object> L, list<int> P){
    int Counter = 0;
    typename list<Object>::const_iterator iter_L;
    typename list<int>::const_iterator iter_P;
    iter_P = P.cbegin();
    iter_L = L.cbegin();
    for (iter_P = P.cbegin(); iter_P != P.cend() && iter_L != L.cend(); iter_P++) {
        while (Counter < *iter_P and iter_L != L.cend()) {
            Counter++;
            iter_L++;
        }
        if (iter_L != L.cend())
            cout << *iter_L << endl;
    }
}

template<typename Iterator, typename Object>
Iterator find(Iterator start, Iterator end, const Object & x){
    Iterator cur = start;
    while (cur != end && *cur != x)
        cur++;
    return cur;
}

<<<<<<< HEAD
=======
template<typename Object>
list<Object> GetInterList(const list<Object> & l1, const list<Object> & l2){
    list<Object> res;
    typename list<Object>::const_iterator ite1;
    typename list<Object>::const_iterator ite2;
    ite1 = l1.cbegin();
    ite2 = l2.cbegin();
    while (ite1 != l1.cend() && ite2 != l2.cend()) {
        if (*ite1 > *ite2)
            ite2++;
        else if (*ite1 < *ite2)
            ite1++;
        else{
            res.push_back(Object{*ite1});
            ite1++;
            ite2++;
        }
    }
    return res;
}


template<typename Object>
list<Object> GetUnionList(const list<Object> & l1, const list<Object> & l2){
    list<Object> res;
    typename list<Object>::const_iterator ite1;
    typename list<Object>::const_iterator ite2;
    ite1 = l1.cbegin();
    ite2 = l2.cbegin();
    while (ite1 != l1.cend() && ite2 != l2.cend()) {
        if (*ite1 > *ite2){
            res.push_back(Object{*ite2});
            ite2++;
        }
        else if (*ite1 < *ite2){
            res.push_back(Object{*ite1});
            ite1++;
        }
        else{
            res.push_back(Object{*ite1});
            ite1++;
            ite2++;
        }
    }
    while (ite1 != l1.cend()) {
        res.push_back(Object{*ite1});
        ite1++;
    }
    while (ite2 != l2.cend()) {
        res.push_back(Object{*ite2});
        ite2++;
    }
    return res;
}

>>>>>>> write_code

#endif /* Chapter3_h */
