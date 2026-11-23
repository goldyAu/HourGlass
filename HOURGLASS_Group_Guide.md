# HOURGLASS -- Group Guide

**Project title:** HOURGLASS: A Student Study Habit and Productivity
Tracking System\
**Tagline:** Make Every Hour Count.

## 1. Program Description

HOURGLASS is a C-based Study Habit and Productivity Tracker that helps
students monitor their daily study hours, set weekly goals, track study
streaks, identify neglected subjects, and evaluate their academic
productivity through weekly trends and graphs. Its goal is to promote
consistency, effective time management, and better study habits.

## 2. Problem the Program Addresses

Students may find it difficult to maintain consistent study routines and
distribute their time among different subjects. Without organized
records, they may overlook subjects, lose track of their study habits,
or struggle to evaluate their progress.

HOURGLASS provides a way to record study activities and review how much
time is spent on each subject.

## 3. Main Features

  -----------------------------------------------------------------------
  Menu option             Feature                 What it does
  ----------------------- ----------------------- -----------------------
  1                       Add Study Record        Records the semester
                                                  day, subject, and hours
                                                  studied.

  2                       View Study Records      Displays saved study
                                                  entries.

  3                       Weekly Productivity     Displays total study
                          Trend                   hours for each week.

  4                       Most Neglected Subject  Identifies the subject
                                                  with the lowest
                                                  accumulated study
                                                  hours.

  5                       Study Streaks           Calculates consecutive
                                                  days with recorded
                                                  study activity.

  6                       Set Weekly Study Goals  Sets or changes the
                                                  weekly goal for each
                                                  subject.

  7                       Goal vs. Actual Hours   Compares a selected
                                                  week's goal and actual
                                                  hours.

  8                       Productivity Graph      Displays a text-based
                                                  bar graph of weekly
                                                  study hours.

  9                       Save Data               Saves the current
                                                  tracker data.

  0                       Save and Exit           Saves the data and
                                                  closes the program.
  -----------------------------------------------------------------------

## 4. How to Use HOURGLASS

### Step 1 -- Launch the program

Run `hourglass.exe` (or the compiled program). On startup, the program
checks for `hourglass.dat`.

-   If valid saved data is found, it loads the previous tracker.
-   If no saved data is found, the program starts the initial setup.

### Step 2 -- Set up the tracker

For a new tracker, enter: 1. The number of subjects (1--8). 2. Each
subject's name. 3. Each subject's weekly study goal in hours.

### Step 3 -- Add study records

Choose **1 -- Add Study Record**. Enter: 1. The semester day (1--112).
2. The subject number from the displayed list. 3. The number of hours
studied.

The program adds the entry to the selected subject and day. Multiple
entries for the same subject and day are combined.

### Step 4 -- Review your records and progress

Choose the relevant menu option: - **2** to view individual study
entries. - **3** to view weekly totals. - **4** to identify the subject
with the lowest total study hours. - **5** to view the longest and
current recorded study streaks. - **7** to compare goals and actual
hours for a selected week. - **8** to view the weekly productivity
graph.

### Step 5 -- Update goals

Choose **6 -- Set Weekly Study Goals** to change the weekly target for
each subject.

### Step 6 -- Save and exit

Choose **9** to save without exiting, or **0** to save and close the
program. The data is stored in `hourglass.dat` in the program's working
directory. Keep this file if you want to continue using the same records
later.

## 5. Programming Concepts Used

  -----------------------------------------------------------------------
  C concept                           How it is used
  ----------------------------------- -----------------------------------
  Variables and data types            Store menu choices, day numbers,
                                      subject counts, hours, and goals.

  Arrays                              Store subject information and daily
                                      study-hour entries.

  Strings                             Store subject names.

  Pointers                            Pass the address of the `Tracker`
                                      structure to functions so they can
                                      access or update it.

  Structures                          The `Tracker` structure groups
                                      subject names, goals, and
                                      study-hour data.

  Selection                           `if`, `else`, and `switch`
                                      statements make decisions based on
                                      input and conditions.

  Repetition                          `for` loops process days, weeks,
                                      and subjects; a `do-while` loop
                                      keeps the menu running.

  User-defined functions              Separate tasks such as recording
                                      hours, displaying reports, and
                                      saving data.

  File handling                       `fopen()`, `fwrite()`, and
                                      `fread()` save and load tracker
                                      data.
  -----------------------------------------------------------------------

