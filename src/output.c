#include "output.h"

void output_exercise (exercise* e, int optional) {
	// iof(FORMAT_ITAL, "\t%s %d %s\n", e->verb, e->quantity, e->unit);
	iof((optional) ? (FORMAT_ITAL | FORMAT_GRAY) : FORMAT_ITAL, "\t%s ", e->verb);
	iof(FORMAT_ITAL | ((optional) ? FORMAT_GRAY : FORMAT_GREN), "%d ", e->quantity);
	iof(FORMAT_ITAL | ((optional) ? FORMAT_GRAY : FORMAT_BLUE), "%s\n", e->unit);
}

void output_cross_training () {
	// Cross training is set in custom.c
	iof(FORMAT_BOLD, STRING_CROSS_TRAINING);
	for (int i = 0; i < sizeof(crosstraining) / sizeof(exercise); i++) {
		output_exercise(&crosstraining[i], 1); // TODO optional-ness
	}
}

void output_reps () {
	iof(FORMAT_BOLD, STRING_REPS);
	for (int i = 0; i < sizeof(repititions) / sizeof(exercise); i++) {
		output_exercise(&repititions[i], 0); // TODO optional-ness
	}
}

void output_day_schedule (day_schedule* ds) {
	for (int i = 0; i < MAX_WORKOUTS_PER_DAY; i++) {
		switch (ds->workouts[i].type) {
			case CROSS_TRAIN:
				output_cross_training();
				break;
		}
	}
}
