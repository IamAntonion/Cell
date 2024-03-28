#include "SorterTape.h"

SorterTape::SorterTape(TapeInterface& input, TapeInterface& output) {
    Sort(input, output);
}

void SorterTape::Sort(TapeInterface& input, TapeInterface& output) {
    std::vector<int> dataTmp;

    //int size = input.Size();

    std::cout << "Here1\n";

    //dataTmp.reserve(size);

    int tmp = NULL;
    while (tmp = input.GetValue()) {
        std::cout << tmp << "\n";
        dataTmp.push_back(tmp);
    }

    std::cout << "Here2\n";

    // for (int i = 0; i != size; ++i) {
    //     int tmp = input.GetValue();
    //     dataTmp.push_back(tmp);
    // }

    std::sort(dataTmp.begin(), dataTmp.end());

    for (int i = 0; i != dataTmp.size(); ++i) {
        output.SetValue(dataTmp[i]);
    }
}

// void SorterTape::Sort(TapeInterface& input) {
//     std::vector<int> dataTmp;

//     int size = input.Size();
//     dataTmp.reserve(size);

//     for (int i = 0; i != size; ++i) {
//         int tmp = input.GetValue();
//         dataTmp.push_back(tmp);
//     }

//     std::sort(dataTmp.begin(), dataTmp.end());

//     std::ifstream tmp;
//     tmp.open("..\\tmp\\tmp.txt");

//     std::ofstream tmpSort;
//     tmpSort.open("..\\tmp\\tmpSort.txt");

//     int num;
//     while (tmp >> num) {

//     }

    
// }