// Strategy.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


class Strategy {
public:
    virtual void execute() const = 0;
    virtual ~Strategy() = default;
};


class ConcreteStrategy1 : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing ConcreteStrategy1" << std::endl;
    }
};


class ConcreteStrategy2 : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing ConcreteStrategy2" << std::endl;
    }
};
 
class Context {
public:
    Context(Strategy* strategy) : strategy(strategy) {}

    void setStrategy(Strategy* newStrategy) {
        delete strategy;  
        strategy = newStrategy;
    }

    void executeStrategy() const {
        strategy->execute();
    }

    ~Context() {
        delete strategy; 
    }

private:
    Strategy* strategy;
};

int main() {
   
    Context context(new ConcreteStrategy1);

   
    context.executeStrategy();

   
    context.setStrategy(new ConcreteStrategy2);

    
    context.executeStrategy();

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
