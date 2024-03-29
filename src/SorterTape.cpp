#include "SorterTape.h"

SorterTape::SorterTape(TapeInterface& input, TapeInterface& output) {
    Sort(input, output);
}

void SorterTape::Sort(TapeInterface& input, TapeInterface& output) {
    std::vector<int> dataTmp;

    input.Rewind();

    for (int i = 0; i!= input.SizeAllData(); ++i) {
        int tmp = input.GetValue();
        dataTmp.push_back(tmp);
    }


    std::sort(dataTmp.begin(), dataTmp.end());

    for (int i = 0; i != dataTmp.size(); ++i) {
        output.SetValue(dataTmp[i]);
    }

    output.CloseAdditionalFile();
}