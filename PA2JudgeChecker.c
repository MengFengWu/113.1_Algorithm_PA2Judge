#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_CHORDS 180000

int answer[10] = {3, 52, 176, 1, 566, 10000, 20000, 504, 608, 1};
int chords[MAX_CHORDS] = {};
int checks[MAX_CHORDS] = {};
int stackA[MAX_CHORDS] = {};
int topA = 0;

int main(int argc, char* argv[]) {
    if(argc != 4) exit(1);
    FILE* out = fopen(argv[2], "r");
    FILE* in = fopen(argv[1], "r");
    if(out < 0) {
        fprintf(stderr, "PA2JudgeChecker: Can not open output file.\n");
        exit(1);
    }
    int mAns;
    fscanf(out, "%d", &mAns);
    if(answer[argv[3][0] - '0'] != mAns) {
        fprintf(stderr, "PA2JudgeChecker: Find wrong number of chords(expect: %d, found: %d).\n", answer[argv[3][0] - '0'], mAns);
        exit(1);
    }

    int NN;
    fscanf(in, "%d", &NN);
    int a, b;

    for(int i = 0; i < NN / 2; i++) {
        if(fscanf(in, "%d %d", &a, &b) == EOF) {
            fprintf(stderr, "PA2JudgeChecker: Judge crashed.\n");
            exit(1);
        }
        chords[a] = b;
        chords[b] = a;
    }
    fclose(in);

    int min = -1;


    for(int i = 0; i < mAns; i++) {
        if(fscanf(out, "%d %d", &a, &b) == EOF) {
            fprintf(stderr, "PA2JudgeChecker: Find wrong lines of chords(expect: %d, found: %d).\n", mAns, i);
            exit(1);
        }
        if(chords[a] != b) {
            fprintf(stderr, "PA2JudgeChecker: Chord (%d, %d) doesn't exist.\n", a, b);
            exit(1);
        }
        if(a < min) {
            fprintf(stderr, "PA2JudgeChecker: The order of chords is not correct.\n");
            exit(1);
        }
        min = a;
        if(a < b) {
            checks[a] = 1;
            checks[b] = -1;
        }
        else {
            checks[a] = -1;
            checks[b] = 1;
        }
    }
    fclose(out);

    for(int i = 0; i < NN; i++) {
        if(checks[i] == 1) {
            stackA[topA] = i;
            topA++;
        }
        else if(checks[i] == -1) {
            if(chords[i] != stackA[topA - 1]) {
                fprintf(stderr, "PA2JudgeChecker: Found crossing chords (%d, %d) and (%d, %d).\n", stackA[topA - 1], chords[stackA[topA - 1]], chords[i], i);
                exit(1);
            }
            else {
                topA--;
            }
        }
    }

    exit(0);
}
