//
//  main.cpp
//  Data_Structures_Algorithms
//
//  Created by 周传赛 on 2023/2/28.
//

#include <iostream>
#include <vector>
#include <list>
#include <time.h>
#include "MyVector.h"
#include "MyList.h"
#include "Chapter3.h"
using namespace std;


int main(int argc, const char * argv[]) {
    // Vector<int> x(100);
    // cout << x.size() << endl;
//    clock_t start, end;
//    start = clock();
//    removeEveryOtherItem(x);
//    end = clock();
//    cout << "list time: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    list<int> a{11, 5, -3, 2, 1, 43, 542, 5, -2, 9};
    list<int> b{2, 4, 5, 6};
    printLots(a, b);
    return 0;
}
