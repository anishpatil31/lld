#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
enum SlotType{
    SMALL, 
    LARGE,
    EXTRA_LARGE,
    UNSPECIFIED,
};
enum VehicleType{
    CYCLE,
    BIKE,
    CAR,
    TEMPO,
    TRUCK,
    UNSPECIFIED_VEHICLE
};
class Slot{
    public:
        SlotType slotType;
        VehicleType vehicleType;
        int vehicleNumber;
        bool isFilled;
        Slot(SlotType slotType){
            this->slotType = slotType;
        }
};
class Floor{
    public :
        set <Slot*> slots;
        void addSlot(Slot* slot){
            slots.insert(slot);
        }
        void removeSlot(Slot* slot){
            slots.erase(slots.find(slot));
        }
        pair<bool, Slot*> parkVehicleInaSlot(SlotType requiredSlot, VehicleType vehicleType, int vehicleNumber, bool checkForRequiredSlot){
            for(auto it: slots){
                if((*it).isFilled){
                    continue;
                }
                if((*it).slotType != requiredSlot && checkForRequiredSlot){
                    continue;
                }
                (*it).vehicleType = vehicleType;
                (*it).vehicleNumber = vehicleNumber;
                (*it).isFilled = true;
                return {true, it};
            }
            Slot* undefinedSlot = new Slot(UNSPECIFIED);
            return {false, undefinedSlot};
        }
};
class ParkingLot{
    void loadSlotToVehicleMap(){
        slotToVehicleMap[SMALL] = {CYCLE, BIKE};
        slotToVehicleMap[LARGE] = {CAR, TEMPO};
        slotToVehicleMap[EXTRA_LARGE] = {TRUCK};
    }
    void loadVehicleToSlotMap(){
        vehicleToSlotMap[CYCLE]  = SMALL;
        vehicleToSlotMap[BIKE]  = SMALL;
        vehicleToSlotMap[CAR]  = LARGE;
        vehicleToSlotMap[TEMPO]  = LARGE;
        vehicleToSlotMap[TRUCK]  = EXTRA_LARGE;
    }
    void loadSlotWisePrices(){
        slotWisePrices[SMALL] = 2;
        slotWisePrices[LARGE] = 5;
        slotWisePrices[EXTRA_LARGE] = 7;
    }
    public :
        set <Floor*> floors;  
        map <SlotType, vector<VehicleType> > slotToVehicleMap;
        map <VehicleType, SlotType>vehicleToSlotMap;
        map <SlotType, int> slotWisePrices;
        map <int, Slot*> slotParkingMap;
        ParkingLot(){
            loadSlotToVehicleMap();
            loadVehicleToSlotMap();
            loadSlotWisePrices();
        }
        void addFloor(Floor* floor){
            floors.insert(floor);
        }
        void removeFloor(Floor* floor){
            floors.erase(floors.find(floor));
        }
        pair<bool, int> parkVehicle(VehicleType vehicleType, int vehicleNumber){
            SlotType slotType = vehicleToSlotMap[vehicleType];
            for(auto it: floors){
                pair <bool, Slot*> p;
                p = it->parkVehicleInaSlot(slotType, vehicleType, vehicleNumber, true);
                if(p.first){
                    slotParkingMap[vehicleNumber] = p.second;
                    return {true, slotWisePrices[p.second->slotType]};
                }
            }
            for(auto it: floors){
                pair <bool, Slot*> p;
                p = it->parkVehicleInaSlot(slotType, vehicleType, vehicleNumber, false);
                if(p.first){
                    slotParkingMap[vehicleNumber] = p.second;
                    return {true, slotWisePrices[p.second->slotType]};
                }
            }
            return {false, 0};
        }
        Slot* removeVehicle(int vehicleNumber){
            Slot* slot = slotParkingMap[vehicleNumber];
            slot->isFilled = false;
            slot->vehicleNumber = 0;
            slot->vehicleType = UNSPECIFIED_VEHICLE;
            return slot;
        }
};
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ParkingLot* parkingLot = new ParkingLot();
    pair <bool, int> p = parkingLot->parkVehicle(BIKE, 1353);
    cout<<"Is Vehicle Parked? "<<p.first<<"\n"<<"Cost of Parking: "<<p.second<<"\n\n";
    
    Slot* slot = new Slot(SMALL);
    Slot* slot2 = new Slot(LARGE);
    
    Floor* floor = new Floor();
    floor->addSlot(slot);
    floor->addSlot(slot2);
    
    parkingLot->addFloor(floor);
    
    p = parkingLot->parkVehicle(BIKE, 1353);
    cout<<"Is Vehicle Parked? "<<p.first<<"\n"<<"Cost of Parking: "<<p.second<<"\n\n";
    
    p = parkingLot->parkVehicle(CYCLE, 2312);
    cout<<"Is Vehicle Parked? "<<p.first<<"\n"<<"Cost of Parking: "<<p.second<<"\n\n";
    
    Slot* tempSlot = parkingLot->removeVehicle(1353);
    cout<<"Slot of type "<<tempSlot->slotType<<" has been freed\n\n";
    
    p = parkingLot->parkVehicle(BIKE, 2817);
    cout<<"Is Vehicle Parked? "<<p.first<<"\n"<<"Cost of Parking: "<<p.second<<"\n\n";
}
