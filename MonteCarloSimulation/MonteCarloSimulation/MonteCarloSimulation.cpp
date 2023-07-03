#include "MonteCarloSimulation.h"
#include <cmath>
#include <algorithm>

MonteCarloSimulation::MonteCarloSimulation(int simulations, double rate, double vol, double initial, double strike, double maturity)
    : numSimulations(simulations), riskFreeRate(rate), volatility(vol), initialPrice(initial),
    strikePrice(strike), timeToMaturity(maturity) {}

double MonteCarloSimulation::calculateOptionCallPrice(double stockPrice) {
    double payoff = std::max(stockPrice - strikePrice, 0.0);
    double discountedPayoff = payoff * exp(-riskFreeRate * timeToMaturity);
    return discountedPayoff;
}

double MonteCarloSimulation::calculateOptionPutPrice(double stockPrice) {
    double payoff = std::max(stockPrice - strikePrice, 0.0);
    double discountedPayoff = payoff * exp(-riskFreeRate * timeToMaturity);
    return discountedPayoff;
}

double MonteCarloSimulation::estimateOptionCallPrice() {
    double totalPayoff = 0.0;
    for (int i = 0; i < numSimulations; ++i) {
        double stockPrice = runSimulation();
        double payoff = calculateOptionCallPrice(stockPrice);
        totalPayoff += payoff;
    }

    double optionPrice = totalPayoff / numSimulations;
    return optionPrice;
}

double MonteCarloSimulation::estimateOptionPutPrice() {
    double totalPayoff = 0.0;
    for (int i = 0; i < numSimulations; ++i) {
        double stockPrice = runSimulation();
        double payoff = calculateOptionCallPrice(stockPrice);
        totalPayoff += payoff;
    }

    double optionPrice = totalPayoff / numSimulations;
    return optionPrice;
}
