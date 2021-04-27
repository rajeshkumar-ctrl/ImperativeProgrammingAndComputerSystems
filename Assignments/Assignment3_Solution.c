
#include <stdio.h>
#include <stdlib.h>


int NoteValidation (char *Array)
{
    for (int i = 0; Array[i] != '\0' ; i++)
    {
      if ( (Array[i] >= 'A' && Array[i] <= 'Z') || (Array[i] >= 'a' && Array[i] <= 'z') )
            return 1;
    }
    return 0;
}


int TimeValidation( char *str )
{
    if ( str[0] < '0' || str[0] > '2' )
    {
        return 0;
    }
    
    if ( str[1] < '0' || str[1] > '9' )
    {
        return 0;
    }

    if ( str[2] != ':' )
    {
        return 0;
    }

    if ( str[3] < '0' || str[3] > '5' )
    {
        return 0;
    }

    if ( str[4] < '0' || str[4] > '9' )
    {
        return 0;
    }
    
    if ( str[5] != '\0' )
    {
        return 0;
    }

    if ( str[0] == '2' && str[1] > '3' )
    {
        return 0;
    }

    return 1;
}



int main(int argc, char *argv[])
{
    int check =1;

     if (argc < 3)
    {   check =0;
        printf ("Wrong Input!\n");
        return 0;
    }
	
        for (int i = 0; i < argc; i += 2) 
        {
            if (TimeValidation(argv[i]) && NoteValidation(argv[i+1])) 
            {
                   check=1;
            }
            else
            {   check =0;
                printf("Wrong input!\n");
            }
        } 

           if(check) {
         FILE* fp = fopen("todolist.txt", "w");
                       
					  for (int i = 1; i < argc; i += 2) 
                      {
			            fprintf(fp, "%s - %s\n", argv[i], argv[i+1]);
                      }

		         fclose(fp); 

}
	
    return 0;
}
//WHole code work properly it also append correct data into todolist but it shows Wrong input though i put correct data!
