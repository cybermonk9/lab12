#include<stdio.h>
#include<string.h>
#define max 100
struct employee
{
int key;
int id;
char name[20];
};
struct employee e[max];
int a[max];
int count=0;
void linearprobe(int key,int id,char name[20]);
void display();
void main()
{
int choice,i,key,id;
char name[20];
for(i=0;i<max;i++)
a[i]=-1;
do
{
printf("enter employee key ,id and name\n");
scanf("%d%d%s",&key,&id,&name);
linearprobe(key,id,name);
display();
printf("\ndo you want to continue (1 for Continue & 0 for Exit)\n");
scanf("%d",&choice);
}while(choice);
}
void linearprobe(int key,int id,char name[20])
{
int rem,i;
rem=key%max;
if(count==max)
{
printf("hash table is full\n");
exit(0);
}
else
{
if(a[rem]==-1)
{
a[rem]=1;
e[rem].key=key;
e[rem].id=id;
strcpy(e[rem].name,name);
count++;
}
else
{
printf("\nCollision Detected\n");
for(i=rem+1; i!=rem;i=(i+1)%max)
{
if(a[i]==-1)
{
count++;
a[i]=1;
e[i].id=id;
e[i].key=key;
strcpy(e[i].name,name);
break;
}
}
}
}
}
void display()
{
int i;
printf("\nHASH TABLE\n");

printf("Address\t Key\t Id\t Name\n");

for(i=0;i<max;i++)
if(a[i]==1)
printf("\n[%d]\t %d\t %d\t %s\n",i,e[i].key,e[i].id,e[i].name);

}

