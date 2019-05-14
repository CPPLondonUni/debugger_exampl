
#include <iostream>
#include <initializer_list>

class bad_vector {
public:
    bad_vector() = default;

    bad_vector(std::initializer_list<int> ilist)
        : arr_(new int[ilist.size()]),
         size_(ilist.size())
    {
        for (int i = 0; i < size_; i++) {
            arr_[i] = *(ilist.begin() + i);
        }
    }

    ~bad_vector() { delete[] arr_; }

    int* begin() { return arr_; }
    const int* begin() const { return arr_; }
    int* end() { return arr_ + size_; }
    const int* end() const { return arr_ + size_; }

    size_t size() const { return size_; }

    int& operator[](size_t idx) { return arr_[idx]; }
    const int& operator[](size_t idx) const { return arr_[idx]; }

private:
    int* arr_ = nullptr;
    size_t size_ = 0;
};

void use_bad_vector(bad_vector vec)
{
    for (int i : vec) {
        std::cout << i << '\n';
    }
}

int main()
{
    bad_vector vec{1, 2, 3};

    for (int i = 0; i <=3; i++) {
        std::cout << vec[i] << '\n';
    }
}

