// Holds the information about the workout schedule for a week
week_schedule schedules[4]; // Size explicitly stated because it's referred to later in the program

void init_schedule () {
	schedules[0].days[Monday].workouts[0] = (workout_item) { RUN_LSD, 1 };
}
