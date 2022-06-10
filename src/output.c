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
			case LIFT:
				output_lift(); // TODO
				break;
			case PSP:
				output_weekly_reps(week);
				break;
			case RUN_LI:
				output_interval(&rl_intervals[weeki_from_weeko(week)],
					VERB_RUN, UNIT_MILES, ds->workouts[i].type);
				break;
			case RUN_LSD:
			case SWIM_LSD:
				output_lsd(ds->workouts[i].type, ds->workouts[i].subtype, week);
				break;
			case RUN_SI:
				output_interval(&rs_intervals[weeki_from_weeko(week)],
					VERB_SPRINT, UNIT_METERS, ds->workouts[i].type);
				break;
			case SWIM_LI:
				output_interval(&sl_intervals[weeki_from_weeko(week)],
					VERB_SWIM, UNIT_YARDS, ds->workouts[i].type);
				break;
			case SWIM_SI:
				output_interval(&ss_intervals[weeki_from_weeko(week)],
					VERB_SWIM, UNIT_YARDS, ds->workouts[i].type);
				break;
		}
	}
	return cross_training_req;
}

void output_exercise (exercise* e, int optional) {
	// iof(FORMAT_ITAL, "\t%s %d %s\n", e->verb, e->quantity, e->unit);
	if (configuration_information.is_check_list) iof((optional) ?
		(FORMAT_ITAL | FORMAT_GRAY) : FORMAT_ITAL, "\t%s", STRING_LIST);
	else iof(0, "\t");
	iof((optional) ? (FORMAT_ITAL | FORMAT_GRAY) : FORMAT_ITAL, "%s ", e->verb);
	iof(FORMAT_ITAL | ((optional) ? FORMAT_GRAY : FORMAT_GREN), "%g ", e->quantity);
	iof(FORMAT_ITAL | ((optional) ? FORMAT_GRAY : FORMAT_BLUE), "%s\n", e->unit);
}

void output_interval (intervals* i, char* verb, char* unit, int workoutname) {
	iof(FORMAT_BOLD, STRING_HEADING, workout_name_string[workoutname]);
	for (int j = 0; j < MAX_INTERVAL_PER_DAY; j++) {
		if ((*i).intvl[j]) {
			exercise e = (exercise) { verb, (*i).intvl[j], unit };
			output_exercise(&e, 0);
		}
	}
}

void output_lift () {
	;
}

void output_lsd (int type, int subtype, int week_number) {
	// Output both Swim and Run LSDs
	week_number = weeki_from_weeko(week_number);
	int runtype = (type == RUN_LSD);
	iof(FORMAT_BOLD, STRING_HEADING, workout_name_string[(runtype) ? RUN_LSD : SWIM_LSD]);
	char* verb = NULL;
	float number = 0;
	char* units = NULL;

	if (runtype) {
		verb = VERB_RUN;
		units = UNIT_MILES;
		if (subtype == 1) number = distance_table[week_number].run_lsd1;
		else if (subtype == 2) number = distance_table[week_number].run_lsd2;
		else number = distance_table[week_number].run_lsd3;
	} else {
		verb = VERB_SWIM;
		units = UNIT_YARDS;
		if (subtype == 1) number = distance_table[week_number].swim_lsd1;
		else if (subtype == 2) number = distance_table[week_number].swim_lsd2;
		else number = distance_table[week_number].swim_lsd3;
	}

	exercise e = (exercise) { verb, number, units };
	output_exercise(&e, 0);
}

void output_weekly_reps (int week_number) {
	iof(FORMAT_BOLD, STRING_HEADING, workout_name_string[PSP]);

	week_number = weeki_from_weeko(week_number);
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
	week_number = weeki_from_weeko(week_number);

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
