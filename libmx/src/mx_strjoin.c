#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
	if(s1 == NULL && s2 == NULL) {
		return NULL;
	}
	else if(s1 == NULL) {
		return mx_strdup(s2);
	}
	else if(s2 == NULL) {
		return mx_strdup(s1);
	}
	else {
		char *new_string = mx_strcat(mx_strdup(s1), mx_strdup(s2));
		
		return new_string;
	}
}


