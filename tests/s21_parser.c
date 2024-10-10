#include "s21_test.h"

START_TEST(s21_test1) {
    char fileName[] = "test.obj";
    Model model={0};

    int count_vertex=8;
    int count_facites=12;
    s21_parser(fileName, &model);
    ck_assert_int_eq(model.total_vertices, count_vertex);
    ck_assert_int_eq(model.total_polygons, count_facites);

    s21_cleaner(&model);

}
END_TEST

// Test that parsed vertices and facets are as expected
START_TEST(s21_test2) {
    char fileName[] = "/Users/louellat/Desktop/Projects/C8_3DViewer_v1.0-2/tests/test.obj";
    Model model = {0};

    // Expected vertex data based on the .obj file
    double expected_vertices[] = {
        0.0, 0.0, 0.0,
        0.0, 0.0, 1.0,
        0.0, 1.0, 0.0,
        0.0, 1.0, 1.0,
        1.0, 0.0, 0.0,
        1.0, 0.0, 1.0,
        1.0, 1.0, 0.0,
        1.0, 1.0, 1.0
    };

    // Expected facet data (vertex indices)
    int expected_facets[12][3] = {
        {1, 7, 5}, {1, 3, 7}, {1, 4, 3}, {1, 2, 4},
        {3, 8, 7}, {3, 4, 8}, {5, 7, 8}, {5, 8, 6},
        {1, 5, 6}, {1, 6, 2}, {2, 6, 8}, {2, 8, 4}
    };

    // Parse the file
    s21_parser(fileName, &model);

    // Check vertices
    for (unsigned int i = 0; i < model.total_vertices * 3; i++) {
        ck_assert_double_eq_tol(model.vertices[i + 3], expected_vertices[i], 1e-6);
    }

    // Check facets
    for (unsigned int i = 0; i < model.total_polygons; i++) {
        for (int j = 0; j < model.polygons[i].count_of_vertices; j++) {
            ck_assert_int_eq(model.polygons[i].numbers_of_vertices[j], expected_facets[i][j]);
        }
    }

    // Clean up model
    s21_cleaner(&model);
}
END_TEST

START_TEST(s21_test3) {
    char fileName[] = "/Users/louellat/Desktop/Projects/C8_3DViewer_v1.0-2/src/tests/minimal.obj";
    Model model = {0};

    double expected_vertices[] = {
        0.0, 0.0, 0.0,
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0
    };

    int expected_facets[1][3] = {{1, 2, 3}};
    s21_parser(fileName, &model);

    for (unsigned int i = 0; i < model.total_vertices * 3; i++) {
        ck_assert_double_eq_tol(model.vertices[i + 3], expected_vertices[i], 1e-6);
    }

    for (unsigned int i = 0; i < model.total_polygons; i++) {
        for (int j = 0; j < model.polygons[i].count_of_vertices; j++) {
            ck_assert_int_eq(model.polygons[i].numbers_of_vertices[j], expected_facets[i][j]);
        }
    }
    s21_cleaner(&model);
}
END_TEST

START_TEST(s21_test_empty_lines) {
    char fileName[] = "/Users/louellat/Desktop/Projects/C8_3DViewer_v1.0-2/tests/empty_lines.obj";

    Model model = {0};

    double expected_vertices[] = {
        0.0, 0.0, 0.0,
        1.0, 1.0, 1.0
    };

    int expected_facets[1][2] = {{1, 2}};
    s21_parser(fileName, &model);
    for (unsigned int i = 0; i < model.total_vertices * 3; i++) {
        ck_assert_double_eq_tol(model.vertices[i + 3], expected_vertices[i], 1e-6);
    }
    for (unsigned int i = 0; i < model.total_polygons; i++) {
        for  (int j = 0; j < model.polygons[i].count_of_vertices; j++) {
            ck_assert_int_eq(model.polygons[i].numbers_of_vertices[j], expected_facets[i][j]);
        }
    }
    s21_cleaner(&model);
}
END_TEST


Suite *parser_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("parser");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_test1);
  tcase_add_test(tc_core, s21_test2);
  tcase_add_test(tc_core, s21_test3);
  tcase_add_test(tc_core, s21_test_empty_lines);

  suite_add_tcase(s, tc_core);

  return s;
}
