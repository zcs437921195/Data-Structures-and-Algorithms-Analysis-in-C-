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
using namespace std;


int main(int argc, const char * argv[]) {
    Vector<int> x(100);
    cout << x.size() << endl;
    List<int> a;
    List<int> b{a};
//    clock_t start, end;
//    start = clock();
//    removeEveryOtherItem(x);
//    end = clock();
//    cout << "list time: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    cout << 1 << endl;
    return 0;
}
