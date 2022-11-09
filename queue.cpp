#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
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
class Queue {
public:
    void Push(const Type& element) {
        // ������ ������� ������� � ������ ����
        stack1_.push(element);
    }
    void Pop() {
        // ��������� ��� �������� �� ������� ����� �� ������,
        // ��� ��� ������ ������� ������� �������� �� ������� ������� �����
        MoveElements();
        // ������� ������� ������� ������� �����
        stack2_.pop();
    }
    Type& Front() {
        // ������ ���������� ������ Pop
        MoveElements();
        return stack2_.top();
    }
    uint64_t Size() const {
        return stack1_.size() + stack2_.size();
    }
    bool IsEmpty() const {
        return (stack1_.empty() && stack2_.empty());
    }

private:
    stack<Type> stack1_;
    stack<Type> stack2_;

    void MoveElements() {
        // ������������� �� ������ ���� �� �������
        // ���������� ������ �����, ����� �� ������ �����
        // ��������� �� ��������. ����� ������� ������� ����� �������.
        if (stack2_.empty()) {
            while (!stack1_.empty()) {
                stack2_.push(stack1_.top());
                stack1_.pop();
            }
        }
    }
};

int main() {
    Queue<int> queue;
    vector<int> values(5);

    // ��������� ������ ��� ������������ �������
    iota(values.begin(), values.end(), 1);
    // ������������ ��������
    random_shuffle(values.begin(), values.end());

    PrintRange(values.begin(), values.end());

    cout << "��������� �������"s << endl;

    // ��������� ������� � ������� ������� � ������ �������
    for (int i = 0; i < 5; ++i) {
        queue.Push(values[i]);
        cout << "����������� ������� "s << values[i] << endl;
        cout << "������ ������� ������� "s << queue.Front() << endl;
    }

    cout << "�������� �������� �� �������"s << endl;

    // ������� ������� � ������ ������� � ����������� �������� �� ������
    while (!queue.IsEmpty()) {
        // ������� ����� ��������� ��������� �������, � ����� �����������,
        // ��� ��� �������� Front �� ������ ������� �� ����������
        cout << "����� �������� ������� "s << queue.Front() << endl;
        queue.Pop();
    }
    return 0;
}
