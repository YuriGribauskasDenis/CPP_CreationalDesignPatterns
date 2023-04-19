
#include <iostream>

using namespace std;

class Singleton
{
public:
    Singleton (const Singleton&) = delete;
    static Singleton* GetInstance() {
        static Singleton* m_instance = nullptr;
        if (m_instance == nullptr) {
            m_instance = new Singleton();
        }
        return m_instance;
    }
    int Finction() {
        return rand();
    }
private:
    Singleton() {};
};

int main()
{
    cout << 5["abxdef"] << endl;
    Singleton* lazy_s = Singleton::GetInstance();
    
    cout << lazy_s->Finction() << endl;

    return 0;
}