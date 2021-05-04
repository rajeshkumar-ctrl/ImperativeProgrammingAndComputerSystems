
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <term.h>
//Hint
struct Person
    {
        char names[30];
        unsigned int age;
        char job[30];
    };

//Initialized everything here including all used void functions!!

struct Person** data;
unsigned int counter = 0;
unsigned int sizeofdata = 10;
void toAllocateData();
void toReAllocteData();
void toAddPerson();
void toListPerson();
void toDeletePerson();
char toListMenu();
void toDeleteDatabase();


//Main function to for selection of void functions
int main()
{
    toAllocateData();
        do
        {   char select = toListMenu();
                switch (select)
                {
                case 'a':
                    toAddPerson();
                    break;
                case 'l':
                    toListPerson();
                    break;
                case 'd':
                    toDeletePerson();
                    break;
                case 'x':
                   toDeleteDatabase();
                   return 0;
                }

        }
        while (1);
   return 0;
}


  char toListMenu()
  {
        printf("\n\n\n");
        printf("|-----------------------------------------------------------------|\n");
        printf("|                                                                 |\n");
        printf("|                          MY MENU                                |\n");
        printf("|                                                                 |\n");
        printf("|_________________________________________________________________|\n");
        printf("|            - a: Add a new person to the database.               |\n" );
        printf("|            - l: List the whole database.                        |\n" );
        printf("|            - d: Delete person from the database.                |\n");
        printf("|            - x: Exit the program.                               |\n");
        printf("|_________________________________________________________________|\n\n\n");
        printf("NOW CHOOSE:......!");

        bool exact= true;
        char selection;
        while (exact)
        {
            scanf(" %c",&selection);
            exact = (selection != 'a' && selection != 'x' && selection != 'l' && selection != 'd');
            if (exact)
            {
                printf ("Something Wrong, PLEASE TRY AGAIN: >>> ");
            }

        }
        return selection;
  }


void toDeleteDatabase()

{
unsigned int i=0;
while (i<sizeofdata)
{
if (data[i] != NULL){
			free(data[i]);
			data[i] = 0;
            }
            i++;
}
free(data);
data=0;
}

void toDeletePerson()
{
    char person_delete[30];
    int Saved=0;
    printf("                ENTER THE NAME OF PERSON YOU WANT TO DELETE:            \n");
    scanf("%s",person_delete);

    for (unsigned int i = 0; i < counter; i++)
	{
		if (strcmp(person_delete, data[i]->names) == 0)
		{
			free(data[i]);
			data[i] = NULL;
			Saved = i;
			break;
		}
	}
	counter= counter-1;
	if (counter % 5 == 0 && counter !=0 && counter != 5 && counter != 10)
	{
		sizeofdata -= 5;
		toReAllocteData();
	}
	struct Person** temp = (struct Person**)malloc(sizeofdata * sizeof(struct Person*));
	for (unsigned int i = 0, j = 0; i < counter; i++, j++)
	{
		if ( i==Saved) //warning: comparison of integer expressions of different signedness: ‘unsigned int’ and ‘int’ [-Wsign-compare]
  //130 |   if ( i==Saved)
  // Here is one error as far as i know i and saved both are unsigned but cannot be compared i dont know the main reason! 
  // i also used (i=~Saved) but it didnt work at all!
		{
			j++;
		}
		temp[i] = data[j];
		data[j] = 0;
	}
	free(data);
	data = temp;
	temp = 0;
}

void toListPerson()
{
	if (counter == 0)
	{
		printf("\n SORRY! ZERO RECORDS HERE! ");
	}
	for (unsigned int i = 0; i < counter; i++)
	{
		printf("\n\n PERSON NO.");
		printf("%d", i + 1);
		printf("\n NAME: ");
		printf("%s", data[i]->names);
		printf("\n AGE: ");
		printf("%d", data[i]->age);
		printf("\n JOB: ");
		printf("%s", data[i]->job);
	}
}

void toAddPerson()
{
	if ((counter != 5 && counter != 0)&&counter % 5 == 0 )
	{
		sizeofdata= sizeofdata + 5;
		toReAllocteData();
	}
	data[counter] = (struct Person*)malloc(sizeof(struct Person));
	printf("\n PERSON`S NAME: ");
	scanf("%s", data[counter]->names);
	printf("\n PERSON`S AGE: ");
	scanf("%u", &data[counter]->age);
	printf("\n PERSON`S JOB: ");
	scanf("%s", data[counter]->job);
	printf("\n EXCELLENT, YOUR DATA IS NOW SAVED!\n");
	counter=counter+1;
}

void toReAllocteData()
{
	data = (struct Person**)realloc(data, sizeofdata * sizeof(struct Person*));
}

void toAllocateData()
{
	data = (struct Person**)malloc(sizeofdata * sizeof(struct Person*));
	for (unsigned int i = 0; i < sizeofdata; i++)
	{
		data[i] = NULL;
	}

}














