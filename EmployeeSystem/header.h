/******************************************************************************************
*FunctionName:Header                                                                      *
*                                                                                         *
*Description:在头文件里定义所需的宏、结构体和函数                                       *
*                                                                                         *
*MakingDate:2019/7/17                                                                     *
*                                                                                         *
*Maker:马振乐                                                                             *
******************************************************************************************/


#ifndef HEADER_H_INCLUDED      //重复包含（重复定义）
#define HEADER_H_INCLUDED


typedef struct Employee
{
    int num;
    char duty[10];
    char name[10];
    char sex[3];
    unsigned char age;
    char edu[10];
    int salary;
    char tel_office[13];
    char tel_home[13];
    char mobile[13];
    char qq[11];
    char address[31];
    struct Employee *next;
}EMP;

char password[9];
EMP *emp_first,*emp_end;
char gsave,gfirst;

int AddEmp();
int FindEmp();
int ListEmp();
int ModifyEmp();
int SummaryEmp();
int DeleteEmp();
int ResetPwd();

int ReadData();
int SaveData();

int Modi_Salary(int s);
char *Modi_Field(char *field,char *s,int n);

EMP *FindName(char *name);
EMP *FinfNum(int num);
EMP *FindTelephone(char *name);
EMP *FindQQ(char *name);

int DisplayEmp(EMP *emp,char *field,char *name);
int CheckFirst();
int Bound(char ch,int n);
int Login();
int Menu();

#endif HEADER_H_INCLUDED
