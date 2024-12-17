#include <stdio.h>
#include <stdbool.h>


//0, 1, 2, 3, 4
typedef enum{
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

//0, 1, 2, 3, 4, 5, 6
typedef enum{
    A, B, C, D, E, F,
    NUM_OF_REGISTERS
} Registers;

int registers[NUM_OF_REGISTERS];

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};

int ip = 0;
int sp = -1;
int stack[256];
bool running = true;

int fetch();

void eval(int instr){
    switch (instr)
    {
    case HLT: {
        running = false;
        break;
    }
    case PSH: {
        //Use value and increment
        sp++; //Increment first because sp is initially at -1
        stack[sp] = program[++ip]; //Increment and use
        break;
    }

    case POP: {
        int val_popped = stack[sp--]; //Use and decrement
        printf("Value popped: %d\n", val_popped);
        break;
    }

    case ADD: {
        int a = stack[sp--];  //Use and decrement
        int b = stack[sp--];  //Use and decrement
        int sum = b + a;
        sp++; //Use and increment
        stack[sp] = sum;
        printf("Sum, %d\n", stack[sp]);

    }
    default:
        break;
    }
}


int main(){
    while(running){
        eval(fetch());
        ip++;
    }
   
    return 0;
}

int fetch(){
    return program[ip];
};