#include "FileTape.h"

FileTape::FileTape(std::string fileName) {
    file_.open(fileName, std::ios::in | std::ios::out | std::ios::binary);
    if (!file_.is_open()) {
        std::cout << "Create new " << fileName << " file\n";
        
        std::fstream file(fileName);
        file_.open(fileName, std::ios::out | std::ios::binary);
        if (!file_.is_open()) {
            throw std::runtime_error(fileName); 
        }
    }
}

void FileTape::Read() {
    int dataTmp;
    //file.read(reinterpret_cast<char*>(data), sizeof(int));
    while (file_ >> dataTmp) {
        //if (data_.size() == N) tmp = 
        data_.push(dataTmp);
    }

    size = data_.size();

    //file_.close();
}

void FileTape::Write(int data) {
    file_ << data << ' ';

    //file_.close();
}

size_t FileTape::Size() {
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