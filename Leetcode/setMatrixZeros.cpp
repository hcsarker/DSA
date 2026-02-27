#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    bool row0 = false, col0 = false;

    // check first row
    for (int j = 0; j < cols; j++)
    {
        if (matrix[0][j] == 0)
        {
            row0 = true;
            break;
        }
    }

    // check first column
    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0)
        {
            col0 = true;
            break;
        }
    }

    // mark rows and columns
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // set zeros
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // zero first row
    if (row0)
    {
        for (int j = 0; j < cols; j++)
            matrix[0][j] = 0;
    }

    // zero first column
    if (col0)
    {
        for (int i = 0; i < rows; i++)
            matrix[i][0] = 0;
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    cout << "Before:\n";
    for (auto &row : matrix)
    {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

    setZeroes(matrix);

    cout << "\nAfter:\n";
    for (auto &row : matrix)
    {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
