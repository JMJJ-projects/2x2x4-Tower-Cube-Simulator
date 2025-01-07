#include <stdio.h>

// Define a point in 3D space
typedef struct {
  int x, y, z;
  char front, up, down, left, right, back;
} Point;

// Define a 4x4x4 space (object)
Point space[4][4][4];

// Initialize the space with default values (0 to 4-1)
void init_space() {
  for (int x = 0; x < 4; x++) {
    for (int y = 0; y < 4; y++) {
      for (int z = 0; z < 4; z++) {
        space[x][y][z].x = x;
        space[x][y][z].y = y;
        space[x][y][z].z = z;
        space[x][y][z].front = ' ';
        space[x][y][z].up = ' ';
        space[x][y][z].down = ' ';
        space[x][y][z].left = ' ';
        space[x][y][z].right = ' ';
        space[x][y][z].back = ' ';
      }
    }
  }
}
void init_tower() {
  for (int x = 1; x < 3; x++) {
    for (int y = 0; y < 4; y++) {
      for (int z = 1; z < 3; z++) {
        space[x][y][z].front = 'b';
        space[x][y][z].up = 'b';
        space[x][y][z].down = 'b';
        space[x][y][z].left = 'b';
        space[x][y][z].right = 'b';
        space[x][y][z].back = 'b';
      }
    }
  }
  for (int x = 1; x < 3; x++) {
    for (int z = 1; z < 3; z++) {
      space[x][3][z].up = 'W';
      space[x][0][z].down = 'Y';
    }
  }
  for (int y = 0; y < 4; y++) {
    for (int x = 1; x < 3; x++) {
      space[x][y][1].front = 'R';
      space[x][y][2].back = 'G';
    }
    for (int z = 1; z < 3; z++) {
      space[1][y][z].left = 'O';
      space[2][y][z].right = 'B';
    }
  }
}

void print_space() {
  for (int z = 3; z >= 0; z--) {
    printf("z = %d:\n", z);
    for (int y = 3; y >= 0; y--) {
      for (int x = 0; x < 4; x++) {
        printf("(%d, %d, %d) ", space[x][y][z].x, space[x][y][z].y,
               space[x][y][z].z);
      }
      printf("\n");
    }
    printf("\n");
  }
}
void print_patterns() {
  for (int z = 3; z >= 0; z--) {
    printf("z = %d:\n", z);
    for (int y = 3; y >= 0; y--) {
      for (int i = 18 * z - 1; i > 0; i--)
        printf(" ");
      printf(" ");
      for (int x = 0; x < 4; x++) {
        printf(" ");
        printf("%c   ", space[x][y][z].up);
      }
      printf("\n");
      for (int i = 18 * z; i > 1; i--)
        printf(" ");
      printf("|");
      for (int x = 0; x < 4; x++) {
        printf("%c%c%c%c ", space[x][y][z].left, space[x][y][z].front,
               space[x][y][z].right, space[x][y][z].back);
      }
      printf("|");
      printf("\n");
      for (int i = 18 * z-1; i > 0; i--)
        printf(" ");
      printf(" ");
      for (int x = 0; x < 4; x++) {
        printf(" ");
        printf("%c   ", space[x][y][z].down);
      }
      printf("\n");
    }
    printf("\n");
  }
  printf("\n");
}
int can_rotate(char axis, int plane) {
	if (plane == 0) {
		for (int a = 1; a < 3; a++) {
			for (int b = 1; b < 3; b++) {
				if (axis == 'x') {
					if (space[0][a][b].left != 'W' && space[0][a][b].left != 'Y')
						return 0;
				}
				if (axis == 'y') {
					if (space[a][0][b].down != 'W' && space[a][0][b].down != 'Y')
						return 0;
				}
				if (axis == 'z') {
					if (space[a][b][0].front != 'W' && space[a][b][0].front != 'Y')
						return 0;
				}
			}
		}
	}
	else if (plane == 3) {
		for (int a = 1; a < 3; a++) {
			for (int b = 1; b < 3; b++) {
				if (axis == 'x') {
					if (space[3][a][b].right != 'W' && space[3][a][b].right != 'Y')
						return 0;
				}
				if (axis == 'y') {
					if (space[a][3][b].up != 'W' && space[a][3][b].up != 'Y')
						return 0;
				}
				if (axis == 'z'){
					if (space[a][b][3].back != 'W' && space[a][b][3].back != 'Y')
					return 0;
				}
			}
		}
	}
	return 1;
}

