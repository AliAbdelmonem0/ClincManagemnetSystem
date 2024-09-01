/*
===================================================================================================
 * Auther : Ali Abdelmonem Ali Ibrahim
 * Object : Clinic mangement system
 * date   : 27/8/2024
 * main.c
===================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "STDTYPES.h"
#include "Clinic.h"

node *Head = NULL ;
node *current = NULL;
node *prev = NULL;

u32 ListLength = 0,Size=0,ID,time,i;
u8 name[60];
u8 gender[10];
u32 PatientAge,PatientId,id;


void main (void)
{
    u8 flag = 0 , exit_f = 1;
    u32 Correctpass , AdminInput , userinput , mode ,newValue,Node_Value,position;

    while(exit_f)
    {
        printf("********************************************************\n");
        printf("************* Welcome To SkinCare Clinic  **************\n");
        printf("********************************************************\n");
	    printf("-> Enter [1] For Admin Mode \n");
	    printf("-> Enter [2] For User Mode \n");
		printf("-> Enter [0] To Exit the Program \n");
	    printf("your choice : ");
	    scanf("%i" , &mode);

	    if(mode == 1)
        {
          printf("=============== To Be In Admin Mode ===============\n");

		  printf("Please Enter The Password : ");
		  for(i = 0; i < 3; i++)
          {
		     scanf("%i" , &Correctpass);
		     if (Correctpass == 1234)
             {
                printf("********************************************************\n");
                printf("**************** Welcome To Admin Mode *****************\n");
                printf("********************************************************\n");

				flag = 1;
				break;
             }
              if (i < 2)
             {
                 printf("Wrong password !!! Please Try Again: ");

             }
		  }
		  if (flag == 1)
          {
				  printf("-> Enter [1] To Add New Patient \n");
				  printf("-> Enter [2] To Edit The Patient Record \n");
				  printf("-> Enter [3] To Reserve A Slot With The Doctor \n");
				  printf("-> Enter [4] To Cancel A Reservation \n");
				  printf("-> Enter [0] To Exit The Program  \n");
				  printf("your choice : ");
				  scanf("%d" , &AdminInput);

				  switch(AdminInput)
				  {
                      case 1 :
                              printf("Please Enter The Patient's Name: ");
			                  scanf(" %[^\n]%*c",name);
					          printf("Please Enter The Patient's Age: ");
			                  scanf("%i",&PatientAge);
					          printf("Please Enter The Patient's Gender (Male or Female): ");
			                  scanf(" %[^\n]%*c",gender);
                              printf("Please Enter The Patient's Id: ");
			                  scanf("%i",&PatientId);
					          AddPatient(name,PatientAge,gender,PatientId);
                              break;

                      case 2 :
                              printf("Enter The Patient ID: ");
					          scanf("%i",&id);
					          EditPatientRecord(id);
                              break;

                      case 3 :
                              TimeReservationForUser();
					          break;

                      case 4 :
                             printf("Enter Your ID: ");
					         scanf("%d",&id);
                             CancelReservation(id);
                             break;
					  case 0 :
					         exit_f = 0;
		                     printf("**************************************************\n");
                             printf("************* End Program Thank You **************\n");
		                     printf("**************************************************\n");
							 break;
                      default :
                           printf("Invalid Choice Please Try Again.\n");
                           break;


				  }
          }
          else if (flag == 0)
          {
           printf("Incorrect Password For 3 Times The Program Closed\n");
           printf("================= Thank You ==================\n");
           exit_f = 0;
          }
    }
    else if (mode == 2)
    {
             printf("*******************************************************\n");
             printf("********************** Welcome In *********************\n");
             printf("********************** User Mode **********************\n");
		     printf("*******************************************************\n");
             printf("-> Enter [1] To Dispaly Paitent File \n");
			 printf("-> Enter [2] To View Today Reservations \n");
			 printf("-> Enter [0] To Exit The Program \n");
			 printf("Your Coice : ");
			 scanf("%i" , &mode);
			 switch(mode)
			 {
				 case 1 :
				          printf("Please, Enter Patient ID : " );
				          scanf("%i" , &id);
				          printf("*******************************************************\n");
                          printf("******************* Patient Record ********************\n");
						  printf("                  ******************\n");

					      ViewPatientRecord(id);
				          break;

				 case 2 :
                          printf("*******************************************************\n");
				          printf("***************** Today Reservations ******************\n");
						  printf("                 ********************\n");
					      PrintReservations();
				          break;

                 case 0 :
					      exit_f = 0;
		                  printf("**************************************************\n");
                          printf("************* End Program Thank You **************\n");
		                  printf("**************************************************\n");
						  break;

				 default :
                         printf("Invalid Choice Please Try Again\n");
                         break;
			 }

        }
        else if (mode == 0)
        {
           exit_f = 0;
		   printf("******************************************************\n");
           printf("*************** End Program Thank You ****************\n");
		   printf("******************************************************\n");
        }
        else
        {
            printf("Wrong Data!!!!\n");
        }
    }
}

