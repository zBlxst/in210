
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"
#include <string.h>
#include "ratp.h"

void recupAge(int *res) {
    *res = (int)mock();   
}



static int setup(void **state) {
    (void) state;
    printf("setUp");
    return 0;
}
static int teardown(void **state) {
    (void) state;
    printf("tearDown");
    return 0;
}
static void null_test_success(void **state) {
    (void) state;
}

static void test_tourist_and_adult(void **state) {
    (void) state;
    will_return(recupAge, 12);
    assert_float_equal(computePrice(13, 1), 2.4, 0.01);
}

static void test_not_tourist_and_adult(void **state) {
    (void) state;
    will_return(recupAge, 12);
    assert_float_equal(computePrice(13, 0), 1.2, 0.01);
}

static void test_tourist_and_not_adult(void **state) {
    (void) state;
    will_return(recupAge, 12);
    assert_float_equal(computePrice(12, 1), 1.2, 0.01);
}

static void test_not_tourist_and_not_adult(void **state) {
    (void) state;
    will_return(recupAge, 12);
    assert_float_equal(computePrice(12, 0), 0.6, 0.01);
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(test_tourist_and_adult),
        cmocka_unit_test(test_not_tourist_and_adult),
        cmocka_unit_test(test_tourist_and_not_adult),
        cmocka_unit_test(test_not_tourist_and_not_adult)
    };
    cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests_name("toto",tests, setup, teardown);
}
