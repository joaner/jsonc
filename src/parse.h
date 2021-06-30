#define MAX_NODE_SIZE = 1000;
#define MAX_NODE_NEST = 1000;

typedef enum {
    JSONC_NIL=0,
    JSONC_ARR=1,
    JSONC_OBJ=2,
    JSONC_NUM=3,
    JSONC_STR=4,
} JSONC_TYPE;

typedef struct {
    char *key;
    JSONC_TYPE type;
    void* p;
    struct json_node_t *node;
    struct json_node_t *next;
} json_node_t;

typedef struct {
    json_node_t *child;
    json_node_t (*get)(void *self, char *key);
    json_node_t (*set)(void *self, char *key, char *value);
} json_t;

json_t *jsonc_parse(char *json);
