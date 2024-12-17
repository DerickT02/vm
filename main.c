#include <stdio.h>
#include <stdbool.h>

typedef enum{
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};

int main(){
    printf("Hello World");
}