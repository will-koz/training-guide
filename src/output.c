#include "output.h"

void output_cross_training (int optional) {
	// Cross training is set in custom.c
	iof((optional) ? (FORMAT_BOLD | FORMAT_GRAY) : FORMAT_BOLD,
		STRING_HEADING, workout_name_string[CROSS_TRAIN]);

	for (int i = 0; i < sizeof(crosstraining) / sizeof(exercise); i++) {
		output_exercise(&crosstraining[i], optional);
	}
}

void output_daily_reps () {
	iof(FORMAT_BOLD | FORMAT_GRAY, STRING_REPS);

	for (int i = 0; i < sizeof(repititions) / sizeof(exercise); i++) {
		output_exercise(&repititions[i], 1);
	}
}

int output_day_schedule (day_schedule* ds) {
	// Returns if cross training is a required part of the day's workouts.
	int cross_training_req = 1;
	for (int i = 0; i < MAX_WORKOUTS_PER_DAY; i++) {
		switch (ds->workouts[i].type) {
			case CROSS_TRAIN:
				cross_training_req = 0;
				output_cross_training(0);
				break;
		}
	}
	return cross_training_req;
}

void output_exercise (exercise* e, int optional) {
	// iof(FORMAT_ITAL, "\t%s %d %s\n", e->verb, e->quantity, e->unit);
	iof((optional) ? (FORMAT_ITAL | FORMAT_GRAY) : FORMAT_ITAL, "\t%s ", e->verb);
	iof(FORMAT_ITAL | ((optional) ? FORMAT_GRAY : FORMAT_GREN), "%d ", e->quantity);
	iof(FORMAT_ITAL | ((optional) ? FORMAT_GRAY : FORMAT_BLUE), "%s\n", e->unit);
}
