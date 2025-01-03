#include <iostream>
#include <algorithm> // STL sort ���

using namespace std;

template <typename T>
class SimpleVector {
private:
    T* data;               // �����͸� �����ϴ� �迭
    size_t currentSize;    // ���� ������ ����
    size_t currentCapacity; // �迭�� ũ�� (capacity)

    // ���������� �迭�� ���Ҵ��ϴ� ���� �Լ�
    void reallocate(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < currentSize; ++i) {
            newData[i] = data[i]; // ���� ������ ����
        }
        delete[] data; // ���� �迭 ����
        data = newData;
        currentCapacity = newCapacity;
    }

public:
    // �⺻ ������
    SimpleVector() : currentSize(0), currentCapacity(10) {
        data = new T[currentCapacity];
    }

    // ũ�⸦ �����ϴ� ������
    SimpleVector(size_t capacity) : currentSize(0), currentCapacity(capacity) {
        data = new T[currentCapacity];
    }

    // ���� ������
    SimpleVector(const SimpleVector& other)
        : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
        data = new T[currentCapacity];
        for (size_t i = 0; i < currentSize; ++i) {
            data[i] = other.data[i];
        }
    }

    // �Ҹ���
    ~SimpleVector() {
        delete[] data;
    }

    // push_back ����
    void push_back(const T& value) {
        if (currentSize >= currentCapacity) {
            reallocate(currentCapacity + 5); // ũ�⸦ 5��ŭ �ø�
        }
        data[currentSize++] = value;
    }

    // pop_back ����
    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
    }

    // ���� ������ ������ ��ȯ
    size_t size() const {
        return currentSize;
    }

    // ���� �迭�� ũ�⸦ ��ȯ
    size_t capacity() const {
        return currentCapacity;
    }

    // resize ����
    void resize(size_t newCapacity) {
        if (newCapacity > currentCapacity) {
            reallocate(newCapacity); // �迭 ũ�⸦ ������Ŵ
        }
    }

    // sortData ����
    void sortData() {
        std::sort(data, data + currentSize);
    }
};


int main() {
    SimpleVector<int> vec;

    // �ʱ� ���� �߰�
    vec.push_back(30);
    vec.push_back(10);
    vec.push_back(20);

    std::cout << "Before sorting:" << std::endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // ������ ����
    vec.sortData();

    cout << "After sorting:" << endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
