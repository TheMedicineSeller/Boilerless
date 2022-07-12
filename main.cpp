#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {
    switch (argc)
    {
        case 1:
            // Spit out help doc
            printf("Format for creating project incorrect; Refer to help below\n%s", helpstring);
        break;
        case 2:
            // Create proj of language `arg1` in default mode
            if (strcmp(argv[1], "--help") == 0) {
                printf("%s", helpstring);

            } else if (strcmp(argv[1], "cpp") == 0) {
                generateSkeleton_C("Project", true);
                printf("C++ Project Directory generated under name 'Project'");
                
            } else if (strcmp(argv[1], "c") == 0) {
                generateSkeleton_C("Project");
                printf("C Project Directory generated under name 'Project'");

            } else if (strcmp(argv[1], "js") == 0) {
                generateSkeleton_JS("Website");
                printf("Javascript Project Skeleton generated under name 'Website'");

            } else {
                printf("Language specified currenty not supported. Refer help below to see lang codes\n%s", helpstring);
            }

        break;

        case 3:
            // Create proj of language `arg1` with name `arg2`
            if (strcmp(argv[1], "cpp") == 0) {
                generateSkeleton_C(argv[2], true);
                printf("C++ Project Directory generated under name '%s'", argv[2]);
                
            } else if (strcmp(argv[1], "c") == 0) {
                generateSkeleton_C(argv[2]);
                printf("C Project Directory generated under name '%s'", argv[2]);

            } else if (strcmp(argv[1], "js") == 0) {
                generateSkeleton_JS(argv[2]);
                printf("Javascript Project Skeleton generated under name '%s'", argv[2]);

            } else {
                printf("Language specified currenty not supported. Refer help below to see lang codes\n%s", helpstring);
            }

        break;

        case 4:
            // Special projs using specific libs
        break;

        default:
            printf("Incorrect Format : Too many arguments specified. Refer help below :\n%s", helpstring);
        break;
    }
    return 0;
}