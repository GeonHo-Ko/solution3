#include <iostream>
#include <algorithm>

template <typename T>
class SimpleVector {
private:
    T* data;
    size_t capacity_;
    size_t size_;

    void reallocate(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity_ = new_capacity;
    }

public:
    SimpleVector() : capacity_(10), size_(0) {
        data = new T[capacity_];
    }

    SimpleVector(size_t capacity) : capacity_(capacity), size_(0) {
        data = new T[capacity_];
    }

    SimpleVector(const SimpleVector& other) : capacity_(other.capacity_), size_(other.size_) {
        data = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    }

    ~SimpleVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size_ >= capacity_) {
            reallocate(capacity_ + 5);
        }
        data[size_++] = value;
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

    void resize(size_t new_capacity) {
        if (new_capacity > capacity_) {
            reallocate(new_capacity);
        }
    }

    void sortData() {
        std::sort(data, data + size_);
    }

    void printData() const {
        for (size_t i = 0; i < size_; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    SimpleVector<int> vec;

    std::cout << "Initial size: " << vec.size() << ", capacity: " << vec.capacity() << '\n';

    for (int i = 0; i < 12; ++i) {
        vec.push_back(i);
        std::cout << "Added " << i << ", size: " << vec.size() << ", capacity: " << vec.capacity() << '\n';
    }

    for (int i = 0; i < 6; ++i) {
        vec.pop_back();
        std::cout << "Popped, size: " << vec.size() << '\n';
    }

    vec.resize(20);
    std::cout << "After resize, capacity: " << vec.capacity() << '\n';

    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.sortData();
    std::cout << "After sorting: ";
    vec.printData();

    return 0;
}
