#include <stdio.h>
#include <string.h> // strcmp, etc.
                    // still avoid spaces in courseCode/status to keep parsing simple.

/* I need to extend the previous task and can't forget this:
  - Parameters added to functions
  - Duplicate-ID check before appending
  - Search by ID
*/

#define file_name "regs.txt"
#define max_courses 200

typedef struct
{
  int id;              // numeric identifier
  char courseCode[32]; // e.g., CS101
  char status[32];     // e.g., Active or Inactive
} Course;

/* Function Prototypes with parameters this time */
void addCourse(int id, const char courseCode[], const char status[]);
int loadCourses(Course list[], int max);
void displayCourses(const Course list[], int count);
void searchCourses(int id);

/* small menu to exercise the functions*/
int main()
{
  int choice = 0;

  do
  {
    printf("\n=== Course Registration (50–59) ===\n");
    printf("1) Add a course (with duplicate ID check)\n");
    printf("2) Display all courses (load -> display)\n");
    printf("3) Search a course by ID\n");
    printf("4) Exit\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1)
    {
      printf("Invalid input. Exiting.\n");
      return 0;
    }

    if (choice == 1)
    {
      // Collect parameters from the user, then call addCourse(id, code, status)
      int id;
      char code[32], status[32];

      printf("Enter course ID (integer): ");
      if (scanf("%d", &id) != 1)
      {
        printf("Bad ID.\n");
        return 0;
      }

      printf("Enter course code (no spaces): ");
      scanf("%31s", code);

      printf("Enter status (no spaces): ");
      scanf("%31s", status);

      addCourse(id, code, status); // function with parameters
    }
    else if (choice == 2)
    {
      // Load from file into an in-memory list, then pass that list to displayCourses(list, count)
      Course list[max_courses];
      int count = loadCourses(list, max_courses);
      displayCourses(list, count);
    }
    else if (choice == 3)
    {
      int id;
      printf("Enter ID to search: ");
      if (scanf("%d", &id) != 1)
      {
        printf("Bad ID.\n");
        return 0;
      }
      searchCourses(id); // function with parameter
    }
    else if (choice == 4)
    {
      printf("Goodbye!\n");
    }
    else
    {
      printf("Please choose 1, 2, 3, or 4.\n");
    }

  } while (choice != 4);

  return 0;
}

/*  Implementation */

/*
  addCourse(id, code, status)
  - Why do I need parameters? The spec requires us to move user I/O out of the function
    and have this function just receive the data it needs to do its job.
  - What it does:
      1) Scan the file to see if 'id' already exists (duplicate protection).
      2) If not found, append a new line: "id code status".
*/
void addCourse(int id, const char courseCode[], const char status[])
{
  // Step 1: duplicate-ID check by scanning the file
  FILE *fp = fopen(file_name, "r");
  if (fp)
  {
    Course c;
    while (fscanf(fp, "%d %31s %31s", &c.id, c.courseCode, c.status) == 3)
    {
      if (c.id == id)
      {
        printf("Add refused: a course with ID %d already exists.\n", id);
        fclose(fp);
        return;
      }
    }
    fclose(fp);
  }
  // If the file doesn't exist yet, it creates one

  // Step 2: append the new record
  fp = fopen(file_name, "a");
  if (!fp)
  {
    printf("Error: could not open %s for appending.\n", file_name);
    return;
  }
  fprintf(fp, "%d %s %s\n", id, courseCode, status);
  fclose(fp);

  printf("Added: ID=%d  Code=%s  Status=%s\n", id, courseCode, status);
}

/*
  loadCourses(list, max)
  - Why do i need to use a loader? displayCourses() must accept a "list of Course" as a parameter.
    To produce that list from the file, we load the file into an in-memory array.
  - Returns how many records were loaded, so the caller can pass the correct count.
*/
int loadCourses(Course list[], int max)
{
  FILE *fp = fopen(file_name, "r");
  if (!fp)
  {
    // No file yet: zero records loaded
    return 0;
  }

  int count = 0;
  while (count < max &&
         fscanf(fp, "%d %31s %31s",
                &list[count].id, list[count].courseCode, list[count].status) == 3)
  {
    count++;
  }

  fclose(fp);
  return count;
}

/*
  displayCourses(list, count)
  - displayCourses to accept a "list of Courses".
    after some research, i learned that in C,  also pass 'count' because arrays decay to pointers and the function cannot know how many valid items there are without being told.
  - print every element in a neat, indexed format.
*/
void displayCourses(const Course list[], int count)
{
  printf("\n--- All Courses (%d) ---\n", count);
  if (count == 0)
  {
    printf("(No courses recorded yet.)\n");
    return;
  }
  for (int i = 0; i < count; i++)
  {
    printf("[%02d] ID: %-6d  Code: %-15s  Status: %s\n",
           i + 1, list[i].id, list[i].courseCode, list[i].status);
  }
}

/*
  searchCourses(id)
  - Why in the file, not the list? I didnt understand this at first, so I researched it:
   The rubric lets me search any way
    searching directly in the file means it still works even if i didn’t call load first.
  - scan the file and print the matching record, or "not found".
*/
void searchCourses(int id)
{
  FILE *fp = fopen(file_name, "r");
  if (!fp)
  {
    printf("No course file found (%s).\n", file_name);
    return;
  }

  Course c;
  while (fscanf(fp, "%d %31s %31s", &c.id, c.courseCode, c.status) == 3)
  {
    if (c.id == id)
    {
      printf("Found: ID=%d  Code=%s  Status=%s\n", c.id, c.courseCode, c.status);
      fclose(fp);
      return;
    }
  }

  fclose(fp);
  printf("No course with ID %d was found.\n", id);
}