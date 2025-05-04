#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
int mod=998244353;
class Pizza{
    public: 
        virtual int cost() = 0;  
};
class VeggieDelight: public Pizza{
    public: 
        int cost(){
            return 100;
        }
};
class Margherita: public Pizza{
    public: 
        int cost(){
            return 120;
        }
};
class Toppings: public Pizza{
};
class ExtraCheese: public Toppings{
    public: 
        Pizza* pizza;
        ExtraCheese(Pizza* pizza){
            this->pizza = pizza;
        }
        int cost(){
            return pizza->cost() + 15;
        }
};
class Jalapeno: public Toppings{
    public: 
        Pizza* pizza;
        Jalapeno(Pizza* pizza){
            this->pizza = pizza;
        }
        int cost(){
            return pizza->cost() + 25;
        }
};
class ExtraVeggies: public Toppings{
    public: 
        Pizza* pizza;
        ExtraVeggies(Pizza* pizza){
            this->pizza = pizza;
        }
        int cost(){
            return pizza->cost() + 35;
        }
};
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Pizza* veggieDelight = new VeggieDelight();
    Pizza* margherita = new Margherita();
    
    cout<<"Cost of Veggie Delight: "<<veggieDelight->cost()<<"\n";
    cout<<"Cost of Margherita: "<<margherita->cost()<<"\n";
    
    Pizza* extraCheese = new ExtraCheese(veggieDelight);
    cout<<"Cost of extra Cheese Veggie Delight pizza: "<<extraCheese->cost()<<"\n";
    
    Pizza* extraCheeseJalapeno = new Jalapeno(extraCheese);
    cout<<"COst of extra Cheese and Jalapeno Veggie Delight Pizza: "<<extraCheeseJalapeno->cost()<<"\n";
    
    Pizza* extraCheeseJalapenoVeggies = new ExtraVeggies(extraCheeseJalapeno);
    cout<<"COst of extra Cheese, Veggies and Jalapeno Veggie Delight Pizza: "<<extraCheeseJalapenoVeggies->cost()<<"\n";
    
    Pizza* extraCheeseVeggies = new ExtraVeggies(extraCheese);
    cout<<"COst of extra Cheese and Veggies Veggie Delight Pizza: "<<extraCheeseVeggies->cost()<<"\n";
}
