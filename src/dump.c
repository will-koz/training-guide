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

int count_run_days () {
	int run_days = 0;
	for (int i = Monday; i <= Sunday; i++) if (is_run_day(i)) run_days++;
	return run_days;
}

int count_swim_days (week_schedule* ws) {
	int swim_days = 0;
	for (int i = 0; i < Sunday + 1; i++) if (is_swim_day(&ws->days[i])) swim_days++;
	return swim_days;
}

int is_run_day (int day) {
	if (day == Saturday) return 0;
	if (day == Sunday) return 0;
	return 1;
}

int is_swim_day (day_schedule* ds) {
	for (int j = 0; j < MAX_WORKOUTS_PER_DAY; j++) {
		if (ds->workouts[j].type == SWIM_LI) return 1;
		if (ds->workouts[j].type == SWIM_LSD) return 1;
		if (ds->workouts[j].type == SWIM_SI) return 1;
	}
	return 0;
}

int weeki_from_weeko (int x) {
	// Week index from week ordinal
	return (--x > 26) ? 26 : x;
}
