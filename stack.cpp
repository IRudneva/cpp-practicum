#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

template <typename It>
void PrintRange(It range_begin, It range_end) {
    for (auto it = range_begin; it != range_end; ++it) {
        cout << *it << " "s;
    }
    cout << endl;
}

template <typename Type>
class Stack {
public:
    void Push(const Type& element) {
        elements_.push_back(element);
    }
    void Pop() {
        elements_.pop_back();
    }
    const Type& Peek() const {
        return elements_.back();
    }
    Type& Peek() {
        return elements_.back();
    }
    void Print() const {
        PrintRange(elements_.begin(), elements_.end());
    }
    uint64_t Size() const {
        return elements_.size();
    }
    bool IsEmpty() const {
        return elements_.empty();
    }

private:
    vector<Type> elements_;
};

template <typename Type>
class SortedStack {
public:
    void Push(const Type& element) {
        // ���� ���� ����, �� ������ ��������� � ���� ����� �������.
        if (elements_.IsEmpty()) {
            elements_.Push(element);
            return;
        }
        // ���� � ����� ��� ���� ��������,
        // ������� ����� �������� ������
        Type last_elem = elements_.Peek();
        // � ������� �� � ���������, ������� �� ����� ��������.
        if (last_elem < element) {
            // ���� ��� ���������� �������� ���������� ����� ����������,
            // ������� �� ����� ������� ������� � ���������� �������� ����� �������
            // � ���� �� ���� ������� ���� ����������.
            elements_.Pop();
            Push(element);
            // ����� ������� ������� (����������� ���� ����� �������������� �����),
            // ����� ������� �� ����� ��� �������, ������� �� �� ����� ���������.
            elements_.Push(last_elem);
        }
        else {
            // � ���� ������ ���������� ��� ������� �� ����������,
            // � �� ����� ����� ��������� ������� ������ �����
            elements_.Push(element);
        }
    }
    void Pop() {
        elements_.Pop();
    }
    const Type& Peek() const {
        return elements_.Peek();
    }
    Type& Peek() {
        return elements_.Peek();
    }
    void Print() const {
        elements_.Print();
    }
    uint64_t Size() const {
        return elements_.Size();
    }
    bool IsEmpty() const {
        return elements_.IsEmpty();
    }

private:
    Stack<Type> elements_;
};

int main() {
    SortedStack<int> stack;
    vector<int> values(5);

    // ��������� ������ ��� ������������ ������ �����
    iota(values.begin(), values.end(), 1);
    // ������������ ��������
    random_shuffle(values.begin(), values.end());

    // ��������� ���� � ���������, ��� ���������� ����������� ����� ������ �������
    for (int i = 0; i < 5; ++i) {
        cout << "����������� ������� = "s << values[i] << endl;
        stack.Push(values[i]);
        stack.Print();
    }
}
