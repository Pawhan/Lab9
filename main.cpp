#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int factorial(int n)
{
    int sum=1;
    for(int i=1;i<=n;i++)
    {
        sum*=i;
    }
    return sum;
}
class Food
{
protected:
    string name;
    float price;
    float volume;
public:
    explicit Food( string n="Alcohol", float c=1, float o=1)
    {
        name=move(n);
        price=c;
        volume=o;
    }
    virtual string write_out()=0;
    virtual float get_volume()=0;
    virtual float get_alcohol_concentration()=0;
    virtual float get_costs()=0;
};
class Beer :public Food
{
    string name;
    float alcohol_concentration;
    string color;
public:
    explicit Beer( string nz="Heineken",string k="Light", float w=5,string n="Alcohol",float c=2.8,float o=1.5):Food(move(n),c,o)
    {
        name=move(nz);
        color=move(k);
        alcohol_concentration=w;
    }
    ~Beer()
    {
        cout<<"Cleaned  ";
    }
    void Write_out()
    {
        cout<<name<<"  /  "<<color<<" /   Percentage   "<<alcohol_concentration<<" / "<<Food::name<<"  /  Price  "<<price<<"   /  Volume  "<<volume<<endl;
    }
    string write_out() override
    {
        return name;
    }
    float get_volume() override
    {
        return volume;
    }
    float get_alcohol_concentration() override
    {
        return alcohol_concentration;
    }
    float get_costs() override
    {
        return price;
    }
};
class Vodka :public Food
{
    string name;
    float alcohol_concentration;
    string made_of;
public:
    explicit Vodka(string nz="Absolute",string m="Potatoes", float w=40,string n="Alcohol",float c=32,float o=4):Food(move(n),c,o)
    {
        name=move(nz);
        made_of=move(m);
        alcohol_concentration=w;
    }
    ~Vodka()
    {
        cout<<"Cleaned   ";
    }
    void Write_out()
    {
        cout<<name<<" /   Percentage  "<<alcohol_concentration<<"  /  "<<made_of<<" /   "<<Food::name<<"  /  Price   "<<price<<"   / Volume  "<<volume<<endl;
    }
    string write_out() override
    {
        return name;
    }
    float get_volume() override
    {
        return volume;
    }
    float get_alcohol_concentration() override
    {
        return alcohol_concentration;
    }
    float get_costs() override
    {
        return price;
    }
};
class Orangeade :public Food
{
    string name;
    string taste;
public:
    explicit Orangeade(string nz="Helena",string s="Orange",string n="Drinks",float c=4.3,float o=2.5):Food(move(n),c,o)
    {
        name=move(nz);
        taste=move(s);
    }
    ~Orangeade()
    {
        cout<<"Cleaned    ";
    }
    void Write_out()
    {
        cout<<name<<"   /  "<<taste<<"  /  "<<Food::name<<" /   Price  "<<price<<" /  Volume "<<volume<<endl;
    }
    string write_out() override
    {
        return name;
    }
    float get_volume() override
    {
        return volume;
    }
    float get_alcohol_concentration() override
    {
        return 0;
    }
    float get_costs() override
    {
        return price;
    }
};
class Crisps :public Food
{
    string name;
    string taste;
public:
    explicit Crisps(string nz="Lays",string s="Green Onion",string n="Snacks",float c=5.6,float o=2):Food(move(n),c,o)
    {
        name=move(nz);
        taste=move(s);
    }
    ~Crisps()
    {
        cout<<"Cleaned   ";
    }
    void Write_out()
    {
        cout<<name<<"  /   "<<taste<<"   /   "<<Food::name<<"   /   Price  "<<price<<"  / Volume   "<<volume<<endl;
    }
    string write_out() override
    {
        return name;
    }
    float get_volume() override
    {
        return volume;
    }
    float get_alcohol_concentration() override
    {
        return 0;
    }
    float get_costs() override
    {
        return price;
    }
};
class Backpack
{
public:
    float capacity;
    vector<Food*>products;
    explicit Backpack(float poj=50)
    {
        capacity=poj;
    }
    ~Backpack()
    {
        cout<<"Cleaned   ";
    }
    void Write_out_capacity()
    {
        cout<<"Backpack capacity  "<<capacity<<endl;
    }
    void DecreaseCapacity()
    {
        int length=products.size();
        capacity-=products[length-1]->get_volume();
    }
    int Is_Place()
    {
        if(capacity>1.5)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int  Is_Full()
    {
        if(capacity<1.5)
            return 1;
        else
            return 0;
    }
    void Add(Food *wsk)
    {
        if(Is_Place())
        {
            products.emplace_back(wsk);
        }
    }
    void Write_out_content()
    {
        cout<<"Backpack contents "<<endl;
        for(auto &i: products) {
            cout<<i->write_out()<<" , ";
        }
        cout<<endl;
    }
    float get_current_alcohol_concentration()
    {
        int length=products.size();
        float temp=0;
        if(length!=0) {
            for (int i = 0; i < length; i++) {
                temp += (products[i]->get_alcohol_concentration()) / 40;
            }
        }
        return temp;
    }
    float Backpack_value()
    {
        int length=products.size();
        float temp=0;
        if(length!=0) {
            for (int i = 0; i < length; i++) {
                temp += (products[i]->get_costs());
            }
        }
        return temp;
    }
};
class Human
{
public:
    int age;
    float weight;
    int year_of_studies;
    float juvenile_protection_rate;
    float money;
    explicit Human(int a=19, float w=120, int y=1, float j=25, float m=150)
    {
        age=a;
        weight=w;
        year_of_studies=y;
        juvenile_protection_rate=j;
        money=m;
    }
    ~Human()
    {
        cout<<"Cleaned   ";
    }
    float get_maximum_alcohol_concentration()
    {
        return (0.2*weight + juvenile_protection_rate + 0.1*factorial(year_of_studies))/age;
    }
    float get_current_alcohol_limit(Backpack &backpack)
    {
        float temp=get_maximum_alcohol_concentration();
        temp-=backpack.get_current_alcohol_concentration();
        return temp;
    }
    float get_current_money_amount(Backpack &backpack)
    {
        float temp=money;
        temp-=backpack.Backpack_value();
        return temp;
    }
};
int main() {
    int a;
    Food *wsk;
    Backpack backpack;
    Beer beer;
    Vodka vodka;
    Orangeade drink;
    Crisps snack;
    Human student;
    beer.Write_out();
    vodka.Write_out();
    drink.Write_out();
    snack.Write_out();
    backpack.Write_out_capacity();
    while (backpack.Is_Place()) {
        if (backpack.Is_Full()==1) {
            cout << "Backpack is full " << endl;
        }
        cout<<"Tell me what to do"<<endl;
        cout<<"Pick 1 to put beer in the backpack"<<endl;
        cout<<"Pick 2 to put vodka in the backpack"<<endl;
        cout<<"Pick 3 to put orangeade in the backpack"<<endl;
        cout<<"Pick 4 to put crisps in the backpack"<<endl;
        cout<<"Pick 5 to end shopping"<<endl;
        cin>>a;
        switch(a)
        {
            case 1:
                if(backpack.capacity>=1.5 and student.get_current_alcohol_limit(backpack)>=beer.get_alcohol_concentration()/40 and student.get_current_money_amount(backpack)>=beer.get_costs())
                {
                    wsk = &beer;
                    backpack.Add(wsk);
                    backpack.Write_out_content();
                    backpack.DecreaseCapacity();
                    backpack.Write_out_capacity();
                }
                else
                {
                    if(backpack.capacity<1.5) {
                        cout << "Not enough space in the backpack" << endl;
                    }
                    else if(student.get_current_alcohol_limit(backpack)<beer.get_alcohol_concentration()/40)
                    {
                        cout<<"You can buy more alcohol , you will be drunk"<<endl;
                    }
                    else
                    {
                        cout<<"You can't buy more   you got no money"<<endl;
                    }
                    backpack.Write_out_capacity();
                }
                break;
            case 2:
                if(backpack.capacity>=4 and student.get_current_alcohol_limit(backpack)>=vodka.get_alcohol_concentration()/40 and student.get_current_money_amount(backpack)>=vodka.get_costs())
                {
                    wsk = &vodka;
                    backpack.Add(wsk);
                    backpack.Write_out_content();
                    backpack.DecreaseCapacity();
                    backpack.Write_out_capacity();
                    cout<<student.get_current_alcohol_limit(backpack)<<endl;
                }
                else
                {
                    if(backpack.capacity<4) {
                        cout << "Not enough space in the backpack" << endl;
                    }
                    else if(student.get_current_alcohol_limit(backpack)<vodka.get_alcohol_concentration()/40)
                    {
                        cout<<"You can buy more vodka , maybe try beer"<<endl;
                    }
                    else
                    {
                        cout<<"You can't buy more   you got no money"<<endl;
                    }
                    backpack.Write_out_capacity();
                }
                break;
            case 3:
                if(backpack.capacity>=2.5 and student.get_current_money_amount(backpack)>=drink.get_costs())
                {
                    wsk = &drink;
                    backpack.Add(wsk);
                    backpack.Write_out_content();
                    backpack.DecreaseCapacity();
                    backpack.Write_out_capacity();
                }
                else
                {
                    if (backpack.capacity<2.5) {
                        cout << "Not enough space in the backpack" << endl;
                    }
                    else
                    {
                        cout<<"You can't buy more   you got no money"<<endl;
                    }
                    backpack.Write_out_capacity();
                }
                break;
            case 4:
                if(backpack.capacity>=2 and student.get_current_money_amount(backpack)>=snack.get_costs())
                {
                    wsk = &snack;
                    backpack.Add(wsk);
                    backpack.Write_out_content();
                    backpack.DecreaseCapacity();
                    backpack.Write_out_capacity();
                }
                else
                {
                    if (backpack.capacity<2) {
                        cout << "Not enough space in the backpack" << endl;
                    }
                    else
                    {
                        cout<<"You can't buy more   you got no money"<<endl;
                    }
                    backpack.Write_out_capacity();
                }
                break;
            case 5:
                cout<<"Shopping ended"<<endl;
                if(backpack.capacity!=50) {
                    sort(backpack.products.begin(), backpack.products.end(), greater<>());
                    backpack.Write_out_content();
                    cout<<"You spent   "<<student.money-student.get_current_money_amount(backpack)<<endl;
                }
                return 0;
            default:
                cout<<"Wrong button picked"<<endl;
                backpack.Write_out_capacity();
                break;
        }
    }
    cout<<"Backpack is full"<<endl;
    sort(backpack.products.begin(),backpack.products.end(),greater<>());
    backpack.Write_out_content();
    cout<<"You spent   "<<student.money-student.get_current_money_amount(backpack)<<endl;
    return 0;
}