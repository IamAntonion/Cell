#include <queue>

class TapeInterface {
public:
    virtual ~TapeInterface() = default;

    virtual void Read() = 0;
    virtual void Write(std::queue<int> data) = 0;
    
    virtual int Size() = 0;
    virtual int GetValue() = 0;
    virtual void SetValue(int value) = 0;
};