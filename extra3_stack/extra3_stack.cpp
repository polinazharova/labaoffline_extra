#include <iostream>
#include <vector>
#include <algorithm>

//СТЕК - структура организации памяти (структура данных), при которой первыми удаляются те данные, которые были записаны последними.
//обычно используется в функциях.

//ОЧЕРЕДЬ - также структура организации памяти, которая напоминает стек, но при этом первым удаляется элемент, который был записан первым.
//т.е. данные в стеке и очереди последовательно расположены, обход их узлов линеен, как, например, у массива. 

//ДЕРЕВО - это уже не последовательная структура хранения данных,
//используется много где и много в каких задачах в том числе вне контекста программирования.
//представляет собой граф, правда со своими особенностями (например, отсутствие простых циклов, т.е., проходя по ребрам дерева
//невозможно попасть из начальной вершины в конечную (если они являются одной и той же вершиной), проходя по ребрам всего один раз).
//у дерева много своих терминов (например, листья, - вершина, на которой оканчивается "ветка" дерева).
//самый распространенный вид - это бинарное дерево.
//распределение в нем происходит так, что левый потомок всегда имеет меньшее значение, чем свой родитель, а правый - всегда большее.
//используется, например, в контейнере map.

class Stack {
//приватные атрибуты
private:
    class Node {
    private:
        int key;
        Node* p;
    public:
        //сеттеры геттеры
        void setP(Node* p) { this->p = p; }
        Node* getP() { return p; }
        int getKey() { return key; }
        void setKey(int key) { this->key = key; }
    };
    int N;
    std::vector<Node*> stack;

public:
    //сеттеры геттеры
    void setN(int N) { this->N = N; }
    int getN() { return N; }

    std::vector<Node*> getStackCopy() { return stack; }
    void setStack(std::vector<Node*> stack) { this->stack = stack; }
    //основной функционал класса
    void stackIsEmpty() { std::cout << "----------" << "STACK IS EMPTY" << "----------" << std::endl; }
    void stackIsOverflow() { std::cout << "----------" << "STACK IS OVERFLOW" << "----------" << std::endl; }
    void size() { std::cout << "----------" << "STACK SIZE IS " << stack.size() << "----------" << std::endl; }

    void push() {
        if (N >= 15)
            stackIsOverflow();
        else {
            Node* obj = new Node;
            (*obj).setP(obj);
            (*obj).setKey(N);
            stack.push_back(obj);
            setN(++N);
        }
    }

    void print() {
        if (N == 0)
            stackIsEmpty();
        else {
            for (std::vector<Node*>::reverse_iterator iter = stack.rbegin(); iter < stack.rend(); iter++)
                std::cout << "::::::::::" << (*(*iter)).getKey() << "::::::::::" << std::endl;
        }
    }

    void pop() {
        if (N <= 0)
            stackIsEmpty();
        else {
            std::cout << "----------" << "DELETED NODE IS " << (*stack[getN() - 1]).getKey() << "----------" << std::endl;
            stack.pop_back();
            print();
            setN(--N);
        }
    }

    void remove() {
        for (int i{ 0 }; i < stack.size(); i++)
            delete (*stack[i]).getP();
    }
    //инверсия (доп задание)
    void reverse() {
        Node* temp;
        std::vector<Node*>::iterator iter_begin = stack.begin();
        std::vector<Node*>::iterator iter_end = stack.end()-1;

        while (iter_end - iter_begin >= 1) {
            temp = *iter_end;
            *iter_end = *iter_begin;
            *iter_begin = temp;

            iter_end--;
            iter_begin++;
        }
        std::cout << "----------REVERSED STACK----------" << std::endl;
        print();
    }
    //перегрузка оператора (сложение стеков + стек с неповторяющимися значениями. доп)
    void operator || (Stack &obj) {
        std::cout << "----------SUM OF STACKS----------" << std::endl;
        for (int i{ 0 }; i < (obj.getStackCopy()).size(); i++) {
            stack.push_back((obj.getStackCopy())[i]);
        }
        setN(N + obj.getStackCopy().size());
        print();

        std::cout << "----------STACK WITH UNIQUE ELEMENTS----------" << std::endl;
        for (int i{ 0 }; i < stack.size()-1; i++) {
            for(int j{i+1}; j < stack.size(); j++){
                if ((*stack[i]).getKey() == (*stack[j]).getKey()) {
                    stack.erase(stack.begin() + j);
                    j--;
                    setN(--N);
                }
            }
    }
        print();
    }
    //деконструктор
    ~Stack() {
        std::cout << "DESTRUCTION (работа деструктора)." << std::endl;
        remove();
    }
    //конструкторы
    Stack() : N{ 10 } {
        Node* obj;
        for (int i{ 0 }; i < N; i++) {
            obj = new Node;
            (*obj).setP(obj);
            (*obj).setKey(i);
            stack.push_back(obj);
        }
    }

