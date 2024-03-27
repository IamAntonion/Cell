#include "SorterTape.h"

SorterTape::SorterTape(TapeInterface& input, TapeInterface& output) {
    Sort(input, output);
}

void SorterTape::Sort(TapeInterface& input, TapeInterface& output) {
    std::vector<int> dataTmp;

    int size = input.Size();
    dataTmp.reserve(size);

    for (int i = 0; i != size; ++i) {
        int tmp = input.GetValue();
        dataTmp.push_back(tmp);
    }


    std::sort(dataTmp.begin(), dataTmp.end());

    for (int i = 0; i != dataTmp.size(); ++i) {
        output.SetValue(dataTmp[i]);
    }
}