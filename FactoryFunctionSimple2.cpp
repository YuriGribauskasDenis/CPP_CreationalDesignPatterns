
#include <iostream>
#include <memory>

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
    ~B() { cout << "B-" << endl; }
    shared_ptr<F> getF() {
        shared_ptr<F> res = mp_f;
        init();
        return res;
    }
private:
    shared_ptr<F> mp_f;
    void init() {
        mp_f = make_shared<F>();
    }
};

int main()
{
    unique_ptr<B> b = make_unique<B>();
    // shared_ptr<F> f = nullptr;
    // f = b->getF();
    shared_ptr<F> f = b->getF();
    f->Print();
    
    cout << endl;
    f = b->getF();
    f->Print();

    return 0;
}