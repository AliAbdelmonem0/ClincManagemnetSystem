#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "StdTypes.h"
#include "Clinic.h"


extern node *Head  ;
extern node *current  ;
extern node *prev  ;
extern u32 ListLength,Size,ID,time,i;
u32 arr[5]={-1,-1,-1,-1,-1};

node* NewNode()
{
	node* temp=(node*)malloc(sizeof(node));
	return temp;
}

void AddPatient(u8 name[],u32 age,u8 gender[], u32 id)
{
    node *NewPatient = (node *)malloc(sizeof(node));
    u32 position = 0;
    current = Head;

    while(current != NULL)
    {
        if (current->id == id)
        {
            printf("This ID Is Already Exist\n");
            return;
        }
        current = current -> next;
        position++;
    }

   strcpy(NewPatient->name,name);
   NewPatient->age = age;
   strcpy(NewPatient->gender,gender);
   NewPatient->id = id;
   NewPatient->next = NULL;
   printf("The Patient Is Added Successfully \n\n");
      current = Head;
    if(Head==NULL)
   {
      Head = NewPatient;
      return;
   }
   while(current->next != NULL)
   {
	   current = current->next;

   }
   current->next = NewPatient;
    Size++;

}


void EditPatientRecord(u32 id)
{
    u8 flg = 0;
    current = Head;
    while(current != NULL && flg==0)
   {
      if(current->id == id)
      {
		printf("Enter The New Name: ");
		scanf(" %[^\n]%*c",current->name);
		printf("Enter The New Age: ");
		scanf("%d",&current->age);
		printf("Enter The New Gender: ");
		scanf(" %[^\n]%*c",current->gender);
		printf("Enter The New ID: ");
		scanf("%d",&current->id);
		flg=1;
      }
	  current = current->next;
   }

   if (flg == 1)
   {
	   printf("The Patient Record Is Edited Successfully\n");
	   return;
   }

   if (flg == 0)
	{
		printf("This Patient Is Not Registered\n");
	}

	return;
}



void TimeReservationForUser()
{
    	u8 flg = 0;
        printf("There Available Slots : \n");
     for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0 : if(arr[0]!=-1){ break;}
                    else{ printf("-> From 2pm to 2:30pm Available, To Reserve This Slot Please Enter [1] \n");}
            break;

			case 1 : if(arr[1]!=-1){ break;}
                    else{ printf("-> From 2:30pm to 3pm Available, To Reserve This Slot Please Enter [2] \n");}
            break;

			case 2 : if(arr[2]!=-1){ break;}
                    else{ printf("-> From 3:30pm to 4pm Available, To Reserve This Slot Please Enter [3] \n");}
            break;

			case 3 : if(arr[3]!=-1){ break;}
                    else{ printf("-> From 4pm to 4:30pm Available, To Reserve This Slot Please Enter [4] \n");}
            break;

			case 4 : if(arr[4]!=-1){ break;}
                    else{ printf("-> From 4:30pm to 5pm Available, To Reserve This Slot Please Enter [5] \n");}
            break;
		}
	}
	printf("You Should Have Id To Reserve A Slot \n");

    printf("Please, Enter Your ID: ");
	scanf("%i",&ID);

	printf("Enter Your Choice : ");
	scanf("%i" , &time);

	for(i=0;i<5;i++)
	{
			if(arr[i]==ID)
			{
				arr[i]=-1;
			}
    }

   current = Head;
   while(current != NULL)
   {
      if(current->id == ID)
      {
        arr[time-1]=ID;
		flg = 1;
      }
      current = current->next;
   }

   if (flg == 1)
   {
	   printf("The Slot Is Reserved Successfully \n");
	   return;
   }

   if (flg == 0)
	  {
	     printf("This ID Is Not Exist, Please Sign up First \n");
	  }
		return;

}



void CancelReservation(u32 ID)
{
	u8 flg=0;
	for(i=0;i<5;i++)
	{
			if(arr[i]==ID)
			{
				arr[i]=-1;
				flg=1;
			}
    }

	if (flg==1)
	{
		printf("The Reservation Is Cancelled Successfully \n");
	}

	if(flg==0)
	{
		printf("You Enterd Wrong ID !! \n");
		return;
	}
	return;
}



void ViewPatientRecord(u32 id)
{
    u8 flg=0;
    current = Head;
    while (current != NULL)
    {
        if (current->id == id)
        {
            printf("-> Patient Name: ");
            printf(current->name);
	        printf("\n");
            printf("-> Patient Age: %d\n",current->age);
            printf("-> Patient Gender: ");
            printf(current->gender);
	        printf("\n");
            printf("-> Patient ID: %d\n",current->id);
			PatientReservation (current->id);

	     flg=1;
        }
        current = current->next;
    }

    if (flg == 0)
    {
		printf(" This Patient Is Not Registered \n");
	}
	return;
}


void PrintReservations()
{
	for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0 : if(arr[0]==-1){break;}
                    else{ printf("From 2pm To 2:30pm is Reserved By The ID Num: %d\n",arr[0]);}
            break;

			case 1 : if(arr[1]==-1){break;}
                    else{ printf("From 2:30pm To 3pm is Reserved By The ID Num: %d\n",arr[1]);}
            break;

			case 2 : if(arr[2]==-1){break;}
                    else{ printf("From 3:30pm To 4pm is Reserved By The ID Num: %d\n",arr[2]);}
            break;

			case 3 : if(arr[3]==-1){break;}
                    else{ printf("From 4pm To 4:30pm is Reserved By The ID Num: %d\n",arr[3]);}
            break;

			case 4 : if(arr[4]==-1){break;}
                    else{ printf("From 4:30pm To 5pm is Reserved By The ID Num: %d\n",arr[4]);}
            break;
		}
	}
}

void PatientReservation(u32 id)
{
    u8 flg = 0;
	for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0 : if(arr[0] != id){break;}
                    else{ printf("-> This Patient Reserved A Slot From 2pm to 2:30pm\n");
                    flg = 1;}
            break;

			case 1 : if(arr[1] != id){break;}
                    else{ printf("-> This Patient Reserved A Slot From 2:30pm to 3pm\n");
						  flg = 1;}
            break;

			case 2 : if(arr[2] != id){break;}
                    else{ printf("-> This Patient Reserved A Slot From 3:30pm to 4pm\n");
                          flg = 1;}
            break;

			case 3 : if(arr[3] != id){break;}
                    else{ printf("-> This Patient Reserved A Slot From 4pm to 4:30pm\n");
							flg = 1;}
            break;

			case 4 : if(arr[4] != id){break;}
                    else{ printf("-> This Patient Reserved A Slot From 4:30pm to 5pm\n");
							flg = 1;}
            break;
		}
	}

	if (flg == 0)
	{
		printf("-> This Patient didn't Reserve Any Slots\n");
	}
}




