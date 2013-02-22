#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
  if(argc != 3) {
    printf("Usage: %s [input binary file] [output german file]\n", argv[0]);
    exit(0);
  }
  FILE* input;
  input = fopen(argv[1], "r");
  if(!input) {
    printf("Failed to open %s. Check if it exists\n", argv[1]);
    exit(0);
  }
  printf("Warning, this will overwrite %s, beginning in 3 seconds\n", argv[2]);
  for(int i = 3; i > 0; i--) {
    printf("%d...", i);
    fflush(stdout);
    sleep(1);
  }
  putchar('\n');
  FILE* output;
  output = fopen(argv[2], "w");
  char c;
  while((c = fgetc(input)) != EOF) {
    for(int i = 7; i >= 0; i--) {
      if(c & (1 << i))
        fprintf(output, "BEER");
      else
        fprintf(output, "SCHNITZEL");
      if(i != 0)
        fprintf(output, " ");;
    }
    fprintf(output, "\n");
  }
}
