#define ERROR_PARSING_ARGS "There was an error parsing the arguments\n"

#define IO_DATEREQUESTED "(Requested on %d-%s%d-%s%d)\n\n"
#define IO_DAYOFWEEK "Outputting workout for %s of week %d:\n"

#define STRING_CROSS_TRAINING "Cross Training:\n"
#define STRING_REPS "Repititions:\n"

char days_of_the_week_char[] = { 'M', 'T', 'W', 'H', 'F', 'S', 'U' };
char* days_of_the_week_string[] = {
	"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

char* workout_name_string[] = {
	"", "Cross training", "Lifting", "P/S/P", "Run long interval", "Run long slow distance",
	"Run short interval", "Swim long interval", "Swim long slow distance", "Swim short interval"
};
