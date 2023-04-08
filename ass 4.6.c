#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int year;
};

struct Library {
    struct Book books[MAX_BOOKS];
    int count;
};

void add_book(struct Library *lib) {
    if (lib->count == MAX_BOOKS) {
        printf("Library is full\n");
        return;
    }
    struct Book book;
    printf("Enter book details:\n");
    printf("Title: ");
    scanf("%s", book.title);
    printf("Author: ");
    scanf("%s", book.author);
    printf("Year: ");
    scanf("%d", &book.year);
    lib->books[lib->count] = book;
    lib->count++;
    printf("Book added to the library\n");
}

void display_books(struct Library lib) 
{
	int i;
    if (lib.count == 0) {
        printf("No books in the library\n");
        return;
    }
    printf("Books in the library:\n");
    for (i = 0; i < lib.count; i++) {
        printf("%d. %s, %s (%d)\n", i+1, lib.books[i].title, lib.books[i].author, lib.books[i].year);
    }
}

void list_books_by_author(struct Library lib) 
{
	int i;
    char author[50];
    printf("Enter author name: ");
    scanf("%s", author);
    printf("Books by author %s:\n", author);
    int found = 0;
    for (i = 0; i < lib.count; i++) {
        if (strcmp(lib.books[i].author, author) == 0) {
            printf("%d. %s, %s (%d)\n", found+1, lib.books[i].title, lib.books[i].author, lib.books[i].year);
            found++;
        }
    }
    if (found == 0) {
        printf("No books found for author %s\n", author);
    }
}

void list_book_count(struct Library lib) {
    printf("Total number of books in the library: %d\n", lib.count);
}

int main() {
    struct Library lib = {0};
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add book details\n");
        printf("2. Display book details\n");
        printf("3. List all books of given author\n");
        printf("4. List the count of books in the library\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book(&lib);
                break;
            case 2:
                display_books(lib);
                break;
            case 3:
                list_books_by_author(lib);
                break;
            case 4:
                list_book_count(lib);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}

