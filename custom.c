// Custom data based on the person who builds the guide.

// Custom crosstraining and repitition exercises. Repititions are always optional and displayed in
// addition to P/S/P workouts, crosstraining is displayed exactly once per day. If it is not a part
// of the schedule, it is displayed as optional.
exercise crosstraining[] = {
	(exercise) {"Bike", 10, "miles"},
	(exercise) {"Plank for", 150, "seconds"}
};

exercise repititions[] = {
	(exercise) { "Do", 150, "sit-ups" },
	(exercise) { "Do", 20, "pull-ups" },
	(exercise) { "Do", 100, "push-ups" },
	(exercise) { "Do", 100, "push-ups" },
	(exercise) { "Do", 60, "push-ups" },
	(exercise) { "Do", 40, "push-ups" }
};

// Change this to a lower value for an easier psp workout or higher for harder.
// 0.50 is recommended because it is the middle, and 1.00 is on the higher end of recommended
float psp_structure = 1.00;

// Each week can change in intensity, and some people advance at different rates. Change each of
// these to get the right push up, sit up, and pull up intensities for you.
int push_up_intensity[27] = {
	0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
};
int sit_up_intensity[27] = {
	0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
};
int pull_up_intensity[27] = {
	0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
};

/* To change the schedule, go to data/week_schedule.c. There have to be exactly four schedules:
 *  - one for odd weeks before week 26
 *  - one for even weeks before week 27
 *  - one for odd weeks after week 26
 *  - one for even weeks after week 27
 */

/* Finally, there need to be three sets of "lifting" workouts. Lifting workouts are so named because
 * it is is generally accepted that most exercises use machines or weights, but they can be
 * any types of exercises that are good for training a specific muscles or specific set of muscles.
 * For example, there is no exercise like running stairs in my opinion, but doing stairs isn't a
 * lifting workout, even though it would go in the Lifting - Lower category.
 */

exercise lift_upper_body[] = {
	(exercise) { "Do", 10, "chin-ups" },
	(exercise) { "Do", 10, "chin-ups" },
	(exercise) { "Do", 10, "chin-ups" },
	(exercise) { "Do", 25, "pike push-ups" },
	(exercise) { "T-pose flicks", 363, "seconds" } // Rap God by Eminem length
};
exercise lift_trunk_body[] = { // AKA Core
	(exercise) { "Jump-rope", 400, "seconds" },
	(exercise) { "Plank", 520, "seconds" }, // Purple Rain by Prince length
	(exercise) { "Side-plank, each", 150, "seconds" },
	(exercise) { "Superman", 150, "seconds" }
};
exercise lift_lower_body[] = {
	(exercise) { "Do", 50, "burpees" },
	(exercise) { "Do", 2, "football-suicides" },
	(exercise) { "Lunge", 400, "meters" },
	(exercise) { "Run", 10, "stair-laps" }
};

// Some of these exercises come from Wikipedia's list of weight training exercises, found here:
// https://en.wikipedia.org/wiki/List_of_weight_training_exercises

/* Don't know where I found this, but if you have access to physical machines, here would be a list
 * of lifts that could be helpful. If you know where it comes from, let me know.
 * Chest & Triceps:
 *   Dumbbell Bench Press: 3 x 8
 *   Dumbbell Incline Bench Press: 3 x 8
 *   Weighted Decline Push-Up: 2 x 12-15
 *   Skull Crusher: 2 x 8
 *   Cable Triceps Kickback: 2 x 10-12
 * Legs, Shoulders, & Abs:
 *   Barbell Front Squat: 3 x 6
 *   Romanian Deadlift: 3 x 8
 *   Bulgarian Split Squat: 2 x 10
 *   Machine Leg Extension superset with Leg Curl: 2 x 12-15 (each)
 *   Dumbbell Arnold Press: 3 x 6-8
 *   Cable Lateral Raise: 3 x 10-12
 *   Face Pull: 2 x 12-15
 *   Weighted Plank: 3 x 30 seconds
 *   Dumbbell Side Bend: 2 x 8 – 12
 * Back & Biceps:
 *   Barbell Row: 4 x 8
 *   Wide-Grip Lat Pulldown: 3 x 8
 *   Dumbbell Pullover: 2 x 12-15
 *   Chin-Up: 2 x 12-15
 *   Hammer Curl: 3 x 6-8
 *   Incline Dumbbell Curl: 2 x 8-10
 * Chest, Legs, & Abs:
 *   Barbell Close-Grip Bench Press: 3 x 6-8
 *   Weighted Dip: 2 x 10-12
 *   Dumbbell Flye: 2 x 12-15
 *   Hack Squat: 3 x 6
 *   Single-Leg Romanian Deadlift: 3 x 10
 *   Back Extension: 2 x 12-15
 *   Machine Leg Extension: 2 x 12-15
 *   Machine Calf Raise: 2 x 12-15
 *   Hanging Leg Raise: 3 x 10
 * Back & Arms:
 *   Dumbbell Row: 4 x 8
 *   Barbell High Pull: 4 x 8-10
 *   Straight-Arm Pulldown: 2 x 12-15
 *   Preacher Curl: 3 x 8
 *   Cable Overhead Extension: 2 x 10-12
 *   Cable Pressdown: 3 x 8
 */
