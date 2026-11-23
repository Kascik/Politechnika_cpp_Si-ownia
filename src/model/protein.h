#pragma once
#include "model/product.h"


class Protein : public Product {
    int weightG_;  //weight in grams
    int servingG_;
    std::string proteinType_;

public:
    Protein(int id, std::string name, std::string brand, int priceGr, int stock, int weightG. int servingG, std::string proteinType)
        : Product(id, std::move(name), std::move(brand), priceGr, stock),
    weightG_(weightG), servingG_(servingG), proteinType_(std::move(proteinType)) {}

    std::string typeName() const override { return "Białko"; }
     int servings() const override {return servingG_ > 0 ? weightG_ / servingG_ : 0;}
    std::string details() const override {
        return proteinType_ + " | " + std::to_string(weightG_) + " g | porcja" + std::to_string(servingG_) + " g";
    }
    std::string toFile() const override {
        return "PROTEIN;" + baseToFile() + ";" + std::to_string(weightG_) + ";" + std::to_string(servingG_) + ";" + proteinType_;
    }
};