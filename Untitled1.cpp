#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[50],dept[50],number[50],id[50];
    float salary;
};

void registratoin()
{
    struct student s[100];
    int i;
    for(i=1;i<=2;i++)
    {
        printf("\nStudent number: %d",i);
        printf("\nName: ");
        scanf("%s", s[i].name);
        printf("Id: ");
        scanf("%s", s[i].id);
        printf("Phone number: ");
        scanf("%s", s[i].number);
        printf("Salary: ");
        scanf("%f", & s[i].salary);
        printf("Department: ");
        scanf("%s", s[i].dept);
        FILE *info;
        info = fopen("textfile.txt","w");
        fwrite(&s,sizeof(s), 1,info);
        fclose(info);
    }
}

void show()
{
    struct student s[100];
    int i;
    for(i=1;i<=2;i++)
    {
        FILE *info;
        info = fopen("textfile.txt", "r");
        fread(&s,sizeof(s),1,info);
        printf("\n\nName: %s",s[i].name);
        printf("\nId: %s",s[i].id);
        printf("\nPhone number: %s",s[i].number);
        printf("\nSalary: %.2f",s[i].salary);
        printf("\nDepartmenet: %s",s[i].dept);
        printf("\n\n");
        fclose(info);
    }
}

int main()
{
    int n;
    printf("Enter 0 for register.......\nEnter 1 for show......\n");
    scanf("%d", &n);
    if (n==0)
    {
        registratoin();
    }
    else if (n==1)
    {
        show();
    }

}
