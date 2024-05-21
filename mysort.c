#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char string[128];
    int number;
} Data;

void quicksort(Data *lines, int left, int right) {
    if (left < right) {
        int s = lines[(left + right) / 2].number;
        int i = left - 1;
        int j = right + 1;
        while (1) {
            while (lines[++i].number > s)
                ;
            while (lines[--j].number < s)
                ;
            if (i >= j) break;
            Data tmp = lines[i];
            lines[i] = lines[j];
            lines[j] = tmp;
        }
        quicksort(lines, left, i - 1);
        quicksort(lines, j + 1, right);
    }
}
int main(int argc, char *argv[]) {
    FILE *file_r = fopen(argv[1], "r");
    FILE *file_w = fopen(argv[2], "w");
    // FILE *file_r = fopen("test_rand.txt", "r");
    // FILE *file_w = fopen("test_out.txt", "w");
    Data *lines = (Data *)malloc(sizeof(Data) * 1000000);
    int count = 0;
    while (fscanf(file_r, "%s%d", lines[count].string, &lines[count].number) !=
           EOF) {
        count++;
    }
    quicksort(lines, 0, count - 1);
    for (int i = 0; i < count; i++) {
        fprintf(file_w, "%s\t%d\n", lines[i].string, lines[i].number);
    }
    fclose(file_r);
    fclose(file_w);
    return 0;
}