#include "Interface.h"
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <iostream>

class FileTape : public TapeInterface {
public:
    FileTape(std::string fileName);
    void Read() override;
    void Write(std::queue<int> data) override;

    int Size() override;
    int GetValue() override;
    void SetValue(int value) override;
private:
    std::fstream file_;     // файл
    std::queue<int> data_;  // данные

    // std::fstream CreateFile();
};