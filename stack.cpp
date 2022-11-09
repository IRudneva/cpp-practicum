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
        // ≈сли стек пуст, то просто вставл€ем в него новый элемент.
        if (elements_.IsEmpty()) {
            elements_.Push(element);
            return;
        }
        // ≈сли в стеке уже есть элементы,
        // возьмем копию элемента сверху
        Type last_elem = elements_.Peek();
        // и сравним ее с элементом, который мы хотим вставить.
        if (last_elem < element) {
            // ≈сли при добавлении элемента сортировка будет нарушатьс€,
            // вытащим из стека верхний элемент и попытаемс€ вставить новый элемент
            // в стек на одну позицию ниже рекурсивно.
            elements_.Pop();
            Push(element);
            // когда вставка удалась (рекурсивный стек начал раскручиватьс€ назад),
            // нужно вернуть на место тот элемент, который мы из стека доставали.
            elements_.Push(last_elem);
        }
        else {
            // ¬ этом случае сортировка при вставке не нарушаетс€,
            // и мы можем смело вставл€ть элемент сверху стека
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

    // заполн€ем вектор дл€ тестировани€ нашего стека
    iota(values.begin(), values.end(), 1);
    // перемешиваем значени€
    random_shuffle(values.begin(), values.end());

    // заполн€ем стек и провер€ем, что сортировка сохран€етс€ после каждой вставки
    for (int i = 0; i < 5; ++i) {
        cout << "¬ставл€емый элемент = "s << values[i] << endl;
        stack.Push(values[i]);
        stack.Print();
    }
}
