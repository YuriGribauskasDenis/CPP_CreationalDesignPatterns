#include <iostream>
#include <ctime>
using namespace std;


class Random
{
public:
    Random(const Random&) = delete;
    static Random& GetInstance(int userSeed = -1)
    {
        unsigned int seedValue;
        if (userSeed < 0)
            seedValue = (unsigned) time(NULL);
        else
           seedValue = (unsigned) userSeed;
        
        srand(seedValue);
        
        static Random Instance;
        return Instance;
    }
    int Integer(int low = 1, int high = 10)
    {
        return (rand() % high) + low;
    }
private:
    Random() {}
    // no data
};

int main() 
{
    Random& r = Random::GetInstance();
    for (int i = 0; i < 5; i++)
        cout << r.Integer() << endl;
    
    return 0; 
}