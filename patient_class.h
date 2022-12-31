typedef struct patient patient; // Declaring structure of patient
 
struct patient {
    u16 id;
    s8 name[STRING_MAX_LENGTH];
    u16 age;
    s8 gender[STRING_MAX_LENGTH];
    patient *link;
};
