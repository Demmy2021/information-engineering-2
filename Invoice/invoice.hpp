#pragma once
#include <iostream>
#include <vector>

class Item{
    std::string name;
    double unit_net_price;
    char VAT_type;
    int amount_sold;

public:

    Item(std::string n = " ", double unp = 0.0, char VAT_t =' ', int ams = 0.0);
    std::string get_name();
    double get_price();
    char get_vat();
    int get_amount();

};

class Invoice{
    std::string seller_nip;
    std::string buyer_nip;
    std::vector<Item> items;

public:
    Invoice(std::string s = "0", std::string b = "0");

    void add_item(const Item &item);
    friend std::ostream &operator<<(std::ostream &str, Invoice &rhs);

};


