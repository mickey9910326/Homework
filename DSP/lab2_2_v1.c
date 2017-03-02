#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#ifndef NAME_LENGTH
#define NAME_LENGTH 20
#endif

typedef struct man {
    char name[NAME_LENGTH];
    char phone[10];
    uint8_t identity; // 0:head_teacher 1:student 2:
    uint8_t participate; // bit0:eng bit1:math bit2:physical bit3:chemistry
} type_man;

typedef struct class {
    char name[NAME_LENGTH];
    uint8_t student_num; // maxinum is 4
    uint8_t teacher_num; // maxinum is 4
    type_man student[3];
    type_man teacher[3];
} type_class;

typedef struct school {
    uint8_t student_num;
    uint8_t class_num;
    char name[NAME_LENGTH];
    type_class class[4];
    type_man head_teacher;
} type_school;

void school_init(type_school* school_p) {
    char name[NAME_LENGTH];
    uint8_t participate;

    printf("Input school name:");
    scanf("%s",name);
    strcpy(school_p->name,name);

    strcpy(school_p->class[0].name, "English");
    strcpy(school_p->class[1].name, "Math");
    strcpy(school_p->class[2].name, "Physical");
    strcpy(school_p->class[3].name, "Chemistry");

    uint8_t break_falg;

    /* TODO
    * use the same man in different class
    * or see as different man in different class
    */

}



int main(int argc, char const *argv[]) {
    type_school myschool;
    // strcpy(myschool.name,"Tresh University");
    // strcpy(myschool.class[0].student[0].name,"aa");
    //
    // printf("%s\n", myschool.name);
    // printf("%s\n", myschool.class[0].student[0].name);

    // school_init(&myschool);
    // printf("%s\n", myschool.name);

    return 0;
}
