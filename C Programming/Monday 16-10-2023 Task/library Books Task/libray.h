#include "DataTypes.h"
#include <string.h>
#include <stdio.h>

#define Array_len_1  100  /* title and author  */
#define Array_len_2  50  /* status  */

#define total_number_of_books 100

typedef struct{
    uint8 title[Array_len_1];
    uint8 author[Array_len_1];
    uint32 year;
    uint32 copies;
    float price;
    uint8 status[Array_len_2];
}book_t;

typedef struct{
    uint32 book_count;
    uint32 total_number_of_copies;
    book_t books[total_number_of_books];
}library_t;

void add_book(library_t *library, book_t *new_book);
uint8 book_exist(library_t *library, book_t *new_book, uint32 *book_indx);
void get_book_from_user(book_t *book_1);
void print_library(library_t *my_library);
void borrow_book(library_t *library, book_t *new_book);
void buy_book(library_t *library, book_t *book_1);
void delete_book(library_t *library, book_t *book_1);

