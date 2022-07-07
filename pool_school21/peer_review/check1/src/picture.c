#include <stdio.h>
#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);

int main() {
  int picture_data[N][M];
  int *picture[N];
  transform(*picture_data, picture, N, M);
  reset_picture(picture, N, M);
  make_picture(picture, N, M);
  return 0;
}

void make_picture(int **picture, int n, int m) {
  int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int tree_trunk[] = {7, 7, 7, 7};
  int tree_foliage[] = {3, 3, 3, 3};
  int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                        {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

  reset_picture(picture, n, m);

  int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
  int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);
  for (int i = 0; i < length_frame_w; i++) {
    picture[0][i] = frame_w[i];
    picture[(length_frame_h - 1) / 2][i] = frame_h[i];
    picture[length_frame_h - 1][i] = frame_w[i];
  }
  for (int i = 0; i < length_frame_h; i++) {
    picture[i][0] = frame_h[i];
    picture[i][(length_frame_w - 1) / 2] = frame_h[i];
    picture[i][length_frame_w - 1] = frame_h[i];
  }
  for (int i = 2; i < 6; i++) {
    for (int j = 3; j < 5; j++) {
      picture[i][j] = tree_foliage[0];
      picture[3][2] = tree_foliage[1];
      picture[4][2] = tree_foliage[1];
      picture[3][5] = tree_foliage[1];
      picture[4][5] = tree_foliage[1];
    }
  }
  picture[13][11] = 0;
  for (int i = 8; i < 11; i++) {
    for (int j = 3; j < 5; j++) {
      picture[i][j] = tree_trunk[0];
      picture[6][3] = tree_trunk[0];
      picture[6][4] = tree_trunk[1];
    }
  }
  picture[10][2] = tree_trunk[0];
  picture[10][5] = tree_trunk[1];
  int h = 0;
  for (int i = 1; i < 7; i++) {
    int w = 0;
    for (int j = 7; j < 12; j++) {
      picture[i][j] = sun_data[h][w];
      w++;
    }
    h++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", picture[i][j]);
    }
    printf("\n");
  }
}
void reset_picture(int **picture, int n, int m) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      picture[i][j] = 0;
    }
  }
}

void transform(int *buf, int **matr, int n, int m) {
  for (int i = 0; i < n; i++) {
    matr[i] = buf + i * m;
  }
}
