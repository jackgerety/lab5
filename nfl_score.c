#include <stdio.h>

int combinations(int score) {
  int possibilities = 0;
  if (score == 0) {
    return 0;
  }
  if (score == 1) {
    return -1;
  }
  if (score >=2) {
    possibilities += (1 + combinations(score-2));
  }
  if (score >=3) {
    possibilities += (1 + combinations(score-3));
  }
  if (score >=6) {
    possibilities += (1 + combinations(score-6));
  }
  if (score >=7) {
    possibilities += (1 + combinations(score-7));
  }
  if (score >=8) {
    possibilities += (1 + combinations(score-8));
  }
  return possibilities;
}

int main() {
  static int TD = 0;
  static int TD_1 = 1;
  static int TD_2 = 2;
  static int Safety = 3;
  static int FG = 4;
  int scoreArr[5] = {0,0,0,0,0};

  printf("Enter 0 or 1 to STOP\n");
  //get int from user
  int score;
  printf("Enter the NFL score: ");
  scanf("%d", &score);

  printf("possible combinations of scoring plays:\n");
  printf("%d", combinations(score));

  
  return 0;
}
