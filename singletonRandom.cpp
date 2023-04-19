#include <iostream>
#include <ctime>
#include <iostream>
#include <memory>

class Randomer
{
public:
    Randomer(const Randomer&) = delete;
    Randomer& operator=(const Randomer&) = delete;
    static Randomer* getRandomer() {
        static std::unique_ptr<Randomer> m_randomer = nullptr;
        if (!m_randomer) {
            //m_randomer = std::make_unique<Renderer>();
            m_randomer = std::unique_ptr<Randomer>(new Randomer());
        }
        return m_randomer.get();
    }
    double getRenderDouble(double start = 0, double end = 10) {
        //Randomer* r = getRandomer();
        double df = end - start;
        double ra = lfsr113();
        double res = ra * df + start;
        return res;
    }
private:
    double lfsr113()
    {
        unsigned int b;
        b  = ((z1 << 6) ^ z1) >> 13;
        z1 = ((z1 & 4294967294U) << 18) ^ b;
        b  = ((z2 << 2) ^ z2) >> 27;
        z2 = ((z2 & 4294967288U) << 2) ^ b;
        b  = ((z3 << 13) ^ z3) >> 21;
        z3 = ((z3 & 4294967280U) << 7) ^ b;
        b  = ((z4 << 3) ^ z4) >> 12;
        z4 = ((z4 & 4294967168U) << 13) ^ b;
        return (z1 ^ z2 ^ z3 ^ z4) * 2.3283064365386963e-10;
    }
    Randomer() {
        unsigned int m_seed = time(NULL);
        z1 = m_seed;
        z2 = m_seed;
        z3 = m_seed;
        z4 = m_seed;
    }
    unsigned int z1;
    unsigned int z2;
    unsigned int z3;
    unsigned int z4;
};

int main() 
{
    std::cout << Randomer::getRandomer()->getRenderDouble() << std::endl;
    std::cout << Randomer::getRandomer()->getRenderDouble() << std::endl;
    std::cout << Randomer::getRandomer()->getRenderDouble() << std::endl;
    std::cout << Randomer::getRandomer()->getRenderDouble() << std::endl;
    
    return 0; 
}