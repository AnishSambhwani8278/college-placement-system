#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int id;
    char name[50];
    float cgpa;
    char skill[50];
    char location[50];
};

struct company
{
    int id;
    char companyName[50];
    float minCGPA;
    char reqSkill[50];
    char location[50];
};

int studentCount = 0;
int companyCount = 0;

struct student s[100];
struct company c[100];

void registerStudent()
{
    printf("Enter Full Name: ");
    scanf("%[^\n]", &s[studentCount].name);
    getchar();

    printf("Enter CGPA: ");
    scanf("%f", &s[studentCount].cgpa);
    getchar();

    printf("Enter Skill(s) (Comma Seprated, No Space): ");
    scanf("%[^\n]", &s[studentCount].skill);
    getchar();

    printf("Enter Location Preference(s) (Comma Seprated, No Space): ");
    scanf("%[^\n]", &s[studentCount].location);

    s[studentCount].id = studentCount + 1;

    studentCount++;
}

void registerCompany()
{
    printf("Enter Company Name: ");
    scanf("%[^\n]", &c[companyCount].companyName);
    getchar();

    printf("Enter Minimum CGPA Required: ");
    scanf("%f", &c[companyCount].minCGPA);
    getchar();

    printf("Enter Required Skill(s) (Comma Seprated, No Space): ");
    scanf("%[^\n]", &c[companyCount].reqSkill);
    getchar();

    printf("Enter Working Location(s) (Comma Seprated, No Space): ");
    scanf("%[^\n]", &c[companyCount].location);

    c[companyCount].id = companyCount + 1;

    companyCount++;
}

void matchOnGradeSkillsAndLocation()
{
    for (int i = 0; i < companyCount; i++)
    {
        printf("Company: %s\n", c[i].companyName);
        printf("Eligible Students:\n");
        int flag = 0;
        for (int j = 0; j < studentCount; j++)
        {

            int skillMatch = 0;
            char skillCopy[50];
            strcpy(skillCopy, c[i].reqSkill);
            char *skillToken = strtok(skillCopy, ",");

            while (skillToken != NULL)
            {
                if (strstr(s[j].skill, skillToken))
                {
                    skillMatch = 1;
                    break;
                }
                else
                {
                    skillToken = strtok(NULL, ",");
                }
            }

            int locationMatch = 0;
            char locationCopy[50];
            strcpy(locationCopy, c[i].location);
            char *locationToken = strtok(locationCopy, ",");

            while (locationToken != NULL)
            {
                if (strstr(s[j].location, locationToken))
                {
                    locationMatch = 1;
                    break;
                }
                else
                {
                    locationToken = strtok(NULL, ",");
                }
            }

            if (s[j].cgpa >= c[i].minCGPA && skillMatch == 1 && locationMatch == 1)
            {
                printf("ID: %d, Student Name: %s, CGPA: %f, Skill(s): %s, Location Prefrence(s): %s\n", s[j].id, s[j].name, s[j].cgpa, s[j].skill, s[j].location);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("No Eligible Students!\n");
        }
    }
}

void matchOnGradeAndSkills()
{
    for (int i = 0; i < companyCount; i++)
    {
        printf("Company: %s\n", c[i].companyName);
        printf("Eligible Students:\n");
        int flag = 0;
        for (int j = 0; j < studentCount; j++)
        {

            int skillMatch = 0;
            char skillCopy[50];
            strcpy(skillCopy, c[i].reqSkill);
            char *token = strtok(skillCopy, ",");

            while (token != NULL)
            {
                if (strstr(s[j].skill, token))
                {
                    skillMatch = 1;
                    break;
                }
                else
                {
                    token = strtok(NULL, ",");
                }
            }

            if (s[j].cgpa >= c[i].minCGPA && skillMatch == 1)
            {
                printf("ID: %d, Student Name: %s, CGPA: %f, Skill(s): %s, Location Prefrence(s): %s\n", s[j].id, s[j].name, s[j].cgpa, s[j].skill, s[j].location);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("No Eligible Students!\n");
        }
    }
}

void matchPlacements()
{
    if (companyCount > 0 && studentCount > 0)
    {
        printf("1. Match By CGPA and Skills\n2. Match By CGPA, Skills and Location Prefrences\n3. Exit\n");
        int choice;
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            matchOnGradeAndSkills();
            return;
        case 2:
            matchOnGradeSkillsAndLocation();
            return;
        case 3:
            printf("Exiting...\n");
            return;
        default:
            printf("Invalid!\n");
        }
    }
    else
    {
        printf("Not Enough Students or Companies!\n");
    }
}

void allStudents()
{
    printf("Registered Students:\n");
    if (studentCount > 0)
    {
        for (int j = 0; j < studentCount; j++)
        {
            printf("ID: %d, Student Name: %s, CGPA: %f, Skill(s): %s, Location Prefrence(s): %s\n", s[j].id, s[j].name, s[j].cgpa, s[j].skill, s[j].location);
        }
    }
    else
    {
        printf("No Students Registered!\n");
    }
}

void allCompanies()
{
    printf("Registered Companies:\n");
    if (companyCount > 0)
    {
        for (int j = 0; j < companyCount; j++)
        {
            printf("ID: %d, Company Name: %s, Minimum CGPA: %f, Required Skill(s): %s, Location(s): %s\n", c[j].id, c[j].companyName, c[j].minCGPA, c[j].reqSkill, c[j].location);
        }
    }
    else
    {
        printf("No Companies Registered!\n");
    }
}

void editStudent()
{
    printf("Student ID: ");
    int sid;
    scanf("%d", &sid);
    getchar();

    if (studentCount > 0 && sid <= studentCount)
    {

        printf("Enter Name: ");
        scanf("%s", &s[sid - 1].name);

        printf("Enter CGPA: ");
        scanf("%f", &s[sid - 1].cgpa);
        getchar();

        printf("Enter Skill(s) (Comma Seprated, No Space): ");
        scanf("%[^\n]", &s[sid - 1].skill);
        getchar();

        printf("Enter Location Preference(s) (Comma Seprated, No Space): ");
        scanf("%[^\n]", &s[sid - 1].location);
    }

    else
    {
        printf("No Student Found!\n");
    }
}

void editCompany()
{
    printf("Company ID: ");
    int cid;
    scanf("%d", &cid);
    getchar();

    if (studentCount > 0 && cid < studentCount)
    {

        printf("Enter Company Name: ");
        scanf("%s", &c[cid - 1].companyName);

        printf("Enter Minimum Required CGPA: ");
        scanf("%f", &c[cid - 1].minCGPA);
        getchar();

        printf("Enter Skill(s) (Comma Seprated, No Space): ");
        scanf("%[^\n]", &c[cid - 1].reqSkill);
        getchar();

        printf("Enter Location Preference(s) (Comma Seprated, No Space): ");
        scanf("%[^\n]", &c[cid - 1].location);
    }

    else
    {
        printf("No Company Found!\n");
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. Register Student\n2. Register Company\n3. Check Registered Students\n4. Check Registered Companies\n5. Edit Student Details\n6. Edit Company Details\n7. Check Matching Of Students With Companies\n8. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            registerStudent();
            break;
        case 2:
            registerCompany();
            break;
        case 3:
            allStudents();
            break;
        case 4:
            allCompanies();
            break;
        case 5:
            editStudent();
            break;
        case 6:
            editCompany();
            break;
        case 7:
            matchPlacements();
            break;
        case 8:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}