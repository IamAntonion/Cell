#include "SorterTape.h"

SorterTape::SorterTape(TapeInterface& input, TapeInterface& output) {
    Sort(input, output);
}

void SorterTape::Sort(TapeInterface& input, TapeInterface& output) {
    std::vector<int> dataTmp;

    int size = input.Size();
    dataTmp.reserve(size);

    for (int i = 0; i != size; ++i) {
    //while (1) {
        //if (input.GetValue() == NULL) break;
        int tmp = input.GetValue();
        std::cout << tmp << " ";
        dataTmp.push_back(tmp);
    }


    std::sort(dataTmp.begin(), dataTmp.end());

    for (int i = 0; i != dataTmp.size(); ++i) {
        output.SetValue(dataTmp[i]);
    }
}