# include <stdlib.h>
# include <stdio.h>

double motor_a8[] = {2,8,12,10,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
double motor_b6[] = {2,8,12,10,7,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0};
double motor_c6[] = {2,8,13,10,8,7,5,5,5,5,5,5,5,5,5,5,5,5,5,5};

// Return thrust in Newtons
double thrust(double *motor, double time, double delta_t) {
    int index;
    int max_index = 20;
    double ret;
    double motor_delta_t = 0.1;

    index = (int) (time / motor_delta_t);

    if (index < max_index) {
        ret = motor[index];
    }
    else {
        ret = 0;
    }

    return ret;
}

