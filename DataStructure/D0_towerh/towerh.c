#include <stdio.h>

int step = 0;

void tower(
    nrDisk  /* no. of disks */,
    from    /* from this peg */,
    to      /* to this peg */,
    via     /* via this peg */)

  /* doing type decleration of parameters here because it seems fun */
  int nrDisk;
  char from, to, via;
{
  if(nrDisk == 1) {
    printf("STEP %d: Move from %c to %c via %c\n", step, from, to, via);
    step++;
  }
  else {
    tower(nrDisk-1, from, via, to);
    tower(1, from, to, via);
    tower(nrDisk-1, via, to, from);
  }

  return;
}

int main() {
  printf("//* Tower of Hanoi Problem *//\n");

  int n;
  printf("Enter the number of disks: ");
  scanf("%d", &n);

  /* fromulate tower of Hanoi and generate list of possible ways */
  tower(n, 'A', 'B', 'C');

  return 0;
}

