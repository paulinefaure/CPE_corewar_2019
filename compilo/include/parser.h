/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser & lexer
*/

#ifndef __ENODE_H__
#define __ENODE_H__

#include "debug.h"

#define ERROR(x) "\33[31mERROR:\33[0m "

#define IF_THEN(c, ret) if (c) ret;
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
typedef void (enode_node_init_callback)(void *user_data);
typedef void (enode_node_parse_callback)(enode_node_t *root, char *filename,
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

        struct {
            int ptr_count;
            enode_node_t *first_array_size_expression;
            enode_node_t *struct_declaration;
            enode_node_t *union_declaration;
            enode_node_t *type_definition;
        } type_usage;
    };
};

typedef struct enode_node_custom enode_node_custom_t;
struct enode_node_custom
{
    void *user_data;
    enode_node_init_callback *init;
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

int enode_node_parser(enode_node_custom_t *custom, char **fnames, int count);





/******         Token         ******/

int skip_whitespace(char **c);
token_t get_token(tokenizer_t *tokenizer);
token_t peek_token(tokenizer_t *tokenizer);
token_t next_token(tokenizer_t *tokenizer);
bool require_token(tokenizer_t *tokenizer, char *string, token_t *token_ptr);
bool token_match(token_t token, char *string);
bool
require_token_type(tokenizer_t *tokenizer, token_type type,
                                            token_t *token_ptr);
int get_binary_op_type_from_token(token_t token);





/******         Binary/Unary Util         ******/

char *enode_get_unary_op_string(int type);
char *enode_get_binary_op_string(int type);





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
void new_string(token_t *tok);
enode_node_t *
parse_struct_body(context_t *context, tokenizer_t *tokenizer, token_t name);
enode_node_t *
parse_type_usage(context_t *context, tokenizer_t *tokenizer);
enode_node_t *
parse_declaration_list(context_t *context, tokenizer_t *tokenizer);
enode_node_t *
parse_declaration_body(context_t *contxt, tokenizer_t *toke, token_t name);
enode_node_t *parse_context_pop_all_tag(context_t *context);
void parse_tag_list(context_t *context, tokenizer_t *tokenizer);
enode_node_t *parse_code(context_t *context, tokenizer_t *tokenizer);
enode_node_t *
parse_enum_body(context_t *context, tokenizer_t *tokenizer, token_t name);
enode_node_t *
parse_identifier_list(context_t *contxt, tokenizer_t *tokenizer);
enode_node_t *
parse_union_body(context_t *context, tokenizer_t *tokenizer, token_t name);
enode_node_t *
parse_expression(context_t *context, tokenizer_t *tokenizer);
enode_node_t *
parse_unary_expression(context_t *context, tokenizer_t *tokenizer);





/******         Graph To C Code         ******/

void
generated_graph_str(context_t *contxt, enode_node_t *root);
void enode_node_write_graph_c(int fd, enode_node_t *root, int follow_next);
void enode_node__write_graph_c(int fd, enode_node_t *root,
                                int follow_next, int nest);
void write_enode_node_struct_declaration(int fd, enode_node_t *root, int nest);
void write_enode_node_declaration(int fd, enode_node_t *root,
                                    int follow_next, int nest);
void write_enode_node_type_usage(int fd, enode_node_t *root, int nest);
void write_enode_node_union_as_c(int fd, enode_node_t *root, int nest);
void write_enode_node_enum_as_c(int fd, enode_node_t *root, int nest);
void write_tag_grah_c(int fd, enode_node_t *root, int nest);
void write_enode_node_binary(int fd, enode_node_t *root, int nest);
void write_enode_node_unary(int fd, enode_node_t *root, int nest);





/******         Parse Context         ******/

void
print_n_reset_errors(context_t *context);
void *
context_allocate_memory(context_t *context, unsigned int size);
enode_node_t *
context_allocate_node(context_t *context);
void
context_clean_up(context_t *context);
void
context_push_error(context_t *context, tokenizer_t *tokenizer, char *msg, ...);





/******         Utils for custom code gen.         ******/

enode_node_t *
enode_get_tag_param(enode_node_t *tag, int parameter_number);
enode_node_t *
get_enode_node_tag(enode_node_t *root, char *tag);
int
enode_node_has_tag(enode_node_t *node, char *tag);
bool
enode_node_declaration_is_type(enode_node_t *root, char *type);
bool
enode_node_struct_member_is_type(enode_node_t *root, char *type);
bool
enode_string_has_alphanumeric_block(char *string, char *substring);
int
enode_string_has_substring(char *string, char *substring);





/******         Print Code Gen.         ******/

void generate_header(int fd, char *filename);
int generate_code(int count, char **filenames);
void generate_print_code(int file, enode_node_t *root, char *acc_str);
void generate__print_code(int file, enode_node_t *node, char *acc_str);
void generate_procedure(int file, int file2, enode_node_t *root);
void generate_destroyer_code(int file, enode_node_t *root);
void generate_setter_code(int file, enode_node_t *root, char *acc_str);

void enode_init_cb(void *data);
void enode_parse_cb(enode_node_t *root, char *filename, void *data);
void enode_clean_up_cb(void *data);

#endif