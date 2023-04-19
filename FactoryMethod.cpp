
#include <iostream>
#include <string>

using namespace std;

class Product
{
public:
    virtual string GetType() const = 0;
};
class Tank : public Product
{
public:
    virtual string GetType() const override {
        return "Tank";
    }
};
class Amx : public Product
{
public:
    virtual string GetType() const override {
        return "Amx";
    }
};

class Factory
{
public:
    virtual Product* FactoryMethod() const = 0;
    string OperationReport() const {
        Product* product = FactoryMethod();
        string report = "Working with " + product->GetType();
        delete product;
        return report;
    }
};
class FactoryOrleans : public Factory
{
public:
    virtual Product* FactoryMethod() const override {
        return new Tank;
    }
};
class FactoryLyon : public Factory
{
public:
    virtual Product* FactoryMethod() const override {
        return new Amx;
    }
};

void ClientCode(const Factory& factory) {
    cout << factory.OperationReport() << endl;
}

int main()
{
    Product* leclerc = new Tank();
    cout << leclerc->GetType() << endl;
    delete leclerc;
    
    Factory* f1 = new FactoryOrleans();
    Factory* f2 = new FactoryLyon();
    
    ClientCode(*f1);
    ClientCode(*f2);
    
    delete f1;
    delete f2;
    
    return 0;
}