#include <errno.h>
#include <string.h>

#include "common.h"

FILE *LogFile = NULL;

void logTime(time_t t) {
	struct tm *lt = localtime(&t);
	fprintf(
		LogFile,
		"%04d-%02d-%02d %02d:%02d:%02d  ",
		lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday,
		lt->tm_hour, lt->tm_min, lt->tm_sec
	);
}

void *checkedMalloc(int nmemb, int size) {
	assert(nmemb >= 0);
	assert(size >= 0);
	void *m = malloc((size_t) nmemb * (size_t) size);
	if (m == NULL) {
		DieSys("Malloc");
	}
	return m;
}

void *checkedCalloc(int nmemb, int size) {
	assert(nmemb >= 0);
	assert(size >= 0);
	void *m = calloc(nmemb, size);
	if (m == NULL) {
		DieSys("Calloc");
	}
	return m;
}
