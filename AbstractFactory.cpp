
#include <iostream>
#include <string>

using namespace std;

class AbstractRadio
{
public:
    virtual string StatusUpdate() const = 0;
};
class ConcreteRadioFV420 : public AbstractRadio
{
public:
    virtual string StatusUpdate() const override {
        return "producing standart radio";
    }
};
class ConcreteRadioFV540 : public AbstractRadio
{
public:
    virtual string StatusUpdate() const override {
        return "producing powerful radio";
    }
};

class AbstractPlate
{
public:
    virtual string StatusUpdate() const = 0;
    virtual string StatusUpdate(const AbstractRadio&) const = 0;
};
class ConcretePlateShutz : public AbstractPlate
{
    virtual string StatusUpdate() const override {
        return "producing infman instructions";
    }
    virtual string StatusUpdate(const AbstractRadio& radio) const override {
        const string product = radio.StatusUpdate();
        return "infman plate put onto " + product;
    }
};
class ConcretePlateCaptain : public AbstractPlate
{
    virtual string StatusUpdate() const override {
        return "producing captain instructions";
    }
    virtual string StatusUpdate(const AbstractRadio& radio) const override {
        const string product = radio.StatusUpdate();
        return "captain plate put onto " + product;
    }
};

class AbstractPlant
{
public:
    virtual AbstractRadio* CreateRadio() const = 0;
    virtual AbstractPlate* CreatePlate() const = 0;
};
class ConcretePlantBayer : public AbstractPlant
{
public:
    virtual AbstractRadio* CreateRadio() const override {
        return new ConcreteRadioFV420();
    }
    virtual AbstractPlate* CreatePlate() const override {
        return new ConcretePlateShutz();
    }
};
class ConcretePlantMann : public AbstractPlant
{
    virtual AbstractRadio* CreateRadio() const override {
        return new ConcreteRadioFV540();
    }
    virtual AbstractPlate* CreatePlate() const override {
        return new ConcretePlateCaptain();
    }

};

void ClientCode(const AbstractPlant& factory) {
    const AbstractRadio *radio = factory.CreateRadio();
    const AbstractPlate *plate = factory.CreatePlate();
    cout << plate->StatusUpdate() << endl;
    cout << plate->StatusUpdate(*radio) << endl;
    delete radio;
    delete plate;
}

int main()
{
    cout << "Client code recieves first factory" << endl;
    ConcretePlantBayer *f1 = new ConcretePlantBayer();
    ClientCode(*f1);
    delete f1;
    cout << endl;
    cout << "Client code recieves second factory" << endl;
    ConcretePlantMann *f2 = new ConcretePlantMann();
    ClientCode(*f2);
    delete f2;


    return 0;
}