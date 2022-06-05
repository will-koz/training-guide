#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "src/types.h"

#include "data/week_schedule.c"

#include "conf.c"
#include "src/dump.c"
#include "src/parse-arguments.c"

exact_day working_day;

int main (int argc, char** argv) {
	init_schedule();

	if (!parse_arguments(&working_day, argc, argv)) {
		printf(ERROR_PARSING_ARGS);
		return 1;
	}

	run_dump(&working_day); // Print out information about the target day and the day of the request
	// workout_schedule_dump(schedules, sizeof(schedules));

	return 0;
}
