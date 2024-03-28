#include "FileTape.h"

class SorterTape {
public:
    SorterTape() = default;
    SorterTape(TapeInterface& input, TapeInterface& output);
    
    void Sort(TapeInterface& input, TapeInterface& output);
    // void Sort(TapeInterface& input);
};