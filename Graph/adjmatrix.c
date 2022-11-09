// Adjacency Matrix 5x5 in C
#include <stdio.h>
#define V 5

// Fungsi inisialisasi matriks ke 0
void init(int arr[][V]) {
  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      arr[i][j] = 0;
}

// Fungsi tambah edge
void addEdge(int arr[][V], int i, int j) {
  arr[i][j] = 1;
  arr[j][i] = 1;
}

// Fungsi print matrix
void printAdjMatrix(int arr[][V]) {
  int i, j;

  for (i = 0; i < V; i++) {
    printf("%d: ", i);
    for (j = 0; j < V; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int adjMatrix[V][V];

  init(adjMatrix);
  addEdge(adjMatrix, 0, 1);
  addEdge(adjMatrix, 0, 2);
  addEdge(adjMatrix, 1, 2);
  addEdge(adjMatrix, 2, 0);
  addEdge(adjMatrix, 1, 4);
  addEdge(adjMatrix, 5, 1);
  addEdge(adjMatrix, 0, 3);
  addEdge(adjMatrix, 3, 4);

  printAdjMatrix(adjMatrix);

  return 0;
}