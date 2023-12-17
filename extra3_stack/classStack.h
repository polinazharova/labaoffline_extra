#include <iostream>
#include <vector>
#include <algorithm>

class Stack {
    //приватные атрибуты
private:
    //класс узлов стека
    class Node {
    private:
        int key;
        Node* p;
    public:
        //сеттеры
        void setP(Node* p) { this->p = p; }
        void setKey(int key) { this->key = key; }
        //геттеры
        Node* getP() { return p; }
        int getKey() { return key; }

    };
    int N; //фиксируем кол-во узлов в стеке (по сути не самый обязательный параметр, 
    //т.к. все можно проверить через vector.size(), но пусть будет для логики стека
    std::vector<Node*> stack; //вектор узлов стека

public:
    //сеттеры
    void setN(int N) { this->N = N; }
    void setStack(std::vector<Node*> stack) { this->stack = stack; }

    //геттеры
    int getN() { return N; }
    std::vector<Node*> getStackCopy() { return stack; }

    //ОСНОВНОЙ ФУНКЦИОНАЛ КЛАССА
    //сообщение, что стек пуст
    void stackIsEmpty() { std::cout << "----------" << "STACK IS EMPTY" << "----------" << std::endl; }

    //сообщение, что стек переполнен (в данной программе - если кол-во узлов будет превышать 15)
    void stackIsOverflow() { std::cout << "----------" << "STACK IS OVERFLOW" << "----------" << std::endl; }

    //вывести в терминал информацию о размере стека
    void size() { std::cout << "----------" << "STACK SIZE IS " << N << "----------" << std::endl; }

    //добавить узел в стек
    void push() {
        if (N >= 15)
            stackIsOverflow();
        else {
            Node* obj = new Node;
            (*obj).setP(obj);
            (*obj).setKey(N);
            stack.push_back(obj);
            N++;
        }
    }
    //вывести весь стек в терминал
    void print() {
        if (N == 0)
            stackIsEmpty();
        else {
            for (std::vector<Node*>::reverse_iterator iter = stack.rbegin(); iter < stack.rend(); iter++)
                std::cout << "::::::::::" << (*(*iter)).getKey() << "::::::::::" << std::endl;
        }
    }
    //удалить узел из стека
    void pop() {
        if (N <= 0)
            stackIsEmpty();
        else {
            std::cout << "----------" << "DELETED NODE IS " << (*stack[N - 1]).getKey() << "----------" << std::endl;
            stack.pop_back();
            print();
            N--;
        }
    }
    //удалить весь стек
    void remove() {
        for (int i{ 0 }; i < stack.size(); i++)
            delete (*stack[i]).getP();
    }

    //перегружаем операцию присваивания для создании копии стека
    //тут момент в том, что если просто скопировать вектор,
    //то в скопированном будут указатели на те же ячейки памяти, которые используются в объекте, который мы копировали,
    //и тогда деструктор дважды попытается очистить одну и ту же область памяти. хотя ошибка при этом не вылезает, 
    //все равно при копировании выделяем другую область памяти, но переносим значения узлов
    void operator = (Stack& obj) {
        stack.resize(obj.getN());
        for (int i{ 0 }; i < obj.getN(); i++) {
            if (stack[i] == nullptr) {
                Node* new_obj = new Node;
                (*new_obj).setP(new_obj);
                stack[i] = new_obj;
            }
            (*stack[i]).setKey((*obj.stack[i]).getKey());
        }
        N = obj.N;
        std::cout << "----------COPIED STACK----------" << std::endl;
        print();
        std::cout << "----------" << "COPIED STACK SIZE IS " << N << "----------" << std::endl;
    }

    //инверсия (доп задание)
    void reverse() {
        Node* temp;
        std::vector<Node*>::iterator iter_begin = stack.begin();
        std::vector<Node*>::iterator iter_end = stack.end() - 1;

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
    void operator || (Stack& obj) {
        std::cout << "----------SUM OF STACKS----------" << std::endl;
        for (int i{ 0 }; i < obj.N; i++) {
            stack.push_back((obj.getStackCopy())[i]);
        }
        N += obj.N;
        print();

        std::cout << "----------STACK WITH UNIQUE ELEMENTS----------" << std::endl;
        for (int i{ 0 }; i < N; i++) {
            for (int j{ i+1 }; j < N; j++) {
                if ((*stack[i]).getKey() == (*stack[j]).getKey()) {
                    stack.erase(stack.begin() + j);
                    j--;
                    N--;
                }
            }
        }
        print();
    }

    //деструктор
    ~Stack() {
        std::cout << "DESTRUCTION (работа деструктора)." << std::endl;
        remove();
    }

    //конструктор дефолтный
    Stack() : N{ 10 } {
        Node* obj;
        for (int i{ 0 }; i < N; i++) {
            obj = new Node;
            (*obj).setP(obj);
            (*obj).setKey(i);
            stack.push_back(obj);
        }
    }
    //конструктор недефолтный
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