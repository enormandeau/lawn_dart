
void print_help(void);
void print_not_enough_parameters(void);
void print_too_many_parameters(void);
void print_banner(void);
void print_simulation_completed(void);
void print_simulation_not_completed(void);
void print_in_flight_statistics(double time, double altitude,
        double total_acceleration, double speed);
void print_post_flight_statistics(double flight_time, double burnout_time,
        double coast_time, double apogee_time, double max_altitude,
        double max_speed, double max_acceleration);

