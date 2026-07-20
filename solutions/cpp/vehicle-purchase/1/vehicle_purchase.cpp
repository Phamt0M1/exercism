#include "vehicle_purchase.h"

namespace vehicle_purchase {

bool needs_license(std::string kind) {
    if (kind == "car" || kind == "truck") {
        return true;
    }
    return false;
}

std::string choose_vehicle(std::string option1, std::string option2) {
    std::string result{""};
    if (option1 < option2) {
        result = option1;
    }else {
        result = option2;
    }
    return result + " is clearly the better choice.";
}

double calculate_resell_price(double original_price, double age) {
    if (age < 3) {
        return original_price * 0.8;
    }else if (age < 10){
        return original_price * 0.7;
    }
    return original_price * 0.5;
}
}
