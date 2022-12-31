void modeSelect() {
    printf("*\tFor admin mode, Enter 1\t\t*\n"
           "*\tFor user mode, Enter 2\t\t*\n"
           "*\tTo exit, Enter 3\t\t*\n"
           "*****************************************\n");
 
    u8 mode;
    printf("Your choice:");
    scanf("%c", &mode);
    if (mode == '1') adminMode();
    /*else if (mode == '2');
    else if (mode == '3') exit(0);
    else {
        printf("Please use the options given, Try again...");
        modeSelect();
    }*/
}
 
void checkAdmin() {
    u8 i = '2';
    u16 pass;
    printf("\nPlease enter the password to enter admin mode\nPassword:");
    while (1) {
        scanf("%hu", &pass);
        if (pass == 1234) return;
        else if (i == '0') {
            printf("You have no remaining trails! Exiting the program...");
            exit(0);
        } else
            printf("Incorrect password!\nYou have remaining %c trails\nEnter the password:", i);
        i--;
    }
}
 
void adminMode() {
    printf("+-----------------------------------------------+\n"
           "|\tWelcome To Admin Mode\t\t\t|\n"
           "|\tYou here can edit, add patient\t\t|\n"
           "|\trecords, reserve and cancel slots\t|\n"
           "|\tPlease enter the password.\t\t|\n"
           "+-----------------------------------------------+\n"
    );
    checkAdmin();
    printf("+-------------------------------------------------------+\n"
           "|\tTo add a new patient, Enter 1\t\t\t+\n"
           "|\tTo edit a patient record, Enter 2\t\t+\n"
           "|\tTo reserve a slot with the doctor, or\t\t+\n"
           "|\tto cancel a reservation, Enter 3\t\t+\n"
           "+-------------------------------------------------------+\n"
    );
    u8 choice = '1';
    printf("Your choice: ");
    scanf(" %c", &choice);
    if (choice == '1') addPatient();
    /*else if (choice == 2) editPatient();
    else if (choice == 3) manageSlot();*/
}
 
u16 NUMBER_OF_PATIENTS = 0;
u8 FIRST_NODE = 0;
 
void addPatient() {
    patient *ptr, *temp;
    ptr = head;
    printf("Enter patient data\n");
    temp = (patient*) malloc(sizeof(patient));
    if (FIRST_NODE == 0) {
        printf("aaEnter patient ID: ");
        scanf(" %hu", &temp->id);
        printf("\nEnter patient name: ");
        scanf(" %[^\n]s", temp->name);
        printf("\nEnter patient age: ");
        scanf(" %hu", &temp->age);
        printf("\nEnter patient gender: ");
        scanf(" %s", temp->gender);
        temp->link = NULL;
        writeToFile(temp->id, temp->name, temp->age, temp->gender);
        head = temp;
        FIRST_NODE = 1;
    }
 
    else {
        printf("ssEnter patient ID: ");
        scanf(" %hu", &temp->id);
        printf("Enter patient name: ");
        scanf(" %[^\n]s", temp->name);
        printf("Enter patient age: ");
        scanf(" %hu", &temp->age);
        printf("Enter patient gender: ");
        scanf(" %s", temp->gender);
        writeToFile(temp->id, temp->name, temp->age, temp->gender);
        temp->link = NULL;
        while (ptr->link != NULL) {
            ptr = ptr -> link;
        }
        ptr -> link = temp;
    }
}
 
void writeToFile(u16 id, s8 *name, u8 age, s8 *gender) {
    FILE *fp = fopen("patients.txt", "w");
    fprintf(fp, "%hu\t%s\t%hu\t%s\n", id, name, age, gender);
}
