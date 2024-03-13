#include <stdio.h>

int get_time_in_minutes(int hours, int minutes) {
    return (hours * 60) + minutes;
}

void print_efficiency(int time_in_minutes) {
    if (time_in_minutes >= 120 && time_in_minutes < 180) {
        printf("highly efficient\n");
    } else if (time_in_minutes >= 180 && time_in_minutes < 240) {
        printf("improve speed\n");
    } else if (time_in_minutes >= 240 && time_in_minutes < 300) {
        printf("training to improve speed\n");
    } else if (time_in_minutes >= 300 && time_in_minutes <= 1440) {
        printf("terminated\n");
    } else {
        printf("Invalid time\n");
    }
}

int main() {
    int hours, minutes, time_in_minutes;

    printf("Enter time to complete job (hh mm): ");
    scanf("%d %d", &hours, &minutes);

    if (hours < 0 || hours > 24 || minutes < 0 || minutes >= 60) {
        printf("Invalid time\n");
        return 0;
    }

    time_in_minutes = get_time_in_minutes(hours, minutes);
    print_efficiency(time_in_minutes);

    return 0;
}
