/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"

static memory_block_t *context_allocate_memory_block(unsigned int need_bytes)
{
    memory_block_t *new_block = 0;
    new_block = malloc(sizeof(memory_block_t) + need_bytes);
    my_memset(new_block, 0, sizeof(memory_block_t) + need_bytes);
    ASSERT(new_block != 0);
    new_block->memory = (char *) new_block + sizeof(memory_block_t);
    new_block->memory_size = need_bytes;
    new_block->next = 0;
    return (new_block);
}

void context_allocate_memory_check(context_t * context, memory_block_t * new)
{
    if (context->active_block) {
        context->active_block->next = new;
        context->active_block = new;
    } else {
        context->first_block = new;
        context->active_block = new;
    }
}

void *context_allocate_memory(context_t * context, unsigned int size)
{
    if (!context->active_block ||
        context->active_block->memory_alloc_position + size >
        context->active_block->memory_size) {
        unsigned int needed_bytes =
            PARSE_CONTEXT_MEMORY_BLOCK_SIZE_DEFAULT;
        if (size > needed_bytes) {
            needed_bytes = size;
        }
        memory_block_t *new_block = 0;
        new_block = context_allocate_memory_block(needed_bytes);
        context_allocate_memory_check(context, new_block);
    }
    ASSERT(context->active_block &&
            context->active_block->memory_alloc_position + size <=
            context->active_block->memory_size);

    void *memory = context->active_block->memory +
        context->active_block->memory_alloc_position;
    context->active_block->memory_alloc_position += size;
    return memory;
}

enode_node_t *context_allocate_node(context_t * context)
{
    enode_node_t *node = context_allocate_memory(context,
                                                sizeof(enode_node_t));
    my_memset(node, 0, sizeof(*node));
    return node;
}

void context_clean_up(context_t * context)
{
    for (memory_block_t * block = context->first_block; block;) {
        memory_block_t *next = block->next;
        free(block);
        block = next;
    }
}
