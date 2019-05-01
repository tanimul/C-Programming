#include<stdio.h>
struct Employees
{
    char employeeName[20];
    int employeeID;
    float employeesalary;
};
int main()
{
    int i;
    struct Employees e[5];
    for(i=1; i<=5; i++)
    {
        printf("Employee Name:");
        scanf("%s",& e[i].employeeName);
        printf("Employee ID:");
        scanf("%d",& e[i].employeeID);
        printf("Employee salary:");
        scanf("%f",& e[i].employeesalary);
    }
    for(i=1; i<=5; i++)
    {
        printf("Employee(%d)Name:%s \n",i,e[i].employeeName);
        printf("Employee(%d)ID:%d \n",i,e[i].employeeID);
        printf("Employee(%d)salary:%f \n",i,e[i].employeesalary);
    }
    return 0;
}
