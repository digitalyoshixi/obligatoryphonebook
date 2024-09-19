#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// forward delcaration of functions
void returncontacts();
bool addcontact(char *name, char* phonenum);
bool delcontact(char *name);


int main(){
  // contact structure
  struct contact{
    char name[20];
    char phonenum[11];
  };
  // list of contacts for phone book
  struct contact phonebook[20];
  int highestindex = 0;

  // user input
  char userinput;
  
  while (true){
    printf("a) View Phonebook\nb) Add contact\nc) Delete contact\n");
    scanf(" %c", &userinput);
    switch (userinput){
      case 'a':
      printf("---------Phonebook---------\n");
        for (int i = 0; i < highestindex; i++){
          printf("%d: %s, %s\n", i, phonebook[i].name, phonebook[i].phonenum);
        }
      printf("---------------------------\n");
        break;

      case 'b':
        struct contact newcontact;
        printf("Name: ");
        scanf("%s", newcontact.name);
        printf("Phone: ");
        // make a temporary value for phone number (since it can be integer)
        scanf("%10s[^\n]", newcontact.phonenum);
        phonebook[highestindex] = newcontact;
        printf("Added %s\n",phonebook[highestindex].name);
        highestindex++;
        break;

      case 'c':
        char todelete[20];
        printf("Name: ");
        scanf("%s", todelete);

        // search the phonebook for the person
        for (int i = 0; i < highestindex; i++){
          if (strcmp(phonebook[i].name , todelete) == 0){
            highestindex--;
            printf("Removed %s\n", todelete);
          }
        }
        break;
                
      default:
        break;
    }
        
  }
}
