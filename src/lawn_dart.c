# include <stdio.h>
# include <stdlib.h>
# include "simulation.h"
# include "physics.h"
# include "help.h"

int main(int argc, char *argv[]) {
    int ret = 0;

    if (argc <= 5) {
        help();
        
        ret = 1;
    }
    else {
        // TODO
        // - Pass arvg[] directly to simulation?
        // - Create struct to hold arguments?
        double mass =     atof(argv[1]);
        double diam =     atof(argv[2]);
        double cd =       atof(argv[3]);
        double wind =     atof(argv[4]);
        double duration = atof(argv[5]);

        simulation(mass, diam, cd, wind, duration);
        ret = 0;
    }
    return ret;
}
