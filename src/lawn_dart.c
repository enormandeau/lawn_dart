# include <stdio.h>
# include <stdlib.h>
# include "simulation.h"
# include "physics.h"
# include "messages.h"

int main(int argc, char *argv[]) {
    int ret = 0;

    if (argc <= 4) {
        if (argc > 1) {
            print_not_enough_parameters();
        }
        print_help();
        
        ret = 1;
    }
    else if (argc > 5) {
        print_too_many_parameters();
        print_help();
        
        ret = 1;
    }
    else {
        double mass =     atof(argv[1]) / 1000; // g -> Kg
        double diam =     atof(argv[2]) / 1000; // mm -> m
        double cd =       atof(argv[3]);        // unit less
        double wind =     atof(argv[4]) / 3.6;  // km/h -> m/s
        double dt =       0.001; //atof(argv[5]);        // seconds

        simulation(mass, diam, cd, wind, dt);
        ret = 0;
    }

    return ret;
}

