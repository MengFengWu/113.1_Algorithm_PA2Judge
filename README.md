# 113.1_Algorithm_PA2Judge

Author: Bigbee

## Usage

Complie two source codes before you continue.
```
g++ -O2 PA2TestDataGenerator.cpp -o PA2TestDataGenerator
gcc -O2 PA2JudgeChecker.c -o PA2JudgeChecker
```
Drag all files to your PA2 directory, then run
```
./PA2Judge.sh
```
then the script will run all testcase for you. If you want to check specific testcase, use
```
./PA2Judge.sh [0-9]
```
where 0-4 are public testcases, 5-9 are **mocking** private testcases.

If you want to check the input files of the private testcases, run
```
./PA2TestDataGenerator
```
,this will create input files in your `./inputs/` directory.

If you want to check you output file manually, use
```
./PA2JudgeChecker <inputfile> <outputfile> <testcase[0-9]>
// for example: ./PA2JudgeChecker ./inputs/1000.in ./outputs/1000.out 1
```

## Misc

You might encounter permission denied issue. If so, use
```
chmod u+x <script/execfile>
```
