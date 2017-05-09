// gcc ./test/test_buffer.c ./slave/buffer.c -o test
#include "..\slave\buffer.h"
#include <stdio.h>
void print_buffer_data(TypeOfBuffer* Buffer_p);

int main(int argc, char const *argv[]) {
    printf("start!\n");
    TypeOfBuffer buffer;
    char data[32];
    int check;
    buffer.GETindex = 0;
    buffer.PUTindex = 0;
    check = put_buffer_bytes(&buffer,10,"0123456789");
    check = put_buffer_bytes(&buffer,10,"0123456789");
    check = put_buffer_bytes(&buffer,10,"0123456789");
    printf("%d ,", check);
    print_buffer_data(&buffer);

    check = put_buffer_bytes(&buffer,4,"a0123");
    printf("%d ,", check);
    print_buffer_data(&buffer);

    check = get_buffer_bytes(&buffer,20,data);
    printf("%d ,", check);
    printf("get = %s\n", data);
    print_buffer_data(&buffer);

    check = put_buffer_bytes(&buffer,10,"a--------a");
    printf("%d ,", check);
    print_buffer_data(&buffer);

    check = get_buffer_bytes(&buffer,20,data);
    printf("%d ,", check);
    printf("get = %s\n", data);
    print_buffer_data(&buffer);

    return 0;
}

void print_buffer_data(TypeOfBuffer* Buffer_p) {
    char i;
    printf("G:%d,P:%d,data:",Buffer_p->GETindex,Buffer_p->PUTindex);
    for (i = 0; i < MAXBUFFBYTES; i++) {
        printf("%c,", Buffer_p->data[i] );
    }
    printf("\n");
}
