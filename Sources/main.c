#include <stdlib.h>
#include <assert.h>
#include "../Headers/stack.h"


void test_newstack(){
    Stack s1 = stack_new(10);
    Stack *stk = &s1;

    assert(stk->top == -1);
    assert(stk->size == 10);
    assert(stk->data[0] == 0);

}

void test_stack_full(){
    Stack s1 = stack_new(10);
    Stack *stk = &s1;

    assert(stack_full(stk) == 0);
}

void test_stack_empty(){
    Stack s1 = stack_new(10);
    Stack *stk = &s1;

    assert(stack_empty(stk) == 1);
}

void test_full_stack() {
    Stack s1 = stack_new(2);
    Stack *stk = &s1;
    StackResult res;

    stk = stack_push(stk, 10, &res);
    assert(res.status == STACK_OK);
    stk = stack_push(stk, 20, &res);
    assert(res.status == STACK_OK);
    stk = stack_push(stk, 30, &res);
    assert(res.status == STACK_FULL);
}

void test_stack() {
    Stack s1 = stack_new(5);
    Stack *stk = &s1;
    StackResult res;
    stk = stack_pop(stk, &res);
    assert(res.status == STACK_EMPTY);

    stk = stack_push(stk, 10, &res);
    assert(res.status == STACK_OK);
    stk = stack_push(stk, 20, &res);
    stk = stack_peek(stk, &res);
    assert(res.status == STACK_OK && res.data == 20);
    
    stk = stack_pop(stk, &res);
    assert(res.status == STACK_OK && res.data == 20);
    stk = stack_peek(stk, &res);
    assert(res.status == STACK_OK && res.data == 10);

    stk = stack_pop(stk, &res);
    assert(stack_empty(stk) == 1);

}



int main(){

    //test_newstack();
    //test_stack_full();
    //test_stack_empty();
    //test_full_stack();
    test_stack();
    return 0;
}