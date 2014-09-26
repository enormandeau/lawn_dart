# include <stdio.h>
# include <string.h>
# include "physics.h"
# include "motors.h"

void simulation( double mass, double diam, double cd,
        double wind, double duration) {

    long int counter = 0;
    double time;
    double acc;
    double impulse;
    double direction = 1;
    double rho = 1;
    double surface = 3.14159 * diam*diam / 1000000;
    double altitude = 0;
    double speed = 0;
    double old_speed = speed;
    double delta_t = 0.05;

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
    int simulation_complete = 0;

    for (time=0; time<=duration; time+=delta_t) {
        if (counter % (int) (1 / delta_t) == 0) print_banner();
        counter++;
        impulse = thrust(motor, time, delta_t);
        acc = acceleration(impulse, mass, altitude);
        if (acc < 0) direction = -1;
<<<<<<< HEAD
        acc += direction * drag(cd, rho, speed, surface);
=======
        acc -= direction * drag(cd, rho, speed, surface);
>>>>>>> fd97a0948ae466b9a03ddc8a2f4c2eb0f655be2c
        if (acc > max_acceleration) max_acceleration = acc;
        printf("|%10.2lf  |%9.1lf  |%12.2lf  |%11.2lf  |\n",
                time, altitude, acc, speed);
        old_speed = speed;
        speed = new_speed(speed, acc, delta_t);
        if (speed > max_speed) max_speed = speed;
        altitude = altitude + delta_t * (old_speed + speed) / 2;
        if (altitude > max_altitude) {
            max_altitude = altitude;
            apogee_time = time;
        }
        flight_time = time;
        if (counter > 1 && altitude <= 0) {
            simulation_complete = 1;
            break;
        }
    }
    printf("+------------+-----------+--------------+-------------+\n");

    // TODO Print flight stats
    if (simulation_complete) {
        puts("The simulation completed");
        puts("");
    }
    else {
        puts(">>> WARNING! The simulation did not complete! <<<");
        puts(">>> Increase the maximum simulation duration. <<<");
        puts("");
    }
    printf("Flight duration: %6.2lf s\n", flight_time);
    printf("Time at apogee: %6.2lf s\n", apogee_time);
    printf("Max altitude: %6.2lf m\n", max_altitude);
    printf("Max speed: %6.2lf m/s\n", max_speed);
    printf("Max acceleration: %6.2lf G\n", max_acceleration / 9.81);
}

