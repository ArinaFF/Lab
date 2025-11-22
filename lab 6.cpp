#include <iostream>

//пункт 1----------------------------------------------
int cnt = 0;
int* find_zero(int** matrix, int R, int Co) { 
	
	int* zer = (int*)malloc(R * sizeof(int));
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < Co; ++c) {
			if (matrix[r][c] == 0) {
				zer[cnt] = r;
				++cnt;
				break;
			}

		}
	}
	if (cnt > 0) {
		zer = (int*)realloc(zer, cnt * sizeof(int));}
	else {
		zer = (int*)realloc(zer, sizeof(int));
		zer[0] = -1;}
	return zer;}


int main() {
	setlocale(LC_ALL, "Russian");
	int R = 2;
	int Co = 2;

	int** matrix = (int**)calloc(R, sizeof(int*));
	for (int r = 0; r < R; ++r) {
		matrix[r] = (int*)calloc(Co, sizeof(int));
		for (int c = 0; c < Co; ++c) {
			int a;
			std::cin >> a;
			while ((r == 0) && (a < 0)) {
				std::cout << "Ошибка" << std::endl;
				std::cin >> a;
			}
			matrix[r][c] = a;
		}
	}
	int A = matrix[0][0];
	int B = matrix[0][1];
	int C = matrix[1][0];
	int D = matrix[1][1];

	int n_r = R + A;
	int n_c = Co + B;
	matrix = (int**)realloc(matrix, n_r * sizeof(int*));
	for (int r = R; r < n_r; ++r) {
		matrix[r] = (int*)calloc(n_c, sizeof(int));
	}
	for (int r = 0; r < n_r; ++r) {
		matrix[r] = (int*)realloc(matrix[r], n_c * sizeof(int));
	}
	for (int r = n_r - 1; r >= 0; --r) {
		for (int c = n_c - 1; c >= 0; --c) {
			if ((r >= A) && (c >= B)) {
				matrix[r][c] = matrix[r - A][c - B];
			}
			else {
				matrix[r][c] = r * C + c * D;
			}
		}
	}
	int* zer = find_zero(matrix, n_r, n_c);
	int k = 0;
	for (int i = 0; i < n_r; ++i) {
		for (int j = 0; j < cnt; ++j) {
			if (i == zer[j]) {
				free(matrix[i - k]);
				for (int m = i - k; m < n_r - 1; ++m) {
					matrix[m] = matrix[m + 1];
				}
				++k;
				matrix = (int**)realloc(matrix, (n_r - k) * sizeof(int*));
				break;
			}
		}
	}
	n_r -= k;
	std::cout << "матрица:" << std::endl;

	for (int r = 0; r < n_r; ++r) {
		std::cout << std::endl;
		for (int c = 0; c < n_c; ++c) {
			std::cout << matrix[r][c] <<" ";
		}
		std::cout << std::endl;
	}
	free(zer);
	for (int r = 0; r < n_r; ++r) {
		free(matrix[r]);
	}
	free(matrix);




	//пункт 2---------------------------
	int* a  = new int;
	int* b = new int;
	int* w = new int;
	std::cin >> *a;
	std::cin >> *b;
	*a *= 2;
	std::cout << *a;
	*w = *a;
	*a = *w;
	*w = *b;
	delete a;
	delete w;
	delete b;

}






























