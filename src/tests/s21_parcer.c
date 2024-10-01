#include "s21_test.h"

START_TEST(s21_test1) {
    char fileName[] = "/Users/hoarfros/C8_3DViewer_v1.0-2/src/tests/test.obj";
    Model model={0};

    int count_vertex=8;
    int count_facites=12;
    s21_parser2(fileName, &model);
    ck_assert_int_eq(model.vertex_count, count_vertex);
    ck_assert_int_eq(model.facets_count, count_facites);

}
END_TEST

START_TEST(s21_test1) {
    char fileName[] = "/Users/hoarfros/C8_3DViewer_v1.0-2/src/tests/test.obj";
    Model model={0};

    int count_vertex=8;
    int count_facites=12;
    s21_parser2(fileName, &model);
    ck_assert_int_eq(model.vertex_count, count_vertex);
    ck_assert_int_eq(model.facets_count, count_facites);

}
END_TEST

Suite *parser_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("parser");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_test1);

  suite_add_tcase(s, tc_core);

  return s;
}
