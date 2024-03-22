#include "SorterTape.h"

SorterTape::SorterTape(TapeInterface& input, TapeInterface& output) {
    Sort(input, output);
}

void SorterTape::Sort(TapeInterface& input, TapeInterface& output) {
    std::vector<int> dataTmp;
    dataTmp.reserve(input.Size());

    for (int i = 0; i != input.Size(); ++i) {
        dataTmp.push_back(input.GetValue());
    }

    std::sort(dataTmp.begin(), dataTmp.end());

    for (int i = 0; i != dataTmp.size(); ++i) {
        output.SetValue(dataTmp[i]);
    }
}