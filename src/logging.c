#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>
#include <logging.h>

char *log_level_strings[] = {"FATAL", "ERROR", "WARNING", "INFO", "DEBUG", "TRACE"};
char *log_level_colors [] = {"\x1b[0;31m", "\x1b[0;31m", "\x1b[0;35m", " \x1b[0;36m", "\x1b[0;34m", "\x1b[0;37m"};

void log_print_level(log_level_t log_level)
{
	printf(log_level_colors[log_level]);
	printf(log_level_strings[log_level]);
	printf(" ");
	printf("\x1b[0m");
}

void _log(log_level_t log_level, const char *fname, uint32_t line, const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	time_t cur_time = time(NULL);
	struct tm *utc;
	utc = gmtime(&cur_time);
	printf("[%i:%i:%i] ", utc->tm_hour, utc->tm_min, utc->tm_sec);

	log_print_level(log_level);

	printf("%s:%u: ", fname, line);
	vprintf(fmt, args);
	printf("\n");
}
