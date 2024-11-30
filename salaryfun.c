
#include <stdio.h>
#include <stdlib.h>

struct Employee{
    char ID[20];
    char Name[20];
    int salary;
    struct Employee* next;
};

struct Employee* create(int *salary)
{
  struct  Employee *p = malloc(sizeof(struct Employee));
  if(p == NULL)
  {
      printf("Fail");
      return NULL;
  }
    p->salary = salary;
    p->next = NULL;
    return p;
}
int main() {

    int sal = 25000;
    
    struct Employee* newEmployee = create(sal);
  if(newEmployee != NULL)
  {
      printf("Salary is %d", newEmployee->salary);
      free(newEmployee);  
  }

    return 0;
}