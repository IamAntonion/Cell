#include <queue>

class TapeInterface {
public:
    virtual void Read() = 0;
    virtual void Write() = 0;
    
    virtual size_t Size() = 0;
    virtual int GetValue() = 0;
    virtual void SetValue(int value) = 0;
};