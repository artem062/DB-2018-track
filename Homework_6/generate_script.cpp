#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

void fill_users(int n) {
    printf("INSERT INTO users (login, email, registration_dttm) VALUES \n");

    for (int i = 1; i <= n; ++i) {
        printf("('login_%d', 'email_%d@mail.ru', '2018-%02d-%02d %d:%02d:%02d')", i, i, rand() % 12 + 1, rand() % 28 + 1,
               rand() % 24, rand() % 60, rand() % 60);
        if (i != n) {
            printf(", \n");
        } else {
            printf(";\n");
        }
    }
}

void fill_serial_studios(int n) {
    printf("INSERT INTO serial_studios (name, foundation_date) VALUES \n");

    for (int i = 1; i <= n; ++i) {
        printf("('studio_%d', '%d-%02d-%02d')", i, rand() % 10 + 2007, rand() % 12 + 1, rand() % 28 + 1);
        if (i != n) {
            printf(", \n");
        } else {
            printf(";\n");
        }
    }
}

void fill_serials(int n) {
    printf("INSERT INTO serials (name, studio_id, format) VALUES \n");

    for (int i = 1; i <= n; ++i) {
        printf("('serial_%d', %d, '%d+')", i, rand() % 100 + 1, rand() % 19);
        if (i != n) {
            printf(", \n");
        } else {
            printf(";\n");
        }
    }
}

void fill_series(int n) {
    printf("INSERT INTO series (serial_id, name, duration, release_date) VALUES \n");

    for (int i = 1; i <= n; ++i) {
        printf("(%d, 'series_%d', '%d:%02d:%02d', '%d-%02d-%02d %d:%02d:%02d')",
                rand() % 100 + 1,
                i,
                rand() % 2, rand() % 60, rand() % 60,
                rand() % 3 + 2016, rand() % 12 + 1, rand() % 28 + 1, rand() % 24, rand() % 60, rand() % 60);
        if (i != n) {
            printf(", \n");
        } else {
            printf(";\n");
        }
    }
}

void fill_payments(int n) {
    printf("INSERT INTO payments (user_id, payment_dttm, payment_sum, paid_period_start, paid_period_end) VALUES \n");

    for (int i = 1; i <= n; ++i) {
        printf("(%d, '%d-%02d-%02d %d:%02d:%02d', %lg, '2018-%02d-%02d %d:%02d:%02d', '2019-%02d-%02d %d:%02d:%02d')",
               rand() % 100 + 1,
               rand() % 3 + 2016, rand() % 12 + 1, rand() % 28 + 1, rand() % 24, rand() % 60, rand() % 60,
               (double)rand() * 1000 / RAND_MAX,
               rand() % 12 + 1, rand() % 28 + 1, rand() % 24, rand() % 60, rand() % 60,
               rand() % 12 + 1, rand() % 28 + 1, rand() % 24, rand() % 60, rand() % 60);
        if (i != n) {
            printf(", \n");
        } else {
            printf(";\n");
        }
    }
}

void fill_views(int n) {
    printf("INSERT INTO views (user_id, series_id, rating, start_time, end_time) VALUES \n");
    int m, d, h;
    for (int i = 1; i <= n; ++i) {
        printf("(%d, %d, %d, '2018-%02d-%02d %d:%02d:%02d', '2018-%02d-%02d %d:%02d:%02d')",
               rand() % 100 + 1,
               rand() % 100 + 1,
               rand() % 10 + 1,
               (m = rand() % 12 + 1), (d = rand() % 28 + 1), (h = rand() % 24), rand() % 30, rand() % 60,
               m, d, h, rand() % 30 + 30, rand() % 60);
        if (i != n) {
            printf(", \n");
        } else {
            printf(";\n");
        }
    }
}

void fill_actors(int n) {
    printf("INSERT INTO actors (first_name, last_name, birthday) VALUES \n");
    for (int i = 1; i <= n; ++i) {
        printf("('actor_%d', 'last_name_%d', '%d-%02d-%02d')",
               i,
               i,
               rand() % 50 + 1960, rand() % 12 + 1, rand() % 28 + 1);
        if (i != n) {
            printf(", \n");
        } else {
            printf(";\n");
        }
    }
}

void fill_serials_has_actors(int n, int actors_cnt = 1) {
    if (actors_cnt < 0) {
        printf("Serial can't have negative actors number\n");
        return;
    } else if (actors_cnt == 0) {
        return;
    }

    printf("INSERT INTO serials_has_actors (serial_id, actor_id) VALUES \n");
    set <int> Acts;

    for (int i = 1; i <= n; ++i) {
        int cnt = rand() % (actors_cnt + 1);
        Acts.clear();
        while (Acts.size() < cnt) {
            int q = rand() % 100 + 1;
            if (Acts.count(q) == 0) {
                Acts.insert(q);
                printf("(%d, %d)", i, q);
                if (Acts.size() < cnt) {
                    printf(", ");
                }
            }
        }
        if (i != n && Acts.size() > 0) {
            printf(", \n");
        } else if (i == n) {
            printf(";\n");
        }
    }
}

int main() {
    int n = 100;
    fill_users(n);
    fill_serial_studios(n);
    fill_serials(n);
    fill_series(n);
    fill_payments(n);
    fill_views(n);
    fill_actors(n);
    fill_serials_has_actors(n, 5);
    return 0;
}
