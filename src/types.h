#define MAX_INTERVAL_PER_DAY 8
#define MAX_WORKOUTS_PER_DAY 4

// If you add new week days because you use another calendar or something, remember to change conf.c
// In fact, you might have to re-read entire code base to know exactly where everything changes
typedef enum { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday } week_day;

typedef enum {
	CROSS_TRAIN = 1, LIFT, PSP, RUN_LI, RUN_LSD, RUN_SI, SWIM_LI, SWIM_LSD, SWIM_SI
} workout_type;

typedef enum {
	// There is also explicit 1, 2, and 3 for that type of LSD
	UPPER_BODY = 4, CORE = 2, LOWER_BODY = 1
} workout_subtype;

typedef struct {
	// exact_day refers to the day and the week
	unsigned int week;
	week_day day;
} exact_day;

typedef struct {
	char* verb;
	float quantity;
	char* unit;
} exercise;

typedef struct {
	workout_type type;
	int subtype;
} workout_item;

typedef struct {
	workout_item workouts[MAX_WORKOUTS_PER_DAY]; // The maximum number of workouts in a schedule
} day_schedule;

typedef struct {
	day_schedule days[Sunday + 1];
} week_schedule;

typedef struct {
	int minsets;
	int maxsets;
	int minreps;
	int maxreps;
} rep_intensity;

typedef struct {
	float run_lsd1;
	float run_lsd2;
	float run_lsd3;
	float run_wucd;
	int swim_lsd1;
	int swim_lsd2;
	int swim_lsd3;
	int swim_wucd;
} week_distance;

typedef struct {
	float intvl[MAX_INTERVAL_PER_DAY];
} intervals;
