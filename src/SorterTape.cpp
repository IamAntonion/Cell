#include "SorterTape.h"

SorterTape::SorterTape(TapeInterface& input, TapeInterface& output) {
    Sort(input, output);
}

void SorterTape::Sort(TapeInterface& input, TapeInterface& output) {
    std::vector<int> dataTmp;

    // int size = input.Size();
    // dataTmp.reserve(size);

    input.Rewind();

    std::cout << "Size^ "<< input.SizeAllData() << "\n";

    //for (int i = 0; i != size; ++i) {
    for (int i = 0; i!= input.SizeAllData(); ++i) {
        int tmp = input.GetValue();
        std::cout << tmp << "\n";
        dataTmp.push_back(tmp);
    }


    std::sort(dataTmp.begin(), dataTmp.end());

    std::cout << "Sorting\n";
    for (int i = 0; i != dataTmp.size(); ++i) {
        output.SetValue(dataTmp[i]);
    }
}