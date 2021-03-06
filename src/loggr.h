#ifndef PRINT_SMV_H
#define PRINT_SMV_H

enum LogLevel { DEBUG = 0, LOG = 1, WARN = 2, ERROR = 3, NONE = 4 };

// set the level for logging
void SetLogLevel(enum LogLevel);

// set colors for UNIX terminal
void SetColors(int);
// set labels for level of logging
void SetLabels(int);
// send a debug message
void Debug(const char*, ...);
// send a normal log
void Log(const char*, ...);
// send a warning
void Warn(const char*, ...);
// send an error
void Error(const char*, ...);

#endif