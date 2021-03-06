#include <iostream>
#include <memory>
#include <vector>

using namespace std;
class Vehicle {

public:
    std::string name() { return name_; }
    int number_of_wheels() { return number_of_wheels_; }
    std::string propulsion_type() { return propulsion_type_; }
    double max_speed() { return max_speed_; }

    virtual ~Vehicle() = default;

protected:
    Vehicle(const std::string &name, int number_of_wheels,
            const std::string &propulsion_type, double max_speed)
      : name_(name), number_of_wheels_(number_of_wheels),
        propulsion_type_(propulsion_type), max_speed_(max_speed) {}


    std::string name_;
    int number_of_wheels_;
    std::string propulsion_type_;
    double max_speed_;
};



class Bike : public Vehicle {

public:
    Bike() : Vehicle("Bike", 2, "Muscles", 30) {}
};


class Car : public Vehicle {

public:
    Car(const std::string &name, const std::string &propulsion_type,
        double max_speed, bool has_abs)
        : Vehicle(name, 4, propulsion_type, max_speed),
          has_abs_(has_abs) {}

    bool has_abs() { return has_abs_; }

private:
    bool has_abs_;
};


int main()
{

    Bike bike;
      std::cout << bike.max_speed() << std::endl; // Will print 30
      std::unique_ptr<Vehicle> skoda_superb_as_vehicle = std::make_unique<Car>("Skoda Superb", "Gasoline", 200, true);

      Car *skoda_superb_as_vehicle_ = dynamic_cast<Car *>(skoda_superb_as_vehicle.get());
      Car passat("Volkswagen Passat", "Diesel", 200, true);

      std::cout << "Name: " << passat.name() << std::endl;
      std::cout << "Name: " << skoda_superb_as_vehicle->name() << std::endl;
      std::cout << "Has ABS: " << skoda_superb_as_vehicle_->has_abs() << std::endl;






//    std::vector<std::unique_ptr<int>> some_pointers;
//    auto number = std::make_unique<int>();
//    some_pointers.emplace_back(std::move(number));

//    std::unique_ptr<int> number_ = std::make_unique<int>(6);
//    std::cout <<"value is: "<<*number_<< endl;
    return 0;
}
