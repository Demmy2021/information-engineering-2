#include <iostream>
#include <invoice.hpp>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>

Item::Item(std::string n, double unp, char VAT_t, int ams){
    name = n;
    unit_net_price = unp;
    VAT_type = VAT_t;
    amount_sold = ams;

}

Invoice::Invoice(std::string s, std::string b){
    seller_nip = s;
    buyer_nip = b;
}

void Invoice::add_item(const Item &item)
{
    items.emplace_back(item);
}

std::string Item::get_name(){
    return name;
}

double Item::get_price(){
    return unit_net_price;
};

char Item::get_vat(){
    return  VAT_type;
};

int Item::get_amount(){
    return amount_sold;
};

std::ostream &operator<<(std::ostream &str, Invoice &rhs){

    double net_sum = 0.0;
    double total = 0.0;
    int i = 1;

    str << "------------------VAT invoice------------------\n"
        << "===============================================\n"
        << "Seller:"<<rhs.seller_nip<<"              "<< "Buyer:"<< rhs.buyer_nip <<"\n"
        << "               c.j.   VAT    il.    net   total\n";
    for(auto item: rhs.items)
    {
        double p_net = item.get_price()*item.get_amount();
        double p_vat = 0.0;


        if(item.get_vat() == 'A') p_vat = p_net*(1.23);
        else if(item.get_vat() == 'B') p_vat = p_net*(1.08);
        else if(item.get_vat() == 'C') p_vat = p_net;


    str << i<<'.'<<item.get_name()<<std::setw(2)<<"   |  "<<std::setw(2)<<item.get_price()<<"  "<<std::setw(2)<<item.get_vat()<<"   |"<<std::setw(2)<<item.get_amount()<<"  |"<<std::setw(4)<<std::fixed<<std::setprecision(2)<<p_net<<"  |"<<std::setw(4)<<std::fixed<<std::setprecision(2)<<p_vat<<'\n';

        net_sum += p_net;
        total+=p_vat;
        i++;

    }

    str << "\n------------------------------------ TOTAL ----\n"
        << "                                  "<<std::fixed<<std::setprecision(2)<< net_sum <<'|'<<std::fixed<<std::setprecision(2)<<total;

    return str;
}
