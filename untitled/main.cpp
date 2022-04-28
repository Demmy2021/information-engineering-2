

#include <iostream>
#include <SuperInvoice.h>
#include <vector>

Item::Item(std::string n, double p, char v, int a){
    name=n;
    price=p;
    vat=v;
    amount=a;
}

Invoice::Invoice(std::string s, std::string b){
    NIP_s=s;
    NIP_b=b;
}

void Invoice::add_item(const Item &item)
{
    items.emplace_back(item);
}

std::string Item::get_name(){
    return name;
}

double Item::get_price(){
    return price;
};

char Item::get_vat(){
    return vat;
};

int Item::get_amount(){
    return amount;
};

std::ostream &operator<<(std::ostream &str, Invoice &rhs){

    double net_sum=0;
    double total=0;
    int i=1;

    str << "------------------VAT invoice------------------\n"
        << "===============================================\n"
        << "Seller:"<<rhs.NIP_s<<"              "<< "Buyer:"<< rhs.NIP_b <<"\n"
        << "                  c.j. VAT   il.    net   total\n";
    for(auto item: rhs.items)
    {
        double p_net = item.get_price()*item.get_amount();
        double p_vat=0;

        if(item.get_vat() == 'A') p_vat = p_net*1.23;
        else if(item.get_vat() == 'B') p_vat = p_net*1.08;
        else if(item.get_vat() == 'C') p_vat = p_net;

    str << i<<'.'<<item.get_name()<<"       | "<<item.get_price()<<" "<<item.get_vat()<<" | "<<item.get_amount()<<" | "<<p_net<<" | " <<p_vat<<'\n';
        net_sum+=p_net;
        total+=p_vat;
        i++;
    }

    str << "\n------------------------------------ TOTAL ----\n"
        << "                                  "<<net_sum<<'|'<<total;

    return str;
}


#include <iostream>
#include <vector>

class Item{
    std::string name;
    double price;
    char vat;
    int amount;

public:
    Item(std::string n="", double p=0, char v=' ', int a=0);
    std::string get_name();
    double get_price();
    char get_vat();
    int get_amount();

};

class Invoice{
    std::string NIP_s;
    std::string NIP_b;
    std::vector<Item> items;

public:
    Invoice(std::string s="0", std::string b="0");

    void add_item(const Item &item);
    friend std::ostream &operator<<(std::ostream &str, Invoice &rhs);

};

#include <iostream>

class Time{
    int hrs;
    int min;
    int sec;
public:
    Time(int s=0);

    friend std::ostream &operator<<(std::ostream &str, Time &rhs);
    friend std::istream &operator>>(std::istream &str, Time &rhs);
    Time operator+(const Time &rhs) const;
    Time operator-(const Time &rhs) const;
    Time operator*(const int &scalar) const;
    operator int();
};



#include <iostream>
#include <Time.h>

Time::Time(int s){
    hrs = s/3600;
    s = s-(hrs*3600);
    min = s/60;
    s = s-(min*60);
    sec = s;
}


std::ostream &operator<<(std::ostream &str, Time &rhs)
{
    if(rhs.hrs!=0)
        str << rhs.hrs << "h";
    if(rhs.min!=0)
        str << rhs.min << "m";
    if(rhs.sec!=0)
        str << rhs.sec << "s";
    return str;
}

std::istream &operator>>(std::istream &str, Time &rhs)
{
    std:: cout << "Enter number of hours:";
    str >> rhs.hrs;
    std:: cout << "Enter number of minutes:";
    str >> rhs.min;
    std:: cout << "Enter number of seconds:";
    str >> rhs.sec;

    return str;
}

Time Time::operator+(const Time &rhs) const {
 return Time( ((hrs+rhs.hrs)*3600)+((min+rhs.min)*60) + sec+rhs.sec  );
}

Time Time::operator-(const Time &rhs) const {
 return Time( ((hrs-rhs.hrs)*3600)+((min-rhs.min)*60) + sec-rhs.sec  );
}

Time Time::operator*(const int &scalar) const {
    return Time( ((sec+(min*60)+(hrs*3600))*scalar) );
}

Time::operator int(){
    return int(sec+(min*60)+(hrs*3600));
}







#include <iostream>
#include <Time.h>
#include <SuperInvoice.h>


int main()
{
    Time t1(200);
    std::cout << t1 << std::endl; // displays 03m:20s
    Time t2;
    std::cin >> t2; // user enters 10h:12m:01s

    Time t3 = t2 - t1; // 10h:8m:41s
    int t3s = t3; // 36521
    std::cout << t3s << std::endl;

    std::cout << "\n\n";
    Invoice inv("7770003699", "0123456789");
    inv.add_item(Item("M3 screw", 0.37, 'A', 100));
    inv.add_item(Item("2 mm drill", 2.54, 'B', 2));
    std::cout << inv << std::endl;
}
