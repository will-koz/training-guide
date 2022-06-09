#include "parse-arguments.h"

int parse_arguments (exact_day* target_day, int argc, char** argv) {
	// Find exact day from first two arguments, or return 0 if there aren't enough arguments

	// Would be 3 because there has to be the command, the week, and the day
	// But if just being called with --help or --guide, it would just be the name and the option
	if (argc < 2) return 0;

	target_day->week = atoi(argv[1]);
	int day_found = 0;

	if (argc >= 3) {
		for (week_day i = Monday; i <= Sunday && !day_found; i++) {
			// default to assuming that the full word is used
			if (strcmp(argv[2], days_of_the_week_string[i]) == 0) {
				target_day->day = i;
				day_found = 1;
			}
		}

		for (week_day i = Monday; i <= Sunday && !day_found; i++) {
			// if the full word isn't used, then just go by initial of the day
			if (argv[2][0] == days_of_the_week_char[i]) {
				target_day->day = i;
				day_found = 1;
			}
		}
	}

	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], ARG_GUIDE) == 0) sayandexit(TEXT_GUIDE);
		if (strcmp(argv[i], ARG_HELP) == 0) sayandexit(TEXT_HELP);
		if (i >= 2) {
			if (strcmp(argv[i], ARG_COLOR) == 0) configuration_information.has_color = 1;
			if (strcmp(argv[i], ARG_LIST) == 0) configuration_information.is_check_list = 1;
			if (strcmp(argv[i], ARG_NOCOLOR) == 0) configuration_information.has_color = 0;
		}
	}

	if (!day_found) return 0; // If a day could not be found, return an error
}

void run_dump (exact_day* target_day) {
	printf(IO_DAYOFWEEK, days_of_the_week_string[target_day->day], target_day->week);

	time_t now = time(NULL);
	struct tm *nowstruct = localtime(&now);
	printf(IO_DATEREQUESTED, nowstruct->tm_year + 1900,
		(nowstruct->tm_mon >= 9) ? "" : "0", nowstruct->tm_mon + 1,
		(nowstruct->tm_mday >= 10) ? "" : "0", nowstruct->tm_mday);

	printf(IO_FROMURL, IO_URL);
}
