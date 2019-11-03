#include <stdlib.h>
#include <string.h>
#include <ruby.h>

int LLVMFuzzerTestOneInput(uint8_t *Data, size_t size) {
    if (size < 1) {
        return 0;
    }
    char *code = malloc(size+1);
    memcpy(code, Data, size);
    code[size] = '\0';
    int state = 0;
    VALUE rVal = rb_eval_string_protect(code, &state)
    free(code);
    return 0;
}