## 6. Suggested Presentation Explanation

### Introduction

"HOURGLASS is a Study Habit and Productivity Tracker developed using the
C programming language. It helps students record their daily study
hours, set weekly goals, and review their productivity throughout a
16-week semester."

### Problem

"Students can have difficulty managing their study time and giving
enough attention to every subject. HOURGLASS provides organized records
and simple reports to help students understand their study habits."

### Features

Briefly explain the nine main functions listed in Section 3. During the
demonstration, show how to add records, view reports, compare goals,
display the graph, and save the data.

### Closing

"Overall, HOURGLASS aims to encourage consistent study habits and better
time management by allowing students to monitor and evaluate their study
activities."

## 7. Suggested Demonstration Order

For a clear video or live demonstration:

1.  Launch HOURGLASS.
2.  Set up three sample subjects and weekly goals, if starting with a
    new data file.
3.  Add several study records across different days and subjects.
4.  View the study records.
5.  Display the weekly productivity trend.
6.  Show the most neglected subject.
7.  Display the study streaks.
8.  Update a weekly goal.
9.  Compare the goal with actual hours for a selected week.
10. Display the productivity graph.
11. Save, exit, and reopen the program to show that records persist.

Use sample data so that the reports and graph contain meaningful
results.

## 8. Possible Questions and Suggested Answers

**Q: Why did you choose this project?**\
A: We chose it because students may struggle with time management and
consistent study habits. We wanted to create a program that helps them
record and review their study activities.

**Q: What is the purpose of HOURGLASS?**\
A: It helps students organize study records, monitor their progress, and
identify subjects that may need more attention.

**Q: How does it identify the most neglected subject?**\
A: It totals the recorded study hours for each subject and identifies
the subject with the lowest total.

**Q: How does the study streak feature work?**\
A: It checks each semester day for any recorded study activity.
Consecutive days with activity are counted as a streak.

**Q: How does the program save information?**\
A: It uses file handling. `fwrite()` writes the tracker structure to a
binary file, and `fread()` reads it when the program starts.

**Q: Why use a structure?**\
A: The `Tracker` structure groups related information, including subject
names, weekly goals, and daily study hours.

**Q: Why use pointers?**\
A: Functions receive a pointer to the tracker so they can access or
modify the same tracker data without passing a separate copy.

**Q: What happens if the user enters an invalid menu choice?**\
A: The program displays an error message and returns to the menu.

## 9. Current Program Scope and Limitations

Be accurate when describing the current code:

-   It supports up to **8 subjects**.
-   It represents a semester as **16 weeks or 112 days**.
-   Study entries are entered manually.
-   The graph is an ASCII/text-based graph, not a graphical chart.
-   The user enters a semester day number rather than a calendar date.
-   The current streak is calculated up to the last day with recorded
    study activity; it does not check today's calendar date.
-   Each subject has one weekly goal value, which is used when comparing
    any selected week.
-   The neglected subject is based on the lowest total recorded hours,
    not on a subject-specific target or difficulty.
-   Data is stored in a binary file named `hourglass.dat`. Keep the file
    in the program's working directory to retain access to the saved
    records.

## 10. Important Reminders for Group Members

-   Read and understand the source code; do not memorize only the sample
    answers.
-   Know what the `Tracker` structure stores.
-   Be able to explain how the arrays represent days and subjects.
-   Understand how pointers are used when passing the tracker to
    functions.
-   Know the difference between `fwrite()` and `fread()`.
-   Test each menu option before recording the demonstration.
-   Use the same program version for the source code, documentation, and
    video.
-   Do not claim that the program has features that are not implemented
    in the current code.

**HOURGLASS -- Make Every Hour Count.**
