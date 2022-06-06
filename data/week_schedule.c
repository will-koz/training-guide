// Holds the information about the workout schedule for a week
week_schedule schedules[4]; // Size explicitly stated because it's referred to later in the program

void init_schedule () {
	schedules[0].days[Monday].workouts[0] = (workout_item) { RUN_LSD, 1 };
	schedules[0].days[Monday].workouts[1] = (workout_item) { SWIM_LSD, 2 };
	schedules[0].days[Monday].workouts[2] = (workout_item) { PSP, 0 };

	schedules[0].days[Tuesday].workouts[0] = (workout_item) { SWIM_LI, 0 };
	schedules[0].days[Tuesday].workouts[1] = (workout_item) {LIFT, UPPER_BODY | CORE | LOWER_BODY};

	schedules[0].days[Wednesday].workouts[0] = (workout_item) { RUN_SI, 0 };
	schedules[0].days[Wednesday].workouts[1] = (workout_item) { LIFT, CORE };
	schedules[0].days[Wednesday].workouts[2] = (workout_item) { PSP, 0 };
	schedules[0].days[Wednesday].workouts[3] = (workout_item) { CROSS_TRAIN, 0 };

	schedules[0].days[Thursday].workouts[0] = (workout_item) { RUN_LSD, 2 };
	schedules[0].days[Thursday].workouts[1] = (workout_item) { SWIM_LSD, 1 };
	schedules[0].days[Thursday].workouts[2] = (workout_item) { PSP, 0 };

	schedules[0].days[Friday].workouts[0] = (workout_item) { RUN_LI, 0 };
	schedules[0].days[Friday].workouts[1] = (workout_item) { LIFT, UPPER_BODY | CORE | LOWER_BODY };
	schedules[0].days[Friday].workouts[2] = (workout_item) { CROSS_TRAIN, 0 };

	schedules[0].days[Saturday].workouts[0] = (workout_item) { SWIM_SI, 0 };
	schedules[0].days[Saturday].workouts[1] = (workout_item) { LIFT, CORE };
	schedules[0].days[Saturday].workouts[2] = (workout_item) { PSP, 0 };

	schedules[0].days[Sunday].workouts[0] = (workout_item) { CROSS_TRAIN, 0 };

	schedules[1].days[Monday].workouts[0] = (workout_item) { RUN_LSD, 1 };
	schedules[1].days[Monday].workouts[1] = (workout_item) { SWIM_LSD, 2 };
	schedules[1].days[Monday].workouts[2] = (workout_item) { LIFT, UPPER_BODY | CORE };

	schedules[1].days[Tuesday].workouts[0] = (workout_item) { SWIM_LI, 0 };
	schedules[1].days[Tuesday].workouts[1] = (workout_item) { LIFT, LOWER_BODY };
	schedules[1].days[Tuesday].workouts[2] = (workout_item) { PSP, 0 };
	schedules[1].days[Tuesday].workouts[3] = (workout_item) { CROSS_TRAIN, 0 };

	schedules[1].days[Wednesday].workouts[0] = (workout_item) { RUN_SI, 0 };
	schedules[1].days[Wednesday].workouts[1] = (workout_item) { LIFT, CORE };
	schedules[1].days[Wednesday].workouts[2] = (workout_item) { PSP, 0 };

	schedules[1].days[Thursday].workouts[0] = (workout_item) { RUN_LSD, 2 };
	schedules[1].days[Thursday].workouts[1] = (workout_item) { SWIM_SI, 0 };
	schedules[1].days[Thursday].workouts[2] = (workout_item) { LIFT, UPPER_BODY | CORE };

	schedules[1].days[Friday].workouts[0] = (workout_item) { SWIM_LSD, 1 };
	schedules[1].days[Friday].workouts[1] = (workout_item) { LIFT, LOWER_BODY };
	schedules[1].days[Friday].workouts[2] = (workout_item) { PSP, 0 };
	schedules[1].days[Friday].workouts[3] = (workout_item) { CROSS_TRAIN, 0 };

	schedules[1].days[Saturday].workouts[0] = (workout_item) { RUN_LSD, 1 };
	schedules[1].days[Saturday].workouts[1] = (workout_item) { LIFT, CORE };
	schedules[1].days[Saturday].workouts[2] = (workout_item) { PSP, 0 };

	schedules[1].days[Sunday].workouts[0] = (workout_item) { CROSS_TRAIN, 0 };

	schedules[2].days[Monday].workouts[0] = (workout_item) { RUN_LSD, 1 };
	schedules[2].days[Monday].workouts[1] = (workout_item) { SWIM_LSD, 2 };
	schedules[2].days[Monday].workouts[2] = (workout_item) { PSP, 0 };

	schedules[2].days[Tuesday].workouts[0] = (workout_item) { SWIM_LI, 0 };
	schedules[2].days[Tuesday].workouts[1] = (workout_item) {LIFT, UPPER_BODY | CORE | LOWER_BODY};

	schedules[2].days[Wednesday].workouts[0] = (workout_item) { RUN_SI, 0 };
	schedules[2].days[Wednesday].workouts[1] = (workout_item) { SWIM_LSD, 3 };
	schedules[2].days[Wednesday].workouts[2] = (workout_item) { LIFT, CORE };

	schedules[2].days[Thursday].workouts[0] = (workout_item) { RUN_LSD, 2 };
	schedules[2].days[Thursday].workouts[1] = (workout_item) { SWIM_LSD, 1 };
	schedules[2].days[Thursday].workouts[2] = (workout_item) { PSP, 0 };

	schedules[2].days[Friday].workouts[0] = (workout_item) { RUN_LI, 0 };
	schedules[2].days[Friday].workouts[1] = (workout_item) { LIFT, UPPER_BODY | CORE | LOWER_BODY };

	schedules[2].days[Saturday].workouts[0] = (workout_item) { RUN_LSD, 3 };
	schedules[2].days[Saturday].workouts[1] = (workout_item) { SWIM_SI, 0 };
	schedules[2].days[Saturday].workouts[2] = (workout_item) { LIFT, CORE };

	schedules[2].days[Sunday].workouts[0] = (workout_item) { PSP, 0 };
	schedules[2].days[Sunday].workouts[1] = (workout_item) { CROSS_TRAIN, 0 };

	schedules[3].days[Monday].workouts[0] = (workout_item) { RUN_SI, 0 };
	schedules[3].days[Monday].workouts[1] = (workout_item) { SWIM_LSD, 2 };
	schedules[3].days[Monday].workouts[2] = (workout_item) { LIFT, UPPER_BODY | CORE };

	schedules[3].days[Tuesday].workouts[0] = (workout_item) { RUN_LSD, 3 };
	schedules[3].days[Tuesday].workouts[1] = (workout_item) { SWIM_LI, 0 };
	schedules[3].days[Tuesday].workouts[2] = (workout_item) { LIFT, LOWER_BODY};

	schedules[3].days[Wednesday].workouts[0] = (workout_item) { RUN_LI, 0 };
	schedules[3].days[Wednesday].workouts[1] = (workout_item) { SWIM_LSD, 3 };
	schedules[3].days[Wednesday].workouts[2] = (workout_item) { LIFT, CORE };
	schedules[3].days[Wednesday].workouts[3] = (workout_item) { PSP, 0 };

	schedules[3].days[Thursday].workouts[0] = (workout_item) { RUN_LSD, 2 };
	schedules[3].days[Thursday].workouts[1] = (workout_item) { SWIM_SI, 0 };
	schedules[3].days[Thursday].workouts[2] = (workout_item) { LIFT, UPPER_BODY | CORE };

	schedules[3].days[Friday].workouts[0] = (workout_item) { SWIM_LSD, 1 };
	schedules[3].days[Friday].workouts[1] = (workout_item) { LIFT, LOWER_BODY };

	schedules[3].days[Saturday].workouts[0] = (workout_item) { RUN_LSD, 1 };
	schedules[3].days[Saturday].workouts[1] = (workout_item) { LIFT, CORE };
	schedules[3].days[Saturday].workouts[2] = (workout_item) { PSP, 0 };

	schedules[3].days[Sunday].workouts[0] = (workout_item) { PSP, 0 };
	schedules[3].days[Sunday].workouts[1] = (workout_item) { CROSS_TRAIN, 0 };
}
