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
