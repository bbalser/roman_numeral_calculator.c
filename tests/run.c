#include <stdlib.h>
#include <check.h>
#include "ConverterTests.h"
#include "CalculatorTests.h"

int main() {

  Suite *converter = converter_suite();
  Suite *calculator = calculator_suite();
  SRunner *sr = srunner_create(converter);
  srunner_add_suite(sr, calculator);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
