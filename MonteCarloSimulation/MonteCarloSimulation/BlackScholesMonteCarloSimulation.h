#ifndef BLACKSCHOLESMONTECARLOSIMULATION_H
#define BLACKSCHOLESMONTECARLOSIMULATION_H

#include "MonteCarloSimulation.h"

class BlackScholesMonteCarloSimulation : public MonteCarloSimulation {
public:
    BlackScholesMonteCarloSimulation(int simulations, double rate, double vol, double initial, double strike, double maturity);
    double runSimulation() override;

private:
    double gaussianBoxMuller();
};

#endif  // BLACKSCHOLESMONTECARLOSIMULATION_H
