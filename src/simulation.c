# include <stdio.h>
# include <string.h>
# include "physics.h"
# include "motors.h"
# include "simulation.h"
# include "messages.h"

void simulation(double mass, double diam, double cd, double wind, double dt) {

    long int counter = 0;
    double time, acc, grav, dra, total_acceleration, impulse;
    int direction = 1;
    double rho = 1.225; // kg/m³
    double radius = diam / 2.0;
    double surface = 3.14159 * radius * radius;
    double altitude = 0;
    double speed = 0;
    double old_speed = 0;
    double delta_t = dt;

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
        if (counter++ % (int) (1 / delta_t) == 0) {
            //print_banner();
        }

        impulse = thrust(motor_c6, time);
        acc = acceleration(impulse, mass, altitude);
        grav = gravity(altitude);
        dra = drag(cd, rho, speed, surface) / mass;

        if (speed < 0) {
            direction = -1;
        }

        total_acceleration = acc - grav - direction * dra;

        //print_in_flight_statistics(time, altitude, total_acceleration, speed);

        if (total_acceleration < 0 && !burnout_reached) {
            burnout_time = time;
            burnout_reached = 1;
        }

        if (total_acceleration > max_acceleration) {
            max_acceleration = total_acceleration;
        }

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

    if (simulation_complete) print_simulation_completed();
    else print_simulation_not_completed();

    print_post_flight_statistics(flight_time, burnout_time, coast_time,
            apogee_time, max_altitude, max_speed, max_acceleration);
}

