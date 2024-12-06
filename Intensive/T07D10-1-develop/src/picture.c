#include <stdio.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform((int *)picture_data, (int **)picture, N, M);

    make_picture(picture, N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", picture[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);

    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[N - 1][i] = frame_w[i];
    }
    for (int i = 0; i < N; i++) {
        picture[i][0] = 1;
        picture[i][M - 1] = 1;
    }

    for (int i = 0; i < 4; i++) {
        picture[5][4 + i] = tree_trunk[i];
    }

    for (int i = 0; i < 4; i++) {
        picture[1 + i][7] = tree_foliage[i];
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            picture[1 + i][1 + j] = sun_data[i][j];
        }
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}
