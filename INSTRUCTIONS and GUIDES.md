
# HOURGLASS: A Student Study Habit and Productivity Tracking System

**Tagline:** Make Every Hour Count.

## 1. About the Program

HOURGLASS is a console-based study habit and productivity tracking system developed using the C programming language. It is designed to help students monitor their study hours, set weekly study goals, track their productivity, and evaluate their study habits throughout a 16-week semester.

The program allows students to record their daily study hours for different subjects and provides summaries and visual representations of their progress.

## 2. Purpose of the Program

The main purpose of HOURGLASS is to help students become more aware of how they spend their study time. By tracking study hours and comparing actual performance with weekly goals, students can identify subjects that need more attention and develop better study habits.

## 3. Main Features

### 3.1 Add Study Record
Allows the user to record the number of hours spent studying a particular subject on a specific day.

- Accepts a semester day from 1 to 112.
- Allows the user to select a registered subject.
- Accepts the number of hours studied.
- Prevents the total recorded study hours for one day from exceeding 24 hours.

### 3.2 View Study Records
Displays the recorded study hours for each subject throughout the semester.

- Shows the days with recorded study sessions.
- Displays the corresponding subjects and study hours.
- Helps users review their study activity.

### 3.3 Weekly Productivity Trend
Calculates and displays the total study hours for each week.

- Divides the 112-day semester into 16 weeks.
- Adds the recorded study hours for each week.
- Helps users observe changes in their weekly productivity.

### 3.4 Most Neglected Subject
Identifies the subject with the lowest accumulated study hours throughout the semester.

- Calculates the total study hours for every subject.
- Compares the accumulated hours.
- Displays the subject with the lowest total.

### 3.5 Study Streaks
Tracks consecutive days with recorded study sessions.

- Calculates the longest study streak.
- Calculates the current streak based on the latest recorded semester day.
- Helps users monitor consistency in their study habits.

### 3.6 Set Weekly Study Goals
Allows users to set or update their weekly study-hour goals for each subject.

- Accepts a target number of hours for every subject.
- Stores the goals for comparison with actual study hours.
- The same subject goal is used for each week.

### 3.7 Goal vs. Actual Hours
Compares the user's actual study hours with their weekly goals.

- Allows the user to select a week.
- Displays the actual hours studied per subject.
- Compares actual hours with the corresponding weekly goal.
- Indicates whether the goal was achieved.

### 3.8 Productivity Graph
Displays a simple ASCII bar graph representing weekly study hours.

- Uses `#` symbols to represent study hours.
- Makes weekly productivity easier to visualize.
- Allows users to compare their study activity across weeks.

### 3.9 Save Data
Saves the user's study records and settings into a binary file named `hourglass.dat`.

- Preserves the user's data when the program closes.
- Allows previously saved data to be loaded when the program starts.
- Prevents users from having to enter their information again every time they run the program.

### 3.10 Save and Exit
Saves the current data and terminates the program safely.

## 4. How the Program Works

### Step 1: Start the Program
When the program starts, it checks whether a saved data file named `hourglass.dat` exists.

- If the file exists and contains valid data, the program loads the saved information.
- If no valid saved data is available, the program initializes a new tracker.

### Step 2: Initial Setup
For a new tracker, the user is asked to:

1. Enter the number of subjects.
2. Enter the name of each subject.
3. Set the weekly study-hour goal for each subject.

The program supports a maximum of eight subjects.

### Step 3: Main Menu
After initialization or loading saved data, the program displays the main menu.

The user can select a feature by entering its corresponding number.

### Step 4: Perform an Operation
The program executes the function associated with the selected menu option.

For example:
- Selecting `1` opens the Add Study Record feature.
- Selecting `3` displays the Weekly Productivity Trend.
- Selecting `5` calculates Study Streaks.
- Selecting `8` displays the Productivity Graph.

After completing an operation, the program returns to the main menu.

### Step 5: Save and Exit
When the user selects `0`, the program saves the current data and exits.


