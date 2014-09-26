double motor[] = {2,8,12,10,7,5,5,5,5,5};

double thrust(double *motor, double time, double delta_t) {
    double motor_delta_t = 0.1;
    //TODO Problem with getting the proper index
    int index = (int) (time / motor_delta_t);
    double ret;
    int max_index = 10;
    if (index < max_index)
        ret = motor[index];
    else
        ret = 0;
    return ret;
}

