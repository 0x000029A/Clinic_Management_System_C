#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void modeSelect(void);  // Mode select function         DONE
void checkAdmin(void);  // Check admin mode password    DONE
void userMode(void);    // User mode function           TODO
void adminMode(void);   // Admin mode function          TODO
void getData(void);     // Get patient data             TODO
void addPatient(void);  // Function too add patients    TODO
void checkID(u8 ID);    // Check if ID exists           TODO
void editPatient(void); // Edit patient record          TODO
void manageSlot(void);  // Reserve or cancel a slot     TODO
u8 scanChoice(void);    // Scanf admin choice           DONE

#endif
