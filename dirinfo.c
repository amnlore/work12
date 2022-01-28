#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
    char a[100];
    if (argc < 2) {
        printf("Add a directory\n");
        fgets(a, sizeof(a), stdin);
        int i = 0;
        while (a[i]) {
            i++;
        }
        a[i - 1] = 0;
    }
    else {
        strcpy(a, argv[1]);
    }
    DIR *d;
    struct dirent *dr;
    d = opendir(a);

    if (d == NULL) printf("error %s\n", strerror(errno));
    else {
        dr = readdir(d);
        struct stat stats;
        unsigned long long i;
        while (dr){
            if (dr -> d_type == 4) printf("Directory: %s\n", dr -> d_name);
            else if (dr -> d_type == 8) {
                printf("File: %s\n", dr -> d_name);
                stat(dr -> d_name, &stats);
                i += stats.st_size;
            }
            dr = readdir(d);
        }
        printf("Regular file size: %llu\n", i);
        closedir(d);
    }
}
