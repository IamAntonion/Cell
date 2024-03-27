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
    while (file_ >> dataTmp) {
        data_.push(dataTmp);
    }
}

void FileTape::Write() {
    file_ << data_.front() << " ";
    std::cout << "Write " << data_.front() << "\n";
    data_.pop();
}

size_t FileTape::Size() {
    return data_.size();
}

int FileTape::GetValue() {
    if (data_.empty()) throw std::invalid_argument("Value is empty");
    
    int tmp = 0;
    tmp = data_.front();
    data_.pop();

    return tmp;
}

void FileTape::SetValue(int value) {
    data_.push(value);
}