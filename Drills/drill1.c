#include <stdio.h>

struct house
{
  int zipcode;
  int year_built;
  double value;
};

void updatevalue(struct house *h)
{
  if (h->zipcode == 21209)
  {
    h->value = h->value + 20000 + (120.32 * h->year_built);
  } else if (h->zipcode == 21286) {
    h->value = h->value + 15000 + (115.10 * h->year_built);
  }
}

int main()
{
  struct house h1 = {21209, 1910, 250000};
  struct house h2 = {21286, 2020, 115000};

  updatevalue(&h1);
  updatevalue(&h2);

  printf("House 1 value: %f\n", h1.value);
  printf("House 2 Value: %f\n", h2.value);

  return 0;
}

/*
 *
 If the house is in 21209:
 Starting Value + 20000 + (120.32 * year built)
 If the house is built in 21286
 Starting value + 15000 + (115.10 * year built)

*/
