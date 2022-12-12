#include <stdio.h>
#include <string.h>
struct data
{
    char name[60];
    char sid[60];
    float cgpa;
    char semester[20];
    char position[20];
};
int main()
{
    struct data stu[30], temp;
    int i, j, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", stu[i].sid);
        scanf("%s", stu[i].name);
        scanf("%f", &stu[i].cgpa);
        scanf("%s", stu[i].semester);
        scanf("%s", stu[i].position);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (stu[j].cgpa > stu[j + 1].cgpa)
            {
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    for (j = 0; j < n; j++)
    {
        printf("Student ID:%s\n", stu[j].sid);
        printf("Name:%s\n", stu[j].name);
        printf("CGPA: %0.2f\n", stu[j].cgpa);
        printf("Semester: %s\n", stu[j].semester);
        printf("Position: %s\n", stu[j].position);
    }
    return 0;
}