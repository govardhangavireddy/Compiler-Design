// VU21CSEN0100450 - Sai Govardhan Naidu
#include <stdio.h>
#include <stdlib.h>

struct Student {
  int sno;
  char sname[50];
  int marks;
  char grade;
};

void SelectionSort(struct Student s[], int n) {
  int i, j, min;
  struct Student temp;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (s[j].marks > s[min].marks) {
        min = j;
      }
      if (min != i) {
        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
      }
    }
  }
}

int main() {
  int n, i;
  printf("Enter the number of students : ");
  scanf("%d", &n);
  struct Student s[n];
  printf("Enter details of Students : (sno,Name,marks) ");
  for (i = 0; i < n; i++) {
    scanf("%d %s %d", &s[i].sno, s[i].sname, &s[i].marks);
    if (s[i].marks > 90) {
      s[i].grade = 'O';
    } else if (s[i].marks <= 90 && s[i].marks > 80) {
      s[i].grade = 'A';
    } else if (s[i].marks <= 80 && s[i].marks > 70) {
      s[i].grade = 'B';
    } else if (s[i].marks <= 70 && s[i].marks > 60) {
      s[i].grade = 'C';
    } else if (s[i].marks <= 60 && s[i].marks > 50) {
      s[i].grade = 'D';
    } else if (s[i].marks <= 50 && s[i].marks > 40) {
      s[i].grade = 'P';
    } else {
      s[i].grade = 'F';
    }
  }
  SelectionSort(s, n);
  printf("Students Details : \n");
  printf("sno\tsname\tmarks\tgrade\n");
  for (i = 0; i < n; i++) {
    printf("%d\t%s\t\t%d\t\t%c\n", s[i].sno, s[i].sname, s[i].marks,
           s[i].grade);
  }
}