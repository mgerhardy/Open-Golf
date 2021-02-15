#ifndef _MSCRIPT_PARSER_H
#define _MSCRIPT_PARSER_H

#include <stdbool.h>

#define MSCRIPT_MAX_SYMBOL_LEN 31
#define MSCRIPT_MAX_FUNCTION_ARGS 15
#define MSCRIPT_MAX_STRUCT_MEMBERS 15

typedef enum mscript_type_type {
    MSCRIPT_TYPE_VOID,
    MSCRIPT_TYPE_VOID_STAR,
    MSCRIPT_TYPE_INT,
    MSCRIPT_TYPE_FLOAT,
    MSCRIPT_TYPE_BOOL,
    MSCRIPT_TYPE_CHAR_STAR,
    MSCRIPT_TYPE_STRUCT,
    MSCRIPT_TYPE_ENUM,
    MSCRIPT_TYPE_ARRAY,
} mscript_type_type_t;

struct mscript;
typedef struct mscript mscript_t;

struct mscript_program;
typedef struct mscript_program mscript_program_t;

struct mscript_type;
typedef struct mscript_type mscript_type_t;

typedef enum mscript_val_type {
    MSCRIPT_VAL_INT,
    MSCRIPT_VAL_FLOAT,
    MSCRIPT_VAL_BOOL,
    MSCRIPT_VAL_OBJECT,
    MSCRIPT_VAL_ARRAY,
} mscript_val_type_t;

typedef struct mscript_val {
    mscript_val_type_t type;
    union {
        float float_val;
        int int_val;
        bool bool_val;

        struct {
            int num_args;
            struct mscript_val *args;
        } object;

        struct {
            int num_args;
            struct mscript_val *args;
        } array;
    };
} mscript_val_t;

mscript_val_t mscript_val_float(float float_val);
mscript_val_t mscript_val_int(int int_val);
mscript_val_t mscript_val_bool(bool bool_val);
mscript_val_t mscript_val_object(int num_args, mscript_val_t *args);
mscript_val_t mscript_val_array(int num_args, mscript_val_t *args);

mscript_t *mscript_create(void);
mscript_program_t *mscript_load_program(mscript_t *mscript, const char *name);

struct mscript_vm;
typedef struct mscript_vm mscript_vm_t;

mscript_vm_t *mscript_vm_create(mscript_program_t *program);
void mscript_vm_run(mscript_vm_t *vm, const char *function_name, int num_args, mscript_val_t *args);

#endif
