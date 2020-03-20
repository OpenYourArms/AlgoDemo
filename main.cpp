#include <iostream>
#include <vector>
#include "Algo/sort.h"

using namespace oyas::sort;

int main() {
//    std::cout << "Hello, World!" << std::endl;

    vector<int> vc;
    typedef decltype(vc) v_t;
    randData(vc,25,0,300);
    print(vc);
    vector<v_t> tb(6,vc);
    BubbleSort(tb[0]);
    SelectionSort(tb[1]);
    InsertionSort(tb[2]);
    MergeSort(tb[3]);
    QuickSort(tb[4]);
    HeapSort(tb[5],greater<int>());
    for(auto& e:tb){
        print(e);
    }

    return 0;
}
