#ifndef __COMMON__
#define __COMMON__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Typy

typedef char *string;

// Zmianne

extern FILE *LogFile;

// Funkcje

void logTime(time_t t);
void logBacktrace();

#define Inf(format, ...) ( \
		(LogFile) ? (\
			logTime(time (NULL)), \
			fprintf(LogFile, format "\n" , ##__VA_ARGS__), \
			fflush(LogFile), \
			(void) 0 \
			) : (void) 0 \
		)


#define Err(format, ...) \
	Inf("[%s] " format, __func__ , ##__VA_ARGS__)

#define ErrSys(format, ...) Err(format " : %s." , ##__VA_ARGS__, \
		strerror(errno))


#define DieErr(format, ...) ( \
		Err("!Abort! " format , ##__VA_ARGS__), \
		exit(EXIT_FAILURE) \
		)

#define DieSys(format, ...) DieErr(format " : %s." , ##__VA_ARGS__, \
		strerror (errno))

# define assert(expr) ( \
		(expr) ? (void) 0 : (\
			DieErr( \
				"%s:%d: Assertion (%s) is false!", \
				__FILE__, __LINE__, #expr)\
			) \
		)



void *checkedMalloc(int n, int size);
void *checkedCalloc(int n, int size);

#define Malloc(Type, num) checkedMalloc(num, sizeof(Type))
#define Calloc(Type, num) checkedCalloc(num,  sizeof(Type))

#endif
