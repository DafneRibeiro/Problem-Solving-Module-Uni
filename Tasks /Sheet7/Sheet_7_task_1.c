#include <stdio.h>

// Basic Course structure as specified
typedef struct
{
  int id;
  char courseCode[32];
  char status[32];
} Course;

// Function prototypes (no parameters, no return values)
void addCourse();      // function to add a course and append to file
void displayCourses(); // function to read and display all courses from file

int main()
{
  // For this part I just add one course, then display all
  // the program can be run the program multiple times to append more courses
  addCourse();
  displayCourses();
  return 0;
}

void addCourse(void)
{
  Course c;

  // Read fields from the user no spaces in strings
  printf("Enter course ID (integer): ");
  scanf("%d", &c.id);

  printf("Enter course code (no spaces, e.g., CS101): ");
  scanf("%31s", c.courseCode);

  printf("Enter status (no spaces, e.g., Active): ");
  scanf("%31s", c.status);

  // Append to regs.txt
  FILE *fp = fopen("regs.txt", "a");
  if (!fp)
  {
    printf("Error: could not open regs.txt for appending.\n");
    return;
  }

  // One line per course: id code status
  fprintf(fp, "%d %s %s\n", c.id, c.courseCode, c.status);
  fclose(fp);

  printf("Saved: %d %s %s\n", c.id, c.courseCode, c.status);
}

void displayCourses(void)
{
  FILE *fp = fopen("regs.txt", "r");
  if (!fp)
  {
    printf("\nNo course file found (regs.txt).\n");
    return;
  }

  printf("\n--- All Courses (from regs.txt) ---\n");

  Course c;
  int row = 0;

  // Read back exactly what I wrote: id code status
  while (fscanf(fp, "%d %31s %31s", &c.id, c.courseCode, c.status) == 3)
  {
    printf("[%02d] ID: %d  Code: %s  Status: %s\n", ++row, c.id, c.courseCode, c.status);
  }

  if (row == 0)
  {
    printf("(No courses recorded yet.)\n");
  }

  fclose(fp);
}