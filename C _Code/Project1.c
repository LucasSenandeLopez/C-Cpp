#include <stdio.h>

typedef struct {
  long int id;
  double average_grade;
  char* name;
  char* surname;
  int age;
} Student; 

double get_grade(const Student* student);

int main(){

  const Student st_1 = {1, 60, "ab", "bc", 14};  

  printf("avg_grade = %f", get_grade(&st_1));
  return 0;
}

double get_grade(const Student* const student){
  return student->average_grade;
}