#pragma once

enum log_level_enum
{
	LOG_FATAL = 0,
	LOG_ERROR,
	LOG_WARN,
	LOG_INFO,
	LOG_DEBUG,
	LOG_TRACE
};

typedef enum log_level_enum log_level_t;

void log_print_level(log_level_t log_level);

#define log_fatal(...) _log(LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)
#define log_error(...) _log(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define log_warn(...) _log(LOG_WARN, __FILE__, __LINE__, __VA_ARGS__)
#define log_info(...) _log(LOG_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define log_debug(...) _log(LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define log_trace(...) _log(LOG_TRACE, __FILE__, __LINE__, __VA_ARGS__)

void _log(log_level_t log_level, const char *fname, uint32_t line, const char *fmt, ...);
