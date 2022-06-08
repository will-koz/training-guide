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

int output_day_schedule (day_schedule* ds, int week) {
	// Returns if cross training is a required part of the day's workouts.
	int cross_training_req = 1;
	for (int i = 0; i < MAX_WORKOUTS_PER_DAY; i++) {
		switch (ds->workouts[i].type) {
			case CROSS_TRAIN:
				cross_training_req = 0;
				output_cross_training(0);
				break;
			case PSP:
				output_weekly_reps(week);
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

void output_weekly_reps (int week_number) {
	iof(FORMAT_BOLD, STRING_HEADING, workout_name_string[PSP]);

	if (--week_number > 26) week_number = 26; // 26, not 27, because arrays start at 0
	int week_push_up_intensity = push_up_intensity[week_number];
	int week_sit_up_intensity = sit_up_intensity[week_number];
	int week_pull_up_intensity = pull_up_intensity[week_number];

	// Start by outputting push up sets
	int sets = (int) roundf(zero_one_map(psp_structure, push_ups_ri[week_push_up_intensity].minsets,
		push_ups_ri[week_push_up_intensity].maxsets));
	int reps = (int) roundf(zero_one_map(psp_structure, push_ups_ri[week_push_up_intensity].minreps,
		push_ups_ri[week_push_up_intensity].maxreps));
	exercise e = (exercise) { VERB_DO, reps, UNIT_PUSHUP };
	for (int i = 0; i < sets; i++) output_exercise(&e, 0);

	// Sit up sets
	sets = (int) roundf(zero_one_map(psp_structure, sit_ups_ri[week_sit_up_intensity].minsets,
		sit_ups_ri[week_sit_up_intensity].maxsets));
	reps = (int) roundf(zero_one_map(psp_structure, sit_ups_ri[week_sit_up_intensity].minreps,
		sit_ups_ri[week_sit_up_intensity].maxreps));
	e = (exercise) { VERB_DO, reps, UNIT_SITUP };
	for (int i = 0; i < sets; i++) output_exercise(&e, 0);

	// Pull up sets
	sets = (int) roundf(zero_one_map(psp_structure, pull_ups_ri[week_pull_up_intensity].minsets,
		pull_ups_ri[week_pull_up_intensity].maxsets));
	reps = (int) roundf(zero_one_map(psp_structure, pull_ups_ri[week_pull_up_intensity].minreps,
		pull_ups_ri[week_pull_up_intensity].maxreps));
	e = (exercise) { VERB_DO, reps, UNIT_PULLUP };
	for (int i = 0; i < sets; i++) output_exercise(&e, 0);
}

void output_wucd (int run, int swim, int week_number, int is_run, int is_swim) {
	if (!(is_run || is_swim)) return;
	iof(FORMAT_BOLD, STRING_WUCD);
	if (--week_number > 26) week_number = 26;

	if (is_run) {
		// If it's a week day, do some warm up running
		float warmupdistancef = distance_table[week_number].run_wucd / run;
		exercise e = (exercise) { VERB_RUN, warmupdistancef, UNIT_MILES };
		output_exercise(&e, 0);
	}

	if (is_swim) {
		int warmupdistancei = distance_table[week_number].swim_wucd / swim;
		exercise e = (exercise) { VERB_SWIM, warmupdistancei, UNIT_YARDS };
		output_exercise(&e, 0);
	}
}
