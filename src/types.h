// If you add new week days because you use another calendar or something, remember to change conf.c
// In fact, you should probably run `grep -r Monday`, just to make sure
typedef enum { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday } week_day;

typedef struct {
	// exact_day refers to the day and the week
	unsigned int week;
	week_day day;
} exact_day;
