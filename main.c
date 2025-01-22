#include <stdio.h>
#include <string.h>
#include<string>
int main() {
    int choice;
    char notes[1000][1000];
    char importance[1000][1000];
    int total_importance = 0;
    int choice_for_importance;
    int sum_of_notes = 0;
    int size;
    int delete_index;

    printf("\nNotes Application\n");
    printf("1. Add Note\n");
    printf("2. Delete Note\n");
    printf("3. Show Important Notes\n");
    printf("4. To see all notes\n");
    printf("5. Edit\n");
    printf("6. Categorize notes\n");
    printf("7. Search note\n");
    printf("8. Tag notes\n");
    printf("9. Exit\n");

    while (choice != 9) {
        printf("Choose an option: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) {
            printf("\nHow many Notes You want to add: ");
            scanf("%d", &size);
            for (int i = 0; i < size; i++) {
                printf("Enter Note Number %d: ", sum_of_notes + 1);
                scanf(" %[^\n]s", notes[sum_of_notes]);

                printf("Is it important? Enter 0 for NO, 1 for YES: ");
                scanf("%d", &choice_for_importance);

                if (choice_for_importance == 1) {
                    int j = 0;
                    while (notes[sum_of_notes][j] != '\0') {
                        importance[total_importance][j] = notes[sum_of_notes][j];
                        j++;
                    }
                    importance[total_importance][j] = '\0';
                    total_importance++;
                }
                sum_of_notes++;
            }
        }
        else if (choice == 2) {
            printf("\nEnter the note number you want to delete: ");
            scanf("%d", &delete_index);
            delete_index--;

            if (delete_index >= 0 && delete_index < sum_of_notes) {
                notes[delete_index][0] = '\0';

                if (delete_index < total_importance) {
                    importance[delete_index][0] = '\0';
                    total_importance--;
                }

                printf("Note deleted successfully.\n");
            } else {
                printf("Invalid note number!\n");
            }
        }
        else if (choice == 3) {
            printf("\nThe Important Notes:\n");
            if (total_importance == 0) {
                printf("No important notes yet.\n");
            } else {
                for (int i = 0; i < total_importance; i++) {
                    printf("Important Note %d: %s\n", i + 1, importance[i]);
                }
            }
        }
        else if(choice == 4) {
            for(int i = 0; i < sum_of_notes; i++) {
                printf("Note NUM.%d : %s \n", i + 1, notes[i]);
            }
        }
        else if(choice == 5) {
            int edit_index;
            printf("\nEnter the note number you want to edit: ");
            scanf("%d", &edit_index);
            edit_index--;

            if(edit_index >= 0 && edit_index < sum_of_notes) {
                printf("Current Note: %s\n", notes[edit_index]);
                printf("Enter the new note: ");
                scanf(" %[^\n]s", notes[edit_index]);
            } else {
                printf("Invalid note number!\n");
            }
        }
        else if(choice == 6) {
            int categorize_index;
            char category[1000];

            printf("\nEnter the note number you want to categorize: ");
            scanf("%d", &categorize_index);
            categorize_index--;

            if(categorize_index >= 0 && categorize_index < sum_of_notes) {
                printf("Current Note: %s\n", notes[categorize_index]);
                printf("Enter a category for this note: ");
                scanf(" %[^\n]s", category);
                printf("Note categorized under: %s\n", category);
            } else {
                printf("Invalid note number!\n");
            }
        }
        else if(choice == 7) {
            char search_term[1000];
            int found = 0;

            printf("\nEnter the keyword to search for: ");
            scanf(" %[^\n]s", search_term);

            for (int i = 0; i < sum_of_notes; i++) {
                if (strstr(notes[i], search_term) != NULL) {
                    printf("Found in Note %d: %s\n", i + 1, notes[i]);
                    found = 1;
                }
            }

            if (!found) {
                printf("No notes found containing the keyword: %s\n", search_term);
            }
        }
        else if(choice == 8) {
            int tag_index;
            char tag[1000];

            printf("\nEnter the number of the important note you want to tag: ");
            scanf("%d", &tag_index);
            tag_index--;  // Adjust for zero-based index

            if(tag_index >= 0 && tag_index < total_importance) {
                printf("Important Note: %s\n", importance[tag_index]);
                printf("Enter a tag for this note: ");
                scanf(" %[^\n]s", tag);
                printf("Important Note tagged with: %s\n", tag);
            } else {
                printf("Invalid important note number!\n");
            }
        }
    }

    return 0;
}
