#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#define BUFFERSIZE  100
#define MAXCOUNT    10

int main(void) {
  int i;
  char buffer[BUFFERSIZE];
  pid_t PID;

  fork();
  PID = getpid();

  /*
   * the purpose of the following loop is to understand that,
   * both processes start their execution right after the
   * system call fork(); since both processes have identical
   * but separate address spaces, those variables initialized
   * before the fork() call have the same values in both
   * address spaces; since every process has its own
   * address space, any modifications will be independent
   * of the others; in other words, if the parent changes
   * the value of its variable, the modification will only
   * affect the variable in the parent process's address space;
   * Other address spaces created by fork() calls will not be
   * affected even though they have identical variable names
   */
  for(i = 0 ; i <= MAXCOUNT ; i++) {
    sprintf(buffer, "Hello from PID: %4d; COUNT: %2d\n", PID, i);

    /*
     * because printf() is "buffered," meaning printf()
     * will group the output of a process together; while
     * buffering the output for the parent process, the child
     * may also use printf() to print out some information,
     * which will also be buffered; as a result, since the
     * output will not be send to screen immediately, you may
     * not get the right order of the expected result;
     * worse, the output from the two processes may be mixed
     * in strange ways; to overcome this problem, you may
     * consider to use the "unbuffered" write
     */
    write(1, buffer, strlen(buffer));
  }

  return 0;
}

