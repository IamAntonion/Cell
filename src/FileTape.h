#pragma once

#include "Interface.h"
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

class FileTape : public TapeInterface {
public:
    FileTape();
    FileTape(const std::string& fileName);
    ~FileTape() {
        if (file_.is_open()) {
            file_.close();
        }
    }

    void Read() override;
    void Write() override;
    void ForwardOneStep() override;
    void Rewind() override;

    size_t Size() override;
    int GetValue() override;
    void SetValue(int value) override;

private:
    int pos_ = 0;
    int N_ = 0;                 // максимальный размер контейнера с данными
    int M_ = 0;                 // максимальная вместимость в байтах

    FileTape* tmpTape_;         //временная лента
    
    std::vector<int> data_;     // данные
    std::fstream file_;         // файл
    std::fstream fileTmp_;      // файл

    std::string nameFile_;

    void GetConfig();
    void SetTape(const std::string& textFile);
};