/*
 * Blake Eakin
 * CIS 234R - Secure Coding
 * Lab 2
 * 
 * Exploration of command line arguments in C.
 *
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
    
    int total_chars = 0, arg_count = 0;
    char * shortest_index = NULL, * longest_index = NULL;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "stop") == 0) {
            break;
        }
        
        int length = strlen(argv[i]);
        total_chars += length;
        ++arg_count;
        
        if ( shortest_index == NULL || strlen(shortest_index) > length ) {
            shortest_index = argv[i];
        }

        if ( longest_index == NULL || strlen(longest_index) < length ) {
            longest_index = argv[i];
        }

    }

    if ( arg_count == 0 ) {
        printf("No command line arguments\n");
    } else {
        printf("Number of command line arguments: %d\n", arg_count);
        printf("Shortest command line argument: %s\n", shortest_index);
        printf("Longest command line argument: %s\n", longest_index);
        printf("Average argument length: %.1f\n", ((float)total_chars / (float)arg_count));
    }
    
    return 0;
}
