# include <stdio.h>
# include <string.h>
# include "physics.h"
# include "motors.h"

void simulation(double mass, double diam, double cd, double wind, double dt) {

    long int counter = 0;
    double time;
    double acc;
    double grav;
    double dra;
    double total_acceleration;
    double impulse;
    int direction = 1;
    double rho = 1.225; // kg/m³
    double radius = diam / 2.0;
    double surface = 3.14159 * radius * radius;
    double altitude = 0;
    double speed = 0;
    double old_speed = 0;
    double delta_t = dt;

    void print_banner(void) {
        //printf("+------------+-----------+--------------+-------------+\n");
        //printf("|  Time (s)  |  Alt (m)  | Accel (m/s2) | Speed (m/s) |\n");
        //printf("+------------+-----------+--------------+-------------+\n");
        printf("#  Time (s)  |  Alt (m)  | Accel (m/s2) | Speed (m/s) |\n");
    }

    // Keep stats about flight
    double max_altitude = 0;
    double max_speed = 0;
    double max_acceleration = 0;
    double flight_time = 0;
    double apogee_time = 0;
    double burnout_time = 0;
    double coast_time = 0;
    int burnout_reached = 0;
    int simulation_complete = 0;

    for (time=0; ; time+=delta_t) {
        if (counter % (int) (1 / delta_t) == 0) {
            ;
            //print_banner();
        }

        counter++;

        impulse = thrust(motor_c6, time, delta_t);
        acc = acceleration(impulse, mass, altitude);
        grav = gravity(altitude);
        dra = drag(cd, rho, speed, surface) / mass;

        if (speed < 0) {
            direction = -1;
        }

        total_acceleration = acc - grav - direction * dra;
        //printf("Acc: %6.2lf, Grav: %6.2lf, Drag: %6.2lf\n",
        //        acc, grav, direction * dra);

        if (total_acceleration < 0 && !burnout_reached) {
            burnout_time = time;
            burnout_reached = 1;
        }

        if (total_acceleration > max_acceleration) {
            max_acceleration = total_acceleration;
        }

        //printf("|%10.2lf  |%9.1lf  |%12.2lf  |%11.2lf  |\n",
        //        time, altitude, total_acceleration, speed);
        old_speed = speed;
        speed = new_speed(speed, total_acceleration, delta_t);

        if (speed > max_speed) {
            max_speed = speed;
        }

        altitude = altitude + delta_t * (old_speed + speed) / 2;

        if (altitude > max_altitude) {
            max_altitude = altitude;
            apogee_time = time;
            coast_time = time - burnout_time;
        }
        
        flight_time = time;

        if (counter > 1 && altitude <= 0) {
            simulation_complete = 1;
            break;
        }
    }
    printf("#------------+-----------+--------------+-------------+\n");

    if (simulation_complete) {
        puts("# The simulation completed");
        puts("#-------------------------");
    }
    else {
        puts(">>> WARNING! The simulation did not complete! <<<");
        puts(">>> Increase the maximum simulation duration. <<<");
        puts("#------------------------------------------------");
    }

    printf("# Flight duration:  %6.2lf s\n", flight_time);
    printf("# Burnout time:     %6.2lf s\n", burnout_time);
    printf("# Coast time:       %6.2lf s\n", coast_time);
    printf("# Time to apogee:   %6.2lf s\n", apogee_time);
    printf("# Falling time:     %6.2lf s\n", flight_time - apogee_time);
    printf("# Max altitude:     %6.2lf m\n", max_altitude);
    printf("# Max speed:        %6.2lf m/s\n", max_speed);
    printf("# Max acceleration: %6.2lf G\n", max_acceleration / 9.81);
}

