#include <stdio.h>

void print_month(int index) {
  if (index == 0) {
    printf(" January ");
  }
  if (index == 1) {
    printf(" February ");
  }
  if (index == 2) {
    printf(" March ");
  }
  if (index == 3) {
    printf(" April ");
  }
  if (index == 4) {
    printf(" May ");
  }
  if (index == 5) {
    printf(" June ");
  }
  if (index == 6) {
    printf(" July ");
  }
  if (index == 7) {
    printf(" August ");
  }
  if (index == 8) {
    printf(" September ");
  }
  if (index == 9) {
    printf(" October ");
  }
  if (index == 10) {
    printf(" November ");
  }
  if (index == 11) {
    printf(" December ");
  }

}

double get_max(const double Arr[], int size) {
  int max;
  for (int i = 0; i<size; i++) {
    if (i == 0) {
      max = Arr[i];
    }
    else {
      if (Arr[i] > max) {
        max = Arr[i];
      }
    }
  }
  return max;
}

int get_max_index(const double Arr[], int size) {
  int max;
  for (int i = 0; i<size; i++) {
    if (i == 0) {
      max = i;
    }
    else {
      if (Arr[i] > max) {
        max = i;
      }
    }
  }
  return max;
}

void insertion_sort(double arr[], int size) {
  int key;
  int j;
  for (int i = 1; i<size; i++) {
    key = arr[i];
    j = i-1;
    while (j >=0 && arr[j] < key) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

int main(){
  FILE *fp;
  double amount;
  double sales[12];
  fp = fopen("sales.txt", "r");
  if (fp == NULL) {
    printf("file io error");
    return 1;
  }
  for (int i = 0; i<12; i++) {
        fscanf(fp, "%lf", &sales[i]);
  }
  double min;
  double max;
  double average;
  for (int j = 0; j<12; j++) {
        average+=sales[j];
    if (j == 0) {
      max = sales[j];
      min = sales[j];
    }
    else {
      if (sales[j] > max) {
        max = sales[j];
      }
      if (sales[j] < min) {
        min = sales[j];
      }
    }
  }
  average = average/12;
  printf("Monthly sales report for 2024:\n");
  printf("Month Sales\n");
  printf("January $%.2lf\n", sales[0]);
  printf("February $%.2lf\n", sales[1]);
  printf("March $%.2lf\n", sales[2]);
  printf("April $%.2lf\n", sales[3]);
  printf("May $%.2lf\n", sales[4]);
  printf("June $%.2lf\n", sales[5]);
  printf("July $%.2lf\n", sales[6]);
  printf("August $%.2lf\n", sales[7]);
  printf("September $%.2lf\n", sales[8]);
  printf("October $%.2lf\n", sales[9]);
  printf("November $%.2lf\n", sales[10]);
  printf("December $%.2lf\n", sales[11]);
  printf("Sales summary:\n");
  printf("Minimum sales: $%.2lf", min);
  printf("\n");
  printf("Maximum sales: $%.2lf\n", max);
  printf("\n");
  printf("Average sales: $%.2lf\n\n", average);

  double jan2jun = (sales[0]+sales[1]+sales[2]+sales[3]+sales[4]+sales[5])/6;
  double feb2jul = (sales[1]+sales[2]+sales[3]+sales[4]+sales[5]+sales[6])/6;
  double mar2aug = (sales[2]+sales[3]+sales[4]+sales[5]+sales[6]+sales[7])/6;
  double apr2sep = (sales[3]+sales[4]+sales[5]+sales[6]+sales[7]+sales[8])/6;
  double may2oct = (sales[4]+sales[5]+sales[6]+sales[7]+sales[8]+sales[9])/6;
  double jun2nov = (sales[5]+sales[6]+sales[7]+sales[8]+sales[9]+sales[10])/6;
  double jul2dec = (sales[6]+sales[7]+sales[8]+sales[9]+sales[10]+sales[11])/6;
  printf("Six-Month Moving Average Report\n");
  printf("January - June: $%.2lf\n", jan2jun);
  printf("February - July: $%.2lf\n", feb2jul);
  printf("March - August: $%.2lf\n", mar2aug);
  printf("April - September: $%.2lf\n", apr2sep);
  printf("May - October: $%.2lf\n", may2oct);
  printf("June - November: $%.2lf\n", jun2nov);
  printf("July - December: $%.2lf\n", jul2dec);
  printf("Highest to Lowest:\n");
  insertion_sort(sales, 12);
  for (int i = 0; i<12; i++) {
    printf("$%.2lf\n", sales[i]);
  }

  
  
  

  fclose(fp);
  return 0;
}