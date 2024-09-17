#include <stdio.h>
#include <stdlib.h>

void flipEvery4thBit(unsigned char *data, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        for (int bit = 0; bit < 8; ++bit) {
            if ((i * 8 + bit + 1) % 4 == 0) {
                data[i] ^= (1 << bit); // Flip the bit
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];

    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Failed to open input file");
        return 1;
    }

    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    if (fileSize <= 0) {
        fprintf(stderr, "Invalid file size or empty file\n");
        fclose(inputFile);
        return 1;
    }

    unsigned char *data = (unsigned char *)malloc(fileSize);
    if (data == NULL) {
        perror("Memory allocation failed");
        fclose(inputFile);
        return 1;
    }

    size_t bytesRead = fread(data, 1, fileSize, inputFile);
    if (bytesRead != fileSize) {
        perror("Failed to read the entire file");
        free(data);
        fclose(inputFile);
        return 1;
    }

    fclose(inputFile);

    flipEvery4thBit(data, fileSize);

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Failed to open output file");
        free(data);
        return 1;
    }

    size_t bytesWritten = fwrite(data, 1, fileSize, outputFile);
    if (bytesWritten != fileSize) {
        perror("Failed to write the entire file");
        free(data);
        fclose(outputFile);
        return 1;
    }

    free(data);
    fclose(outputFile);

    printf("File encryption completed successfully.\n");

    return 0;
}
