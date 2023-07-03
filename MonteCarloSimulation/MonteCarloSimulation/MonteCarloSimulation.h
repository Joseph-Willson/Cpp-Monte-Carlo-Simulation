#ifndef MONTECARLOSIMULATION_H
#define MONTECARLOSIMULATION_H

class MonteCarloSimulation {
protected:
    int numSimulations;
    double riskFreeRate;
    double volatility;
    double initialPrice;
    double strikePrice;
    double timeToMaturity;

public:
    MonteCarloSimulation(int simulations, double rate, double vol, double initial, double strike, double maturity);
    virtual double runSimulation() = 0;
    double calculateOptionCallPrice(double stockPrice);
    double estimateOptionCallPrice();
    double calculateOptionPutPrice(double stockPrice);
    double estimateOptionPutPrice();
};

#endif  // MONTECARLOSIMULATION_H
