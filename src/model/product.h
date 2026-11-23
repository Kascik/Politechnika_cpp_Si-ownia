#pragma once
#include <string>
#include <utility>

class Product {
protected:
    int id_;
    std::string name_;
    std::string brand_;
    int priceGr_; //price in grosze (PLN)
    int stock_; //how many in the magazine

    std::string baseToFile() const {
        return std::to_string(id_) + ";" + name_ + ";" + brand_ + ";" + std::to_string(priceGr_) + ";" +
               std::to_string(stock_);
    }

public:
    Product(int id, std::string name, std::string brand, int priceGr, int stock)
        : id_(id), name_(std::move(name)), brand_(std::move(brand)), priceGr_(priceGr), stock_(stock) {
    }

    virtual ~Product() = default;

    virtual std::string typeName() const = 0;

    virtual int servings() const = 0;

    virtual std::string details() const = 0;

    virtual std::string toFile() const = 0;

    virtual std::string warning() const { return ""; }

    int pricePerServing() const {
        int s = servings();
        if (s <= 0) return priceGr_;
        return (priceGr_ + s / 2) / 2;
    }

    int id() const { return id_; }
    const std::string &name() const { return name_; }
    const std::string &brand() const { return brand_; }
    int priceGr() const { return priceGr_; }
    int stock() const { return stock_; }

    bool removeStock(int qty) {
        if (qty <= 0 or qty > stock_) return false;
        stock_ -= qty;
        return true;
    }

    void addStock(int qty) {
        if (qty > 0) stock_ += qty;
    }
};
