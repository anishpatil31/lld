#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
int mod=998244353;
class Observer{
    public:
        virtual void update() = 0;
};
class Observable{
    public:
      virtual void plus(Observer* observerObj) = 0;  
      virtual void minus(Observer* observerObj) = 0;  
      virtual void notify() = 0;  
      virtual string getData() = 0;  
      virtual void setData(int newStockCount) = 0;  
};
class EmailObserver: public Observer{
  public:
    string emailID;
    Observable* observableObj;
    EmailObserver(string emailID, Observable* observableObj){
        this->emailID = emailID;
        this->observableObj = observableObj;
    }
    void update(){
        cout<<"sending email to "<<emailID<<" that "<<observableObj->getData()<<" have been added\n";
    }
};
class SMSObserver: public Observer{
  public:
    string phoneNumber;
    Observable* observableObj;
    SMSObserver(string phoneNumber, Observable* observableObj){
        this->phoneNumber = phoneNumber;
        this->observableObj = observableObj;
    }
    void update(){
        cout<<"sending SMS to "<<phoneNumber<<" that "<<observableObj->getData()<<" have been added\n";
    }
};
class IphoneObservable: public Observable{
    public:
        set <Observer*> observerList;
        int stockCount=0;
        void plus(Observer* obj){
            observerList.insert(obj); 
        }
        void minus(Observer* obj){
            observerList.erase(observerList.find(obj));
        }
        void notify(){
            for(auto it: observerList){
                it->update();
            }
        }
        string getData(){
            string s = to_string(stockCount) + " units of iPhone";
            return s;
        }
        void setData(int newStockCount){
            stockCount+=newStockCount;
            if(stockCount-newStockCount == 0 && newStockCount > 0){
                notify();
            }
        }
};
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Observable* iphoneObj = new IphoneObservable();
    
    Observer* emailObserver = new EmailObserver("abc@123.com", iphoneObj);
    iphoneObj->plus(emailObserver);
    Observer* smsObserver = new SMSObserver("12345", iphoneObj);
    iphoneObj->plus(smsObserver);
    Observer* emailObserver2 = new EmailObserver("def@456.com", iphoneObj);
    iphoneObj->plus(emailObserver2);
    
    iphoneObj->setData(10);
    cout<<"\n";
    iphoneObj->setData(20);
    iphoneObj->setData(-30);
    iphoneObj->setData(100);
}
