# include <stdio.h>
# include "physics.h"
# include "motors.h"

void simulation( double mass, double diam, double cd, double avgimp,
        double totimp, double wind, double duration) {

    long int counter = 0;
    double time;
    double acc;
    double impulse;
    double altitude = 0;
    double speed = 0;
    double old_speed = speed;
    double delta_t = 0.1;

    void print_banner(void) {
        printf("+------------+-----------+--------------+-------------+\n");
        printf("|  Time (s)  |  Alt (m)  | Accel (m/s2) | Speed (m/s) |\n");
        printf("+------------+-----------+--------------+-------------+\n");
    }

    // Keep stats about flight
    double max_altitude = 0;
    double max_speed = 0;
    double max_acceleration = 0;
    double flight_time = 0;
    double apogee_time = 0;

    for (time=0; time<=duration; time+=delta_t) {
        if (counter % 30 == 0) print_banner();
        counter++;
        impulse = thrust(motor, time, delta_t);
        acc = acceleration(impulse, mass, altitude);
        if (acc > max_acceleration) max_acceleration = acc;
        printf("|%10.2lf  |%9.1lf  |%12.2lf  |%11.2lf  |\n",
                time, altitude, acc, speed);
        old_speed = speed;
        speed = new_speed(speed, acc, delta_t);
        if (speed > max_speed) max_speed = speed;
        altitude = altitude + delta_t * (old_speed + speed) / 2;
        if (altitude > max_altitude) max_altitude = altitude;
        if (counter > 1 && altitude <= 0)
            break;
    }

    flight_time = time;
    // TODO Print flight stats
}

