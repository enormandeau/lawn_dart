# include <stdio.h>
# include "motors.h"

void print_help(void) {
    puts("Example usages:\n\
\n\
Running a simulation:\n\
    lawn_dart -m 100 -d 42 -c 0.8 -w 2 -M Estes_B6\n\
\n\
Listing available motors (-l, --list_motors):\n\
    lawn_dart -l\n\
\n\
Getting this help (-h, --help):\n\
    lawn_dart -h\n");
}

void print_not_enough_parameters(void) {
    puts("--- Not enough parameters ---\n");
}

void print_too_many_parameters(void) {
    puts("--- Too many parameters ---\n");
}

void print_banner(void) {
    //printf("+------------+-----------+--------------+-------------+\n");
    //printf("|  Time (s)  |  Alt (m)  | Accel (m/s2) | Speed (m/s) |\n");
    //printf("+------------+-----------+--------------+-------------+\n");
    printf("#  Time (s)  |  Alt (m)  | Accel (m/s2) | Speed (m/s) |\n");
}

void print_simulation_completed(void) {
    puts("The simulation completed");
    puts("-------------------------");
}

void print_simulation_not_completed(void) {
    puts(">>> WARNING! The simulation did not complete! <<<");
    puts(">>> Increase the maximum simulation duration. <<<");
    puts("------------------------------------------------");
}

void print_in_flight_statistics(double time, double altitude,
        double total_acceleration, double speed) {
        printf("|%10.2lf  |%9.1lf  |%12.2lf  |%11.2lf  |\n",
                time, altitude, total_acceleration, speed);
}

void print_post_flight_statistics(double flight_time, double burnout_time,
        double coast_time, double apogee_time, double max_altitude,
        double max_speed, double max_acceleration) {
    printf("Flight duration:  %6.2lf s\n", flight_time);
    printf("Burnout time:     %6.2lf s\n", burnout_time);
    printf("Coast time:       %6.2lf s\n", coast_time);
    printf("Time to apogee:   %6.2lf s\n", apogee_time);
    printf("Falling time:     %6.2lf s\n", flight_time - apogee_time);
    printf("Max altitude:     %6.2lf m\n", max_altitude);
    printf("Max speed:        %6.2lf m/s\n", max_speed);
    printf("Max acceleration: %6.2lf G\n", max_acceleration / 9.81);
    puts("");
}

void print_motor_list() {
    puts(motor_list);
}

