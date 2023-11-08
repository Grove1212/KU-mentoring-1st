#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//좌표로 삼각형 넓이 구하는 함수
float getArea(int x1, int y1, int x2, int y2, int x3, int y3);

int main(void)
{
	int row, col;	//행렬의 행과 열
	int count = 0;	//커질 수 있는 아름다운 삼각형의 개수
	int numOfCell;	//행렬의 원소 개수
	scanf("%d %d", &row, &col);
	getchar();

	char** matrix = (char**)malloc(sizeof(char*) * row);	// 행렬의 행 동적할당

	//행렬의 열 동적할당
	for (int i = 0; i < row; i++)
	{
		matrix[i] = (char*)malloc(sizeof(char) * col);
	}

	//행렬의 모든 원소 입력
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = getchar();
		}
		getchar();
	}

	numOfCell = row * col;	//행렬의 원소 개수 구하기

	//삼각형 2개 구해서 비교하기
	for (int i = 0; i < numOfCell; i++)
	{
		for (int j = i + 1; j < numOfCell; j++)
		{
			for (int k = j + 1; k < numOfCell; k++)
			{
				// 삼각형의 세 꼭짓점의 행과 열 구하기
				int row1 = i / col;
				int col1 = i % col;
				int row2 = j / col;
				int col2 = j % col;
				int row3 = k / col;
				int col3 = k % col;

				// 아름다운 삼각형이 아니면 넘어가기
				if (matrix[row1][col1] == matrix[row2][col2] || matrix[row1][col1] == matrix[row3][col3] || matrix[row2][col2] == matrix[row3][col3])
					continue;

				// 삼각형의 넓이 구하기
				float area1 = getArea(col1, row1, col2, row2, col3, row3);


				// 비교할 삼각형 생성해서 넓이 비교하기
				for (int l = 0; l < numOfCell; l++)
				{
					// 비교할 삼각형의 꼭짓점이 원래 삼각형의 꼭짓점과 겹치면 안됌
					if (l == i || l == j || l == k)
						continue;

					// 비교할 삼각형의 한 꼭짓점의 행과 열 구하기
					int row4 = l / col;
					int col4 = l % col;

					// 비교할 삼각형의 넓이
					float area2;



					// 비교할 삼각형이 아름다운 삼각형인지 구하기
					if (matrix[row1][col1] != matrix[row4][col4] && matrix[row2][col2] != matrix[row4][col4])
					{
						// 비교할 삼각형의 넓이 구하기
						area2 = getArea(col1, row1, col2, row2, col4, row4);

						// 넓이 비교하기
						if (area2 > area1)
						{
							count++;
							break;
						}
					}



					// 비교할 삼각형이 아름다운 삼각형인지 구하기
					if (matrix[row1][col1] != matrix[row4][col4] && matrix[row3][col3] != matrix[row4][col4])
					{
						// 비교할 삼각형의 넓이 구하기
						area2 = getArea(col1, row1, col3, row3, col4, row4);

						// 넓이 비교하기
						if (area2 > area1)
						{
							count++;
							break;
						}
					}



					// 비교할 삼각형이 아름다운 삼각형인지 구하기
					if (matrix[row2][col2] != matrix[row4][col4] && matrix[row3][col3] != matrix[row4][col4])
					{
						// 비교할 삼각형의 넓이 구하기
						area2 = getArea(col2, row2, col3, row3, col4, row4);

						// 넓이 비교하기
						if (area2 > area1)
						{
							count++;
							break;
						}
					}
				}
			}
		}
	}

	printf("%d", count);

	for (int i = 0; i < row; i++)
	{
		free(matrix[i]);
	}

	free(matrix);
}

float getArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	float area;
	area = 0.5f * abs((x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x2 * y1 + x3 * y2));
	return area;
}