void rotate_plane(char axis, int plane) {
  Point temp[4][4] = {0};
  int test;
  if ((test = can_rotate(axis, plane)) == 0) {
    printf("------\nMove is locked!\n------\n");
  } 
  else {
    if (axis == 'x') {
      for (int z = 0; z < 4; z++) {
        for (int y = 0; y < 4; y++) {
          temp[z][3 - y] = space[plane][y][z];

          temp[z][3 - y].up = space[plane][y][z].back;
          temp[z][3 - y].front = space[plane][y][z].up;
          temp[z][3 - y].down = space[plane][y][z].front;
          temp[z][3 - y].back = space[plane][y][z].down;
          space[plane][y][z].front = ' ';
          space[plane][y][z].up = ' ';
          space[plane][y][z].down = ' ';
          space[plane][y][z].left = ' ';
          space[plane][y][z].right = ' ';
          space[plane][y][z].back = ' ';
        }
      }
      for (int z = 0; z < 4; z++) {
        for (int y = 0; y < 4; y++) {
          space[plane][y][z] = temp[y][z];
        }
      }
    } else if (axis == 'y') {
      for (int z = 0; z < 4; z++) {
        for (int x = 0; x < 4; x++) {
          temp[z][3 - x] = space[x][plane][z];

          temp[z][3 - x].left = space[x][plane][z].front;
          temp[z][3 - x].front = space[x][plane][z].right;
          temp[z][3 - x].right = space[x][plane][z].back;
          temp[z][3 - x].back = space[x][plane][z].left;
          space[x][plane][z].front = ' ';
          space[x][plane][z].up = ' ';
          space[x][plane][z].down = ' ';
          space[x][plane][z].left = ' ';
          space[x][plane][z].right = ' ';
          space[x][plane][z].back = ' ';
        }
      }

      for (int z = 0; z < 4; z++) {
        for (int x = 0; x < 4; x++) {
          space[x][plane][z] = temp[x][z];
        }
      }
    } else if (axis == 'z') {
      for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
          temp[x][3 - y] = space[x][y][plane];

          temp[x][3 - y].up = space[x][y][plane].right;
          temp[x][3 - y].left = space[x][y][plane].up;
          temp[x][3 - y].down = space[x][y][plane].left;
          temp[x][3 - y].right = space[x][y][plane].down;
          space[x][y][plane].front = ' ';
          space[x][y][plane].up = ' ';
          space[x][y][plane].down = ' ';
          space[x][y][plane].left = ' ';
          space[x][y][plane].right = ' ';
          space[x][y][plane].back = ' ';
        }
      }
      for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
          space[x][y][plane] = temp[y][x];
        }
      }
    } else {
      printf("Invalid axis!\n");
    }
  }
}

int main() {
  printf("------\nThe Tower!\n\nThis program simulates the complex 2x2x4 Tower "
         "Cube. Made by John-Michael JENY JEYARAJ.\n");
  char axis, mode;
  int plane;
  init_space();
  init_tower();
  while (1) {
    printf(
        "------\nS - Spatial Mode\nP - Pattern Mode\nQ - Quit\n------\nMode:");
    scanf(" %c", &mode);

    if (mode == 'S') {
      printf("------\nSpatial Mode shows the points of a graph 4x4x4. starting "
             "from (0,0,0) to (4,4,4), where each point represents a block "
             "occupying that space. This allows the user to see easily how the "
             "rotations are done.\n------\nInitial Space:\n");
      print_space();
      while (1) {
        printf("Rotate which axis (x, y, z, m(modes), Q(quit)): ");
        scanf(" %c", &axis);
        if (axis == 'Q') {
          return 0;
        } else if (axis == 'm')
          break;
        printf("Rotate which plane (0,1,2,3): ");
        scanf(" %d", &plane);
        rotate_plane(axis, plane);
        print_space();
      }
    } else if (mode == 'P') {
      printf("------\nPattern Mode shows how the stickers of the tower will "
             "rotate. Each point is represented as its own unique block, that "
             "has stickers on each of its sides. Each individual block is then "
             "represented as patterns, to easily allow another program to turn "
             "the pattern into a 3D object, and would mimic the tower "
             "exactly.\n------\nInitial Space:\n");
      print_patterns();
      while (1) {
        printf("Rotate which axis (x, y, z, m(modes), q(quit)): ");
        scanf(" %c", &axis);
        if (axis == 'q') {
          return 0;
        } else if (axis == 'm') {
          break;
        }
        printf("Rotate which plane (0,1,2,3): ");
        scanf(" %d", &plane);

        rotate_plane(axis, plane);
        print_patterns();
      }
    } else {
      return 0;
    }
  }
}
