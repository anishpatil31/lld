#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
int mod=998244353;
class Vehicle{
    public:
        virtual void name() = 0;  
};
class Audi: public Vehicle{
    public: 
        void name(){
            cout<<"This is Audi\n";
        }
};
class Mercedes: public Vehicle{
    public:
        void name(){
            cout<<"This is Mercedes\n";
        }
};
class Swift: public Vehicle{
    public:
        void name(){
            cout<<"This is Swift\n";
        }
};
class Seltos: public Vehicle{
    public:
        void name(){
            cout<<"This is Kia Seltos\n";
        }
};
class VehicleTypes{
    public:
        virtual Vehicle* getVehicle(string vehicleType) = 0;
};
class LuxuryVehicle: public VehicleTypes{
    public:
        Vehicle* getVehicle(string vehicleType){
            Vehicle* vehicle;
            if(vehicleType == "AUDI"){
                vehicle = new Audi();
            } else if(vehicleType == "MERCEDES"){
                vehicle = new Mercedes();
            }
            return vehicle;
        }
};
class BudgetVehicle: public VehicleTypes{
    public:
        Vehicle* getVehicle(string vehicleType){
            Vehicle* vehicle;
            if(vehicleType == "SWIFT"){
                vehicle = new Swift();
            } else if(vehicleType == "SELTOS"){
                vehicle = new Seltos();
            }
            return vehicle;
        }
};
class VehicleFactory{
    public: 
        VehicleTypes* getVehicleType(string factoryType){
            VehicleTypes* factory;
            if(factoryType == "BudgetVehicle"){
                factory = new BudgetVehicle();
            } else if(factoryType == "LuxuryVehicle"){
                factory = new LuxuryVehicle();
            }
            return factory;
        }
};
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    VehicleFactory* vehicleFactoryObj = new VehicleFactory();
    VehicleTypes* vehicleTypesObj = vehicleFactoryObj->getVehicleType("LuxuryVehicle");
    Vehicle* vehicleObj = vehicleTypesObj->getVehicle("MERCEDES");
    vehicleObj->name();
    
    VehicleFactory* vehicleFactoryObj2 = new VehicleFactory();
    VehicleTypes* vehicleTypesObj2 = vehicleFactoryObj2->getVehicleType("BudgetVehicle");
    Vehicle* vehicleObj2 = vehicleTypesObj2->getVehicle("SELTOS");
    vehicleObj2->name();
}
