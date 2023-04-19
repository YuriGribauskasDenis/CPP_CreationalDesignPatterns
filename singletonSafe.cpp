#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

class Singleton
{
public:
    Singleton(Singleton&) = delete;
    
    void operator=(const Singleton&) = delete;

    static Singleton* GetInstance(const string& value) {
        static Singleton* m_singleton = nullptr;
        static mutex mtx;
        //lock_guard<mutex> lck (mtx);
        mtx.lock();
        if(m_singleton == nullptr){
            m_singleton = new Singleton(value);
        }
        mtx.unlock();
        return m_singleton;
    }
    
    void SomeBusinessLogic()
    {
        // ...
    }

    const string& value() const {
        return m_value;
    }
    
private:
    Singleton(const string& value): m_value(value) {}

    string m_value;
};

void ThreadFoo(){
    // Following code emulates slow initialization.
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FOO");
    cout << singleton->value() << "\n";
}

void ThreadBar(){
    // Following code emulates slow initialization.
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    cout << singleton->value() << "\n";
}


int main()
{
    cout <<"If you see the same value, then singleton was reused (yay!\n" <<
            "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
            "RESULT:\n";
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}