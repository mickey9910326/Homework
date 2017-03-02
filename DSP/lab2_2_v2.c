#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#define NAME_LENGTH 20
#define CLASS_MAX_STUDENT 3
#define CLASS_MAX_TEACHER 2

typedef struct man {
    char name[NAME_LENGTH];
    char phone[10];
    uint8_t identity; // 0:lead_teacher 1:teacher 2:student
    uint8_t participate; // bit0:eng bit1:math bit2:phy bit3:chemistry
} *pMan, Man;

typedef struct class {
    char name[NAME_LENGTH];
    uint8_t student_num;
    uint8_t teacher_num;
    pMan student[CLASS_MAX_STUDENT];
    pMan teacher[CLASS_MAX_TEACHER];
} *pClass, Class;

typedef struct school {
    char name[NAME_LENGTH];
    uint8_t student_num;
    uint8_t class_num;
    pMan lead_teacher;
    pClass class[4];
} *pSchool, School;


pMan    create_man(char name[NAME_LENGTH], char phone[10], uint8_t participate);
pClass  create_class(char name[NAME_LENGTH]);
pSchool create_school(char name[NAME_LENGTH]);

void school_add_class(pSchool school,char name[NAME_LENGTH]);
void school_add_lead_teacher(pSchool school,char name[NAME_LENGTH], char phone[10]);
void school_add_teacher(pSchool school ,char name[NAME_LENGTH] ,char phone[10] ,uint8_t participate);
void school_add_student(pSchool school, char name[NAME_LENGTH], char phone[10], uint8_t participate);

void school_print(pSchool school);


int main(int argc, char const *argv[]) {
    pSchool myschool = create_school("Tresh University");
    school_add_class(myschool,"English");
    school_add_class(myschool,"Math");
    school_add_class(myschool,"Physical");
    school_add_class(myschool,"Chemistr");

    school_add_lead_teacher(myschool,"TTT","1234567890");

    school_add_teacher(myschool,"T1" ,"0912345678",5);
    school_add_teacher(myschool,"T2" ,"0912345678",10);
    school_add_teacher(myschool,"T3" ,"0912345678",9);

    school_add_student(myschool,"Jobs"  ,"0912345678",5);
    school_add_student(myschool,"Steve" ,"0912345678",6);
    school_add_student(myschool,"Niggle","0912345678",7);
    school_add_student(myschool,"Bernie","0912345678",15);

    school_print(myschool);
    return 0;
}


pMan create_man(char name[NAME_LENGTH], char phone[10], uint8_t participate) {
    pMan man;
    man = (pMan) malloc(sizeof(Man));
    strcpy(man->name, name);
    strcpy(man->phone, phone);
    man->participate=participate;
    return man;
}

pClass create_class(char name[NAME_LENGTH]) {
    pClass class;
    class = (pClass) malloc(sizeof(Class));
    strcpy(class->name, name);
    class->student_num=0;
    class->teacher_num=0;
    return class;
}

pSchool create_school(char name[NAME_LENGTH]) {
    pSchool school;
    school = (pSchool) malloc(sizeof(School));
    strcpy(school->name, name);
    school->class_num = 0;
    school->student_num = 0;
    return school;
}

void school_add_class(pSchool school,char name[NAME_LENGTH]) {
    pClass class = create_class(name);
    school->class[school->class_num] = class;
    school->class_num++;
}

void school_add_student(pSchool school, char name[NAME_LENGTH], char phone[10], uint8_t participate) {
    pMan man =  create_man(name,phone,participate);
    man->identity = 2;
    school->student_num++;
    uint8_t i;
    for (i = 0; i < 4; i++) {
        if (participate & 0x01) {
            pClass class = school->class[i];
            if (class->student_num==CLASS_MAX_STUDENT){
                participate = participate>>1;
                continue;
                // TODO give a new participate
            }
            class->student[class->student_num] = man;
            class->student_num++;
        }
        participate = participate>>1;
    }
}
void school_add_teacher(pSchool school ,char name[NAME_LENGTH] ,char phone[10] ,uint8_t participate) {
    pMan man = create_man(name,phone,participate);
    man->identity = 1;
    uint8_t i;
    for (i = 0; i < 4; i++) {
        if (participate & 0x01) {
            pClass class = school->class[i];
            if ( class->teacher_num==CLASS_MAX_TEACHER ){
                participate = participate>>1;
                continue;
                // TODO give a new participate
            }
            class->teacher[class->teacher_num] = man;
            class->teacher_num++;
        }
        participate = participate>>1;
    }
}
void school_add_lead_teacher(pSchool school,char name[NAME_LENGTH], char phone[10]) {
    pMan man = create_man(name,phone,15);
    man->identity = 0;
    school->lead_teacher = man;
}

void school_print(pSchool school) {
    printf("----%s----\n", school->name);
    printf("lead teacher: %s\n", school->lead_teacher->name);
    printf("student_num: %d\n", school->student_num);
    uint8_t i,j;
    for (i = 0; i < school->class_num ; i++) {
        pClass class = school->class[i];
        printf("Class name: %s \n", class->name);
        printf("  Teacher : ");
        for (j = 0; j < class->teacher_num ; j++) {
            pMan teacher = class->teacher[j];
            printf("%10s", teacher->name);
        }
        printf("\n");
        printf("  Student : ");
        for (j = 0; j < class->student_num ; j++) {
            pMan student = class->student[j];
            printf("%10s", student->name);
        }
        printf("\n");
    }
}
