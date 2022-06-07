#include "dump.h"

void workout_schedule_dump (week_schedule schedule[], int schedule_size) {
	for (int i = 0; i < schedule_size / sizeof(week_schedule); i++) {
		printf("Schedule #%d:\n", i + 1);
		for (int j = Monday; j <= Sunday; j++) {
			printf("\t%s\n", days_of_the_week_string[j]);
			for (int k = 0; k < MAX_WORKOUTS_PER_DAY; k++) {
				if (schedule[i].days[j].workouts[k].type)
					printf("\t\t%d\n", schedule[i].days[j].workouts[k].type);
			}
		}
	}
}

int count_swim_days (week_schedule* ws) {
	int swim_days = 0;
	for (int i = 0; i < Sunday + 1; i++) {
		int swim_day = 0;
		for (int j = 0; j < MAX_WORKOUTS_PER_DAY; j++) {
			if (ws->days[i].workouts[j].type == SWIM_LI) swim_day = 1;
			if (ws->days[i].workouts[j].type == SWIM_LSD) swim_day = 1;
			if (ws->days[i].workouts[j].type == SWIM_SI) swim_day = 1;
		}
		if (swim_day) swim_days++;
	}
	return swim_days;
}
