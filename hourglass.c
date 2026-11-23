
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 8
#define DAYS 112
#define WEEKS 16
#define NAME_LENGTH 40
#define FILE_NAME "hourglass.dat"

typedef struct {
    int subjectCount;
    char subjects[MAX_SUBJECTS][NAME_LENGTH];
    float weeklyGoal[MAX_SUBJECTS];
    float hours[DAYS][MAX_SUBJECTS];
} Tracker;

// Function declarations
void initializeTracker(Tracker *t);
void loadData(Tracker *t);
void saveData(Tracker *t);
void addStudyRecord(Tracker *t);
void viewRecords(Tracker *t);
void weeklyTrend(Tracker *t);
void neglectedSubject(Tracker *t);
void studyStreak(Tracker *t);
void setGoals(Tracker *t);
void goalComparison(Tracker *t);
void productivityGraph(Tracker *t);
float getSubjectTotal(Tracker *t, int subject);
float getWeeklyTotal(Tracker *t, int week);
int hasStudied(Tracker *t, int day);
int readInteger(const char *message);
float readFloat(const char *message);
void displayMenu(void);

// Initialize tracker
void initializeTracker(Tracker *t) {
    int i, j;

    t->subjectCount = 0;

    for (i = 0; i < MAX_SUBJECTS; i++) {
        strcpy(t->subjects[i], "");
        t->weeklyGoal[i] = 0;

        for (j = 0; j < DAYS; j++) {
            t->hours[j][i] = 0;
        }
    }

    printf("\n====================================\n");
    printf("          HOURGLASS SETUP\n");
    printf("====================================\n");

    do {
        t->subjectCount =
            readInteger("Enter number of subjects (1-8): ");
    } while (t->subjectCount < 1 ||
             t->subjectCount > MAX_SUBJECTS);

    for (i = 0; i < t->subjectCount; i++) {
        printf("\nSubject %d name: ", i + 1);

        fgets(t->subjects[i], NAME_LENGTH, stdin);
        t->subjects[i][strcspn(t->subjects[i], "\n")] = '\0';

        t->weeklyGoal[i] =
            readFloat("Weekly study goal (hours): ");
    }
}

// Save tracker data
void saveData(Tracker *t) {
    FILE *file = fopen(FILE_NAME, "wb");

    if (file == NULL) {
        printf("\nError saving data!\n");
        return;
    }

    fwrite(t, sizeof(Tracker), 1, file);
    fclose(file);

    printf("\nData successfully saved!\n");
}

// Load previously saved data
void loadData(Tracker *t) {
    FILE *file = fopen(FILE_NAME, "rb");

    if (file != NULL) {
        Tracker temp;

        if (fread(&temp, sizeof(Tracker), 1, file) == 1 &&
            temp.subjectCount >= 1 &&
            temp.subjectCount <= MAX_SUBJECTS) {

            *t = temp;
            printf("\nWelcome back to HOURGLASS!\n");
            printf("Previous records loaded successfully.\n");

        } else {
            printf("\nSaved data is invalid.\n");
            initializeTracker(t);
        }

        fclose(file);
    } else {
        initializeTracker(t);
    }
}

// Read integer input
int readInteger(const char *message) {
    char input[100];
    char *end;
    long value;

    while (1) {
        printf("%s", message);

        if (fgets(input, sizeof(input), stdin) == NULL)
            return 0;

        value = strtol(input, &end, 10);

        while (*end == ' ' || *end == '\t' ||
               *end == '\n' || *end == '\r') {
            end++;
        }

        if (end != input && *end == '\0')
            return (int)value;

        printf("Invalid input. Enter a whole number.\n");
    }
}

// Read decimal input
float readFloat(const char *message) {
    char input[100];
    char *end;
    float value;

    while (1) {
        printf("%s", message);

        if (fgets(input, sizeof(input), stdin) == NULL)
            return 0;

        value = strtof(input, &end);

        while (*end == ' ' || *end == '\t' ||
               *end == '\n' || *end == '\r') {
            end++;
        }

        if (end != input && *end == '\0' && value >= 0)
            return value;

        printf("Invalid input. Enter a non-negative number.\n");
    }
}

