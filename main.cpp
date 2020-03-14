#include <iostream>
#include <vector>
#include "Algo/sort.h"

using namespace oyas::sort;

int main() {
//    std::cout << "Hello, World!" << std::endl;

    vector<int> vc;
    typedef decltype(vc) v_t;
    randData(vc,15,0,300);
    print(vc);
    vector<v_t> tb(5,vc);
    BubbleSort(tb[0]);
    SelectionSort(tb[1]);
    InsertionSort(tb[2]);
    MergeSort(tb[3]);
    QuickSort(tb[4]);
    for(auto& e:tb){
        print(e);
    }
    return 0;
}
