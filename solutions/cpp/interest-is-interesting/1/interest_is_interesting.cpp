double interest_rate(double balance) {
    if (balance < 0.0) {
        return 3.213;
    }else if (balance >= 0.0 && balance < 1000.0) {
        return 0.5;
    }else if (balance >= 1000.0 && balance < 5000.0) {
        return 1.621;
    }
    return 2.475;
}

double yearly_interest(double balance) {
    return balance * (interest_rate(balance)/100);
}

double annual_balance_update(double balance) {
    return balance + yearly_interest(balance);
}

int years_until_desired_balance(double balance, double target_balance) {
    int years{0};
    while (target_balance > balance) {
        years += 1;
        balance = annual_balance_update(balance);
    }
    return years;
}
