#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*Transpose)(char*);

void reverse_string(char* str) {
    if (!str) return;

    int len = strlen(str); //O(n)
    char *start = str;
    char *end = str + len - 1;
    char temp;

    while (start < end) {//flips characters
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void transform_and_print(char* input, Transpose func) {
    printf("Old:    %s\n", input);
    func(input);
    printf("New:    %s\n", input);
}

int main() {
    char buffer[1024];

    printf("Input: ");
    if (fgets(buffer, sizeof(buffer), stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0';

        size_t len = strlen(buffer);
        char *dynamic_str = (char*)malloc((len + 1) * sizeof(char));

        if (dynamic_str == NULL) {
            return 1;
        }

        strcpy(dynamic_str, buffer);
        transform_and_print(dynamic_str, reverse_string);
        free(dynamic_str);
    }

    return 0;
}