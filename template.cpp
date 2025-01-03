#include <iostream>
#include <algorithm> // STL sort 사용

using namespace std;

template <typename T>
class SimpleVector {
private:
    T* data;               // 데이터를 저장하는 배열
    size_t currentSize;    // 현재 원소의 개수
    size_t currentCapacity; // 배열의 크기 (capacity)

    // 내부적으로 배열을 재할당하는 헬퍼 함수
    void reallocate(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < currentSize; ++i) {
            newData[i] = data[i]; // 기존 데이터 복사
        }
        delete[] data; // 기존 배열 해제
        data = newData;
        currentCapacity = newCapacity;
    }

public:
    // 기본 생성자
    SimpleVector() : currentSize(0), currentCapacity(10) {
        data = new T[currentCapacity];
    }

    // 크기를 지정하는 생성자
    SimpleVector(size_t capacity) : currentSize(0), currentCapacity(capacity) {
        data = new T[currentCapacity];
    }

    // 복사 생성자
    SimpleVector(const SimpleVector& other)
        : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
        data = new T[currentCapacity];
        for (size_t i = 0; i < currentSize; ++i) {
            data[i] = other.data[i];
        }
    }

    // 소멸자
    ~SimpleVector() {
        delete[] data;
    }

    // push_back 구현
    void push_back(const T& value) {
        if (currentSize >= currentCapacity) {
            reallocate(currentCapacity + 5); // 크기를 5만큼 늘림
        }
        data[currentSize++] = value;
    }

    // pop_back 구현
    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
    }

    // 현재 원소의 개수를 반환
    size_t size() const {
        return currentSize;
    }

    // 현재 배열의 크기를 반환
    size_t capacity() const {
        return currentCapacity;
    }

    // resize 구현
    void resize(size_t newCapacity) {
        if (newCapacity > currentCapacity) {
            reallocate(newCapacity); // 배열 크기를 증가시킴
        }
    }

    // sortData 구현
    void sortData() {
        std::sort(data, data + currentSize);
    }
};


int main() {
    SimpleVector<int> vec;

    // 초기 원소 추가
    vec.push_back(30);
    vec.push_back(10);
    vec.push_back(20);

    std::cout << "Before sorting:" << std::endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // 데이터 정렬
    vec.sortData();

    cout << "After sorting:" << endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
