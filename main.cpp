#include "header.h"
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
                generateSkeleton_CPP("Project");
                printf("\nC++ Project Directory generated under name 'Project'");
                
            } else if (strcmp(argv[1], "c") == 0) {
                generateSkeleton_C("Project");
                printf("\nC Project Directory generated under name 'Project'");

            } else if (strcmp(argv[1], "js") == 0) {
                generateSkeleton_JS("Website");
                printf("\nJavascript Project Skeleton generated under name 'Website'");

            } else {
                printf("Language specified currenty not supported. Refer help below to see lang codes\n%s", helpstring);
            }

        break;

        case 3:
            // Create proj of language `arg1` with name `arg2`
            if (strcmp(argv[1], "cpp") == 0) {
                generateSkeleton_CPP(argv[2]);
                printf("\nC++ Project Directory generated under name '%s'", argv[2]);
                
            } else if (strcmp(argv[1], "c") == 0) {
                generateSkeleton_C(argv[2]);
                printf("\nC Project Directory generated under name '%s'", argv[2]);

            } else if (strcmp(argv[1], "js") == 0) {
                generateSkeleton_JS(argv[2]);
                printf("\nJavascript Project Skeleton generated under name '%s'", argv[2]);

            } else {
                printf("Language specified currenty not supported. Refer help below to see lang codes\n%s", helpstring);
            }

        break;

        case 4:
            // Set compiler version / enable typescript
            if (strcmp(argv[1], "cpp")) {
                generateSkeleton_CPP(argv[2], atoi(argv[3]));

            } else if (strcmp(argv[1], "c")) {
                generateSkeleton_C(argv[2], atoi(argv[3]));

            } else if (strcmp(argv[1], "js")) {
                if (strcmp(argv[3], "ts")) {
                    generateSkeleton_JS(argv[2], true);

                } else {
                    printf("Invalid Javascript option :- (to create typescript project, pass 'ts')\n");
                }
            } else {
                printf("Invalid parameters passed. Refer help below :\n%s", helpstring);
            }
        break;

        case 5:
            // Specific library dependacies setup
        break;

        default:
            printf("Incorrect Format : Too many arguments specified. Refer help below :\n%s", helpstring);
        break;
    }
    return 0;
}