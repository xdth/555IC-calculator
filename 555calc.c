
#include <stdio.h>
#include <unistd.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

void getEnter(void); /* second void? */
int first(int, int, int);
int second(int, int);
void get1(int *, int *, int *);
void get2(int *, int *);

float timeHigh;
float timeLow;
float duty_cycle_percentage;
float frequency;
float timeoutDelay;

int main (int argc, char** argv){
  int value1, value2, value3, operation;
  clear();
  while(1) {
    gotoxy(20,9);
    printf("555 IC calculator\n\n\n");
    printf("\t[0] Exit\n\t[1] Astable    :: Square wave\n\t[2] Monostable :: Timeout\n\n\n\n\tChoose an operation: ");
    scanf("%d", &operation);
    switch(operation) {
      case 0:
        clear();
        printf("Goodbye\n");
        return 0;
      case 1:
        get1(&value1, &value2, &value3);
        printf("%d", first(value1,value2,value3));
        break;
      case 2:
        get2(&value1, &value2);
        printf("%d", second(value1,value2));
        break;
      default:
        printf("Error: Unrecognized command, try again.");
        getEnter();
        break;
    }
  }
}

void getEnter(void) {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
  printf("\n\n\n\n\n\n\tPress ENTER to go back to the menu.");
  while (ch = getchar()) != '\n' && ch != EOF);
 clear();
}

void result(void) {
  printf("\n\n\tResult:\n\t");
}

void get1(int *value1_ptr, int *value2_ptr, int *value3_ptr) {
  printf("\tValue of the 1st resistor (R1) in Ohms: ");
  scanf("%d", value1_ptr);
  printf("\tValue of the 2nd resistor (R2) in Ohms: ");
  scanf("%d", value2_ptr);
  printf("\tValue of the capacitor (C1) in Farads: ");
  scanf("%d", value3_ptr);
}

void get2(int *value1_ptr, int *value2_ptr) {
  printf("\tValue of the resistor (R1) in Ohms: ");
  scanf("%d", value1_ptr);
  printf("\tValue of the capacitor (C1) in Farads: ");
  scanf("%d", value2_ptr);
}

int first(int x,int y,int z){
  result();
  timeHigh=0.693*(x+y)*z;
  printf("\n\tTime High (secs): %f",timeHigh);
  timeLow=0.693*y*z;
  printf("\n\tTime Low (secs): %f",timeLow);
  duty_cycle_percentage=(timeHigh/(timeHigh+timeLow))*100;
  printf("\n\tDuty Cycle Percentage: %f",duty_cycle_percentage);
  frequency=1.44/((x+y+y)*z);
  printf("\n\tFrequency: %f",frequency);
  getEnter();
  return 0;
}

int second(int x,int y){
  result();
  timeoutDelay=1.1*x*y;
  printf("\n\tTime Out Delay (secs): %f",timeoutDelay);
  getEnter();
  return 0;
}
