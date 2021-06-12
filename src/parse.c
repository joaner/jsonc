#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "parse.h"

json_t *jsonc_parse(char *json) {
    printf("%zu\n", sizeof(json));
    printf("%zu\n", sizeof(json_scalar_t));
    printf("%zu\n", sizeof(json_node_t));
    json_t *data = malloc(sizeof(json_t));

    int i;
    size_t len = strlen(json);

    enum JSONC_TYPE t = JSONC_NIL;

    for (i = 0; i < len; i++) {
        char c = json[i];
        if (c == '{') {
            t = JSONC_OBJ;
        } else if (c == '[') {
            t = JSONC_ARR;
        } else if (c == '"') {
            t = JSONC_STR;
        }

        printf("%c", c);
        printf("%d", t);
    }

    return data; 
}