## 5. Main Menu Options and Their Functions

The HOURGLASS main menu contains ten options. Each option provides a specific function for managing and analyzing the user's study habits.

### Option 1: Add Study Record

**Purpose:** Records the number of hours the user spends studying a particular subject.

**How it works:**
1. The user enters the semester day (1–112).
2. The user selects a registered subject.
3. The user enters the number of hours spent studying.
4. The program validates the input and saves the record in the tracker.

**Example:** If the user studies Mathematics for 2 hours on Day 1, the program records 2 hours under Mathematics for that day.

**Expected result:** The study record is added and can be viewed or included in productivity calculations.

### Option 2: View Study Records

**Purpose:** Displays the study records entered by the user.

**How it works:**
1. The program checks all 112 semester days.
2. It checks the recorded hours for every registered subject.
3. It displays the days and subjects with recorded study sessions.

**Example:**
- Day 1 – Mathematics: 2 hours
- Day 2 – Computer Science: 3 hours
- Day 3 – English: 1.5 hours

**Expected result:** The user can review their recorded study activities throughout the semester.

### Option 3: Weekly Productivity Trend

**Purpose:** Displays the total number of study hours accumulated each week.

**How it works:**
1. The program divides the 112-day semester into 16 weeks.
2. It calculates the total study hours recorded during each week.
3. It displays the weekly totals.

**Example:**
- Week 1 – 15 hours
- Week 2 – 18 hours
- Week 3 – 12 hours

**Expected result:** The user can identify which weeks had higher or lower study activity.

### Option 4: Most Neglected Subject

**Purpose:** Identifies the subject with the lowest accumulated study hours.

**How it works:**
1. The program calculates the total study hours for each subject.
2. It compares the accumulated hours.
3. It identifies and displays the subject with the lowest total.

**Example:**
- Mathematics – 30 hours
- English – 20 hours
- Computer Science – 45 hours

**Expected result:** English is identified as the most neglected subject because it has the lowest accumulated study hours.

### Option 5: Study Streaks

**Purpose:** Measures the user's consistency in recording study sessions.

**How it works:**
1. The program checks the semester days with recorded study hours.
2. It identifies consecutive days with study records.
3. It calculates the longest study streak.
4. It calculates the current streak based on the latest recorded semester day.

**Example:** If the user has study records on Days 1, 2, 3, and 5, the longest streak is 3 consecutive days.

**Expected result:** The user can see their longest streak and current streak.

### Option 6: Set Weekly Study Goals

**Purpose:** Allows the user to establish or update the target number of study hours for each subject per week.

**How it works:**
1. The program displays the registered subjects.
2. The user enters a weekly study-hour goal for each subject.
3. The program updates and stores the goals.

**Example:**
- Mathematics – 5 hours per week
- English – 3 hours per week
- Computer Science – 6 hours per week

**Expected result:** The updated goals will be used when comparing actual study hours with weekly targets.

**Note:** The same goal for each subject is used across all 16 weeks unless the user updates it.

### Option 7: Goal vs. Actual Hours

**Purpose:** Compares the user's actual study hours with their weekly study goals.

**How it works:**
1. The user selects a week.
2. The program calculates the actual study hours for each subject during that week.
3. It compares the actual hours with the corresponding weekly goal.
4. It displays whether the user achieved the goal.

**Example:**

| Subject | Weekly Goal | Actual Hours | Status |
|---|---:|---:|---|
| Mathematics | 5 hours | 6 hours | ACHIEVED |
| English | 3 hours | 2 hours | NOT YET |
| Computer Science | 6 hours | 6 hours | ACHIEVED |

**Expected result:** The user can determine which subject goals were achieved and which still need attention.

### Option 8: Productivity Graph

**Purpose:** Provides a visual representation of the user's weekly study hours using an ASCII bar graph.

**How it works:**
1. The program calculates the total study hours for each week.
2. It converts the weekly totals into proportional bar lengths.
3. It displays the results using `#` symbols.

