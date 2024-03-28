#include "FileTape.h"

FileTape::FileTape() {
    GetConfig();
}

FileTape::FileTape(std::string fileName) {
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
    bool first = false;
    while (file_ >> dataTmp) {
        if (data_.size() >= M_ / sizeof(int)) {
            if (!first) {
                tmp.open(".\\tmp\\tmp.txt");
                first = true;
            }
            tmp << dataTmp << " ";
        } else {
            std::cout << dataTmp << std::endl;
            data_.push_back(dataTmp);
        }
    }
    if (tmp.is_open()) {
        tmp.close();
        //tmpTape_->SetTape(".\\tmp\\tmp.txt");
        std::ofstream outputText(".\\tmp\\outtmp.txt");
        std::ifstream inputText(".\\tmp\\tmp.txt");
        int num;
        while (inputText >> num) {
            outputText << num << " ";
        }

        outputText.close();
        inputText.close();

        FileTape tapeTmp(".\\tmp\\outtmp.txt");
        tmpTape_ = &tapeTmp;
        tmpTape_->Read();
    }
}

void FileTape::Write() {
    if (data_.empty()) throw std::invalid_argument("Can't write. Vector is empty");
    size_t size = Size();
    for (int i = 0; i != size; ++i) {
        file_ << data_[pos_] << " ";
        ForwardOneStep();
    }
}

size_t FileTape::Size() {
    size_t size = 0;
    //if (tmpTape_ != nullptr) size += tmpTape_->Size();
    size += data_.size();
    return size;
}

int FileTape::GetValue() {
    if (data_.empty()) throw std::invalid_argument("Can't get value. Vector is empty");

    int tmp;
    if (pos_ == Size()) {
        tmp = data_[pos_];
        ForwardOneStep();
        return tmp;
    }
    if (tmp == NULL) {
        tmp = tmpTape_->GetValue();
        return tmp;
    }
    return NULL;
}

void FileTape::SetValue(int value) {
    if (data_.size() >= M_ / sizeof(int)) {
        fileTmp_ << value << " ";
    } else {
        std::cout << value << std::endl;
        data_.push_back(value);
    }
    if (data_.size() >= M_ / sizeof(int)) {
        fileTmp_.close();
        //tmpTape_->SetTape(".\\tmp\\tmp.txt");
        std::ofstream outputText(".\\tmp\\outtmp.txt");
        std::ifstream inputText(".\\tmp\\tmp.txt");
        int num;
        while (inputText >> num) {
            outputText << num << " ";
        }

        outputText.close();
        inputText.close();

        FileTape tapeTmp(".\\tmp\\outtmp.txt");
        tmpTape_ = &tapeTmp;
        tmpTape_->Read();
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
}

void FileTape::SetTape(const std::string& textFile) {
    fileTmp_.open(textFile);
}