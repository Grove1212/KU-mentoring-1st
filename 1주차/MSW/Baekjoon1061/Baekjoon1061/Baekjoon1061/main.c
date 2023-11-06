#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//��ǥ�� �ﰢ�� ���� ���ϴ� �Լ�
float getArea(int x1, int y1, int x2, int y2, int x3, int y3);

int main(void)
{
	int row, col;	//����� ��� ��
	int count = 0;	//Ŀ�� �� �ִ� �Ƹ��ٿ� �ﰢ���� ����
	int numOfCell;	//����� ���� ����
	scanf("%d %d", &row, &col);
	getchar();

	char** matrix = (char**)malloc(sizeof(char*) * row);	// ����� �� �����Ҵ�

	//����� �� �����Ҵ�
	for (int i = 0; i < row; i++)
	{
		matrix[i] = (char*)malloc(sizeof(char) * col);
	}

	//����� ��� ���� �Է�
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = getchar();
		}
		getchar();
	}

	numOfCell = row * col;	//����� ���� ���� ���ϱ�

	//�ﰢ�� 2�� ���ؼ� ���ϱ�
	for (int i = 0; i < numOfCell; i++)
	{
		for (int j = i + 1; j < numOfCell; j++)
		{
			for (int k = j + 1; k < numOfCell; k++)
			{
				// �ﰢ���� �� �������� ��� �� ���ϱ�
				int row1 = i / col;
				int col1 = i % col;
				int row2 = j / col;
				int col2 = j % col;
				int row3 = k / col;
				int col3 = k % col;

				// �Ƹ��ٿ� �ﰢ���� �ƴϸ� �Ѿ��
				if (matrix[row1][col1] == matrix[row2][col2] || matrix[row1][col1] == matrix[row3][col3] || matrix[row2][col2] == matrix[row3][col3])
					continue;

				// �ﰢ���� ���� ���ϱ�
				float area1 = getArea(col1, row1, col2, row2, col3, row3);


				// ���� �ﰢ�� �����ؼ� ���� ���ϱ�
				for (int l = 0; l < numOfCell; l++)
				{
					// ���� �ﰢ���� �������� ���� �ﰢ���� �������� ��ġ�� �ȉ�
					if (l == i || l == j || l == k)
						continue;

					// ���� �ﰢ���� �� �������� ��� �� ���ϱ�
					int row4 = l / col;
					int col4 = l % col;

					// ���� �ﰢ���� ����
					float area2;



					// ���� �ﰢ���� �Ƹ��ٿ� �ﰢ������ ���ϱ�
					if (matrix[row1][col1] != matrix[row4][col4] && matrix[row2][col2] != matrix[row4][col4])
					{
						// ���� �ﰢ���� ���� ���ϱ�
						area2 = getArea(col1, row1, col2, row2, col4, row4);

						// ���� ���ϱ�
						if (area2 > area1)
						{
							count++;
							break;
						}
					}



					// ���� �ﰢ���� �Ƹ��ٿ� �ﰢ������ ���ϱ�
					if (matrix[row1][col1] != matrix[row4][col4] && matrix[row3][col3] != matrix[row4][col4])
					{
						// ���� �ﰢ���� ���� ���ϱ�
						area2 = getArea(col1, row1, col3, row3, col4, row4);

						// ���� ���ϱ�
						if (area2 > area1)
						{
							count++;
							break;
						}
					}



					// ���� �ﰢ���� �Ƹ��ٿ� �ﰢ������ ���ϱ�
					if (matrix[row2][col2] != matrix[row4][col4] && matrix[row3][col3] != matrix[row4][col4])
					{
						// ���� �ﰢ���� ���� ���ϱ�
						area2 = getArea(col2, row2, col3, row3, col4, row4);

						// ���� ���ϱ�
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