    Stack(int N) {
        Node* obj;
        if (N > 15 || N < 0)
            this->N = 10;
        else
            this->N = N;

        for (int i{ 0 }; i < N; i++) {
            obj = new Node;
            (*obj).setP(obj);
            (*obj).setKey(i);
            stack.push_back(obj);
        }
    }
};


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int N;
    //преамбула
    std::cout << "Введите кол-во элементов в стеке (не больше 15 для одного стека, иначе будет переполнен!): ";
    std::cin >> N;
    
    Stack ctuck(N);
    std::cout << "0 - Выйти из программы. " << std::endl;
    std::cout << "1 - Сообщение о том, что стек пуст." << std::endl;
    std::cout << "2 - Сообщение о том, что стек переполнен." << std::endl;
    std::cout << "3 - Копировать весь стек в новый объект." << std::endl;
    std::cout << "4 - Добавить элемент в стек." << std::endl;
    std::cout << "5 - Удалить элемент из стека и вывести стек на экран." << std::endl;
    std::cout << "6 - Удалить весь стек (выходит из программы)." << std::endl;
    std::cout << "7 - Вывести информацию о длине стека." << std::endl;
    std::cout << "8 - Вывести стек в терминал. " << std::endl;
    
    //реализация функционала класса
    while (1){
        Stack* stack_ptr = new Stack();
        std::cout << "Введите цифру: ";
        std::cin >> N;
        switch (N)
        {
        case 0:
        {
            std::cout << "Бонус! Сейчас вам будут представлены два сложенные стека (один, который только что использовался," << std::endl;
            std::cout << "а второй с рандомным количеством элементов), а так же полученный стек только с уникальными элементами и его инвертированная версия." << std::endl;
            Stack new_one(1 + rand() % 15);

            ctuck || new_one;
            ctuck.reverse();
            std::cout << std::endl;

            std::cout << "Спасибо за то, что выбрали именно нашу программу!" << std::endl;
            std::cout << std::endl << "---------------------------------------" << std::endl;
            delete stack_ptr;
            return 0;
        }
        case 1:
            ctuck.stackIsEmpty();
            break;
        case 2:
            ctuck.stackIsOverflow();
            break;
        case 3:
        {
            (*stack_ptr).setStack(ctuck.getStackCopy());
            std::cout << "COPIED STACK:" << std::endl;
            (*stack_ptr).print();
            break;
        }
        case 4:
            ctuck.push();
            break;

        case 5:
            ctuck.pop();
            break;
        case 6:
        {
            std::cout << "Бонус! Сейчас вам будут представлены два сложенные стека (один, который только что использовался," << std::endl;
            std::cout << "а второй с рандомным количеством элементов), а так же полученный стек только с уникальными элементами и его инвертированная версия." << std::endl;
            Stack new_one(1 + rand() % 15);

            ctuck || new_one;
            ctuck.reverse();
            std::cout << std::endl;

            ctuck.stackIsEmpty();
            std::cout << "Спасибо за то, что выбрали именно нашу программу!" << std::endl;
            std::cout << std::endl << "---------------------------------------" << std::endl;
            delete stack_ptr;
            return 0;
        }
        case 7:
            ctuck.size();
            break;
        case 8:
            ctuck.print();
            break;
        default:
        {
            std::cout << "Бонус! Сейчас вам будут представлены два сложенные стека (один, который только что использовался," << std::endl;
            std::cout << "а второй с рандомным количеством элементов), а так же полученный стек только с уникальными элементами и его инвертированная версия." << std::endl;
            Stack new_one(1 + rand() % 15);

            ctuck || new_one;
            ctuck.reverse();
            std::cout << std::endl;

            std::cout << "Такой цифры не было среди предложенных." << std::endl;
            std::cout << std::endl << "---------------------------------------" << std::endl;
            delete stack_ptr;
            return 0;
        }
            
        }
    }

    return 0;
}


