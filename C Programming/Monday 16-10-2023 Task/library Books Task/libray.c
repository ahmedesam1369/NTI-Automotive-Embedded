#include "libray.h"

void add_book(library_t *library, book_t *new_book){
    if((library == NULL ) || (new_book == NULL )){
        printf("Error!!! Enter a valid Address \n");
    }else{
        uint32 book_indx;
        if(book_exist(library, new_book, &book_indx)){
            uint32 l_y_or_n;
            printf("Book is Already Exist\n");
            printf("Do U Wanna add another copy[Yes(Enter 1)  No(Enter 0)]: ");
            scanf("%i",&l_y_or_n);
            fflush(stdin);
            if(l_y_or_n &&((library->total_number_of_copies + new_book->copies) <= total_number_of_books)){
                library->books[book_indx].copies+= new_book->copies;
                library->total_number_of_copies += new_book->copies;
            }else{
              printf("Library is FULL\n");
            }

        }else{
        library->book_count++;
        if(library->total_number_of_copies >= total_number_of_books){
            printf("Library is FULL\n");
        }else{
            library->total_number_of_copies += new_book->copies;

            strcpy(&library->books[library->book_count].author, &new_book->author);

            library->books[library->book_count].copies = new_book->copies;
            library->books[library->book_count].price = new_book->price;

            strcpy(&library->books[library->book_count].status, &new_book->status);
            strcpy(&library->books[library->book_count].title, &new_book->title);

            library->books[library->book_count].year = new_book->year;

            printf("Book Added Successfully\n");
        }
        }


    }

}
uint8 book_exist(library_t *library, book_t *new_book, uint32 *book_indx){
    uint8 l_status = 0;
    for(int i=1; i<= library->book_count; i++){
        if(strcmp(library->books[i].title, new_book->title) == 0){
            l_status = 1;
            *book_indx = i;
        }

    }
    return l_status;
}

void get_book_from_user(book_t *book_1){
    printf("Enter Book title : ");
    gets(&book_1->title);
    printf("Enter Book Author Name : ");
    gets(&book_1->author);
    printf("Enter Book Status : ");
    gets(&book_1->status);
    printf("Enter Number of Copies : ");
    scanf("%i",&book_1->copies);
    fflush(stdin);
    printf("Enter Publication Year : ");
    scanf("%i", &book_1->year);
    fflush(stdin);
    printf("Enter Book Price : ");
    scanf("%f", &book_1->price);
    fflush(stdin);
}

void print_library(library_t *my_library){
    for(int i=1; i<= my_library->book_count; i++){
    printf("----------- BOOK Number %i ---------------\n", i);
    printf(" Book title : %s\n", my_library->books[i].title);
    printf(" Book Author Name : %s\n", my_library->books[i].author);
    printf(" Book Status : %s\n", my_library->books[i].status);
    printf(" Number of Copies : %d\n", my_library->books[i].copies);
    printf(" Publication Year : %d\n", my_library->books[i].year);
    printf(" Book Price : %0.1f\n", my_library->books[i].price);

    }
    printf("Total Number of Copies is %i", my_library->total_number_of_copies);
}


void borrow_book(library_t *library, book_t *book_1){
    uint32 book_indx;
    uint8 book_exis_obj;
    printf("Enter Book title to Borrow : ");
    gets(&(book_1->title));
    book_exis_obj = book_exist(library, book_1, &book_indx);

    if(book_exis_obj && (library->books[book_indx].copies > 0)){
        library->books[book_indx].copies--;
        library->total_number_of_copies--;
        printf("Book Borrowed Sucessfuly \'t Exist");
    }else{
        printf("Book Doesn\'t Exist\n");
    }
}

void buy_book(library_t *library, book_t *book_1){
    uint32 book_indx;
    uint8 book_exis_obj;
    printf("Enter Book title to Buy : ");
    gets(&(book_1->title));
    book_exis_obj = book_exist(library, book_1, &book_indx);

    if(book_exis_obj){
        library->books[book_indx].copies++;
        library->total_number_of_copies++;
        printf("Book Buyed Sucessfuly \'t");
    }else{
        printf("Book Doesn\'t Exist\n");
        printf("ADD it First!!!!!!!!!!!!!!!\n");
    }
}

void delete_book(library_t *library, book_t *book_1){
    uint32 book_indx;
    uint8 book_exis_obj;
    printf("Enter Book title to Delete : ");
    gets(&(book_1->title));
    book_exis_obj = book_exist(library, book_1, &book_indx);

    if(book_exis_obj){
        uint8 temp[] = "Nothing";
        library->total_number_of_copies -= library->books[book_indx].copies;
        strcpy(&library->books[book_indx].title, temp);
        for(int i= book_indx; i< library->book_count; i++){
            library->books[i] = library->books[i+1];
        }
        library->book_count--;

        printf("Book Deletd Sucessfuly \n");
    }else{
        printf("Book Doesn\'t Exist and Nothing Deleted\n");
    }
}
