#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "patient_class.h"

patient *head;
 
/* Main */
int main() {
    printf("*****************************************\n"
           "*\t\tWELCOME TO\t\t*\n"
           "*\tClinic Management System v1.0\t*\n"
           "*****************************************\n");
    modeSelect();
 
    return 0;
}
