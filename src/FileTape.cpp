#include "FileTape.h"

FileTape::FileTape(std::string fileName) {
    file_.open(fileName, std::ios::in | std::ios::out | std::ios::binary);
    // if (!file_) {
    //     std::cout << "Create new " << fileName << ".txt file";

    // }
}

void FileTape::Read() {
    int dataTmp;
    //file.read(reinterpret_cast<char*>(data), sizeof(int));
    while (file_ >> dataTmp) {
        data_.push(dataTmp);
    }

    file_.close();
}

void FileTape::Write(std::queue<int> data) {
    //file_.write(reinterpret_cast<char*>(data), sizeof(int));
    while (!data.empty()) {
        file_ << data.front();
        data.pop();
    }

    file_.close();
}

int FileTape::Size() {
    return data_.size();
}

int FileTape::GetValue() {
    if (data_.empty()) throw std::invalid_argument("Value is zero");
    
    int tmp = 0;
    tmp = data_.front();
    data_.pop();

    return tmp;
}

void FileTape::SetValue(int value) {
    data_.push(value);
}

// std::fstream FileTape::CreateFile() {

// }