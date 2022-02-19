#include "loggr.h"

#include <stdarg.h>
#include <stdio.h>

/*
 NONE    -   NONE
 DEBUG   -  WHITE
 LOG     -  GREEN
 WARNING - YELLOW
 ERROR   -    RED
*/
char* colors[] = {"\x1B[0m", "\x1B[36m", "\x1B[32m", "\x1B[33m", "\x1B[31m"};
char* labels[] = {"(DEBUG)   ", "(LOG)     ", "(WARNING) ", "(ERROR)   "};

// boolean - is colour set?
unsigned short int colors_set = 0;
// boolean - is labeling set?
unsigned short int labels_set = 0;

// minimum log level
enum LogLevel minLevel = DEBUG;
// list of arguments after log text (...)
va_list arg;

// base function for logging, every function's just this but more specific :P
void Basic_Log(enum LogLevel level, char* txt, va_list arg) {
  if (level < minLevel) return;  // return if importance is too low
  if (labels_set) printf("%s", labels[level]);  // print label if enabled
  if (colors_set) printf("%s", colors[level]);      // set colour if enabled
  
  vprintf(txt, arg);

  // NOTE - is this really needed though:
  printf("%s\n", colors[0]);  // revert back to base colour
}

inline void SetLogLevel(enum LogLevel level) { minLevel = level; }

inline void SetColors(int yes) { colors_set = yes; }
inline void SetLabels(int yes) { labels_set = yes; }

void Debug(char* txt, ...) {
  va_start(arg, txt); // record extra arguments into arg
  Basic_Log(DEBUG, txt, arg);
  va_end(arg);
}

void Log(char* txt, ...) {
  va_start(arg, txt);
  Basic_Log(LOG, txt, arg);
  va_end(arg);
}

void Warning(char* txt, ...) {
  va_start(arg, txt);
  Basic_Log(WARNING, txt, arg);
  va_end(arg);
}

void Error(char* txt, ...) {
  va_start(arg, txt);
  Basic_Log(ERROR, txt, arg);
  va_end(arg);
}