**Example:**

```text
WEEKLY PRODUCTIVITY GRAPH

Week 1  ########## 
Week 2  ###############
Week 3  #######
Week 4  ####################
```

**Expected result:** The user can easily compare weekly productivity through a simple text-based graph.

### Option 9: Save Data

**Purpose:** Saves the current tracker information so it can be accessed the next time the program runs.

**How it works:**
1. The program opens the `hourglass.dat` file.
2. It writes the current tracker information into the file.
3. It closes the file after saving.

**Expected result:** The user's subjects, weekly goals, and study records are preserved.

### Option 0: Save and Exit

**Purpose:** Saves all current tracker information and terminates the program.

**How it works:**
1. The program saves the current data.
2. It completes the saving process.
3. It exits the application.

**Expected result:** The program closes while preserving the user's saved information.

---


## 6. Important Program Information

- **Programming Language:** C
- **Program Type:** Console-based application
- **Tracking Period:** 16 weeks
- **Total Tracking Days:** 112 days
- **Maximum Subjects:** 8
- **Maximum Recorded Hours Per Subject Per Day:** 24 hours
- **Data Storage:** Binary file (`hourglass.dat`)

## 7. Programming Concepts Used

HOURGLASS demonstrates several fundamental programming concepts in C.

| Programming Concept | Application in the Program |
|---|---|
| Variables and Data Types | Store study hours, days, goals, and menu selections. |
| Selection Statements | Handle menu choices and validate user input using `if`, `else`, and `switch`. |
| Repetition Statements | Use loops to process subjects, days, weeks, and menu operations. |
| Arrays | Store subject names, weekly goals, and daily study records. |
| Strings | Store and process subject names. |
| Pointers | Pass data to functions and manipulate tracker information. |
| Structures | Organize related study information using the `Tracker` structure. |
| User-Defined Functions | Divide the program into smaller and reusable operations. |
| File Handling | Save and load tracker information using file operations. |

## 8. Data Organization

The program uses a structure named `Tracker` to organize the user's information.

It contains:

- `subjectCount` - Stores the number of registered subjects.
- `subjects` - Stores the names of the subjects.
- `weeklyGoal` - Stores the weekly study-hour goal for each subject.
- `hours` - Stores the daily study hours for every subject throughout the 112-day semester.

The daily study records are organized using a two-dimensional array.

The first dimension represents the semester day, while the second dimension represents the subject.

## 9. Compilation and Execution

### Requirements
- A C compiler such as GCC.
- Visual Studio Code or another code editor.
- A terminal or command prompt.

### Compile the Program

Open the terminal in the folder containing `hourglass.c` and execute:

```bash
gcc -std=c11 -Wall -Wextra hourglass.c -o hourglass.exe
```

### Run the Program

In PowerShell, execute:

```powershell
.\hourglass.exe
```

If compilation is successful, the program will run in the terminal.

## 10. File Structure

The project can be organized as follows:

```text
HOURGLASS/
│
├── hourglass.c
├── README.md
├── HOURGLASS_GUIDE.md
├── .gitignore
└── hourglass.dat
```

**Note:** The `hourglass.dat` file is generated automatically when the program saves data. It does not need to be created manually.

## 11. Limitations

- The program supports a maximum of eight subjects.
- The tracking period is limited to 112 days or 16 weeks.
- Weekly study goals are assigned per subject and remain the same across all weeks unless updated.
- Study streaks are based on recorded semester days rather than actual calendar dates.
- The program uses a console interface and does not have a graphical user interface.
- The program stores data locally in a binary file.

## 12. Conclusion

HOURGLASS provides students with a simple way to monitor their study habits and productivity. Through daily study records, weekly goals, productivity summaries, study streaks, and graphical representations, students can better understand their study patterns and identify areas that need improvement.

By making study time measurable and organized, HOURGLASS encourages students to become more consistent, responsible, and productive in their academic activities.

**HOURGLASS — Make Every Hour Count.**
