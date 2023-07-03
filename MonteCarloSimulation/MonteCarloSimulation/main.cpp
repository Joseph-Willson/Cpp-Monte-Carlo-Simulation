#include <algorithm>    // Needed for the "max" function
#include <cmath>
#include <iostream>
#include "BlackScholesMonteCarloSimulation.h"




int main() {
    int num_sims = 10000000;   // Number of simulated asset paths                                                       
    double S = 107.0;  // Option price                                                                                                                                                                   
    double r = 0.02;   // Risk-free rate (5%)                                                                           
    double sigma = 0.15;    // Volatility of the underlying (20%)                                                            
    double T = 1.0;    // One year until expiry
    double mu = r;
    double F = S * exp(mu * T);
    double K = F;  // Strike price

    double ITM = 1;

    K = ITM * F;


    BlackScholesMonteCarloSimulation simulation(num_sims, r, sigma, S, K, T);
    double optionCallPrice = simulation.estimateOptionCallPrice();
    double optionPutPrice = simulation.estimateOptionPutPrice();

    std::cout << "Estimated option call price: " << optionCallPrice << std::endl;
    std::cout << "Estimated option Put price: " << optionPutPrice << std::endl;

    return 0;
}