// Display main menu
void displayMenu(void) {
    printf("\n========================================\n");
    printf("               HOURGLASS\n");
    printf("          Make Every Hour Count\n");
    printf("========================================\n");
    printf("[1] Add Study Record\n");
    printf("[2] View Study Records\n");
    printf("[3] Weekly Productivity Trend\n");
    printf("[4] Most Neglected Subject\n");
    printf("[5] Study Streaks\n");
    printf("[6] Set Weekly Study Goals\n");
    printf("[7] Goal vs Actual Hours\n");
    printf("[8] Productivity Graph\n");
    printf("[9] Save Data\n");
    printf("[0] Save and Exit\n");
    printf("========================================\n");
}

// Add study record
void addStudyRecord(Tracker *t) {
    int day, subject;
    float hours;

    printf("\n========== ADD STUDY RECORD ==========\n");

    day = readInteger("Enter semester day (1-112): ");

    if (day < 1 || day > DAYS) {
        printf("Invalid day number!\n");
        return;
    }

    printf("\nAvailable Subjects:\n");

    for (int i = 0; i < t->subjectCount; i++)
        printf("[%d] %s\n", i + 1, t->subjects[i]);

    subject = readInteger("Select subject: ");

    if (subject < 1 || subject > t->subjectCount) {
        printf("Invalid subject selection!\n");
        return;
    }

    hours = readFloat("Enter hours studied: ");

    if (hours > 24) {
        printf("A day cannot contain more than 24 study hours.\n");
        return;
    }

    int index = day - 1;
    int subjectIndex = subject - 1;

    if (t->hours[index][subjectIndex] + hours > 24) {
        printf("Recorded hours for this subject on this day "
               "cannot exceed 24.\n");
        return;
    }

    t->hours[index][subjectIndex] += hours;

    printf("\nStudy record successfully added!\n");
    printf("%s: %.2f hours\n",
           t->subjects[subjectIndex], hours);
}

// View study records
void viewRecords(Tracker *t) {
    int found = 0;

    printf("\n========== STUDY RECORDS ==========\n");
    printf("%-12s %-25s %s\n", "Day", "Subject", "Hours");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < t->subjectCount; j++) {
            if (t->hours[i][j] > 0) {
                printf("%-12d %-25s %.2f\n",
                       i + 1,
                       t->subjects[j],
                       t->hours[i][j]);
                found = 1;
            }
        }
    }

    if (!found)
        printf("No study records available yet.\n");
}

// Calculate total hours per subject
float getSubjectTotal(Tracker *t, int subject) {
    float total = 0;

    for (int i = 0; i < DAYS; i++)
        total += t->hours[i][subject];

    return total;
}

// Calculate total hours per week
float getWeeklyTotal(Tracker *t, int week) {
    float total = 0;
    int start = week * 7;

    for (int i = start; i < start + 7; i++) {
        for (int j = 0; j < t->subjectCount; j++)
            total += t->hours[i][j];
    }

    return total;
}

// Weekly productivity trend
void weeklyTrend(Tracker *t) {
    printf("\n========== WEEKLY PRODUCTIVITY ==========\n");

    for (int i = 0; i < WEEKS; i++) {
        printf("Week %2d: %.2f hours\n",
               i + 1, getWeeklyTotal(t, i));
    }
}

// Identify most neglected subject
void neglectedSubject(Tracker *t) {
    int lowest = 0;
    float lowestHours = getSubjectTotal(t, 0);

    printf("\n========== SUBJECT ANALYSIS ==========\n");

    for (int i = 0; i < t->subjectCount; i++) {
        float total = getSubjectTotal(t, i);

        printf("%-25s %.2f hours\n",
               t->subjects[i], total);

        if (total < lowestHours) {
            lowestHours = total;
            lowest = i;
        }
    }

    printf("\nMost neglected subject: %s\n",
           t->subjects[lowest]);
    printf("Total study hours: %.2f\n", lowestHours);
}

// Check if student studied on a particular day
int hasStudied(Tracker *t, int day) {
    for (int i = 0; i < t->subjectCount; i++) {
        if (t->hours[day][i] > 0)
            return 1;
    }

    return 0;
}

