#include <algorithm>
#include <vector>
#include "FileTape.h"

class SorterTape {
public:
    SorterTape() = default;
    SorterTape(TapeInterface& input, TapeInterface& output);
    
    static void Sort(TapeInterface& input, TapeInterface& output);
};