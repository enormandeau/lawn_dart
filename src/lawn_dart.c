# include <stdio.h>
# include <stdlib.h>
# include "simulation.h"
# include "physics.h"
# include "help.h"

int main(int argc, char *argv[]) {
    int ret = 0;

    if (argc <= 4) {
        help();
        
        ret = 1;
    }
    else {
        double mass =     atof(argv[1]) / 1000; // g -> Kg
        double diam =     atof(argv[2]) / 1000; // mm -> m
        double cd =       atof(argv[3]);        // unit less
        double wind =     atof(argv[4]) / 3.6;  // km/h -> m/s
        double dt =       atof(argv[5]);        // seconds

        simulation(mass, diam, cd, wind, dt);
        ret = 0;
    }
    return ret;
}
