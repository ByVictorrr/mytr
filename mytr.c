#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mytr.h"

void initTable(int *table)
{
	int i;
	for(i=0; i<ASCII; i++)
		table[i] = i;
}
int strl(char * s)
{
		char * base = s;

		while (*(++s) != '\0')
			;
			return s - base;
}

/* getline: reads a line then stores into line 
return 0: returned normall;
*/
int getLine( int *table)
{
	char c;
	while ( (c = getchar()) != EOF )
	{	
		if(table[(int)c]!= DELETED)
			putchar(table[(int)c]);
		if(c=='\n');
	}
	return 0; /*for overflow error or EOF*/
}
int getFormat(int argc, char *set1)
{ 
	switch(argc)
	{
		case 1: 
			fprintf(stderr, "mytr:\n usage: mytr [-d] 'set1' ['set2'] \n");
			return 0;
			break;
		case 2:
			if (strcmp(set1,"-d") != 0)
				fprintf(stderr, "mytr:\n usage: mytr [-d] 'set1' ['set2'] \n");
			else
				fprintf(stderr, "mytr:\n usage: mytr [-d] 'set1' ['set2'] \n");
			return 0;
			break;
		case 3: /*should be three if no error*/
			if ( strcmp(set1,"-d") == 0) /* if set1 is -d - delete mode*/
				return 1;
			else
				return 2; /*translation set1 -> set 2*/
		default:
			fprintf(stderr, "mytr:\n usage: mytr [-d] 'set1' ['set2'] \n");
			return 0;
	}
}

/*getEscChar: return the value value of espace character given that \ is the character before c in the string*/
char getEscChar(char c)
{
	switch(c)
	{
	case '\\': /* have to check this way because computer reads in \\ but in characters \\ is \*/
		return '\\';
	case 'n':
		return '\n';
	case 't':
		return '\t';
	}
	return c;
}

/*fills table for delete option:
 *table[deleteC] = -1; if used
 *table[i] = i; if not used
 */
void fillDeleteTable(int *table, char *set)
{
	char c;
	while (*set){
		if (*set == '\\' && *(set+1) != '\0') /* if set1 has a escape character*/
		{
			if(*(set+1) == 't' || *(set+1) =='\\' || *(set+1) == 'n')
			{
			c = getEscChar(*(set+1));
			set++;
			}
		}else
			c = *set;
	table[(int)c]= DELETED; /*this indicates that in our hash table if you give it a key of c->-1 if used alread*/
	set++;
	}
}

void fillTranslateTable(int *table, char *set1, char *set2)
{
	char c, b;
	int i, j, size1 = strl(set1), size2 = strl(set2);
	for(i=0,j=0; i< size1; i++) /*go till set1 == '\0'*/
	{ 
		if(set1[i] == '\\' && i <= size1-2){
			c=getEscChar(set1[i+1]);
			if(c == '\t' || c=='\\' || c == '\n' )
				i++;
		}
		else
			c=set1[i];	
/*check set 2*/
		if(set2[j] == '\\' && j <= size2-2)
		{	b=getEscChar(set2[j+1]);
			if(b == '\t' || b=='\\' || b== '\n')
				j++;
		}
		else
			b=set2[j];	

		if(c != '\n')	
			table[(int)c] = b;	
		else{ /*if set1 has \n' in it everything else equals null*/
			int k;
			for(k=0; k<ASCII; k++){
				table[(int)k] = '\0';
			}
			}
		/*will get here if set1 > set2*/	
		if (j< size2-1 )
			j++;
	}
		
	/*if reached last char of set2 i is index at which that ends*/
}
int main(int argc, char *argv[])
{
/* getFormat: 
return  0: if there is an error end program
returns 1: in -d mode
return  2: in tranlate mode
*/

	switch(getFormat(argc,argv[1]))
	{
		case 0: /* usage error*/
			return 0;

		case 1: /* mytr -d 'set' option*/
		{
			initTable(hashTable); /* hashTable[i] = i; if not used*/
			fillDeleteTable(hashTable, argv[2]);
			getLine(hashTable);
		}
		case 2: /* mytr 'argv[1]' 'argv[2]'*'*/
		{
			initTable(hashTable); /* hashTable[i] = i; if not used*/
			fillTranslateTable(hashTable, argv[1], argv[2]);
			getLine(hashTable);
		}
	}
		return 0;

}


