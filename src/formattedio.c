#define FORMAT_BOLD 1
#define FORMAT_ITAL 2
#define FORMAT_BLUE 4
#define FORMAT_GREN 8
#define FORMAT_REDX 16
#define FORMAT_GRAY 32

int iof (int formatting, const char* format, ...) {
	va_list arg;
	int done;

	if (formatting & FORMAT_BOLD) printf("\033[1m");
	if (formatting & FORMAT_ITAL) printf("\033[3m");
	if (formatting & FORMAT_BLUE) printf("\033[34m");
	if (formatting & FORMAT_GREN) printf("\033[32m");
	if (formatting & FORMAT_REDX) printf("\033[31m");
	if (formatting & FORMAT_GRAY) printf("\033[90m");

	va_start(arg, format);
	done = vfprintf(stdout, format, arg);
	va_end(arg);

	printf("\033[0m");

	return done;
}
