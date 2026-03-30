#include <stdio.h>
#include "file.h"
#include"contact.h"


void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fptr = fopen("contact.csv", "r"); //declare a file pointer fptr and opens read mode
    if (fptr == NULL) { //check if the file open failed
        printf("Error opening file to load the contacts!\n");
        return;
    }

    int num =0;

    fscanf(fptr,"%d\n",&num); 

    addressBook->contactCount=num; //store read number


    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        fscanf(fptr, "%[^,],%[^,],%[^\n]\n",
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email); //read the name,phone,email
    }

    fclose(fptr); //close fptr pointer
}


void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fptr = fopen("contact.csv", "w"); //declare a file pointer fptr and open file write mode
    if (fptr == NULL) //check if the file open failed 
    {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fptr, "%d\n", addressBook->contactCount);

    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        fprintf(fptr, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email); //print write name,phone,email
    }

    fclose(fptr); //close fptr pointer
}
