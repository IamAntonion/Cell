#include "Interface.h"
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class FileTape : public TapeInterface {
public:
    FileTape() = default;
    FileTape(std::string fileName);
    //~FileTape();

    void Read() override;
    void Write(int data) override;

    size_t Size() override;
    int GetValue() override;
    void SetValue(int value) override;
private:
    std::fstream file_;     // файл
    std::queue<int> data_;  // данные

    FileTape* tmp;          // следующий tape

    int N = INT_MAX;        // максимальная длина tape
    size_t size;            // текущая длина
};