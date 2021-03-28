#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  int opcio, op1=-1, op2=-1, op3=-1;

  do{
    printf("Select and option: type 0 to exit program\n");
    printf("1. Service one: Meal order.\n");
    printf("2. Service two: Calculate deliver time\n");
    printf("3. Service three: Calculate total meal cost\n");
    scanf("%d", &opcio);
    
    switch(opcio){
      case 1 :
	//execute service 1 code
	
	break;
      case 2 :
	//execute service 2 code
	if(op1 == -1 && op2 == -1 && op3 == -1){
	  printf("No order to be delivered, please select service 1 and make your order.\n");
	} else {
	  printf("Creating child to make the calculations.\n");
	  
	}
	break;
      case 3 :
	//execute service 3 code
	if(op1 == -1 && op2 == -1 && op3 == -1){
	  printf("No order to be delivered, please select service 1 and make your order.\n");
	} else {
	  printf("Creating child to make the calculations.\n");
	  
	}
	break;
      case 0:
	//exit program
	printf("Exiting program.\n");
	return 0;
      default :
	//unwanted values in menu
	printf("Opcio incorrecta, escull un servei del menu.\n");
	break;
    }
  } while (opcio != 0);
  return 0;
}
