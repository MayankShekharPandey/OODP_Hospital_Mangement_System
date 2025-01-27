#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
    char disease[NAME_LENGTH];
} Patient;

Patient patients[MAX_PATIENTS];
int patientCount = 0;

void addPatient();
void viewPatients();
void searchPatient();
void deletePatient();
void updatePatient();
void countPatients();
void menu();

int main() {
    while (1) {
        menu();
    }
    return 0;
}

void menu() {
    int choice;

    printf("\n--- Hospital Management System ---\n");
    printf("1. Add Patient\n");
    printf("2. View Patients\n");
    printf("3. Search Patient\n");
    printf("4. Delete Patient\n");
    printf("5. Update Patient\n");
    printf("6. Count Patients\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addPatient();
            break;
        case 2:
            viewPatients();
            break;
        case 3:
            searchPatient();
            break;
        case 4:
            deletePatient();
            break;
        case 5:
            updatePatient();
            break;
        case 6:
            countPatients();
            break;
        case 7:
            printf("Exiting the program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Error: Maximum patient limit reached.\n");
        return;
    }

    Patient newPatient;
    newPatient.id = patientCount + 1;

    printf("Enter patient name: ");
    getchar();
    fgets(newPatient.name, NAME_LENGTH, stdin);
    newPatient.name[strcspn(newPatient.name, "\n")] = 0;

    printf("Enter patient age: ");
    scanf("%d", &newPatient.age);

    printf("Enter disease: ");
    getchar();
    fgets(newPatient.disease, NAME_LENGTH, stdin);
    newPatient.disease[strcspn(newPatient.disease, "\n")] = 0;

    patients[patientCount] = newPatient;
    patientCount++;

    printf("Patient added successfully!\n");
}

void viewPatients() {
    if (patientCount == 0) {
        printf("No patients to display.\n");
        return;
    }

    printf("\n--- Patient Records ---\n");
    for (int i = 0; i < patientCount; i++) {
        printf("ID: %d\n", patients[i].id);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Disease: %s\n", patients[i].disease);
        printf("---------------------------\n");
    }
}

void searchPatient() {
    int id;
    printf("Enter patient ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("\nPatient found:\n");
            printf("ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Disease: %s\n", patients[i].disease);
            return;
        }
    }
    printf("Patient with ID %d not found.\n", id);
}

void deletePatient() {
    int id;
    printf("Enter patient ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            printf("Patient with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Patient with ID %d not found.\n", id);
}

void updatePatient() {
    int id;
    printf("Enter patient ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("\nUpdating patient with ID %d:\n", id);
            printf("Enter new name (leave blank to keep unchanged): ");
            getchar();
            char newName[NAME_LENGTH];
            fgets(newName, NAME_LENGTH, stdin);
            if (newName[0] != '\n') {
                newName[strcspn(newName, "\n")] = 0;
                strcpy(patients[i].name, newName);
            }

            printf("Enter new age (enter -1 to keep unchanged): ");
            int newAge;
            scanf("%d", &newAge);
            if (newAge != -1) {
                patients[i].age = newAge;
            }

            printf("Enter new disease (leave blank to keep unchanged): ");
            getchar();
            char newDisease[NAME_LENGTH];
            fgets(newDisease, NAME_LENGTH, stdin);
            if (newDisease[0] != '\n') {
                newDisease[strcspn(newDisease, "\n")] = 0;
                strcpy(patients[i].disease, newDisease);
            }

            printf("Patient with ID %d updated successfully!\n", id);
            return;
        }
    }
    printf("Patient with ID %d not found.\n", id);
}

void countPatients() {
    printf("\nTotal number of patients: %d\n", patientCount);
}
