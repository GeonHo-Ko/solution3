#include <iostream>

template <typename T>
class SimpleVector {
private:
    T* data;             
    size_t capacity_;
    size_t size_;

public:
    SimpleVector() : capacity_(10), size_(0) {
        data = new T[capacity_];
    }

    SimpleVector(size_t capacity) : capacity_(capacity), size_(0) {
        data = new T[capacity_];
    }

    ~SimpleVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size_ < capacity_) {
            data[size_++] = value;
        }
    }

    void pop_back() {
        if (size_ > 0) {
            --size_;
        }
    }

    size_t size() const {
        return size_;
    }

    size_t capacity() const {
        return capacity_;
    }
};

int main() {
    SimpleVector<int> vec;

    std::cout << "Initial size: " << vec.size() << ", capacity: " << vec.capacity() << '\n';

    for (int i = 0; i < 12; ++i) {
        vec.push_back(i);
        std::cout << "Added " << i << ", size: " << vec.size() << '\n';
    }

    for (int i = 0; i < 6; ++i) {
        vec.pop_back();
        std::cout << "Popped, size: " << vec.size() << '\n';
    }

    return 0;
}