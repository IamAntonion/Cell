#include "SorterTape.h"

SorterTape::SorterTape(TapeInterface& input, TapeInterface& output) {
    Sort(input, output);
}

void SorterTape::Sort(TapeInterface& input, TapeInterface& output) {
    std::vector<int> dataTmp;

    int size = input.Size();
    dataTmp.reserve(size);
    //std::cout << "Size " << input.Size() - 1 << " value:\n";

    for (int i = 0; i != size; ++i) {
        int tmp = input.GetValue();
        dataTmp.push_back(tmp);
        //std::cout << "Sort " << dataTmp.back() << "\n";
    }

    //std::cout << "Size dataTmp " << dataTmp.size() << " value:\n";

    std::sort(dataTmp.begin(), dataTmp.end());

    for (int i = 0; i != dataTmp.size(); ++i) {
        //std::cout << "Sort vector " << dataTmp[i] << "\n";
        output.SetValue(dataTmp[i]);
    }
}