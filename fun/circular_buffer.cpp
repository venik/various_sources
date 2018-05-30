#include <iostream>

#define BUFFER_CAPACITY 5

class Buffer {
private:
    int _buffer[BUFFER_CAPACITY];
    int _write_idx;
    int _read_idx;

public:

    Buffer() {
        _write_idx = 0;
        _read_idx = 0;
    }

    int write(int val) {
        int next_write_idx = (_write_idx + 1) % BUFFER_CAPACITY;
        if (next_write_idx == _read_idx) {
            // overflow
            return -1;
        }
        _write_idx = next_write_idx;
        _buffer[_write_idx] = val;
        return val;
    }

    int read() {
        if (_read_idx == _write_idx) {
            // no more to read
            return -1;
        }

        _read_idx = (_read_idx + 1) % BUFFER_CAPACITY;
        return _buffer[_read_idx];
    }
};

int main() {
    Buffer buf;
    std::cout<<"write "<<buf.write(1)<<"\n";
    std::cout<<"write "<<buf.write(2)<<"\n";
    std::cout<<"write "<<buf.write(3)<<"\n";
    std::cout<<"write "<<buf.write(4)<<"\n";
    std::cout<<"write "<<buf.write(5)<<"\n";
    std::cout<<"write "<<buf.write(6)<<"\n";

    std::cout<<"read "<<buf.read()<<"\n";
    std::cout<<"read "<<buf.read()<<"\n";
    std::cout<<"read "<<buf.read()<<"\n";
    std::cout<<"read "<<buf.read()<<"\n";
    std::cout<<"read "<<buf.read()<<"\n";
    std::cout<<"read "<<buf.read()<<"\n";

    std::cout<<"write "<<buf.write(7)<<"\n";
    std::cout<<"read "<<buf.read()<<"\n";

    std::cout<<"write "<<buf.write(8)<<"\n";
    std::cout<<"read "<<buf.read()<<"\n";
    std::cout<<"read "<<buf.read()<<"\n";

    return 0;
};