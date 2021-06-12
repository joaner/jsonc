#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    long fsize;
    char *json;

    if (argc > 1) {
        fp = fopen(argv[1], "r");
    } else {
        printf("Usage: %s test/1.json\n", argv[0]);
        exit(2);
    }
    if (!fp) {
        perror(argv[1]);
    }

    // example from https://stackoverflow.com/a/3747128
    fseek(fp, 0L, SEEK_END);
    fsize = ftell(fp);
    rewind(fp);

    json = calloc(1, fsize + 1);
    if (!json) {
        fclose(fp);
        fputs("memory allow fails\n", stderr);
        exit(1);
    }

    if ( 1 != fread(json, fsize, 1, fp)) {
        printf("%s", json);
        fclose(fp);
        free(json);
        fputs("entire read fails\n", stderr);
        exit(1);
    }

    fclose(fp);
    free(json);
}