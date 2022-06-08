#define ERROR_PARSING_ARGS "There was an error parsing the arguments\n"

#define IO_DATEREQUESTED "(Requested on %d-%s%d-%s%d)\n"
#define IO_DAYOFWEEK "Outputting workout for %s of week %d:\n"
#define IO_FROMURL "Taken from %s .\n\n"
#define IO_URL "https://www.sealswcc.com/training/navy-seal-swcc-physical-training-guide.html"

#define STRING_HEADING "%s:\n"
#define STRING_REPS "Repititions:\n"
#define STRING_WUCD "Warm Ups / Cool downs:\n"

#define VERB_DO "Do"
#define VERB_RUN "Run"
#define VERB_SPRINT "Sprint"
#define VERB_SWIM "Swim"
#define UNIT_METERS "meters"
#define UNIT_MILES "miles"
#define UNIT_PULLUP "pull-ups"
#define UNIT_PUSHUP "push-ups"
#define UNIT_SITUP "sit-ups"
#define UNIT_YARDS "yards"

// For days of the week and workout names, look src/types.h too because they are tied together
char days_of_the_week_char[] = { 'M', 'T', 'W', 'H', 'F', 'S', 'U' };
char* days_of_the_week_string[] = {
	"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

char* workout_name_string[] = {
	"", "Cross training", "Lifting", "P/S/P", "Run long interval", "Run long slow distance",
	"Run short interval", "Swim long interval", "Swim long slow distance", "Swim short interval"
};
