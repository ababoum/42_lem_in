#include "../inc/lem_in.h"

int main(void)
{
    // reading from stdin
    char *line;

    line = get_next_line(0);
    while (line) {
        printf("%s", line);
        free(line);
        line = get_next_line(0);
    }
    return (0);
}