#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "src/types.h"

#include "custom.c"
#include "data/intervals.c"
#include "data/rep-tables.c"
#include "data/run-swim-distances.c"
#include "data/week-schedule.c"
#include "src/formattedio.h"
#include "src/math.h"

#include "conf.c"
#include "src/dump.c"
#include "src/formattedio.c"
#include "src/math.c"
#include "src/output.c"
#include "src/parse-arguments.c"

exact_day working_day;

int main (int argc, char** argv) {
	init_schedule();

	if (!parse_arguments(&working_day, argc, argv)) {
		printf(ERROR_PARSING_ARGS);
		return 1;
	}

	int schedule_from_week = 0;
	if (working_day.week < 26) schedule_from_week = (working_day.week % 2) ? 0 : 1;
	else schedule_from_week = (working_day.week % 2) ? 2 : 3;
	int run_days = count_run_days();
	int swim_days = count_swim_days(&schedules[schedule_from_week]);
	day_schedule* exact_day_schedule = &schedules[schedule_from_week].days[working_day.day];

	run_dump(&working_day); // Print out information about the target day and the day of the request

	output_wucd(run_days, swim_days, working_day.week, is_run_day(working_day.day),
		is_swim_day(exact_day_schedule));

	if (output_day_schedule(exact_day_schedule, working_day.week)) output_cross_training(1);
	output_daily_reps();

	return 0;
}
