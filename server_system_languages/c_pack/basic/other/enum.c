#include<stdio.h>
#include<string.h>
#include<stdbool.h>

enum spectrum {
red, orange, yellow, green, blue, violet};

const char * colors[] = {
"red", "orange", "yellow", "green", "blue", "violet"};

#define LEN 30

int main(void)
{
    char choice[LEN];
    enum spectrum color;
    bool color_is_found = false;

    puts("Enter a color (empty line to quit):");
}
