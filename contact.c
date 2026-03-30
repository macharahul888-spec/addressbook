//Documentation
//Nmae   : M.Rahul
//ID     :25021-326
//Date   :28-09-2025
//Description : AddressBook Project  
#include <stdio.h>
#include <stdlib.h> //< > for representing library
#include <string.h>
#include <strings.h>
#include "contact.h" // whichever code on same directory is included
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
  // Sort contacts based on the chosen criteria
  if ( sortCriteria == 1 ) //sorting based on name 
  {
    for ( int i = 0 ; i < addressBook->contactCount - 1 ; i++) //outer loop
    {
      for ( int j = 0 ; j < addressBook->contactCount - i - 1 ; j++ ) //inner loop
      {
        if (( strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name) > 0 ))  //compare two string
        {
          char temp[50]; //tempory varible(dest,rsc)
          strcpy(temp,addressBook->contacts[j].name);//copie name (dest,rsc)
          strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
          strcpy(addressBook->contacts[j+1].name,temp);
        }
      }
    }

    printf("%-30s%-30s%-30s%-30s\n\n","SL NO","Name","Number","Email");
    for ( int i = 0 ; i < addressBook->contactCount ; i++ )
    {
      printf("%-30d%-30s%-30s%-30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }


  }

  else if ( sortCriteria == 2 ) //sorting based on number
  {
    for ( int i = 0 ; i < addressBook->contactCount - 1 ; i++) //outer loop
    {
      for ( int j = 0 ; j < addressBook->contactCount - i - 1 ; j++ ) //inner loop
      {
        if (( strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone) > 0 )) //compare two string
        {
          char temp[50]; //tempory varible(dest,rsc)
          strcpy(temp,addressBook->contacts[j].phone);//copie number (dest,rsc)
          strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
          strcpy(addressBook->contacts[j+1].phone,temp);
        }
      }
    }

    printf("%-30s%-30s%-30s%-30s\n\n","SL NO","Name","Number","Email");
    for ( int i = 0 ; i < addressBook->contactCount ; i++ )
    {
      printf("%-30d%-30s%-30s%-30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

  }

  else if ( sortCriteria == 3 ) //sorting based on email
  {
    for ( int i = 0 ; i < addressBook->contactCount - 1 ; i++) //outer loop
    {
      for ( int j = 0 ; j < addressBook->contactCount - i - 1 ; j++ ) //inner loop
      {
        if (( strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email) > 0 )) //compre two string
        {
          char temp[50];//tempory varible(dest,rsc)
          strcpy(temp,addressBook->contacts[j].email);//copie email(dest,rsc)
          strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);
          strcpy(addressBook->contacts[j+1].email,temp);
        }
      }
    }

    printf("%-30s%-30s%-30s%-30s\n\n","SL NO","Name","Number","Email");
    for ( int i = 0 ; i < addressBook->contactCount ; i++ )
    {
      printf("%-30d%-30s%-30s%-30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

  }

  else if ( sortCriteria == 4 ) //normal listing
  {
    printf("%-30s%-30s%-30s%-30s\n\n","SL NO","Name","Number","Email");
    for ( int i = 0 ; i < addressBook->contactCount ; i++ )
    {
      printf("%-30d%-30s%-30s%-30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

  }
}

void initialize(AddressBook *addressBook) {
  addressBook->contactCount = 0;
  //populateAddressBook(addressBook);

  //Load contacts from file during initialization (After files)
  loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
  saveContactsToFile(addressBook); // Save contacts to file
  exit(EXIT_SUCCESS); // Exit the program
}

void createContact(AddressBook *addressBook)
{
    char name[50], number[20], email[50]; //declare charcter array
    
    while (1) //infinte loop run,the loop will be only exit when a break. 
    { 
        printf("Enter the Name: ");
        scanf(" %[^\n]", name); //read user input
        if (validation_name(name)) //call function 
        break;
        printf("Invalid name. Please try again.\n"); //if condition fale print invalid name
    }

    while (1) //infinte loorun,the loop will be only exist a break
    {
        printf("Enter the Number: ");
        scanf(" %[^\n]", number);//read user input
        if (validation_phone_no(number, addressBook)) //call function
        break;
        printf("Invalid or duplicate phone number. Please try again.\n");
    }

    while (1) //run loop infinte,it will be only exist
    {
        printf("Enter the Email: ");
        scanf(" %[^\n]", email);//read user input
        if (validation_email(email, addressBook)) //call function 
        break;
        printf("Invalid or duplicate email. Please try again.\n");
    }

    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, number);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email); //copie name,number,email
    addressBook->contactCount++; //increment contact count

    printf("Contact added successfully!\n");
}

int searchContact(AddressBook *addressBook) 
{
    char finder[50]; //declare character array
    int option;//declare interger varible
    printf("\nEnter Searching Options\n\n");
    printf("1. Search By Name\n");
    printf("2. Search By Number\n");
    printf("3. Search By Email\n");
    printf("Choose an Option: ");
    scanf("%d", &option);
    getchar(); // clear newline

    switch (option) 
    {
        case 1: 
        {
            printf("Enter the name to search: ");
            scanf(" %[^\n]", finder);

            for (int i = 0; i < addressBook->contactCount; i++) //loop start a iterate
            {
                if (strcmp(finder, addressBook->contacts[i].name) == 0) //check compare string
                {
                    printf("\n%-5s%-30s%-30s%-30s\n", "ID", "Name", "Number", "Email");
                    printf("%-5d%-30s%-30s%-30s\n", i,
                           addressBook->contacts[i].name,
                           addressBook->contacts[i].phone,
                           addressBook->contacts[i].email); 
                    return i;
                }
            }
            break;
        }

        case 2: 
        {
            printf("Enter the number to search: ");
            scanf(" %[^\n]", finder); //user input

            for (int i = 0; i < addressBook->contactCount; i++) //loop start a iterate 
            {
                if (strcmp(finder, addressBook->contacts[i].phone) == 0)  //comparing two string
                {
                    printf("\n%-5s%-30s%-30s%-30s\n", "ID", "Name", "Number", "Email");
                    printf("%-5d%-30s%-30s%-30s\n", i,
                           addressBook->contacts[i].name,
                           addressBook->contacts[i].phone,
                           addressBook->contacts[i].email);
                    return i;
                }
            }
            break;
        }

        case 3: 
        {
            printf("Enter the email to search: ");
            scanf(" %[^\n]", finder);//user input

            for (int i = 0; i < addressBook->contactCount; i++) //loop to itrate every single contact
            {
                if (strcmp(finder, addressBook->contacts[i].email) == 0) //compare two string 
                {
                    printf("\n%-5s%-30s%-30s%-30s\n", "ID", "Name", "Number", "Email");
                    printf("%-5d%-30s%-30s%-30s\n", i,
                           addressBook->contacts[i].name,
                           addressBook->contacts[i].phone,
                           addressBook->contacts[i].email);
                    return i;
                }
            }
            break;
        }

        default:
            printf("Invalid search option.\n");
            return -1;
    }

    printf("\nNo contact found.\n");
    return -1;  // not found
}

void editContact(AddressBook *addressBook)
{
    if (searchContact(addressBook) == 1)
    {
        int index; //declare interger varible
        printf("Enter the index you want to edit: ");
        scanf("%d", &index); //read input

        int option;
        printf("\nEDIT MENU\n1. Edit the name\n2. Edit the number\n3. Edit the email\nChoose an option: ");
        scanf("%d", &option);

        char newValue[100]; //declare character array
        int valid = 0; //declare interger varible valid and initializes it to 0.

        switch (option) //switch statement
        {
            case 1:
                while (!valid) //while loop run
                {
                    printf("Enter the new name: ");
                    scanf(" %[^\n]", newValue);
                    valid = validation_name(newValue); //call function
                    if (!valid) printf("Invalid name. Please try again.\n"); //if not valid print this message
                }
                strcpy(addressBook->contacts[index].name, newValue); //copie new name
                break;

            case 2:
                while (!valid) //while loop run
                {
                    printf("Enter the new number: ");
                    scanf(" %[^\n]", newValue);
                    valid = validation_phone_no(newValue, addressBook); //call funtion
                    if (!valid) printf("Invalid or duplicate phone number. Please try again.\n"); //if not valid print this message
                }
                strcpy(addressBook->contacts[index].phone, newValue); //copie new number
                break;

            case 3:
                while (!valid)
                {
                    printf("Enter the new email: ");
                    scanf(" %[^\n]", newValue);
                    valid = validation_email(newValue, addressBook); //call function
                    if (!valid) printf("Invalid or duplicate email. Please try again.\n"); //if not valid print this message
                }
                strcpy(addressBook->contacts[index].email, newValue); //copie new email
                break;

            default:
                printf("Invalid option selected.\n");
                return;
        }

        printf("Data has been updated successfully!\n\n");
    }
    else
    {
        printf("Data not found.\n");
    }
}
void deleteContact(AddressBook *addressBook) 
{
    int ret = searchContact(addressBook); //declare integer varible ret and assign it the result of calling the search contact

    if (ret == -1) 
        return;

    char confirm; //declare character varible
    printf("Do you want to delete this contact? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') { //check user input either y or n
        for (int i = ret; i < addressBook->contactCount - 1; i++) 
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];//copie data next count
        }
        addressBook->contactCount--; //decrement contact count
        printf("Contact deleted successfully.\n");
    } else 
    {
        printf("Contact not deleted.\n");
    }
}