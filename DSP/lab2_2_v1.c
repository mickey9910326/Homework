#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#define NAME_LENGTH 20
#define CLASS_MAX_STUDENT 3
#define CLASS_MAX_TEACHER 2

#define stu1 {"Jobs"  ,"0912345678",2,15}
#define stu2 {"Steve" ,"0912345678",2,2}
#define stu3 {"Nig"   ,"0912345678",2,3}
#define stu4 {"Bernie","0912345678",2,8}

#define te1 {"T1","0912345678",1,9}
#define te2 {"T2","0912345678",1,2}
#define te3 {"T3","0912345678",1,4}
#define te4 {"T4","0912345678",1,8}

#define lt {"T4","0912345678",1,8}

#define c1 {"English"  ,3,1,{stu1,stu2,stu3},{te1}}
#define c2 {"Math"     ,2,1,{stu1,stu3}     ,{te2}}
#define c3 {"Physical" ,2,1,{stu1,stu4}     ,{te3}}
#define c4 {"Chemistry",1,1,{stu1}          ,{te1}}

#define SCHOOL_INFO {"Tresh",4,4,{c1,c2,c3,c4},lt}


typedef struct man {
    char name[NAME_LENGTH];
    char phone[10];
    int identity; // 0:head_teacher 1:student 2:
    int participate; // bit0:eng bit1:math bit2:physical bit3:chemistry
} type_man;

typedef struct class {
    char name[NAME_LENGTH];
    int student_num; // maxinum is 4
    int teacher_num; // maxinum is 4
    type_man student[CLASS_MAX_STUDENT];
    type_man teacher[CLASS_MAX_TEACHER];
} type_class;

typedef struct school {
    char name[NAME_LENGTH];
    int class_num;
    int student_num;
    type_class class[4];
    type_man head_teacher;
} type_school;

void school_init(type_school* school_p) {
    char name[NAME_LENGTH];
    char phone[10];
    int participate;
    int i;

    printf("Input school name:");
    scanf("%s",name);
    strcpy(school_p->name,name);

    strcpy(school_p->class[0].name, "English");
    strcpy(school_p->class[1].name, "Math");
    strcpy(school_p->class[2].name, "Physical");
    strcpy(school_p->class[3].name, "Chemistry");

    int break_falg;

    /* TODO
    * use the same man in different class
    * or see as different man in different class
    */
    while ( break_falg ) {
        printf("ADD teacher? (1 continue 0 stop):");
        scanf("%d",&break_falg);
        if (!break_falg) { break; }
        printf("Input teacher name:");
        scanf("%s",name);
        printf("Input teacher phone:");
        scanf("%s",phone);
        printf("Input teacher participate:");
        scanf("%d" ,&participate);

        for (i = 0; i < 4; i++) {
            if (participate & 0x01) {
                type_class* class_p = &(school_p->class[i]);
                if ( class_p->teacher_num==CLASS_MAX_TEACHER ){
                    participate = participate>>1;
                    continue;
                    // TODO give a new participate
                }
                type_man* man = &(class_p->teacher[class_p->teacher_num]);
                strcpy(man->name,name);
                strcpy(man->phone,phone);
                man->participate = participate;
                man->identity = 1;
                class_p->teacher_num++;
            }
            participate = participate>>1;
        }
    }
    break_falg = 1;
    while ( break_falg ) {
        printf("ADD stedunt? (1 continue 0 stop):");
        scanf("%d",&break_falg);
        if (!break_falg) { break; }
        printf("Input student name:");
        scanf("%s",name);
        printf("Input student phone:");
        scanf("%s",phone);
        printf("Input student participate:");
        scanf("%d" ,&participate);

        school_p->student_num++;

        for (i = 0; i < 4; i++) {
            printf("OA");
            if (participate & 0x01) {
                type_class* class_p = &(school_p->class[i]);
                if ( class_p->student_num==CLASS_MAX_STUDENT ){
                    participate = participate>>1;
                    continue;
                    // TODO give a new participate
                }
                type_man* man = &(class_p->student[class_p->student_num]);
                strcpy(man->name,name);
                strcpy(man->phone,phone);
                man->participate = participate;
                man->identity = 2;
                class_p->student_num++;
            }
            participate = participate>>1;
        }
        printf("OAO");
    }
}

void school_print(type_school* school_p) {
    printf("----%s----\n", school_p->name);
    printf("lead teacher: %s\n", school_p->head_teacher.name);
    printf("student_num: %d\n", school_p->student_num);
    int i,j;
    for (i = 0; i < school_p->class_num ; i++) {
        type_class* class_p = &(school_p->class[i]);
        printf("Class name: %s \n", class_p->name);
        printf("  Teacher : ");
        for (j = 0; j < class_p->teacher_num ; j++) {
            type_man* man_p = &(class_p->teacher[j]);
            printf("%10s", man_p->name);
        }
        printf("\n");
        printf("  Student : ");
        for (j = 0; j < class_p->student_num ; j++) {
            type_man* man_p = &(class_p->student[j]);
            printf("%10s", man_p->name);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[]) {
    type_school myschool = SCHOOL_INFO;

    // school_init(&myschool);
    school_print(&myschool);

    // type_class c = {"MATH",0,0,{{"Jobs","0912345678",1,1},{"Jobs","0912345678",1,1}},};
    type_class c = {"MATH",2,2,{stu1,stu2},{te1}};
    printf("%s\n", c.student[0].name);
    // myschool.class[0].student[0] = stu1;


    return 0;
}
