#include <stdio.h>
#include <stdlib.h>
#include "libray.h"

library_t my_library;


int main()
{
    my_library.book_count = 0;
    my_library.total_number_of_copies = 0;

    book_t book_0, book_1, book_2, book_3;

    strcpy(&book_1.title, "y");
    strcpy(&book_1.author, "Ahmed");
    strcpy(&book_1.status, "Good");
    book_1.copies = 5;
    book_1.year = 2020;
    book_1.price = 150.5;
    strcpy(&book_2.title, "yy");
    strcpy(&book_2.author, "Esam");
    strcpy(&book_2.status, "Not Good");
    book_2.copies = 10;
    book_2.year = 2022;
    book_2.price = 46.5;
    strcpy(&book_3.title, "yyy");
    strcpy(&book_3.author, "Gamal");
    strcpy(&book_3.status, "Bad");
    book_3.copies = 20;
    book_3.year = 2024;
    book_3.price = 100.5;


    uint32 flag = 1;
    uint32 choose;
    while(flag){
        printf("\n( 1 ) ADD BOOK\n( 2 ) Print Library\n( 3 ) Borrow Book\n");
        printf("( 4 ) Buy Book\n( 5 ) Delete Book \n( 6 ) Exit\n ");
        printf("Choose Number::: ");
        scanf("%i", &choose);
        fflush(stdin);
        switch(choose){
        case 1:
            get_book_from_user(&book_0);
            add_book(&my_library, &book_0);

            /* Use Them to test Faster */
//            add_book(&my_library, &book_1);
//            add_book(&my_library, &book_2);
//            add_book(&my_library, &book_3);
            break;
        case 2:
            print_library(&my_library);
            break;
        case 3:
            borrow_book(&my_library, &book_3);
            break;
        case 4:
            buy_book(&my_library, &book_3);
            break;
        case 5:
            delete_book(&my_library, &book_3);
            break;
        case 6:
            flag = 0;
            break;
        default:
            printf("Error!! Enter Number Between 0 ~ 6 ");
        }
    }


    return 0;
}
