#include <iostream>

using namespace std;


class Vehicle{

  public:
    std::string name(){
        return name_;}

       int number_of_wheels() { return number_of_wheels_; }
       std::string propulsion_type() { return propulsion_type_; }
       double max_speed() {
           return max_speed_;
       }
public:
  std::string t_name() {
      return t_name_;
  }
       std::string proportion_type() { return proportion_type_; }
       std::string wheel_type() { return wheel_type_; }
       double power_rating() {
           return power_rating_;
       }

public:
  std::string type() {
      return type_;
  }
       double max_carriage_capacity() {
           return max_carriage_capacity_; }
       double aircraft_speed() {
           return aircraft_speed_;
       }

public:
      std::string mc_name(){
          return mc_name_;}
      std::string mc_type(){
      return mc_type_;}

      int carriage_capacity(){ return carriage_capacity_; }

protected:

       Vehicle(const std::string &name, int number_of_wheels,
                   const std::string &propulsion_type,  double max_speed): name_(name), number_of_wheels_(number_of_wheels),
               propulsion_type_(propulsion_type), max_speed_(max_speed) {}

           std::string name_;
           int number_of_wheels_;
           std::string propulsion_type_;
           double max_speed_;

protected:

       Vehicle(const std::string &t_name, const std::string &proportion_type,
               const std::string &wheel_type,double power_rating)
             : t_name_(t_name), proportion_type_(proportion_type),
               wheel_type_(wheel_type),power_rating_(power_rating) {}

           std::string t_name_;
           std::string proportion_type_;
           std::string wheel_type_;
           double power_rating_;

protected:

       Vehicle(const std::string &type, double max_carriage_capacity, double aircraft_speed)
             : type_(type), max_carriage_capacity_(max_carriage_capacity),
               aircraft_speed_(aircraft_speed){}

           std::string type_;
           double max_carriage_capacity_;
           double aircraft_speed_;

protected:

       Vehicle(const std::string &mc_name, const std::string &mc_type, int carriage_capacity)
             : mc_name_(mc_name), mc_type_(mc_type), carriage_capacity_(carriage_capacity){}

           std::string mc_name_;
           std::string mc_type_;
           int carriage_capacity_;

};
class Bike : public Vehicle{

   public :
    Bike() : Vehicle("bike", 2, "Muscle", 30){}
};


class Car : public Vehicle{
public :
    Car(const std::string &name, const std::string &propulsion_type,double max_speed, bool has_abs)
        : Vehicle(name, 4, propulsion_type, max_speed),has_abs_(has_abs){}
    bool has_abs(){
        return has_abs_;
    }
private:
    bool has_abs_;
};

class F1 : public Car{

public:

    F1(const std::string &name, double max_speed, float service_time)
        : Car(name, "Jaguar", max_speed, true), service_time_(service_time){}

    float service_time(){
        return service_time_;
          }
private: float  service_time_;
};

class Tractor : public Vehicle{

public :
    Tractor(const std::string &t_name,const std::string &proportion_type,
            const std::string &wheel_type,double power_rating, bool has_haulers):
    Vehicle(t_name, proportion_type, wheel_type, power_rating),has_haulers_(has_haulers){}
        bool has_haulers(){
            return has_haulers_;}
private:
       bool has_haulers_;

};

class Motorcycle : public Vehicle{

public:

   Motorcycle(const std::string &mc_name, const std::string &mc_type, int carriage_capacity,float service_time)
       : Vehicle(mc_name, mc_type, carriage_capacity), service_time_(service_time){}

    float service_time(){
        return service_time_;
          }
private: float  service_time_;
};

class Aircraft : public Vehicle{
public :
    Aircraft(const std::string &type, double max_carriage_capacity,
             double aircraft_speed, bool has_wings, bool has_landing_gear, bool has_rotor )
        : Vehicle(type,max_carriage_capacity, aircraft_speed),has_wings_(has_wings),
          has_landing_gear_(has_landing_gear), has_rotor_(has_rotor){}
    bool has_wings() {
         return has_wings_;}

    bool has_landing_gear() {
        return has_landing_gear_;}

    bool has_rotor() {
        return has_rotor_;}
private:
    bool has_wings_;
    bool has_landing_gear_;
    bool has_rotor_;
};

class Plane : public Aircraft{

public:

   Plane(const std::string &type, double max_carriage_capacity, double aircraft_speed, float service_time)
       : Aircraft(type, max_carriage_capacity, aircraft_speed, true,true,false), service_time_(service_time){}

    float service_time(){
        return service_time_;
          }

private: float  service_time_;
};

class Helicopter : public Aircraft{

public:

   Helicopter(const std::string &type, double max_carriage_capacity, double aircraft_speed, float service_time)
       : Aircraft(type, max_carriage_capacity, aircraft_speed, false, false, true), service_time_(service_time){}

    float service_time(){
        return service_time_;
          }

private: float  service_time_;
};



int main()
{
    Bike mybike;
    std::cout <<"----------------------------------"<<std::endl;
    std::cout <<"Bike Information" <<std::endl;
    std::cout<<mybike.max_speed()<<std::endl;

    Car mycar("Volkswagen Passat", "Diesel", 200, true);
    F1 myf1("Jaguar", 350, 2.5);

    std::cout <<"----------------------------------"<<std::endl;
    std::cout <<"F1 Car Information" <<std::endl;
    std::cout<<"Name of Car:"<< myf1.name() <<std::endl;
    std::cout<<"Speed of Car:"<<myf1.max_speed() <<std::endl;
    std::cout<<"Service Time:"<<myf1.service_time() <<std::endl;

    std::cout <<"----------------------------------"<<std::endl;
    std::cout <<"Car Information" <<std::endl;
    std::cout << "Name: " << mycar.name() << std::endl;
    std::cout << "Has ABS: " << mycar.has_abs() << std::endl;

    std::cout <<"----------------------------------"<<std::endl;
    std::cout <<"Tractor Information" <<std::endl;
    Tractor tractor("Compact", "Gasoline", "Tyre", 40, false);
    std::cout << "Name: " << tractor.t_name() << std::endl;
    std::cout << "Has Haulers: " << tractor.has_haulers() << std::endl;

    std::cout <<"----------------------------------"<<std::endl;
    std::cout <<"Motor Cycle Information" <<std::endl;
    Motorcycle motor_cycle("Suzuki", "Power Bike", 2 , 2.5);
    std::cout << "Name: " << motor_cycle.mc_name() << std::endl;
    std::cout << "Service Period: " << motor_cycle.service_time() << std::endl;

    std::cout <<"----------------------------------"<<std::endl;
    std::cout <<"Plane Information" <<std::endl;
    Plane plane("Airbus", 300, 250, 4.5);
    std::cout << "Name: " << plane.type() << std::endl;
    std::cout << "Has Wings: " << plane.has_wings() << std::endl;
    std::cout << "Has Landing gear: " << plane.has_landing_gear() << std::endl;
    std::cout << "Has Rotor: " << plane.has_rotor() << std::endl;

    std::cout <<"----------------------------------"<<std::endl;
    std::cout <<"Helicopter Information" <<std::endl;
    Helicopter helicopter("Chopper",20, 80,3.5);
    std::cout << "Name: " << helicopter.type() << std::endl;
    std::cout << "Has Wings: " << helicopter.has_wings() << std::endl;
    std::cout << "Has Landing gear: " << helicopter.has_landing_gear() << std::endl;
    std::cout << "Has Rotor: " << helicopter.has_rotor() << std::endl;

    return 0;
}
