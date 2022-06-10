// Custom data based on the person who builds the guide.

// Custom crosstraining and repitition exercises. Repititions are always optional and displayed in
// addition to P/S/P workouts, crosstraining is displayed exactly once per day. If it is not a part
// of the schedule, it is displayed as optional.
exercise crosstraining[] = {
	(exercise) {"Bike", 10, "miles"},
	(exercise) {"Plank for", 150, "seconds"}
};

exercise repititions[] = {
	(exercise) {"Do", 150, "sit-ups"},
	(exercise) {"Do", 100, "push-ups"},
	(exercise) {"Do", 100, "push-ups"},
	(exercise) {"Do", 60, "push-ups"},
	(exercise) {"Do", 40, "push-ups"}
};

// Change this to a lower value for an easier psp workout or higher for harder.
// 0.50 is recommended because it is the middle, and 1.00 is on the higher end of recommended
float psp_structure = 1.00;

// Each week can change in intensity, and some people advance at different rates. Change each of
// these to get the right push up, sit up, and pull up intensities for you.
int push_up_intensity[27] = {
	0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4
};
int sit_up_intensity[27] = {
	0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4
};
int pull_up_intensity[27] = {
	0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4
};

/* To change the schedule, go to data/week_schedule.c. There have to be exactly four schedules:
 *  - one for odd weeks before week 26
 *  - one for even weeks before week 27
 *  - one for odd weeks after week 26
 *  - one for even weeks after week 27
 */

/* Finally, there need to be three sets of "lifting" workouts. Lifting workouts are so named because
 * it is is generally accepted that most exercises use machines or weights, but they can be
 * any types of exercises. For example, there is no exercise like running stairs in my opinion, but
 * doing stairs isn't a lifting workout, even though it would go in the Lifting - Lower category.
 */

exercise lift_upper_body[] = {};
exercise lift_trunk_body[] = { // AKA Core
};
exercise lift_lower_body[] = {};