// Calculate study streaks
void studyStreak(Tracker *t) {
    int current = 0;
    int longest = 0;
    int temporary = 0;
    int lastDay = -1;

    for (int i = 0; i < DAYS; i++) {
        if (hasStudied(t, i)) {
            temporary++;
            lastDay = i;

            if (temporary > longest)
                longest = temporary;
        } else {
            temporary = 0;
        }
    }

    if (lastDay != -1) {
        for (int i = lastDay; i >= 0; i--) {
            if (hasStudied(t, i))
                current++;
            else
                break;
        }
    }

    printf("\n========== STUDY STREAKS ==========\n");
    printf("Longest study streak: %d days\n", longest);
    printf("Current streak ending on last recorded day: %d days\n",
           current);

    if (longest >= 7)
        printf("Excellent consistency! Keep it up!\n");
    else
        printf("Keep building your study habits!\n");
}

// Set weekly study goals
void setGoals(Tracker *t) {
    printf("\n========== SET STUDY GOALS ==========\n");

    for (int i = 0; i < t->subjectCount; i++) {
        printf("\n%s\n", t->subjects[i]);

        printf("Current weekly goal: %.2f hours\n",
               t->weeklyGoal[i]);

        t->weeklyGoal[i] =
            readFloat("New weekly goal: ");
    }

    printf("\nStudy goals successfully updated!\n");
}

// Compare goal and actual hours
void goalComparison(Tracker *t) {
    int week;

    printf("\n========== GOAL VS ACTUAL ==========\n");

    week = readInteger("Enter week number (1-16): ");

    if (week < 1 || week > WEEKS) {
        printf("Invalid week number!\n");
        return;
    }

    printf("\nWeek %d Report\n", week);
    printf("%-22s %-12s %-12s %s\n",
           "Subject", "Goal", "Actual", "Status");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < t->subjectCount; i++) {
        float actual = 0;
        int start = (week - 1) * 7;

        for (int j = start; j < start + 7; j++)
            actual += t->hours[j][i];

        printf("%-22s %-12.2f %-12.2f %s\n",
               t->subjects[i],
               t->weeklyGoal[i],
               actual,
               actual >= t->weeklyGoal[i]
                   ? "ACHIEVED" : "NOT YET");
    }
}

// Display productivity graph
void productivityGraph(Tracker *t) {
    float totals[WEEKS];
    float maximum = 0;

    printf("\n========== PRODUCTIVITY GRAPH ==========\n");

    for (int i = 0; i < WEEKS; i++) {
        totals[i] = getWeeklyTotal(t, i);

        if (totals[i] > maximum)
            maximum = totals[i];
    }

    if (maximum == 0) {
        printf("No data available to generate graph.\n");
        return;
    }

    printf("\nWeekly Study Hours\n\n");

    for (int i = 0; i < WEEKS; i++) {
        int bars = (int)((totals[i] / maximum) * 40);

        printf("W%02d | ", i + 1);

        for (int j = 0; j < bars; j++)
            printf("#");

        printf(" %.2f hrs\n", totals[i]);
    }

    printf("\nEach # represents a proportional amount of study time.\n");
}

// Main function
int main(void) {
    Tracker tracker;
    int choice;

    loadData(&tracker);

    do {
        displayMenu();

        choice = readInteger("Enter your choice: ");

        switch (choice) {
            case 1:
                addStudyRecord(&tracker);
                break;

            case 2:
                viewRecords(&tracker);
                break;

            case 3:
                weeklyTrend(&tracker);
                break;

            case 4:
                neglectedSubject(&tracker);
                break;

            case 5:
                studyStreak(&tracker);
                break;

            case 6:
                setGoals(&tracker);
                break;

            case 7:
                goalComparison(&tracker);
                break;

            case 8:
                productivityGraph(&tracker);
                break;

            case 9:
                saveData(&tracker);
                break;

            case 0:
                saveData(&tracker);
                printf("\nThank you for using HOURGLASS!\n");
                printf("Make Every Hour Count!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
