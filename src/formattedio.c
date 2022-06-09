#define FORMAT_BOLD 1
#define FORMAT_ITAL 2
#define FORMAT_BLUE 4
#define FORMAT_GREN 8
#define FORMAT_REDX 16
#define FORMAT_GRAY 32

int iof (int formatting, const char* format, ...) {
	va_list arg;
	int done;

	if (configuration_information.has_color && (formatting & FORMAT_BOLD)) printf("\033[1m");
	if (configuration_information.has_color && (formatting & FORMAT_ITAL)) printf("\033[3m");
	if (configuration_information.has_color && (formatting & FORMAT_BLUE)) printf("\033[34m");
	if (configuration_information.has_color && (formatting & FORMAT_GREN)) printf("\033[32m");
	if (configuration_information.has_color && (formatting & FORMAT_REDX)) printf("\033[31m");
	if (configuration_information.has_color && (formatting & FORMAT_GRAY)) printf("\033[38:5:250m");

	va_start(arg, format);
	done = vfprintf(stdout, format, arg);
	va_end(arg);

	if (configuration_information.has_color) printf("\033[0m");

	return done;
}
