#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  int pid;
  int cont=1,cont2=1,cont3=1;
  int opcio1=-1, opcio2=-1, opcio3=-1, opcio4;
  while(cont2 == 1){
    //getting option 1 from user
    printf("Select what service you want to make:\n");
    printf("1- Service one - Order your meal.\n");
    printf("2- Service two - Return total time o deliver the order.\n");
    printf("3- Service three - Return total cost of the meal.\n");
    scanf("%d", &opcio4);
    if(opcio4 == 0){
      cont2=0;
      return -4;
    }
    while(opcio4 < 1 || opcio4 > 3){
      printf("Numero no correcte, torna a escriure 1, 2 o 3: ");
      scanf("%d", &opcio4);
    }
  pid = fork();

  if(pid == 0){
    //check if the opcio4 is 1, 2 or 3 because the code of the child will depend on that number
    if(opcio4 == 1){
      //service 1 code
    } else if (opcio4 == 2){
      //service 2 code
    } else if(opcio4 == 3){
      //service 3 code
    }
    
    //child process: takes order
    while(cont==1){
      //getting option 1 from user
      printf("ENTRANT CHOISES? -- type 0 to quit program.\n");
      printf("1) Crispy baked falafel         - costs: 3.50 EUR - time: 3 mins.\n");
      printf("2) Peanut Slaw in soba Noodles  - costs: 2.50 EUR - time: 1 mins.\n");
      printf("3) Bio Hummus                   - costs: 3.00 EUR - time: 2 mins.\n");
      scanf("%d", &opcio1);
      if(opcio1 == 0){
	cont=0;
	return -1;
      }
      while(opcio1 < 1 || opcio1 > 3){
	printf("Numero no correcte, torna a escriure 1, 2 o 3: ");
	scanf("%d", &opcio1);
      }
      printf("Has escollit la opcio (%d).\n",opcio1);
      //getting option 2 from user
      printf("MAIN DISH CHOISES -- type 0 to quit program.\n");
      printf("4) Minimal eggplant Lasagna - costs: 4.00 EUR - time: 3 mins.\n");
      printf("5) Spicy Veggie Tacos       - costs: 4.50 EUR - time: 4 mins.\n");
      printf("6) Plant Based XXL Burger   - costs: 5.00 EUR - time: 5 mins.\n");
      scanf("%d", &opcio2);
      if(opcio2 == 0){
	cont=0;
	return -2;
      }
      while(opcio2 < 4 || opcio2 > 6){
	printf("Numero no correcte, torna a escriure 4, 5 o 6: ");
	scanf("%d", &opcio2);
      }
      printf("Has escollit la opcio (%d).\n",opcio2);
      //getting option 3 from user
      printf("DRINKS -- type 0 to quit program.\n");
      printf("7) Sparlinkg Water  - costs: 1.00 EUR - time: 1 mins.\n");
      printf("8) Macha Ice Tea    - costs: 1.50 EUR - time: 1 mins.\n");
      printf("9) Bio Orange Juice - costs: 2.50 EUR - time: 1 mins.\n");
      scanf("%d", &opcio3);
      if(opcio3 == 0){
	cont=0;
	return -3;
      }
      while(opcio3 < 7 || opcio3 > 9){
	printf("Numero no correcte, torna a escriure 7, 8 o 9: ");
	scanf("%d", &opcio3);
      }
      printf("Has escollit la opcio (%d).\n",opcio3);
      printf("Opcions escollides:\nOpcio1: %d\nOpcio2: %d\nOpcio3: %d\n", opcio1, opcio2, opcio3);
      return 0;
    }
  } else {
    //parent process
    int wstatus;
    wait(&wstatus);
    if(WIFEXITED(wstatus)){
      int statusCode = WEXITSTATUS(wstatus);
      printf("Status Code: %d.\n", statusCode);
      if(statusCode == 0){
	printf("Code executed correctly.\n");
      } else if(statusCode == 255){
	printf("Error en 1st part of the code.\n");
      } else if(statusCode == 254){
	printf("Error en 2nd part of the code.\n");
      } else if(statusCode == 253){
	printf("Error en 3rd part of the code.\n");
      }
    }
  }
  //while statement
}
  return 0;
}
