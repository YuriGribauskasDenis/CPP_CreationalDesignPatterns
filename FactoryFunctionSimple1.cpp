
#include <iostream>

using namespace std;

class F
{
public:
    F() { cout << "F+" << endl; }
    ~F() { cout << "F-" << endl; }
    void Print() {
        cout << "success ";
        static int count = 0;
        cout << ++count;
        cout << endl;
    }
private:
};

class B
{
public:
    B() { init(); cout << "B+" << endl; }
    ~B() { delete mp_f; cout << "B-" << endl; }
    F* getF() {
        F* res = mp_f;
        init();
        return res;
    }
private:
    F* mp_f;
    void init() {
        mp_f = new F();
    }
};

int main()
{
    B* b - new B();
    F* f = b->getF();
    f->Print();
    delete f;
    
    f = b->getF();
    f->Print();
    delete f;

    delete b;

    return 0;
}