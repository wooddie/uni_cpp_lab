#include <iostream>
#include <string>
#include <vector>

class Vehicle
{
private:
    std::string brand;
    int year;
    int mileage;

public:
    Vehicle(const std::string &v_brand, int v_year, int v_mileage)
        : brand(v_brand), year(v_year), mileage(v_mileage) {}

    virtual ~Vehicle() = default;

    std::string getBrand() const
    {
        return brand;
    }
    int getYear() const
    {
        return year;
    }
    int getMileage() const
    {
        return mileage;
    }

    virtual void printInfo() const
    {
        std::cout << "Brand: " << this->brand << std::endl;
        std::cout << "Year: " << this->year << std::endl;
        std::cout << "Mileage: " << this->mileage << std::endl;
    }
};

class Car : public Vehicle
{
private:
    int doors;
    bool isElectric;

public:
    Car(const std::string &c_brand, int c_year, int c_mileage, int c_doors, bool c_isElectric)
        : Vehicle(c_brand, c_year, c_mileage),
          doors(c_doors),
          isElectric(c_isElectric)
    {
    }

    void printInfo() const override
    {
        std::cout << "Car info:" << std::endl;
        Vehicle::printInfo();
        std::cout << "Doors: " << this->doors << std::endl;
        std::cout << std::boolalpha << "Is electric: " << this->isElectric << std::endl;
        std::cout << std::endl;
    }
};

class Bus : public Vehicle
{
private:
    int seats;

public:
    Bus(const std::string &b_brand, int b_year, int b_mileage, int b_seats)
        : Vehicle(b_brand, b_year, b_mileage),
          seats(b_seats) {}

    void printInfo() const override
    {
        std::cout << "Bus info:" << std::endl;
        Vehicle::printInfo();
        std::cout << "Seats: " << this->seats << std::endl;
        std::cout << std::endl;
    }
};

int main()
{
    Car car("Tesla model 3", 2025, 200, 4, true);
    car.printInfo();

    Bus bus("Li-Fan", 2020, 400, 15);
    bus.printInfo();

    std::vector<Vehicle *> garage;

    garage.push_back(new Car("Toyota mark 2", 2000, 3000, 4, false));
    garage.push_back(new Bus("Gaz", 1980, 10000, 14));

    for (auto v : garage)
    {
        v->printInfo();
        delete v;
        v = nullptr;
    }

    return 0;
}