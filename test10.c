#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
	char name[50];
	int freq;
	struct Person *next;
} person, *plink;

plink cons(int *n,plink temp)
{
	temp = (plink)malloc(sizeof(person));                //malloc(sizeof(plink));
	if (temp == NULL) {
		printf("Out of memory in cons\n");
		exit(1);
	}
	else
	{
		strcpy(temp->name, n);
		temp->next = NULL;
		temp->freq = 0;
		++(temp->freq);
	}
	return temp;
}
plink check(int*n, plink head)
{   
	plink temp2;
	temp2 = head;
	while (temp2 != NULL)
	{
		if (strcmp(temp2->name,n) == 0)
		{
			++(temp2->freq);
			return 0;
		}
		temp2 = temp2->next;
	}
	return 1;
}

plink sort(int j, plink head)
{
	plink temp,temp2,t;
	temp = temp2 = t = NULL;
	for(int i =0;i<=j;i++)
	{	temp = temp2 = head;
		while (temp->next!= NULL)
		{
			if (temp->name[0] > temp->next->name[0])
			{  
				t=temp->next;
				temp->next=temp->next->next;
				t->next= temp;
				if(temp==head)
				{ head = temp2 = t; }
				else
				{ temp2->next = t; }
				temp = t;
			}
			temp2 = temp;
			temp = temp->next;	
		} 
	}
	t = head;
	printf("Sorted Linked List \n");
	while (t != NULL)
	{
		printf("%s \t %d \n", t->name, t->freq);
		t = t->next;
	}
}

plink createlinkedlist()
{
	plink head = NULL;
	plink temp = NULL;
	plink p = NULL;
	int y=0,j=0;
	do
	{
		char str3[50];
		gets(str3);
		if (head == NULL)
		{
			temp = cons(str3, temp);
			j++;
			head = temp;
		}
		else if (head != NULL)
		{  
			if (check(str3, head) == 1)
			{
				j++;
				temp =cons(str3, temp);
				p = head;
				while (p->next != NULL)
				{
					p = p->next;
				}
				p->next = temp;
			}	
		}
		scanf("%d", &y);
	} while (y == 0);

p = head;
printf("Unsorted Linked List \n");
	while (p != NULL)
	{
		printf("%s \t %d \n", p->name, p->freq);
		p = p->next;
	}
	sort(j, head);
printf("%s \n", p->name);
	
}

int main() {
	//person p1, p2;
	createlinkedlist();
	// p2=(*p1)next;
	// p2->name=ReadName1(p2);
	// p1->age = ReadAge(p2);
	// p2->next=0;  
}