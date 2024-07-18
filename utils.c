#include "utils.h"

char *read_file_contents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Determine file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate buffer for file contents
    char *buffer = (char *) malloc(file_size + 1);
    if (!buffer) {
        fclose(file);
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // Read file contents into buffer
    size_t read_size = fread(buffer, 1, file_size, file);
    buffer[read_size] = '\0';  // Null-terminate buffer

    fclose(file);
    return buffer;
}