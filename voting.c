#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[100], count = 0;
void looks();
int admin_Check();
void insertCandidates();
void candidate_Name();
void vote();
int main()
{
    looks();
    // int val=admin_Check();
    // printf("%d",val);
    // insertCandidates();
    // candidate_Name();
    // candidate_Name();
    vote();
    return 0;
}
void looks()
{
    printf("\t\t\t=============================================================\n");
    printf("\t\t\t=               WELLCOME TO ELECTION SYSTEM                 =\n");
    printf("\t\t\t=                    OF NILPHAMARI                          =\n");
    printf("\t\t\t=============================================================\n");
    printf("\t\t\t=          PLEASE ENTER USER NAME AND PASSWORD              =\n");
    printf("\t\t\t=============================================================\n");
    printf("\t\t\t=============================================================\n");
}
int admin_Check()
{
    char name[32], password[32];
    printf("User Name :");
    scanf("%s", name);
    printf("\nPassword  :");
    scanf("%s", password);
    if (strcmp(name, "admin") == 0 && strcmp(password, "admin") == 0)
    {
        return 1;
    }
    return 0;
}
void insertCandidates()
{
    int people, i, count = 0;
    printf("\t\t\tHow many Candidates Do you want?\n");
    scanf("%d", &people);
    int raw = people * 2;
    char store_Candidate[raw][100];
    for (i = 0; i < raw; i += 2)
    {
        printf("\t\t\tEnter the Name of the Candidate No:%d\n", count += 1);
        fflush(stdin);
        scanf("%[^\n]%*c", store_Candidate[i]);
        printf("\t\t\tEnter sysmbole of the Candidate.\n");
        scanf("%s", store_Candidate[i + 1]);
    }
    FILE *ptr = fopen("candidate.txt", "w");
    fprintf(ptr, "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    for (int i = 0; i < raw; i++)
    {
        fprintf(ptr, "%s\n", store_Candidate[i]);
    }
    fprintf(ptr, "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    fclose(ptr);
}
void candidate_Name()
{
    char str[10][210], ch[100];
    int i, line = 0;
    FILE *ptr = fopen("candidate.txt", "r");
    while (fscanf(ptr, "%[^\n]%*c", ch) != EOF)
    {
        line += 1;
    }
    fclose(ptr);
    FILE *ptr_1 = fopen("candidate.txt", "r");
    for (i = 0; i < line; i++)
    {
        fscanf(ptr_1, "%[^\n]%*c", str[i]);
    }
    for (i = 0; i < line - 2; i += 2)
    {
        count += 1;
        printf("\n%d. Name:%s Symbol:%s", count, str[i + 1], str[i + 2]);
    }
    fclose(ptr_1);
}
void vote()
{
    int idNum;
    FILE *ptr = fopen("voter.txt", "w");
    printf("Enter 0 to exit\n");
    while (1)
    {
        printf("Enter Your Voter ID\n");
        scanf("%d", &idNum);
        if (idNum == 0)
        {
            break;
        }
        fprintf(ptr, "%d\n", idNum);
    }
    candidate_Name();
    printf("\nEnter the Number from above to vote");
}
void voteCount()
{
    int i;
    for (i = 0; i < count; i++)
    {
        arr[i];
    }
}