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


#endif /* Chapter3_h */
