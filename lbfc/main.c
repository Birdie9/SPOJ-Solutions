#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct node
{
char name[31];

struct node *next ;
};


int main()
{
int test ,i  ;

struct node hash[30];

scanf("%d",&test);

int names,k,count, flag;

struct node *curr, *prev ;

char name1[32];

while(test--)
{

  for(i=0;i<30;i++)
  {
   hash[i].next = NULL;
  }

  count =0;

  scanf("%d",&names);

  while(names--)
  {
    //flag = 0;

  	scanf("%s",name1);

    k = (strlen(name1)%30) ;

    curr = hash[k].next ;

    prev = &hash[k];

    while(1)
    {

     if(curr==NULL)
     {
     	curr = (struct node*) malloc(sizeof(struct node));

        curr ->next = NULL;

     	strcpy(curr->name,name1);

     	count++;

     	break;

     }

     else
     {

      if(strcmp(curr->name,name1)==0)
      {

      curr = curr->next;

      prev->next = curr;

      count--;

       //prev = curr;

       break ;
      }

      else
      {
      	prev = curr;
      	curr = curr->next;

      }

      }


     }
  }


  printf("%d\n",count);
}
return 0;
}
