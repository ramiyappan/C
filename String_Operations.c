
//**** NAME           :   RAMASWAMY IYAPPAN   ****//
//**** GEORGE MASON   :   SPRING 2022         ****//
//**** G_NUMBER       :   G01348097           ****//
//**** COURSE         :   CS-531              ****//
//**** HOMEWORK       :   1                   ****//


#include <stdio.h>    						// For Standard I/O operations
#include <string.h>   						// For String operations

/********	 User-defined function for checking empty string 	********/
int empt(char *str)    
{ 
  int flag=0;
  if(strlen(str)==0) 						// Condition for checking Empty string
  {
    printf("\n---ERROR: String cannot be empty!!---\nPlease enter again..\n");
    flag++;
  }
  return flag;
}

/********         User-defined function for checking Duplicate string	 ********/
int dup(char *str,char s[][26])
{ 
  int dupflag=0;
  for(int new=0;new<10;new++)					// Loop for checking if current input string is already in the array
  {
    if(strcmp(s[new],str)==0)
    { 
      printf("\n---ERROR: Duplicate string!!---\nPlease enter any other string..");
      dupflag++; 
    }
  }
  return dupflag;
}

/******** 	 User-defined function for bubble sorting the Entered Strings 	 ********/
void bubsort(char s[][26])
{ 
  char temp[30];
  for (int i=0;i<10;i++)
  {
    for(int j=0;j<9-i;j++)
    {
      if(strcmp(s[j],s[j+1])>0)
      {
        strcpy(temp, s[j]);
        strcpy(s[j],s[j+1]);
        strcpy(s[j+1],temp);
      }
    }
  }
}

/******** User-defined function for Printing the Ascending order of Entered Strings ********/
void print_ASC(char s[][26])
{
  printf("\nAscending order of Character Strings:\n-------------------------------------\n");
  for(int i=0;i<10;i++)
    printf("%s\n",s[i]);
}

/******** User-defined function for Printing the Descending order of Entered Strings ********/
void print_DESC(char s[][26])
{
  printf("\nDescending order of Character Strings:\n--------------------------------------\n");
  for(int i=9;i>=0;i--)
    printf("%s\n",s[i]); 
}

/*************	 Beginning of the main() function	 *************/
int main() 
{
  char s[10][26];  						// 2D Array variable to store entered valid character strings 
  char str[26];    						// Temporary String variable to store the input entered by the user
  int i,j,flag,p; 				        	// Loop variables
  char invd[] = {'!','@','#','$','%','^','(',')'};  		// Array of invalid characters
  printf("\t\t\t------- Enter 10 Character Strings -------"); 
  for(i=0;i<10;i++) 						// Loop for prompting 10 character strings
  { 
    c:
    flag = 0;
    memset(str,'\0',sizeof(str));				// Clearing the memory
    printf("\nEnter String %d: ", i+1);
    fgets(str,26,stdin);
    str[strcspn(str,"\n")] = '\0';				// To remove newline stored in fgets
    
    if(strlen(str) == 25)					// To check for possible unread characters in the input stream
    	while((p = getchar()) != EOF)
	{
	   if(p!='\n')
	   {
	      flag = 2;
	   }
           else
              break;
        }

    if(flag == 2)						// Condition for checking if the string has more than 25 characters
    { 
       printf("\n---ERROR: Invalid length!!---\nPlease enter between 1 to 25 characters..\n");
       goto c;
    }

    flag = empt(str);						// calling empt() function for checking if empty
    if(flag!=0)
       goto c; 							// if empty goes to c label and reprompts the user
    
    for(j=0;j<8;j++)    					// Loop for checking if invalid characters are present
      while(strchr(str,invd[j])!=NULL)
      {
        printf("\n---ERROR: %c is an invalid character!!--- \nPlease enter again..\n", invd[j]);
        goto c; 						// if present goes to c label and reprompts the user
      }
    
    int dupflag = dup(str,s);    				// calling dup() function
    if(dupflag!=0)
      goto c;							// if duplicate is found goes to c label and reprompts the user
      
    if(flag==0 && dupflag==0)  	// copies character strings from temporary variable(str) into 2d Array(s) if all valid cases satisfied
      strcpy(s[i],str);     
  }
  
  bubsort(s);							// Calling bubsort() function for sorting the character strings array(s)
  
  printf("\nPrint character strings in Ascending or Descending order: ");
  
  char g;							// for getting user input choice for Ascending or Descending
  scanf(" %c", &g);
  
  while(g!='A' && g!='D') 					// Condition for checking input characters other than 'A' or 'D'
  {
    printf("\n---ERROR: Invalid Character!!---\nPlease Enter either 'A' or 'D' :");
    scanf(" %c", &g);
  }
  
  if(g=='D')
    print_DESC(s);						//if 'D' calls print_DESC() function to print Descending order
  if(g=='A')
    print_ASC(s);						//if 'A' calls print_ASC() function to print Ascending order

  printf("\nString with lowest ASCII value: %s", s[0]);		// String with low ASCII
  printf("\nString with highest ASCII value: %s\n", s[9]);	// String with high ASCII

  return 0;
}
