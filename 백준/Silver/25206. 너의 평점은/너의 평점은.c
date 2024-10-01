#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    double average_grade = 0.0;
    double sum_grade = 0.0;

    for (int i = 0; i < 20; i++)
    {
        char subject[51];
        double grade;
        char score_input[3];

        scanf("%s %lf %s", subject, &grade, score_input);
        getchar();

        double score = 0.0;

        if (strcmp(score_input, "A+") == 0) score = 4.5;
        else if (strcmp(score_input, "A0") == 0) score = 4.0;
        else if (strcmp(score_input, "B+") == 0) score = 3.5;
        else if (strcmp(score_input, "B0") == 0) score = 3.0;
        else if (strcmp(score_input, "C+") == 0) score = 2.5;
        else if (strcmp(score_input, "C0") == 0) score = 2.0;
        else if (strcmp(score_input, "D+") == 0) score = 1.5;
        else if (strcmp(score_input, "D0") == 0) score = 1.0;
        else if (strcmp(score_input, "F") == 0) score = 0.0;
        else { score = 0.0; grade = 0.0; }

        average_grade += (grade * score);
        sum_grade += grade;
    }
    if (sum_grade > 0) printf("%.5lf", average_grade / sum_grade);
    else printf("0.00000");

    return 0;
}