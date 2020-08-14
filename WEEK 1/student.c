#include<stdio.h>
struct student{
	char roll[15];
	char name[40];
	int m1,m2,m3,m4;
	float avg;
	char grade;
};
int main()
{
	struct student s[3];
	for(int i=0;i<3;i++)
	{
		int sum =0;
		scanf("%s",s[i].roll);
		scanf("%s",s[i].name);
		scanf("%d%d%d%d",&s[i].m1,&s[i].m2,&s[i].m3,&s[i].m4);
		sum = s[i].m1 + s[i].m2 + s[i].m3 + s[i].m4;
		s[i].avg = sum / 4.0;
		if(s[i].avg > 85.5)
		s[i].grade = 'A';
		else if(s[i].avg >= 45.0 && s[i].avg <85.5)
		s[i].grade = 'B';
		else
		s[i].grade = 'C';
	}
	for(int i=0;i<3;i++)
	printf("roll = %s\tname= %s\tgrade=%c\n",s[i].roll,s[i].name,s[i].grade);
}