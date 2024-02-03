#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *intToRoman(int num) {
  char *symbols[13] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                       "XL", "X",  "IX", "V",  "IV", "I"};
  char *result = ( char * )malloc(sizeof(char) * 20);
  result[0] = '\0';
  int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  int remainder_value = num;
  int counter = 0;

  while(remainder_value != 0 && counter < 13) {
    if(remainder_value <  values[counter]) {
      counter++;
      continue;
    }
    int division_result =  floor(remainder_value / values[counter]);
    remainder_value = remainder_value - (division_result * values[counter]);
    for (int i = 0; i < division_result; i++) {
      result = strcat(result, symbols[counter]);
    }
    counter++;
  } 
  
  return result;
}


int main() {
  int number = 1001;
  char* res = intToRoman(number);
  printf("%s", res);
}



