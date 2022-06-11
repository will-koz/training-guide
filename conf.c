// remember to update --help text if you are adding a new option
#define ARG_COLOR "--color"
#define ARG_GUIDE "--guide"
#define ARG_HELP "--help"
#define ARG_LIST "--list"
#define ARG_NOCOLOR "--no-color"

#define ERROR_PARSING_ARGS "There was an error parsing the arguments\n"

#define IO_DATEREQUESTED "(Requested on %d-%s%d-%s%d)\n"
#define IO_DAYOFWEEK "Outputting workout for %s of week %d:\n"
#define IO_FROMURL "Taken from %s .\n\n"
#define IO_URL "https://www.sealswcc.com/training/navy-seal-swcc-physical-training-guide.html"

#define STRING_HEADING "%s:\n"
#define STRING_LIST "- [ ] "
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

char* TEXT_HELP = "\
Training guide help:\n\
Usage: [./]guide WEEK DAY [OPTIONS]\n\
--color    - Print with color output (default)\n\
--guide    - Print out some of the training guide information\n\
--help     - See --help for details\n\
--list     - Print out with a Checklist template at the beginning of each line\n\
--no-color - Do not print with color output\
";

char* TEXT_GUIDE = "\
The SEAL SWCC Naval Special Warfare (NSW) Physical Training Guide (PTG) provides information\n\
about the type of training required to properly prepare for the rigors of Basic Underwater\n\
Demolition/SEAL (BUD/S) or Basic Crewman Selection (BCS). Each week of progressively harder\n\
workouts in the PTG is designed to help you develop the strength and endurance to withstand the\n\
rigors oftraining.\n\n\
The PTG is designed to assist anyone who wants to improve their fitness in order to take and pass\n\
the NSW Physical Screening Test (PST) and succeed at BUD/S or BCS.\n\n\
The PTG offers a 26 week training template that will help a person with average fitness train\n\
effectively and minimize the risk of injury. The training template can be modified to suit your\n\
individual needs. If you want, you can extend the 26 week training template indefinitely.\n\n\
Key points to training:\n\
  1. Keep it simple\n\
  2. Use proper technique (get coaching from qualified sources if necessary)\n\
  3. Develop the whole body, especially the parts known to be vulnerable to injury\n\
Your workouts should be:\n\
  1. Planned, structured, organized\n\
  2. Balanced and well-rounded\n\
  3. Applied gradually and consistently\n\n\
Most of your cardiovascular exercise should focus on running and swimming. Resistance training\n\
targeting the whole body should be performed to develop the optimal muscular strength and\n\
endurance to resist injury and succeed at BUD/S or BCS. Specific emphasis on push-ups, sit-ups,\n\
and pull-ups will be necessary to achieve the required standards for the PST. Cross-training such\n\
as cycling, rowing, or hiking will complement and supplement your basic training. Work to achieve\n\
balanced fitness, with the optimal combination of endurance, strength, mobility, and flexibility.\n\
Work to improve your unsatisfactory qualities, and don’t just focus on the things you're good\n\
at.\n\n\
Running:\n\
  1. Try to do interval training on a measured course, such as a running track. If that is not \n\
     possible, find a location with a firm, flat surface without traffic that is safe for fast\n\
     running.\n\
  2. Try to do LSD running on a variety of different surfaces or terrains: flat, hilly, firm, and\n\
     soft – pavement, trails, grass, beaches, even snow.\n\
  3. Don’t worry about wearing boots when running. If you do run in boots, run only a couple\n\
     miles a week.\n\
Swimming:\n\
  1. A pool is desirable for interval training.\n\
  2. Take every safety precaution if you train in open water (lake or ocean)\n\
  3. Mix free style swimming into your workouts in addition to the Combat Sidestroke (CSS). This\n\
     will increase intensity and promote fitness that will translate to faster CSS swimming.\n\
     Perform as much as one third of your training using free style, mixed into interval and LSD\n\
     workouts.\n\
  4. Be careful if you include swimming with fins as part of your training. Make sure your ankles\n\
     are strong and flexible first. About 1000 yards per week with fins is sufficient.\n\
Cross Training:\n\
  1. You can supplement your run and swim training with cross-training using other cardiovascular\n\
     activities. Appropriate activities use large muscles and can be performed rhythmically and\n\
     continuously. Examples include (but are not limited to) cycling, rowing, stair stepping,\n\
     elliptical machines, and hiking.\n\
  2. Use cross-training activities to help build your conditioning base without over-training\n\
     (since you don’t want to ramp up your running or swimming volume too quickly). Use\n\
     cross-training to inject a little variety into your routine.\n\
  3. When necessary, substitute cross-training for running or swimming. This might happen if you\n\
     have a minor injury, there is bad weather, or your regular training facility is not\n\
     available.\n\n\
If you need more information, or even if you don't need more information, please read through:\n\
https://www.sealswcc.com/training/navy-seal-swcc-physical-training-guide.html .\
";

// For days of the week and workout names, look src/types.h too because they are tied together
char days_of_the_week_char[] = { 'M', 'T', 'W', 'H', 'F', 'S', 'U' };
char* days_of_the_week_string[] = {
	"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

char* workout_name_string[] = {
	"", "Cross training", "Lifting", "P/S/P", "Run long interval", "Run long slow distance",
	"Run short interval", "Swim long interval", "Swim long slow distance", "Swim short interval"
};

struct {
	int is_check_list;
	int has_color;
} configuration_information;

void init_configuration () {
	configuration_information.is_check_list = 0;
	configuration_information.has_color = 1;
}
