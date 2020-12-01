#include <assert.h>
#include "../Headers/stack.h"

Stack stack_new(uint32_t size){
    size = (size > 0 && size < MAX_DEPTH)? size: MAX_DEPTH;
    Stack s1 = { size, -1, {0} };
    return s1;
}

uint8_t stack_full(const Stack *stk){
    assert (stk != NULL);
    return ( (stk->top + 1 == stk->size));
}

uint8_t stack_empty(const Stack *stk){
    assert (stk != NULL);
    return (stk->top == -1);
}

Stack* stack_push(Stack *stk, float ele, StackResult *res){
    assert (stk != NULL);
    if ((stk->top + 1) < stk->size) {
        stk->data[++stk->top] = ele;
        res->status = STACK_OK;
        res->data = ele;


    } else {
        res->status = STACK_FULL;
    }

    return stk;
}

Stack* stack_pop(Stack *stk, StackResult *res){
    assert(stk != NULL);
    if (stk->top != -1){
        res->data = stk->data[stk->top];
        --stk->top;
        res->status = STACK_OK;
    } else {
        res->status = STACK_EMPTY;
    }

    return stk;
}

Stack* stack_peek(Stack *stk, StackResult *res){
    assert(stk != NULL);
    if (stk->top != -1){
        res->data = stk->data[stk->top];
        res->status = STACK_OK;
    } else {
        res->status = STACK_EMPTY;
    }

    return stk;
}