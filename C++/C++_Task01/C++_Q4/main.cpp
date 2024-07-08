#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double population = 162100;
    const double growth_rate = 0.065;
    int years = 0;

    // Loop to calculate years needed to reach a population of 1,000,000
    while (population < 1000000) {
        population *= (1 + growth_rate);
        cout << "Year " << years + 1 << ": Population = " << population << endl;
        years++;
    }
    
    cout << "Total years needed: " << years << endl;

    return 0;
}
