#include "Interface.h"
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <queue>

class FileTape : public TapeInterface {
public:
    FileTape() = default;
    FileTape(std::string fileName);
    //~FileTape();

    void Read() override;
    void Write() override;

    size_t Size() override;
    int GetValue() override;
    void SetValue(int value) override;
private:
    std::fstream file_;     // файл
    std::queue<int> data_;  // данные

    FileTape* tmp;          // следующий tape

    //int N = 40;        // максимальная длина ленты tape
    //size_t M = 20;        // ограничение памяти в байтах
    //size_t size = 0;            // текущая длина
};