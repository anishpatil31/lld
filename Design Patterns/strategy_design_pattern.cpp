#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
int mod=998244353;
class DriveInterface{
    public:
        virtual void drive() = 0;
};
class NormalDrive: public DriveInterface{
    public: 
        void drive() {
            cout<<"normal utility\n";
        }
};
class SpecialDrive: public DriveInterface{
    public:
        void drive() {
            cout<<"special utility\n";
        }
};
class Vehicle{
  public:
    DriveInterface* driveObj;
    
    virtual void drive() = 0;
    
    Vehicle(DriveInterface* obj): driveObj(obj){}
};
class SportsVehicle:public Vehicle{
    public:
        void drive(){
            driveObj->drive();
        }
        SportsVehicle() : Vehicle(new SpecialDrive()) {}
};
class PassengerVehicle:public Vehicle{
    public:
        void drive(){
            driveObj->drive();
        }
        PassengerVehicle(): Vehicle(new NormalDrive()) {}
};
class HimalayanVehicle:public Vehicle{
    public:
        void drive(){
            driveObj->drive();
        }
        HimalayanVehicle(): Vehicle(new SpecialDrive()){}
};
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Vehicle* passengerVehicleObj = new PassengerVehicle();
    passengerVehicleObj->drive();
    
    Vehicle* sportsVehicleObj = new SportsVehicle();
    sportsVehicleObj->drive();
    
    Vehicle* himalayanVehicleObj = new HimalayanVehicle();
    himalayanVehicleObj->drive();
}
