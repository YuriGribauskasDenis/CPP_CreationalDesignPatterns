#include <iostream>
using namespace std;

class Singleton
{
public:
    Singleton(const Singleton&) = delete;
    static Singleton& GetInstance()
    {
        return s_Instance;
    }
    void Function() {}
private:
    Singleton() {}
    // data
    static Singleton s_Instance;
};

Singleton Singleton::s_Instance;

int main() 
{
    //Singleton::GetInstance().Function();
    
    //Singleton instance = Singleton::GetInstance();
    Singleton& instance = Singleton::GetInstance();
    instance.Function();
    
    return 0; 
}