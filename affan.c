#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void welcome(void);
void bubble_sort(void);
void insertion_sort(void);
void selection_sort(void);
void merge_sort_run(void);
void quick_sort_run(void);
void palindromic_numbers(void);
void lift_simulation(void);
void vasya_books(void);
void two_types_of_burgers(void);
void game_with_string(void);
void display_menu(void);
void clear_screen(void);



void clear_screen(void) {
    #ifdef _WIN32

    #else
        system("clear"); // Linux/macOS
    #endif
}


void welcome(void) {
     printf("\n\t\t\t\t\t-----------------------------------------\n");
    printf("\t\t\t\t\t|\t  Bismillah Hirrahmir Rahim  \t|\n");
    printf("\t\t\t\t\t-----------------------------------------\n");
    printf("\t\t\t\t\t   ------------------------------\n");
    printf("\t\t\t\t\t  |\t  Assalamualaikum      \t|\n");
    printf("\t\t\t\t\t   ------------------------------\n\n\n\n");

    printf("\n-----------------\n");
    printf(" My Project \n");
    printf("-----------------\n");


    printf("1. Submitted by\n2. Submitted to\n3. About The Project\n");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\tEnter Your Choice: > ");

    int option;
    scanf("%d", &option);

    switch (option) {
        case 1:
            clear_screen();
            printf("Name: Affan Julfiker\n");
            printf("ID: 232-15-682\n");
            printf("Department: CSE\n");
            printf("Section: 65_F\n");
            printf("Course: Algorithm Lab\n");
            printf("\nPress any key to get back...\n");
            getchar();  // To consume any leftover newline character from the input buffer
            getchar();  // Wait for a key press
            welcome();
            break;
        case 2:
            clear_screen();
            printf("Course Teacher: Abdullah Al Mamun\n");
            printf("Lecturer\n");
            printf("Department: CSE\n");
            printf("\nPress any key to get back...\n");
            getchar();
            getchar();
            welcome();
            break;
        case 3:
            clear_screen();
            break;
        default:
            printf("Invalid option, returning to menu...\n");
            welcome();
            break;
    }
}



void bubble_sort() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge_sort_run() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void quick_sort_run() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void palindromic_numbers() {
    int num;
    printf("Enter a number to check if it is palindromic: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Negative numbers cannot be palindromic.\n");
        return;
    }

    int reversed = 0, original = num;
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    if (original == reversed) {
        printf("%d is a palindromic number.\n", original);
    } else {
        printf("%d is not a palindromic number.\n", original);
    }
}

void lift_simulation() {
    int current_floor = 0, target_floor;
    printf("Enter the target floor: ");
    scanf("%d", &target_floor);

    if (target_floor < 0 || target_floor > 100) {
        printf("Invalid floor. Please enter a floor between 0 and 100.\n");
        return;
    }

    if (target_floor > current_floor) {
        for (int i = current_floor + 1; i <= target_floor; i++) {
            printf("Lift moving up: Floor %d\n", i);
        }
    } else if (target_floor < current_floor) {
        for (int i = current_floor - 1; i >= target_floor; i--) {
            printf("Lift moving down: Floor %d\n", i);
        }
    } else {
        printf("You are already on the target floor.\n");
    }
}

void vasya_books() {
    int n, m;
    printf("Enter the number of books and the number Vasya can carry: ");
    scanf("%d %d", &n, &m);

    if (n <= 0 || m <= 0) {
        printf("Invalid input. Both numbers must be positive.\n");
        return;
    }

    int *books = (int *)malloc(n * sizeof(int));
    printf("Enter the order of books: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    int count = 0, carried = 0;
    for (int i = 0; i < n; i++) {
        if (carried + books[i] > m) {
            count++;
            carried = 0;
        }
        carried += books[i];
    }
    if (carried > 0) count++;

    printf("Vasya needs %d trips.\n", count);
    free(books);
}

void two_types_of_burgers() {
    int buns, patties, cutlets;
    printf("Enter the number of buns, patties, and cutlets: ");
    scanf("%d %d %d", &buns, &patties, &cutlets);

    if (buns < 2) {
        printf("Not enough buns to make any burgers.\n");
        return;
    }

    int max_burgers = 0;
    for (int i = 0; i <= buns / 2; i++) {
        int burger_with_patties = i <= patties ? i : patties;
        int remaining_buns = buns - 2 * i;
        int burger_with_cutlets = remaining_buns / 2 <= cutlets ? remaining_buns / 2 : cutlets;
        int total_burgers = burger_with_patties + burger_with_cutlets;
        if (total_burgers > max_burgers) max_burgers = total_burgers;
    }

    printf("Maximum number of burgers that can be made: %d\n", max_burgers);
}

void game_with_string() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int count[26] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i] - 'a']++;
    }

    int odd_count = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) odd_count++;
    }

    if (odd_count <= 1) {
        printf("The string can form a palindrome.\n");
    } else {
        printf("The string cannot form a palindrome.\n");
    }
}

// Main menu
void display_menu(void) {
    int choice;
    do {
        printf("\n\t\t\t\t\t---------------------------------\n");
        printf("\t\t\t\t\t|\t     Algorithm Project    \t|\n");
        printf("\t\t\t\t\t---------------------------------\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Palindromic Numbers\n");
        printf("7. Lift Simulation\n");
        printf("8. Vasya's Books\n");
        printf("9. Two Types of Burgers\n");
        printf("10. Game with String\n");
        printf("0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        clear_screen();

        switch(choice) {
            case 1: bubble_sort(); break;
            case 2: insertion_sort(); break;
            case 3: selection_sort(); break;
            case 4: merge_sort_run(); break;
            case 5: quick_sort_run(); break;
            case 6: palindromic_numbers(); break;
            case 7: lift_simulation(); break;
            case 8: vasya_books(); break;
            case 9: two_types_of_burgers(); break;
            case 10: game_with_string(); break;
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid choice, please try again.\n"); break;
        }
    } while(choice != 0);
}

int main(void) {
    welcome();
    display_menu();
    return 0;
}