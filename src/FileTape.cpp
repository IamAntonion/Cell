#include "FileTape.h"

FileTape::FileTape() {
    GetConfig();
}

FileTape::FileTape(const std::string& fileName) {
    GetConfig();

    file_.open(fileName, std::ios::in | std::ios::out | std::ios::binary);
    if (!file_.is_open()) {
        std::cout << "Create new " << fileName << " file\n";
        
        std::fstream file(fileName);
        file_.open(fileName, std::ios::out | std::ios::binary);
        if (!file_.is_open()) {
            throw std::runtime_error(fileName + "Impossible to create"); 
        }
    }
}

void FileTape::Read() {
    int dataTmp;
    std::ofstream tmp;
    bool first = true;

    while (file_ >> dataTmp) {
        if (data_.size() >= M_ / sizeof(int)) {
            if (first) {
                tmp.open(".\\tmp\\tmp.txt");
                first = false;
            }
            tmp << dataTmp << " ";
            ++sizeData;
        } else {
            data_.push_back(dataTmp);
        }
    }

    file_.close();
    tmp.close();

    Rewind();
}

void FileTape::Write() {
    if (data_.empty()) throw std::invalid_argument("Can't write. Vector is empty");
    size_t size = Size();
    for (int i = 0; i != size; ++i) {
        file_ << data_[pos_] << " ";
        ForwardOneStep();
    }
    
    if (SizeAllData() != Size()) {
        int num = 0;

        fileTmp_.open(".\\tmp\\sorttmp.txt", std::ios::in | std::ios::out | std::ios::binary);
        if (!fileTmp_.is_open()) throw std::runtime_error(".\\tmp\\sorttmp.txt Impossible to open");

        while (fileTmp_ >> num) {
            file_ << num << " ";
        }
        fileTmp_.close();
    }
    file_.close();
}

size_t FileTape::Size() {
    return data_.size();;
}

size_t FileTape::SizeAllData() {
    return Size() + sizeData;
}

int FileTape::GetValue() {
    if (data_.empty()) throw std::invalid_argument("Can't get value. Vector is empty");
    int result;
    if (pos_ != Size()) {
        result = data_[pos_];
        ForwardOneStep();
        return result;
    }
    
    std::ofstream outputText(".\\tmp\\outtmp.txt");
    std::ifstream inputText(".\\tmp\\tmp.txt");

    bool first = true;
    int tmp;
    while (inputText >> tmp) {
        if (first == true) {
            first = false;
            result = tmp;
        } else {
            outputText << tmp << " ";
        }
    }

    outputText.close();
    inputText.close();

    std::ofstream output(".\\tmp\\tmp.txt");
    std::ifstream input(".\\tmp\\outtmp.txt");

    while (input >> tmp) {
        output << tmp << " ";
    }

    output.close();
    input.close();

    return result;
}

void FileTape::SetValue(int value) {
    if (Size() == 0) {
        std::ofstream output(".\\tmp\\sorttmp.txt");
        if (!output.is_open()) throw std::runtime_error(".\\tmp\\sorttmp.txt Impossible to create");
        output.close();
        fileTmp_.open(".\\tmp\\sorttmp.txt", std::ios::in | std::ios::out | std::ios::binary);
        if (!fileTmp_.is_open()) throw std::runtime_error(".\\tmp\\sorttmp.txt Impossible to open");
    }
    
    if (data_.size() >= M_ / sizeof(int)) {
        fileTmp_ << value << " ";
        ++sizeData;
    } else {
        data_.push_back(value);
    }
    
}

void FileTape::ForwardOneStep() {
    ++pos_;
}

void FileTape::Rewind() {
    pos_ = 0;
}

void FileTape::GetConfig() {
    std::ifstream conf(".\\config\\config.txt");
    if (!conf.is_open()) throw std::runtime_error("config.txt doesn't exist");

    std::string input = ""; 
    while (conf >> input) {
        if (input[0] == 'N') {
            if (input[1] == '=') {
                int num = std::stoi(input.substr(2));;
                N_ = num;
                data_.reserve(N_);
            }
        }
        if (input[0] == 'M') {
            if (input[1] == '=') {
                int num = std::stoi(input.substr(2));;
                M_ = num;
                if ((M_ / sizeof(int)) < N_) data_.reserve(M_ / sizeof(int));
            }
        }
    }
    conf.close();
}

void FileTape::CloseAdditionalFile() {
    fileTmp_.close();
}