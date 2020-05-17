/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser & lexer
*/

#ifndef __ENODE_H__
#define __ENODE_H__

#include <stdbool.h>
#include "debug.h"
#include "op.h"

#define ERROR(x) "\33[31mERROR:\33[0m "

#define IF_THEN(c, ret) if (c){ ret;};
#define ELIF(c) else if (c)
#define ASSIGN_RETURN_IF(c, assign, ret) if (c) assign; \
                                        IF_THEN(c, ret)

#define LOG_ERROR(cond, ret, msg, ...) \
    if (cond) my_printf(ERROR(0)"\33[33m"msg"\33[0m", ##__VA_ARGS__); \
    IF_THEN(cond, ret)


//////////////////////////////////////////////
//                                          //
//              STRUCTURES                  //
//                                          //
//////////////////////////////////////////////


typedef enum token_type {
    token_unknown,

    token_alpha_num,
    token_number,
    token_string,
    token_comment,
    token_symbole,
    token_register,
    token_dir_number,
    token_dir_label,
    token_label,

    token_eof,
} token_type;

typedef enum enode_binary_op_type
{
    enode_binary_op_type_invalid,
    enode_binary_op_type_add,
    enode_binary_op_type_subtract,
    enode_binary_op_type_multiply,
    enode_binary_op_type_divide,
    enode_binary_op_type_modulus,
    enode_binary_op_type_bitshift_left,
    enode_binary_op_type_bitshift_right,
    enode_binary_op_type_bitwise_and,
    enode_binary_op_type_bitwise_or,
    enode_binary_op_type_boolean_and,
    enode_binary_op_type_boolean_or,
    enode_binary_op_type_max
} enode_binary_op_type;

typedef enum enode_unary_op_type
{
    enode_unary_op_type_invalid,
    enode_unary_op_type_negative,
    enode_unary_op_type_not,
    enode_unary_op_type_bitwise_negate,
    enode_unary_op_type_max
} enode_unary_op_type;

typedef enum node_type {
    node_identifier,
    node_declaration,
    node_type_usage,
    node_number,
    node_string,
    node_char,
    node_label,
    node_dir_label,
    node_header,
    node_instruction
} node_type;

typedef struct token {
    token_type type;
    int length;
    char *txt;
    int lines_traversed;
    char *cur;
} token_t;

typedef struct tokenizer {
    char *at;
    int lines;
    int error;
} tokenizer_t;

typedef struct enode_node enode_node_t;
typedef int (enode_node_parse_callback)(enode_node_t *root, char *filename,
                                                        void *user_data);
typedef void (enode_node_clean_up_callback)(void *user_data);

struct enode_node {

    enode_node_t *next;
    node_type type;
    int length;
    int size;
    int argcode;
    int flag;

    enode_node_t *first_arg;

    union {
        char *string;
        char *name;
    };
    union {
        struct {
            enode_node_t *declaration;
        } identifier;

        struct {
            enode_node_t *value;
        } header;

        struct {
            enode_node_t *instruction;
        } label;
    };
};

typedef struct enode_node_custom enode_node_custom_t;
struct enode_node_custom
{
    void *user_data;
    enode_node_parse_callback *parse;
    enode_node_clean_up_callback *clean_up;
};

typedef struct parse_error parse_error_t;
struct parse_error
{
    char *str;
    int line;
    char *file;
};

static const int PARSE_CONTEXT_MEMORY_BLOCK_SIZE_DEFAULT = 4096;

typedef struct memory_block memory_block_t;
struct memory_block
{
    char *memory;
    size_t memory_size;
    size_t memory_alloc_position;
    memory_block_t *next;
};

typedef struct parse_context context_t;
struct parse_context
{
    memory_block_t *first_block;
    memory_block_t *active_block;
    int error_stack_size;
    int error_stack_max;
    parse_error_t *error_stack;
    enode_node_t *tag_stack_head;
    int exit;
};






//////////////////////////////////////////////
//                                          //
//              PROTOTYPES                  //
//                                          //
//////////////////////////////////////////////



/******         Main Call         ******/
int generate_code(int count, char **filenames);
int enode_node_parser(enode_node_custom_t *custom, char **fnames, int count);





/******         Token         ******/

int skip_whitespace(char **c);
token_t get_token(tokenizer_t *tokenizer);
token_t peek_token(tokenizer_t *tokenizer);
token_t next_token(tokenizer_t *tokenizer);
bool require_token(tokenizer_t *tokenizer, char *string, token_t *token_ptr);
bool token_match(token_t token, char *string);
bool require_token_type(tokenizer_t *tokenizer, token_type type,
                                            token_t *token_ptr);



/******         Extension File Util         ******/

bool verif_ext(char *name);
char *replace_extension(char *name, char *ext);





/******         Utils         ******/

char *context_strcat_dup(context_t *cont, char *str1, char *str2);
char *context_strdup(context_t *cont, char *src);
int my_char_is_symbol(int c);





/******         Parser         ******/

void parse_string(char **c, token_t *token);
void parse_alpha(char **c, token_t *token);
void parse_number(char **c, token_t *token);
enode_node_t *parse_code(context_t *context, tokenizer_t *tokenizer);




/******         Graph To C Code         ******/

void generated_graph_str(context_t *contxt, enode_node_t *root);





/******         Parse Context         ******/

void print_n_reset_errors(context_t *context);
void *context_allocate_memory(context_t *context, unsigned int size);
enode_node_t *context_allocate_node(context_t *context);
void context_clean_up(context_t *context);
void context_push_error(context_t *context,
                        tokenizer_t *tokenizer, char *msg, ...);
enode_node_t *parse_args(context_t *ctx, tokenizer_t *toke,
                            op_t op, args_type_t type);
enode_node_t *parse_instruction(context_t *ctx,
                                tokenizer_t *tokenizer, token_t *name);



int enode_parse_cb(enode_node_t *root, char *filename, void *data);
void enode_clean_up_cb(void *data);

size_t get_request_label_position(
                    enode_node_t *first, enode_node_t *tofind);
size_t get_label_position(enode_node_t *first, char *labelname);

int conversion_instruction(int fd, enode_node_t * root, enode_node_t *node);
void print(char **out, const char *format, va_list args);
void set_node(enode_node_t *new, token_t *token, int size, int flag);
void invert_byte(int *val);
void write_exec_magic(header_t *header);
size_t get_enode_size(enode_node_t *current);
void write_comment_header(enode_node_t *root, header_t *header);

#endif