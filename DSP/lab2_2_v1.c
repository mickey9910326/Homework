#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 20
#define CLASS_MAX_STUDENT 3
#define CLASS_MAX_TEACHER 2

#define stu1 {"st1" ,"0912345678",2,0}
#define stu2 {"st2" ,"0912345678",2,0}
#define stu3 {"st3" ,"0912345678",2,0}
#define stu4 {"st4" ,"0912345678",2,0}

#define te1 {"T1","0912345678",1,0}
#define te2 {"T2","0912345678",1,0}
#define te3 {"T3","0912345678",1,0}
#define te4 {"T4","0912345678",1,0}

#define lt {"LT","0912345678",1,8}

#define MAN_INI {stu1,stu2,stu3,stu4,te1,te2,te3,te4,lt}

#define c1 {"English"  ,0,0,{},{}}
#define c2 {"Math"     ,0,0,{},{}}
#define c3 {"Physical" ,0,0,{},{}}
#define c4 {"Chemistry",0,0,{},{}}

#define SCHOOL_INFO {"Tresh",4,0,{c1,c2,c3,c4}}

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
    type_man* student_p[CLASS_MAX_STUDENT];
    type_man* teacher_p[CLASS_MAX_TEACHER];
} type_class;

typedef struct school {
    char name[NAME_LENGTH];
    int class_num;
    int student_num;
    type_class class[4];
    type_man* head_teacher_p;
} type_school;

type_man man_arr[9] = MAN_INI;

void school_init(type_school* school_p) {
    int i,j;
    int identity;
    int input;

    for (i = 0; i < 9; i++) {
        type_man* man_p = &man_arr[i];
        printf("name: %s\n", man_p->name);
        printf("input identity :");
        scanf("%d", &identity);

        for (j = 0; j < 4; j++) {
            type_class* class_p = &(school_p->class[j]);
            printf("is part in %s? ", class_p->name);
            scanf("%d", &input);
            man_p->participate |= input<<j;
            if(input)
            switch (identity) {
                case 1:
                    if (class_p->teacher_num != CLASS_MAX_TEACHER) {
                        class_p->teacher_p[class_p->teacher_num] = man_p;
                        class_p->teacher_num++;
                    }
                    break;
                case 2:
                    if (class_p->student_num != CLASS_MAX_STUDENT) {
                        class_p->student_p[class_p->student_num] = man_p;
                        class_p->student_num++;
                    }
                    break;
            }
        }
        if (identity==2) {
            school_p->student_num++;
        }
        if ( identity == 0) {
            school_p->head_teacher_p = man_p;
        }
    }
}

void school_print(type_school* school_p) {
    printf("----%s----\n", school_p->name);
    printf("lead teacher: %s\n", school_p->head_teacher_p->name);
    printf("student_num: %d\n", school_p->student_num);
    int i,j;
    for (i = 0; i < school_p->class_num ; i++) {
        type_class* class_p = &school_p->class[i];
        printf("Class name: %s \n", class_p->name);
        printf("  Teacher : ");
        for (j = 0; j < class_p->teacher_num ; j++) {
            type_man* teacher_p = class_p->teacher_p[j];
            printf("%10s", teacher_p->name);
        }
        printf("\n");
        printf("  Student : ");
        for (j = 0; j < class_p->student_num ; j++) {
            type_man* student_p = class_p->student_p[j];
            printf("%10s", student_p->name);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[]) {
<<<<<<< HEAD
    type_school school = SCHOOL_INFO;
    school_init(&school);
    school_print(&school);
=======
    type_school myschool = SCHOOL_INFO;

    // school_init(&myschool);
    school_print(&myschool);

    // type_class c = {"MATH",0,0,{{"Jobs","0912345678",1,1},{"Jobs","0912345678",1,1}},};
    type_class c = {"MATH",2,2,{stu1,stu2},{te1}};
    printf("%s\n", c.student[0].name);
    // myschool.class[0].student[0] = stu1;


>>>>>>> origin/master
    return 0;
}
