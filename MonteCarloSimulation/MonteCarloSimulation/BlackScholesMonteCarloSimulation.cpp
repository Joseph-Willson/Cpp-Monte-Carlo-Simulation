#include "BlackScholesMonteCarloSimulation.h"
#include <cmath>

BlackScholesMonteCarloSimulation::BlackScholesMonteCarloSimulation(int simulations, double rate, double vol, double initial, double strike, double maturity)
    : MonteCarloSimulation(simulations, rate, vol, initial, strike, maturity) {}

double BlackScholesMonteCarloSimulation::runSimulation() {
    double drift = (riskFreeRate - 0.5 * volatility * volatility) * timeToMaturity;
    double diffusion = volatility * sqrt(timeToMaturity);

    double randomValue = gaussianBoxMuller();
    double stockPrice = initialPrice * exp(drift + diffusion * randomValue);
    return stockPrice;
}

double BlackScholesMonteCarloSimulation::gaussianBoxMuller() {
    double x = 0.0;
    double y = 0.0;
    double euclidSq = 0.0;

    // Generate two uniform random variables until the square of their "euclidean distance" is less than unity
    do {
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        euclidSq = x * x + y * y;
    } while (euclidSq >= 1.0);

    return x * sqrt(-2 * log(euclidSq) / euclidSq);
}
